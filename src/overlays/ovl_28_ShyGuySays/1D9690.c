#include "common.h"
#include "ShyGuySays.h"
int abs(int);

/* .data (0x1E0670) */
u32 D_800FD5C0_ShyGuySays = 0x19971204; /* random seed */
u16 D_800FD5C4_ShyGuySays = 0;
s16 D_800FD5C6_ShyGuySays = 0;
s16 D_800FD5C8_ShyGuySays = 0;
s16 D_800FD5CA_ShyGuySays = 0;
s16 D_800FD5CC_ShyGuySays = 0;
s16 D_800FD5CE_ShyGuySays = 0;
f32 D_800FD5D0_ShyGuySays = 0.0f;
f32 D_800FD5D4_ShyGuySays = 0.0f;
f32 D_800FD5D8_ShyGuySays = 0.0f;
u16 D_800FD5DC_ShyGuySays[2] = { 0, 180 };
u32 D_800FD5E0_ShyGuySays = 180;
u32 D_800FD5E4_ShyGuySays = 0;
s16 D_800FD5E8_ShyGuySays = 0;
u16 D_800FD5EA_ShyGuySays = 0;
f32 D_800FD5EC_ShyGuySays = 60.0f;

typedef struct unkStruct_ShyGuySays_06 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u16 unk12;
} unkStruct_ShyGuySays_06; /* sizeof 0x14 */

extern unkStruct_ShyGuySays_06 D_800FDC70_ShyGuySays[6];
extern s16 D_800FDC5C_ShyGuySays[3];
extern u32 D_800FDC28_ShyGuySays[4];
extern unkStructShyGuySays_03 D_800FDC38_ShyGuySays[5];
f32 func_80025D40(s16);
void func_800FBE60_ShyGuySays(omObjData*);
extern s16 D_800FD5C6_ShyGuySays;
extern s16 D_800FD5C8_ShyGuySays;
extern s16 D_800FD5CA_ShyGuySays;
typedef struct ShyGuyGridCell {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} ShyGuyGridCell; /* sizeof 6 */

extern ShyGuyGridCell* D_800FD9B4_ShyGuySays;
extern s16 D_800FD9B0_ShyGuySays;
extern u16 D_800FD9B8_ShyGuySays[2];
extern omObjData* D_800FD9AC_ShyGuySays;
extern s16 D_800FDC68_ShyGuySays[];
extern s16 D_800FDC6C_ShyGuySays;
extern f32 D_800FD5D0_ShyGuySays;
extern f32 D_800FD5D4_ShyGuySays;
extern f32 D_800FD5D8_ShyGuySays;
extern omObjData* D_800F3FB0[];

s16 func_8001755C(s32);
f32 func_80025D40(s16);
void func_800FBE60_ShyGuySays(omObjData*);
s16 func_80023FC8(s16);
u16 func_800FB2C8_ShyGuySays(s32);
void func_800FAA80_ShyGuySays(s16);
void func_800FAED8_ShyGuySays(s16, s32);
void func_800FA8F4_ShyGuySays(omObjData*);
void func_800FA960_ShyGuySays(omObjData*);
void func_80066DF4(s16, s16, s16, f32, f32, f32);
void func_80067284(s16, s16, f32);
void func_80060F04(s16, s16, s16, s16);
s16 func_800FB520_ShyGuySays(f32, f32, f32, s16, u16);
void func_800FB840_ShyGuySays(omObjData*);
void func_800F8818_ShyGuySays(omObjData*);
void func_800F9D80_ShyGuySays(unkShyGuySaysStruct*, u16);
void func_800F9C50_ShyGuySays(u16*);
void func_800F7680_ShyGuySays(s16*, u16);
void func_800F702C_ShyGuySays(omObjData*, f32);
/* retail calls func_80064EF4 unprototyped in func_800FA77C (int result narrowed to s16) */
#define func_80064EF4_s32 ((s32 (*)(s32, s32))func_80064EF4)
void func_800F82B0_ShyGuySays(omObjData*);


void func_800F65E0_ShyGuySays(void) {
    u8 temp_s0;

    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    func_8001DE70(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &omOutView), 0xA0);
    func_800234B8(0U, 0xFF, 0xFF, 0xFF);
    func_800234B8(1U, 0xFF, 0xFF, 0xFF);
    func_80023504(1, -96.0f, 100.0f, 26.0f);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 4000.0f);
    func_800F6FC0_ShyGuySays();
    func_800F747C_ShyGuySays((rand8() << 8) | rand8());
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800EE984 = 0;
    D_800FD9A4_ShyGuySays = 0;
    D_800FD9A6_ShyGuySays = 0;
    D_800FD9A8_ShyGuySays = 0;
    D_800FD99C_ShyGuySays = 0;
    D_800FD9A0_ShyGuySays = 0;
    D_800FDC1A_ShyGuySays = 0;
    D_800FDC1C_ShyGuySays = 0;
    D_800FDC1E_ShyGuySays = 0;
    D_800FDD10_ShyGuySays = 1;
    D_800FDC20_ShyGuySays = NULL;
    D_800FD998_ShyGuySays = omAddObj(0x20, 0, 0, -1, &func_800F67F8_ShyGuySays);
    func_8007B168("\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73\x00", 1);
    PlaySound(0x1A5);
}

void func_800F67F8_ShyGuySays(omObjData* arg0) {
    arg0->func_ptr = &func_800F6930_ShyGuySays;
    func_800F736C_ShyGuySays();
    func_800F8068_ShyGuySays();
    D_800FDC20_ShyGuySays = omAddObj(1, 7, 0, -1, &func_800FBAE4_ShyGuySays);
    omSetStatBit(D_800FDC20_ShyGuySays, 0xA0);
    func_800F81A4_ShyGuySays();
    D_800F2AF8[D_800ED440] = omAddObj(0, 0, 0, -1, &func_800FA77C_ShyGuySays);
    D_800ED440++;
    D_800F2AF8[D_800ED440] = omAddObj(0, 0, 0, -1, &func_800FB6E0_ShyGuySays);
    D_800ED440++;
    func_800FB30C_ShyGuySays();
    func_800F71F4_ShyGuySays();
    D_800FD9A0_ShyGuySays = 1;
    func_80060128(0x19);
    if (_CheckFlag(MINIGAME_ISLAND_ENDING) != 0) {
        D_800FDC1C_ShyGuySays = 1;
    }
}

void func_800F6930_ShyGuySays(omObjData* arg0) {
    func_800F6F98_ShyGuySays(arg0);
    func_800F72A4_ShyGuySays();
    switch (D_800FD5C4_ShyGuySays) {
    case 0:
        if (func_80072718() == 0) {
            D_800FDD10_ShyGuySays = func_80060288();
            GMesCreate(0);
            D_800FD5C4_ShyGuySays = 1;
            return;
        }
        return;
    case 1:
        if (GMesStatAllGet() == 0) {
            D_800FD9A0_ShyGuySays = 2;
            D_800FD5C4_ShyGuySays = 2;
            return;
        }
        break;
    case 2:
        func_800FB424_ShyGuySays();
        break;
    }
}

void func_800F69F8_ShyGuySays(void) {
    func_800F73EC_ShyGuySays();
    func_800FA8D4_ShyGuySays();
    func_80060198();
    func_80060268(D_800FDD10_ShyGuySays);
    omOvlReturnEx(1);
}


// decomp-permuter
void func_800F6A38_ShyGuySays(omObjData *arg0)
{
  s16 sp10[6] = {0x451, 0x452, 0x453, 0x454, 0x455, 0x456};
  s16 sp20[4];
  f32 t;
  s16 i;
  s32 flag;
  char done;
  func_800F6F98_ShyGuySays(arg0);
  func_800F72A4_ShyGuySays();
  if (D_800FD5CA_ShyGuySays != 0)
  {
    if (D_800FD9A4_ShyGuySays == 1)
    {
      t = ((f32) D_800FD5CC_ShyGuySays) / 30.0;
      if (t > 1.0)
      {
        t = 1.0f;
        D_800FD5CA_ShyGuySays = 0;
      }
      func_800F9C50_ShyGuySays((u16 *) sp20);
      for (i = 0; i < 4; i++)
      {
        if (sp20[i] == 1)
        {
          break;
        }
      }

      func_800F702C_ShyGuySays(D_800F3FB0[i], t);
    }
    D_800FD5CC_ShyGuySays++;
  }
  switch (D_800FD5C6_ShyGuySays)
  {
    case 0:
      if ((++D_800FD5C8_ShyGuySays) >= 0)
    {
      flag = 2;
      if (D_800FD9A4_ShyGuySays == 0)
      {
        flag = 0x11;
      }
      GMesCreate(flag);
      D_800FD5C8_ShyGuySays = 0;
      D_800FD5C6_ShyGuySays = 1;
    }
      break;

    case 1:
      if (((++D_800FD5C8_ShyGuySays) >= 0) && (GMesStatAllGet() == 2))
    {
      flag = 0x32;
      if (D_800FD9A4_ShyGuySays == 0)
      {
        flag = 0x34;
      }
      func_80060128(flag);
      D_800FD5C8_ShyGuySays = 0;
      D_800FD5C6_ShyGuySays = 2;
    }
      break;

    case 2:
      if ((++D_800FD5C8_ShyGuySays) >= 0)
    {
      D_800FDC1A_ShyGuySays = 1;
      D_800FD5C8_ShyGuySays = 0;
      D_800FD5C6_ShyGuySays = 3;
    }
      break;

    case 3:
      D_800FD5C8_ShyGuySays++;
      if (D_800FD9A4_ShyGuySays != 0)
    {
      if (D_800FD5C8_ShyGuySays < 0x15)
      {
        break;
      }
      func_800F9C50_ShyGuySays((u16 *) sp20);
      for (i = 0; i < 4; i++)
      {
        if (sp20[i] == 1)
        {
          break;
        }
      }

      GMesCreate(4, D_800FDC10_ShyGuySays[i]);
      PlaySound(sp10[D_800FDC10_ShyGuySays[i]]);
      GwPlayer[i].coins_mg += 10;
    }
      D_800FD5C8_ShyGuySays = 0;
      D_800FD5C6_ShyGuySays = 4;
      break;

    case 4:
      D_800FD5C8_ShyGuySays++;
      if (D_800FD9A4_ShyGuySays != 0)
    {
      done = 0x53 < D_800FD5C8_ShyGuySays;
    }
    else
    {
      done = D_800FD5C8_ShyGuySays >= 0x5A;
    }
      if (done && (GMesWait() == 0))
    {
      func_800726AC(0, 0x14);
      func_800601D4(0x28);
      D_800FD5C8_ShyGuySays = 0;
      D_800FD5C6_ShyGuySays = 5;
    }
      break;

    case 5:
      if (func_80072718() == 0)
    {
      arg0->func_ptr = &func_800F69F8_ShyGuySays;
    }
      break;

  }

}
void func_800F6E50_ShyGuySays(omObjData* arg0) {
    unkStruct_ShyGuySays_01* temp_v1_2;

    func_800F6F98_ShyGuySays(arg0);
    func_800F72A4_ShyGuySays();
    switch (D_800FD5CE_ShyGuySays) {
    case 0:
        GMesCreate(2);
        temp_v1_2 = &D_800FD9C0_ShyGuySays[D_800FDC1E_ShyGuySays];
        if ((temp_v1_2->unk_00 != 0) && (temp_v1_2->unk_04 != 0x200)) {
            GwPlayer[D_800FDC1E_ShyGuySays].coins_mg += 10;
        }
        D_800FD5CE_ShyGuySays++;
        return;
    case 1:
        if (GMesStatAllGet() != 2) {
            return;
        }
        D_800FD5CE_ShyGuySays++;
        return;
    case 2:
        if (GMesWait() == 0) {
            func_800726AC(0, 20);
            func_80060398(40);
            D_800FD5CE_ShyGuySays++;
            return;
        }
        return;
    default:
        if (func_80072718() == 0) {
            arg0->func_ptr = &func_800F69F8_ShyGuySays;
        }
        break;
    }
}

void func_800F6F98_ShyGuySays(omObjData* arg0) {
    if (D_800F5144 == 1) {
        arg0->func_ptr = &func_800F69F8_ShyGuySays;
    }
}

void func_800F6FC0_ShyGuySays(void) {
    CRot.x = -14.5f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 191.2f;
    Center.z = 0.2f;
    CZoom = 1069.0f;
}

void func_800F702C_ShyGuySays(omObjData* arg0, f32 arg1) {
    s16 temp_s0 = (D_800F2AF8[0]->work[0] << 8) | D_800F2AF8[0]->work[1];

    if (arg1 == 0.0) {
        D_800FD980_ShyGuySays.x = arg0->trans.x;
        D_800FD980_ShyGuySays.y = 100.0f;
        D_800FD980_ShyGuySays.z = arg0->trans.z;
        D_800FD98C_ShyGuySays.x = Center.x;
        D_800FD98C_ShyGuySays.y = Center.y;
        D_800FD98C_ShyGuySays.z = Center.z;
        return;
    }

    Center.x = D_800FD98C_ShyGuySays.x + (arg1 * (D_800FD980_ShyGuySays.x - D_800FD98C_ShyGuySays.x));
    Center.y = D_800FD98C_ShyGuySays.y + (arg1 * (D_800FD980_ShyGuySays.y - D_800FD98C_ShyGuySays.y));
    Center.z = D_800FD98C_ShyGuySays.z + (arg1 * (D_800FD980_ShyGuySays.z - D_800FD98C_ShyGuySays.z));
    CZoom = (1069.0 - (arg1 * 400.0));
    func_80066DC4(temp_s0, 0, (D_800FDC64_ShyGuySays->unk_00[2] * 320.0f), (60.0 - (arg1 * 4.0) + 2.0 * func_800AEAC0(arg1 * 180.0)));
}

void func_800F71F4_ShyGuySays(void) {
    s16 i;

    for (i = 0; i < 10; i++) {
        D_800FDCE8_ShyGuySays[i].unk_00 = D_800FDCE8_ShyGuySays[i].unk_02 = -1;
    }
}

void func_800F7244_ShyGuySays(s16 arg0, s16 arg1) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_800FDCE8_ShyGuySays[i].unk_00 == -1) {
            D_800FDCE8_ShyGuySays[i].unk_00 = arg0;  
            D_800FDCE8_ShyGuySays[i].unk_02 = arg1;
            return;
        }
    }
}

void func_800F72A4_ShyGuySays(void) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_800FDCE8_ShyGuySays[i].unk_00 != -1) {
            D_800FDCE8_ShyGuySays[i].unk_02 = D_800FDCE8_ShyGuySays[i].unk_02 - 1;
            if (D_800FDCE8_ShyGuySays[i].unk_02 <= 0) {         
                PlaySound(D_800FDCE8_ShyGuySays[i].unk_00);
                D_800FDCE8_ShyGuySays[i].unk_00 = D_800FDCE8_ShyGuySays[i].unk_02 = -1;
            }
        }
    }
}

void func_800F736C_ShyGuySays(void) {
    u16 i;

    D_800FDC64_ShyGuySays = HuMemDirectMalloc(sizeof(unkStruct_ShyGuySays_04));
    D_800FDC64_ShyGuySays->unk_00[0] = 1.0f;
    
    for (i = 1; i < 100; i++) {
        D_800FDC64_ShyGuySays->unk_00[i] = 1.0 / (f32) i;
    }
}

void func_800F73EC_ShyGuySays(void) {
    HuMemDirectFree(D_800FDC64_ShyGuySays);
}

u16 func_800F740C_ShyGuySays(u16 arg0) { //shared overlay function
    D_800FD5C0_ShyGuySays = D_800FD5C0_ShyGuySays * 0x19971204;
    D_800FD5C0_ShyGuySays = (D_800FD5C0_ShyGuySays + 0x19760831) >> 0x10;
    if (arg0 == 0) {
        return D_800FD5C0_ShyGuySays;
    } else {
        return (D_800FD5C0_ShyGuySays % arg0);
    }
}

void func_800F747C_ShyGuySays(u16 arg0) { //shared overlay function
    D_800FD5C0_ShyGuySays = arg0 + (arg0 * D_800FD5C0_ShyGuySays);
}

f32 func_800F74A0_ShyGuySays(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f4;
    f32 var_f12;
    f32 var_f14;

    var_f12 = arg0;
    var_f14 = arg1;

    if (var_f12 >= 360.0) {
        var_f12 -= 360.0;
    } else if (var_f12 < 0.0) {
        var_f12 += 360.0;
    }

    if (var_f14 >= 360.0) {
        var_f14 -= 360.0;
    } else if (var_f14 < 0.0) {
        var_f14 += 360.0;
    }

    temp_f4 = func_8009B618(var_f12 - var_f14 + 360.0, 360.0);
    if (temp_f4 < 180.0) {
        if (temp_f4 <= arg2) {
            return temp_f4;
        } else {
            return arg2;
        }
    } else {
        if (360.0 - temp_f4 <= arg2) {
            return -(360.0 - temp_f4);
        } else {
            return -arg2;
        }
    }
}

f32 func_800F7608_ShyGuySays(f32 arg0, f32 arg1) {
    f32 var_f4 = func_800B0CD8(arg0, arg1);

    if (var_f4 > 360.0) {
        var_f4 -= 360.0;
    } else if (var_f4 < 0.0) {
        var_f4 += 360.0;
    }

    return var_f4;
}

void func_800F7680_ShyGuySays(s16* arg0, u16 arg1) {
    u16 i;
    u16 j;
    s16 tmp;

    for (i = 0; i < arg1 - 1; i++) {
        for (j = i + 1; j < arg1; j++) {
            if (arg0[i] > arg0[j]) {
                tmp = arg0[i];
                arg0[i] = arg0[j];
                arg0[j] = tmp;
            }
        }
    }
}
f32 func_800F7720_ShyGuySays(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f2 = 1.0 - arg0;
    return temp_f2 * temp_f2 * arg1 + temp_f2 * arg0 * arg2 * 2.0 + arg0 * arg0 * arg3;
}
void func_800F7780_ShyGuySays(f32 arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4) {
    f32* var_s4 = &arg1->x;
    f32* var_s3 = &arg2->x;
    f32* var_s2 = &arg3->x;
    f32* var_s1 = &arg4->x;
    s32 i;

    for (i = 0; i < 3; i++) {
        *(var_s1++) = func_800F7720_ShyGuySays(arg0, *(var_s4++), *(var_s3++), *(var_s2++));
    }
}

f32 func_800F781C_ShyGuySays(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return ((arg0 - 1.0) * arg1 + (1.0 - arg0 * 2.0) * arg2 + arg0 * arg3) * 2.0;
}

void func_800F7874_ShyGuySays(f32 arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4) {
    f32* var_s4 = &arg1->x;
    f32* var_s3 = &arg2->x;
    f32* var_s2 = &arg3->x;
    f32* var_s1 = &arg4->x;
    f32 var_f2;
    f32 sp10[3];
    s32 i;

    for (i = 0; i < 3; i++) {
        sp10[i] = func_800F781C_ShyGuySays(arg0, *(var_s4++), *(var_s3++), *(var_s2++));
    }

    var_f2 = sqrtf(SQ(sp10[0]) + SQ(sp10[1]) + SQ(sp10[2]));

    if (var_f2 != 0.0f) {
        var_f2 = 1.0 / var_f2;
        for (i = 0; i < 3; i++) {
            *(var_s1++) = var_f2 * sp10[i];
        }
    } else {
        *(var_s1++) = 0.0f;
        *(var_s1++) = 0.0f;
        *(var_s1++) = 1.0f;
    }
}

void func_800F79E4_ShyGuySays(s16 arg0, unkStructShyGuySays_03* arg1, s16 arg2) {
    D_800F2B7C[arg0].unk_08 = arg1->unk_00;
    D_800F2B7C[arg0].unk_4C = 1.0f;

    if (arg2 >= 0) {
        D_800F2B7C[arg0].unk_0A = 0;
        D_800F2B7C[arg0].unk_48 = 0;
        D_800F2B7C[arg0].unk_50 = arg1->unk_02;
    } else {
        D_800F2B7C[arg0].unk_0A = 4;
        D_800F2B7C[arg0].unk_48 = arg1->unk_02;
        D_800F2B7C[arg0].unk_50 = 0;        
    }
}

void func_800F7A8C_ShyGuySays(s16 arg0, omObjData* arg1) {
    func_80025798(arg0, arg1->trans.x, arg1->trans.y, arg1->trans.z);
    func_800257E4(arg0, arg1->rot.x, arg1->rot.y, arg1->rot.z);
    func_80025830(arg0, arg1->scale.x, arg1->scale.y, arg1->scale.z);
}

f32 func_800F7AF8_ShyGuySays(f32 arg0, f32 arg1, f32 arg2) {
    if (arg1 < arg0) {
        if (fabs(arg0 - arg1) > arg2) {
            return arg2;
        }
        return fabsf(arg0 - arg1);
    }
    if (fabs(arg1 - arg0) > arg2) {
        return -arg2;
    }
    return -fabs(arg1 - arg0);
}
// register allocation: arg0/arg1 copies swap s2/s3 (masked 0, raw 5); a local element pointer fixes the
// registers but not the folded 0x1C offset (tried p = &(&arg1->unk_1C)[arg2], inline and base forms)
#ifdef NON_MATCHING
void func_800F7B74_ShyGuySays(omObjData* arg0, unkStruct_ShyGuySays_01* arg1, u16 arg2, s32 arg3) {
    arg0->motion[arg2] = func_8001755C(arg3);
    (&arg1->unk_1C)[arg2].unk_00 = func_80025E48(arg0->motion[arg2]);
    (&arg1->unk_1C)[arg2].unk_02 = func_80025D40(arg0->motion[arg2]);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_ShyGuySays/1D9690", func_800F7B74_ShyGuySays);
#endif
void func_800F7C0C_ShyGuySays(s16 arg0, s16 arg1, u16 arg2) {
    unk2C0C0StructC0* src;
    unk2C0C0StructC0* dst;
    unk2C0C0Struct40* ent;
    unk2C0C0Struct50* grp;
    u16 i;
    u16 j;

    src = D_800F2B7C[arg0].unk_6C;
    dst = D_800F2B7C[arg1].unk_6C;
    if (arg2 < src->unk_6A && arg2 < dst->unk_6A) {
        if (dst->unk_A0 == (unk2C0C0Struct50*)-1) {
            for (j = 0; j < src->unk_84; j++) {
                ent = &dst->unk_88[j];
                if (ent->unk_00 == arg2) {
                    ent->unk_48 = dst;
                    ent->unk_00 = arg2;
                    break;
                }
            }
        } else {
            for (i = 0; i < dst->unk_70; i++) {
                grp = &dst->unk_A0[i];
                for (j = 0; j < grp->unk_00; j++) {
                    if (grp->unk_04[j] == arg2) {
                        grp->unk_60 = src;
                        grp->unk_04[j] = arg2;
                        break;
                    }
                }
            }
        }
    }
}
void func_800F7D88_ShyGuySays(s16 arg0, s16 arg1, u16 arg2, f32 arg3) {
    unk2C0C0StructC0* temp_a3;
    unk2C0C0StructC0* temp_t0;
    unk2C0C0StructE0* var_a2;
    unk2C0C0StructE0* var_a3;
    unk2C0C0StructE0* var_t0;
    s16 temp_a2 = arg2;
    s16 temp_v0;
    s16 i;

    temp_t0 = D_800F2B7C[arg0].unk_6C;
    temp_a3 = D_800F2B7C[arg1].unk_6C;

    if (~temp_a2 == 0) {
        return;
    }

    var_a2 = &temp_t0->unk_04[temp_t0->unk_80[temp_a2].unk_0A];
    var_a3 = &temp_a3->unk_04[temp_a3->unk_80[temp_a2].unk_0A];
    var_t0 = &temp_t0->unk_08[D_800F37F0][temp_t0->unk_80[temp_a2].unk_0A];

    temp_v0 = temp_t0->unk_80[temp_a2].unk_0C;
    for (i = 0; i < temp_v0; i++) {
        *var_t0 = *var_a2;
        if (var_a2->unk_00 != var_a3->unk_00 || var_a2->unk_02 != var_a3->unk_02 || var_a2->unk_04 != var_a3->unk_04) {
            var_t0->unk_00 = var_a2->unk_00 * arg3 + var_a3->unk_00 * (1.0f - arg3);
            var_t0->unk_02 = var_a2->unk_02 * arg3 + var_a3->unk_02 * (1.0f - arg3);
            var_t0->unk_04 = var_a2->unk_04 * arg3 + var_a3->unk_04 * (1.0f - arg3);
            var_t0->unk_0C.r = (s32) ((s8) var_a2->unk_0C.r * arg3 + (s8) var_a3->unk_0C.r * (1.0f - arg3));
            var_t0->unk_0C.g = (s32) ((s8) var_a2->unk_0C.g * arg3 + (s8) var_a3->unk_0C.g * (1.0f - arg3));
            var_t0->unk_0C.b = (s32) ((s8) var_a2->unk_0C.b * arg3 + (s8) var_a3->unk_0C.b * (1.0f - arg3));
        }
        var_a2++;
        var_a3++;
        var_t0++;
    }
}

void func_800F8068_ShyGuySays(void) {
    D_800FDC5C_ShyGuySays[0] = func_800174C0(0x3C0004, 0x99);
    D_800FDC5C_ShyGuySays[1] = func_800174C0(0x3C0005, 0x99);
    D_800FDC5C_ShyGuySays[2] = func_800174C0(0x3C0004, 0x499);
    func_800258EC(D_800FDC5C_ShyGuySays[0], 4, 4);
    func_800258EC(D_800FDC5C_ShyGuySays[1], 4, 4);
    func_800258EC(D_800FDC5C_ShyGuySays[2], 4, 4);
}
s16 func_800F80F8_ShyGuySays(s16 arg0) {
    s16 ret;

    switch (arg0) {
    case 2:
        ret = func_80023FC8(D_800FDC5C_ShyGuySays[0]);
        break;
    case 3:
        ret = func_80023FC8(D_800FDC5C_ShyGuySays[1]);
        break;
    case 4:
        ret = func_80023FC8(D_800FDC5C_ShyGuySays[2]);
        break;
    default:
        return -1;
    }
    func_800258EC(ret, 4, 0);
    return ret;
}
void func_800F81A4_ShyGuySays(void) {
    u16 i;
    omObjData* obj;

    for (i = 0; i < 5; i++) {
        D_800FDC10_ShyGuySays[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        obj = D_800F3FB0[D_800F2BC0] = omAddObj(3, 0x10, 4, -1, &func_800F82B0_ShyGuySays);
        obj->work[0] = i;
        omSetStatBit(D_800F3FB0[D_800F2BC0], 0xA0);
        D_800F2BC0++;
        D_800FD9A4_ShyGuySays++;
        D_800FD9A6_ShyGuySays++;
    }
}

const ShyGuyMotTbl D_800FD6C8_ShyGuySays = { { { 9, 12 }, { 9, 12 }, { 5, 8 }, { 4, 7 }, { 9, 11 }, { 5, 8 } } };

void func_800F82B0_ShyGuySays(omObjData* arg0) {
    ShyGuyMotTbl sp10 = D_800FD6C8_ShyGuySays;
    s32 file0 = 0;
    s32 file1 = 0;
    s16 player;
    s32 chr;
    s32 form;
    s32 dir;
    s32 i;
    unkStruct_ShyGuySays_01* p;
    s16 level;

    arg0->func_ptr = &func_800F8818_ShyGuySays;
    player = 0;
    switch (arg0->work[0]) {
    case 0:
        player = 0;
        break;
    case 1:
        player = 1;
        break;
    case 2:
        player = 2;
        break;
    case 3:
        player = 3;
        break;
    }
    D_800FDC10_ShyGuySays[arg0->work[0]] = chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    form = D_800C59AC[chr].unk_04;
    switch (chr) {
    case 0:
        file0 = 0x3C000B;
        file1 = 0x3C0011;
        break;
    case 1:
        file0 = 0x3C000C;
        file1 = 0x3C0012;
        break;
    case 2:
        file0 = 0x3C000D;
        file1 = 0x3C0013;
        break;
    case 3:
        file0 = 0x3C000E;
        file1 = 0x3C0014;
        break;
    case 4:
        file0 = 0x3C000F;
        file1 = 0x3C0015;
        break;
    case 5:
        file0 = 0x3C0010;
        file1 = 0x3C0016;
        break;
    }
    arg0->model[0] = LoadFormFile(dir | form, 0xA99);
    if (chr == 4) {
        arg0->model[1] = LoadFormFile(file0, 0xA8D);
        arg0->model[2] = LoadFormFile(file1, 0xA8D);
        func_80025930(arg0->model[1], 0x20000, 0x20000);
        func_80025930(arg0->model[2], 0x20000, 0x20000);
        func_80025AD4(arg0->model[1]);
        func_80025AD4(arg0->model[2]);
        func_80025B34(arg0->model[1]);
        func_80025B34(arg0->model[2]);
        func_800258EC(arg0->model[1], 0x10, 0x10);
        func_800258EC(arg0->model[2], 0x10, 0x10);
    } else {
        arg0->model[1] = LoadFormFile(file0, 0xA9D);
        arg0->model[2] = LoadFormFile(file1, 0xA9D);
    }
    arg0->model[3] = func_800F80F8_ShyGuySays(3);
    func_80026040(arg0->model[1]);
    for (i = 0; i < 8; i++) {
        arg0->model[4 + i] = func_800F80F8_ShyGuySays(2);
    }
    for (i = 0; i < 4; i++) {
        arg0->model[12 + i] = func_800F80F8_ShyGuySays(4);
    }
    p = &D_800FD9C0_ShyGuySays[arg0->work[0]];
    func_800F9D80_ShyGuySays((unkShyGuySaysStruct*)p, arg0->work[0]);
    switch (GwPlayer[player].cpu_difficulty) {
    case 0:
        level = 4;
        break;
    case 1:
        level = 3;
        break;
    case 2:
        level = 2;
        break;
    case 3:
        level = 1;
        break;
    default:
        level = 3;
        break;
    }
    p->unk_0C = level;
    p->unk_08 = GwPlayer[player].port;
    if (GwPlayer[player].flags & 1) {
        p->unk_08 = -1;
    } else {
        D_800FDC1E_ShyGuySays = player;
    }
    func_800F7C0C_ShyGuySays(arg0->model[1], arg0->model[0], sp10.unk_00[chr].unk_00);
    func_800F7C0C_ShyGuySays(arg0->model[1], arg0->model[0], sp10.unk_00[chr].unk_02);
    func_800F7B74_ShyGuySays(arg0, p, 0, dir | 0x5C);
    func_800F7B74_ShyGuySays(arg0, p, 1, dir | 0x5D);
    func_800F7B74_ShyGuySays(arg0, p, 2, dir | 0x94);
    func_800F7B74_ShyGuySays(arg0, p, 3, dir | 0x80);
    func_800F79E4_ShyGuySays(arg0->model[0], &p->unk_1C, -1);
    D_800F2B7C[arg0->model[0]].unk_48 = 0.0f;
    arg0->work[1] = 1;
    arg0->trans.x = p->unk_84 = arg0->work[0] * 300.0 + -450.0;
    arg0->trans.y = 0.0f;
    arg0->trans.z = -1000.0f;
    arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
}
void func_800F8818_ShyGuySays(omObjData* arg0) {
    ShyGuyMotTbl sp10;
    unkStruct_ShyGuySays_01* temp_s2;
    s32 temp_s0;
    u16 var_s0;

    sp10 = D_800FD6C8_ShyGuySays;
    temp_s2 = &D_800FD9C0_ShyGuySays[arg0->work[0]];

    if (func_8005FD5C() + D_800F64F8 == 0) {
        temp_s2->unk_90 += 10;
        if (temp_s2->unk_90 >= 180) {
            temp_s2->unk_90 -= 180;
        }
    }

    func_800F7D88_ShyGuySays(arg0->model[1], arg0->model[2], sp10.unk_00[D_800FDC10_ShyGuySays[arg0->work[0]]].unk_00, func_800AEAC0(temp_s2->unk_90));
    func_800F7D88_ShyGuySays(arg0->model[1], arg0->model[2], sp10.unk_00[D_800FDC10_ShyGuySays[arg0->work[0]]].unk_02, func_800AEAC0(temp_s2->unk_90));

    if (func_8005FD5C() + D_800F64F8 != 0 || temp_s2->unk_00 == 0) {
        return;
    }

    if (temp_s2->unk_04 != 0x200 && (D_800FDC4C_ShyGuySays > 0 && D_800FDC4C_ShyGuySays < 5) && temp_s2->unk_10 == 1 && temp_s2->unk_14 == 1) {
        temp_s0 = temp_s2->unk_14;
        temp_s2->unk_04 = 0;
        if (temp_s2->unk_08 != -1) {
            if (ContBtnTrg[temp_s2->unk_08] & B_BUTTON) {
                func_800F9118_ShyGuySays(arg0, 1);
                temp_s2->unk_04 = temp_s0;
            } else if (ContBtnTrg[temp_s2->unk_08] & A_BUTTON) {
                func_800F9118_ShyGuySays(arg0, 2);
                temp_s2->unk_04 = 2;
            }
        } else {
            func_800F8D58_ShyGuySays(arg0);
        }
    } else if (D_800FDC4C_ShyGuySays == 6) {
        func_800F9118_ShyGuySays(arg0, 6);
    }

    if ((temp_s2->unk_04 & 0x200) && temp_s2->unk_18 != 0) {
        func_800F9118_ShyGuySays(arg0, 11);
        arg0->scale.x -= 0.025 / 3;
        arg0->scale.y -= 0.025 / 3;
        arg0->scale.z -= 0.025 / 3;
        arg0->trans.z -= 20.0f;
        temp_s2->unk_2C.x += func_800F7AF8_ShyGuySays(arg0->trans.x, temp_s2->unk_2C.x, 6.0f);
        temp_s2->unk_2C.y -= func_800F7AF8_ShyGuySays(-40.0f, temp_s2->unk_2C.y, 6.0f);
        temp_s2->unk_2C.z -= 20.0f;
        temp_s2->unk_18--;
        if (temp_s2->unk_18 == 0) {
            for (var_s0 = 0; var_s0 < 12; var_s0++) {
                func_800258EC(arg0->model[var_s0], 4, 4);
            }
            temp_s2->unk_00 = 0;
        }
    } else if (D_800FD9A0_ShyGuySays == 3 && D_800FDC1A_ShyGuySays == 1) {
        func_800F9118_ShyGuySays(arg0, 10);
    }

    func_800F9F60_ShyGuySays(arg0, &arg0->model[4], 8);
    func_800FA308_ShyGuySays(arg0, &arg0->model[12], 4);

    arg0->trans.y -= 20.0f;
    arg0->trans.y = func_800F7AF8_ShyGuySays(func_800FB190_ShyGuySays(arg0->trans.x, arg0->trans.z), arg0->trans.y, 2.0f) + arg0->trans.y + 20.0f;

    temp_s2->unk_88 += func_800F740C_ShyGuySays(0) & 7;
    if (temp_s2->unk_88 >= 360) {
        temp_s2->unk_88 -= 360;
    }

    arg0->trans.x = func_800AEAC0(temp_s2->unk_88) * 20.0f + temp_s2->unk_84;
    arg0->trans.y -= 20.0f;

    if (D_800FDC10_ShyGuySays[arg0->work[0]] == 4) {
        arg0->trans.z += 20.0f;
    }

    func_800F7A8C_ShyGuySays(arg0->model[3], arg0);

    arg0->trans.y += 20.0f;
    if (D_800FDC10_ShyGuySays[arg0->work[0]] == 4) {
        arg0->trans.z -= 20.0f;
    }
}

void func_800F8D58_ShyGuySays(omObjData* arg0) { //matches but needs rodata support
    unkStruct_ShyGuySays_01* temp_s1;
    s32 phi_a0;
    s16 phi_s0;

    temp_s1 = &D_800FD9C0_ShyGuySays[arg0->work[0]];
    if (temp_s1->unk_8C == 0) {
        temp_s1->unk_8C = 1;
        temp_s1->unk_8A = 0;
        phi_a0 = MIN(20, D_800FDC54_ShyGuySays);
        temp_s1->unk_18 = temp_s1->unk_0A + func_800F740C_ShyGuySays(phi_a0 + 5);
    }
    
    switch ( func_800FD200_ShyGuySays() ) {
    case 0:
        break;
    case 1:
        if (D_800FDC4C_ShyGuySays < 3) {
            return;
        }
        if (D_800FDC4C_ShyGuySays == 3 && func_800FD1D0_ShyGuySays() < 20.0) {
            return;
        }
        temp_s1->unk_8A++;
        if (temp_s1->unk_8A < temp_s1->unk_18) {
            return;
        }
        phi_s0 = 100 - (temp_s1->unk_0C * (D_800FD9A8_ShyGuySays - 4));
        phi_s0 &= (~phi_s0 >> 0x1F);
        if (D_800FD9A8_ShyGuySays < 5) {
            phi_s0 = 100;
        }
        if (func_800F740C_ShyGuySays(100) >= phi_s0) {
            func_800F9118_ShyGuySays(arg0, 1);
            temp_s1->unk_04 = 1;
            temp_s1->unk_8C = 0;
        } else {                
            func_800F9118_ShyGuySays(arg0, 2);
            temp_s1->unk_04 = 2;
            temp_s1->unk_8C = 0;
        }
        break;
    case 2:
        if (D_800FDC4C_ShyGuySays < 3) {
            return;
        }
        if (D_800FDC4C_ShyGuySays == 3 && func_800FD1D0_ShyGuySays() < 20.0) {
            return;
        }
        temp_s1->unk_8A++;
        if (temp_s1->unk_8A < temp_s1->unk_18) {
            return;
        }
        phi_s0 = 100 - (temp_s1->unk_0C * (D_800FD9A8_ShyGuySays - 4));
        phi_s0 &= (~phi_s0 >> 0x1F);
        if ((s32) D_800FD9A8_ShyGuySays < 5) {
            phi_s0 = 100;
        }
        if (func_800F740C_ShyGuySays(100) < phi_s0) {
            func_800F9118_ShyGuySays(arg0, 1);
            temp_s1->unk_04 = 1;
            temp_s1->unk_8C = 0;
        } else {                
            func_800F9118_ShyGuySays(arg0, 2);
            temp_s1->unk_04 = 2;
            temp_s1->unk_8C = 0;
        }
        break;
    case 3:
        if (D_800FDC4C_ShyGuySays <= 0 || D_800FD99C_ShyGuySays < 0xA) {
            return;
        }
        if ((temp_s1->unk_0A >= 4) && (func_800F740C_ShyGuySays(0) & 3)) {
            if ((func_800F740C_ShyGuySays(0) & 1) != 0) {
                func_800F9118_ShyGuySays(arg0, 1);
                temp_s1->unk_04 = 1;
                temp_s1->unk_8C = 0;
            } else {
                func_800F9118_ShyGuySays(arg0, 2);
                temp_s1->unk_04 = 2;
                temp_s1->unk_8C = 0;
            }
        }
        break;
    }

    if (temp_s1->unk_18 >= D_800FDC54_ShyGuySays + 4.0f) {
        temp_s1->unk_18 = D_800FDC54_ShyGuySays + 4.0f;
    }
}

void func_800F9118_ShyGuySays(omObjData* arg0, s16 arg1) {
    unk_ovl_2D_struct* temp_s1;
    unkStruct_ShyGuySays_01* temp_s0;
    s16 temp_v0;
    s16 var_s3;

    temp_s1 = &D_800F2B7C[arg0->model[0]];
    temp_s0 = &D_800FD9C0_ShyGuySays[arg0->work[0]];

    switch (arg0->work[0]) {
        case 0:
            var_s3 = 0x20;
            break;
        case 1:
            var_s3 = 0x30;
            break;
        case 2:
            var_s3 = 0x50;
            break;
        default:
            var_s3 = 0x60;
            break;
    }

    if (temp_s1->unk_48 < temp_s1->unk_50 && (arg1 != 10 || arg1 != 11)) {
        return;
    }

    switch (arg1) {
        case 1:
            if (temp_s0->unk_10 == 1 && temp_s0->unk_14 == 1) {
                temp_v0 = func_80060540(0x2F9, arg0->work[0]);
                if (temp_v0 != -1) {
                    func_800607C4(temp_v0, var_s3);
                }
                temp_s0->unk_10 = 2;
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_1C, 1);
            }
            break;
        case 2:
            if (temp_s0->unk_10 == 1 && temp_s0->unk_14 == 1) {
                temp_v0 = func_80060540(0x2FA, arg0->work[0]);
                if (temp_v0 != -1) {
                    func_800607C4(temp_v0, var_s3);
                }
                temp_s0->unk_14 = 2;
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_20, 1);
            }
            break;
        case 6:
            if (temp_s0->unk_10 == 2 && temp_s0->unk_14 == 1) {
                temp_s0->unk_10 = 1;
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_1C, -1);
            } else if (temp_s0->unk_10 == 1 && temp_s0->unk_14 == 2) {
                temp_s0->unk_14 = 1;
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_20, -1);
            }
            break;
        case 10:
            if (temp_s0->unk_92 == 0 && temp_s1->unk_48 >= temp_s1->unk_50) {
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_24, 1);
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_20, -1);
                temp_s1->unk_48 = 0.0f;
                func_80025C20(arg0->model[0], temp_s0->unk_24.unk_00, 0, 0xA, 0);
                temp_s0->unk_92++;
            } else if (temp_s1->unk_0C == -1 && temp_s1->unk_48 >= temp_s1->unk_50) {
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_24, 1);
            }
            break;
        case 11:
            if (temp_s0->unk_92 == 0 && temp_s1->unk_48 >= temp_s1->unk_50) {
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_28, 1);
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_20, -1);
                temp_s1->unk_48 = 0.0f;
                func_80025C20(arg0->model[0], temp_s0->unk_28.unk_00, 0, 0xA, 0);
                temp_s0->unk_92++;
            } else if (temp_s1->unk_0C == -1 && temp_s1->unk_48 >= temp_s1->unk_50) {
                func_800F79E4_ShyGuySays(arg0->model[0], &temp_s0->unk_28, 1);
            }
            break;
    }
}

void func_800F94A8_ShyGuySays(void) {
    u16 i;
    unkStruct_ShyGuySays_01* p = D_800FD9C0_ShyGuySays;
    omObjData* obj;

    for (i = 0; i < 4; i++, p++) {
        obj = D_800F3FB0[i];
        if (p->unk_00 != 0 && p->unk_04 != 0x200 && p->unk_08 == -1 && p->unk_10 == 1 && p->unk_14 == 1) {
            if (func_800F740C_ShyGuySays(0) & 1) {
                func_800F9118_ShyGuySays(obj, 1);
                p->unk_04 = 1;
            } else {
                func_800F9118_ShyGuySays(obj, 2);
                p->unk_04 = 2;
            }
            p->unk_8C = 0;
        }
    }
}
void func_800F95BC_ShyGuySays(void) {
    u16 i;
    unkStruct_ShyGuySays_01* p = D_800FD9C0_ShyGuySays;
    omObjData* obj;

    for (i = 0; i < 4; i++, p++) {
        obj = D_800F3FB0[i];
        if (p->unk_00 != 0 && p->unk_04 != 0x200 && p->unk_08 != -1 && p->unk_10 == 1 && p->unk_14 == 1) {
            if (func_800F740C_ShyGuySays(0) & 1) {
                func_800F9118_ShyGuySays(obj, 1);
                p->unk_04 = 1;
            } else {
                func_800F9118_ShyGuySays(obj, 2);
                p->unk_04 = 2;
            }
            p->unk_8E = 1;
            p->unk_8C = 0;
        }
    }
}
void func_800F96D4_ShyGuySays(void) {
    s16 i;
    unk_ovl_2D_struct* m;
    unkStruct_ShyGuySays_01* p;

    for (i = 0; i < 4; i++) {
        m = &D_800F2B7C[D_800F3FB0[i]->model[0]];
        p = &D_800FD9C0_ShyGuySays[i];
        if (D_800FD9C0_ShyGuySays[i].unk_00 != 0 && D_800FD9C0_ShyGuySays[i].unk_04 != 0x200 && p->unk_8E != 0) {
            m->unk_4C = 0.0f;
            m->unk_50 = m->unk_48;
            p->unk_04 = 0;
            p->unk_10 = 1;
            p->unk_14 = 1;
        }
    }
}
s16 func_800F97A8_ShyGuySays(void) {
    unkStruct_ShyGuySays_01* p = D_800FD9C0_ShyGuySays;
    u16 i;

    for (i = 0; i < 4; i++, p++) {
        if (p->unk_00 == 0 || D_800FD9C0_ShyGuySays[i].unk_04 == 0x200) {
            continue;
        }
        if (p->unk_10 != 1 || p->unk_14 != 1) {
            return 0;
        }
    }
    return 1;
}
s16 func_800F9828_ShyGuySays(void) {
    s16 i;
    unk_ovl_2D_struct* m;

    for (i = 0; i < 4; i++) {
        m = &D_800F2B7C[D_800F3FB0[i]->model[0]];
        if (D_800FD9C0_ShyGuySays[i].unk_00 != 0 && D_800FD9C0_ShyGuySays[i].unk_04 != 0x200 && m->unk_48 != m->unk_50) {
            return 0;
        }
    }
    return 1;
}
void func_800F98EC_ShyGuySays(void) {
    s16 i;
    unk_ovl_2D_struct* m;

    for (i = 0; i < 4; i++) {
        m = &D_800F2B7C[D_800F3FB0[i]->model[0]];
        if (D_800FD9C0_ShyGuySays[i].unk_00 != 0 && D_800FD9C0_ShyGuySays[i].unk_04 != 0x200 && m->unk_4C == 0.0f) {
            m->unk_0A = 4;
            m->unk_4C = 1.0f;
            m->unk_50 = 0.0f;
        }
    }
}
s16 func_800F99C0_ShyGuySays(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        if (D_800FD9C0_ShyGuySays[i].unk_00 != 0 && D_800FD9C0_ShyGuySays[i].unk_04 == 512) {
            if (D_800FD9C0_ShyGuySays[i].unk_18 > 60.0) {
                return 0;
            }
        }
    }

    return 1;
}

s16 func_800F9A7C_ShyGuySays(u16 arg0, s16 arg1) {
    if (D_800FD9C0_ShyGuySays[arg0].unk_00 == 0 || D_800FD9C0_ShyGuySays[arg0].unk_04 == 0x200) {
        return 1;
    }
    return D_800FD9C0_ShyGuySays[arg0].unk_04 == arg1;
}
void func_800F9AFC_ShyGuySays(u16 arg0) {
    s16 sp18[6] = { 0x45F, 0x460, 0x461, 0x462, 0x463, 0x464 };
    unkStruct_ShyGuySays_01* p;
    s16 fx;

    p = &D_800FD9C0_ShyGuySays[arg0];
    p->unk_18 = 0x78;
    p->unk_04 = 0x200;
    fx = func_800FB520_ShyGuySays(p->unk_2C.x, p->unk_2C.y, p->unk_2C.z, 2, 3);
    func_80067284(D_800FDC70_ShyGuySays[fx].unk2, 0, 1.0f);
    D_800FDC70_ShyGuySays[fx].unk10 = 4;
    PlaySound(0x2FB);
    if (p->unk_08 != -1) {
        func_80060F04(arg0, 0x14, 0, 0x14);
    }
    func_800F7244_ShyGuySays(sp18[D_800FDC10_ShyGuySays[arg0]], 0xA);
}
void func_800F9C50_ShyGuySays(u16 arg0[]) {
    u16 i;
    
    if (--D_800FD9A6_ShyGuySays > 0) {
        for (i = 0; i < 4; i++) {
            D_800FD9CE_ShyGuySays[i].unk_00 -= D_800FD9A6_ShyGuySays;
        }
    }

    for (i = 0; i < 4; i++) {
        arg0[i] = D_800FD9CE_ShyGuySays[i].unk_00;
    }

}

void func_800F9D14_ShyGuySays(s16 arg0) {   
    u16 i;

    for (i = 0; i < 4; i++) {
        if ((D_800FD9C0_ShyGuySays[i].unk_00 != 0) && (D_800FD9C0_ShyGuySays[i].unk_04 != 0x200)) {
            D_800FD9CE_ShyGuySays[i].unk_00 = arg0;
        }
    }
}

void func_800F9D80_ShyGuySays(unkShyGuySaysStruct* arg0, u16 playerIndex) {
    func_8009B770((unkGlobalStruct_00* ) arg0, 0, 0x94);
    arg0->unk0 = 1;
    arg0->unk4 = 0;
    arg0->unk8 = -1;
    arg0->unkA = -1;
    arg0->unkC = 0;
    arg0->unkE = 4;
    arg0->unk10 = 1;
    arg0->unk14 = 1;
    arg0->unkA = (s16) (func_800F740C_ShyGuySays(5U) + 1);
    arg0->unk18 = (s32) (arg0->unkA + (func_800F740C_ShyGuySays(0x19U) & 0xFFFF));
    switch (playerIndex) {
    case 0:
        arg0->unk2C = -110.0f;
        arg0->unk34 = 220.0f;
        arg0->unk44 = -110.0f;
        arg0->unk4C = 250.0f;
        break;
    case 1:
        arg0->unk2C = -70.0f;
        arg0->unk34 = 150.0f;
        arg0->unk44 = -70.0f;
        arg0->unk4C = 170.0f;
        break;
    case 2:
        arg0->unk2C = 70.0f;
        arg0->unk34 = 150.0f;
        arg0->unk44 = 70.0f;
        arg0->unk4C = 170.0f;
        break;
    case 3:
        arg0->unk2C = 110.0f;
        arg0->unk34 = 220.0f;
        arg0->unk44 = 110.0f;
        arg0->unk4C = 250.0f;
    }
    arg0->unk30 = 90.0f;
    arg0->unk48 = 50.0f;
    arg0->unk80 = (s32) (func_800F740C_ShyGuySays(0x168U) & 0xFFFF);
    arg0->unk84 = 0;
    arg0->unk88 = func_800F740C_ShyGuySays(0x168U);
    arg0->unk8A = 0;
    arg0->unk8C = 0;
    arg0->unk8E = 0;
    arg0->unk90 = 0;
    arg0->unk92 = 0;
}


void func_800F9F60_ShyGuySays(omObjData* arg0, s16* arg1, u16 arg2) {
    unkStruct_ShyGuySays_01* temp_s2;
    f32 sp18[3];
    f32 temp_f20;
    f32 var_f2;
    u16 i;

    temp_s2 = &D_800FD9C0_ShyGuySays[arg0->work[0]];

    if (D_800FDC20_ShyGuySays == NULL) {
        var_f2 = 0.0f;
    } else {
        var_f2 = D_800FDC20_ShyGuySays->trans.y;
    }

    if (arg0->trans.y == 1.0f || arg0->trans.y == 2.0f) {
        temp_s2->unk_2C.y = var_f2 - 0.0;
    } else {
        temp_s2->unk_2C.y = var_f2 - 4.0;
    }

    sp18[0] = func_800F7608_ShyGuySays(arg0->trans.y - temp_s2->unk_2C.y, arg0->trans.z - temp_s2->unk_2C.z);
    sp18[1] = func_800F7608_ShyGuySays(arg0->trans.x - temp_s2->unk_2C.x, arg0->trans.z - temp_s2->unk_2C.z);
    sp18[2] = 0.0f;

    temp_s2->unk_80 += func_800F740C_ShyGuySays(0) & 7;
    if (temp_s2->unk_80 > 360) {
        temp_s2->unk_80 -= 360;
    }

    temp_s2->unk_5C.x = arg0->trans.x;
    temp_s2->unk_5C.y = arg0->trans.y;
    temp_s2->unk_5C.z = arg0->trans.z;

    temp_s2->unk_50.x = temp_s2->unk_2C.x + func_800AEAC0(sp18[1]) * 20.0f * 20.0f + func_800AEAC0(temp_s2->unk_80) * 20.0f * 2.0f;
    temp_s2->unk_50.y = arg0->trans.y - 40.0f;
    temp_s2->unk_50.z = temp_s2->unk_2C.z + func_800AEFD0(sp18[1]) * 20.0f * 20.0f;

    for (i = 1; i < arg2 + 1; i++) {
        temp_f20 = i * D_800FDC64_ShyGuySays->unk_00[arg2];
        func_800F7780_ShyGuySays(temp_f20, &temp_s2->unk_2C, &temp_s2->unk_50, &temp_s2->unk_5C, &temp_s2->unk_68);
        func_800F7874_ShyGuySays(temp_f20, &temp_s2->unk_2C, &temp_s2->unk_50, &temp_s2->unk_5C, &temp_s2->unk_74);

        func_80025798(arg1[i], temp_s2->unk_68.x, temp_s2->unk_68.y, temp_s2->unk_68.z);

        sp18[0] = func_800F7608_ShyGuySays(temp_s2->unk_74.y, -temp_s2->unk_74.z);
        sp18[1] = func_800F7608_ShyGuySays(-temp_s2->unk_74.x, -temp_s2->unk_74.z);
        sp18[2] = 0.0f;

        func_800257E4(arg1[i], sp18[0], sp18[1], sp18[2]);
        func_80025830(arg1[i], 1.0f, 1.0f, 1.9f);

        if (i == 1) {
            temp_s2->unk_38.x = temp_s2->unk_68.x;
            temp_s2->unk_38.y = temp_s2->unk_68.y + 8.0;
            temp_s2->unk_38.z = temp_s2->unk_68.z + 20.0f;
        }
    }
}

// register allocation in the joint loop: (f32)i lands in t's $f20, retail uses a $f2 temp (masked 2, raw 7);
// tried swapped operands, t/sway declaration order
#ifdef NON_MATCHING
void func_800FA308_ShyGuySays(omObjData* arg0, s16* arg1, u16 arg2) {
    f32 sp18[3];
    unkStruct_ShyGuySays_01* p;
    f32 sway;
    f32 t;
    u16 i;

    sway = 0.0f;
    p = &D_800FD9C0_ShyGuySays[arg0->work[0]];
    if (D_800FDC20_ShyGuySays == NULL) {
        p->unk_44.y = -90.0f;
    } else {
        p->unk_44.y = D_800FDC20_ShyGuySays->trans.y - 90.0;
    }
    if (p->unk_04 & 0x200) {
        for (i = 0; i < arg2; i++) {
            func_800258EC(arg1[i], 4, 4);
        }
    }
    switch (arg0->work[0]) {
    case 0:
        sway = func_800AEAC0(p->unk_80) * 20.0f * 0.5;
        if (sway > 0.0f) {
            sway = 0.0f;
        }
        break;
    case 1:
    case 2:
        sway = func_800AEAC0(p->unk_80) * 20.0f * 0.5;
        break;
    case 3:
        sway = func_800AEAC0(p->unk_80) * 20.0f * 0.5;
        if (sway < 0.0f) {
            sway = 0.0f;
        }
        break;
    }
    p->unk_50.x = p->unk_44.x + (p->unk_2C.x - p->unk_44.x) * 0.5 - sway;
    switch (arg0->work[0]) {
    case 0:
    case 3:
        p->unk_50.y = p->unk_2C.y + 40.0;
        p->unk_38.y *= 0.8;
        p->unk_38.x *= 0.9;
        break;
    case 1:
    case 2:
        p->unk_50.y = p->unk_2C.y + 28.0;
        break;
    }
    p->unk_50.z = p->unk_44.z + 15.0;
    for (i = 0; i < arg2; i++) {
        t = (f32)i * D_800FDC64_ShyGuySays->unk_00[arg2];
        func_800F7780_ShyGuySays(t, &p->unk_44, &p->unk_50, &p->unk_38, &p->unk_68);
        func_800F7874_ShyGuySays(t, &p->unk_44, &p->unk_50, &p->unk_38, &p->unk_74);
        func_80025798(arg1[i], p->unk_68.x, p->unk_68.y, p->unk_68.z);
        sp18[0] = func_800F7608_ShyGuySays(p->unk_74.y, -p->unk_74.z);
        sp18[1] = func_800F7608_ShyGuySays(-p->unk_74.x, -p->unk_74.z);
        sp18[2] = 0.0f;
        func_800257E4(arg1[i], sp18[0], sp18[1], sp18[2]);
        func_80025830(arg1[i], 1.0f, 1.0f, 0.5f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_ShyGuySays/1D9690", func_800FA308_ShyGuySays);
#endif
void func_800FA77C_ShyGuySays(omObjData* arg0) {
    s32 ret;
    s16 sprite;

    arg0->func_ptr = NULL;
    D_800FD9AC_ShyGuySays = omAddObj(1, 1, 0, -1, &func_800FA8F4_ShyGuySays);
    omSetStatBit(D_800FD9AC_ShyGuySays, 0xA0);
    D_800FDC68_ShyGuySays[0] = func_800FB2C8_ShyGuySays(0x350013);
    sprite = ret = func_80064EF4_s32(1, 0);
    func_80067208(sprite, 0, D_800FDC68_ShyGuySays[0], 0);
    func_800674BC(sprite, 0, 0x4000);
    func_80066DC4(sprite, 0, D_800FDC64_ShyGuySays->unk_00[2] * 320.0f, 0x3C);
    func_80067354(sprite, 0, 2.0f, 2.0f);
    func_800674BC(sprite, 0, 0x503C);
    func_80067384(sprite, 0, 0xFFFF);
    arg0->work[0] = (u32)(ret << 16) >> 24;
    arg0->work[1] = ret;
    SetFadeInTypeAndTime(0, 0x10);
}
void func_800FA8D4_ShyGuySays(void) {
    HuMemDirectFree(D_800FD9B4_ShyGuySays);
}
void func_800FA8F4_ShyGuySays(omObjData* arg0) {
    arg0->func_ptr = &func_800FA960_ShyGuySays;
    arg0->model[0] = func_800174C0(0x350001, 0x99);
    D_800FD9B0_ShyGuySays = arg0->model[0];
    func_80026040(arg0->model[0]);
    func_800FAA80_ShyGuySays(arg0->model[0]);
}
void func_800FA960_ShyGuySays(omObjData* arg0) {
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FD5D8_ShyGuySays -= 1.0;
    }
    func_80027C1C(arg0->model[0], D_800FD5D4_ShyGuySays, D_800FD5D8_ShyGuySays, 0x20, 0x20);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FD5D0_ShyGuySays += 1.5;
    }
    if (D_800FD5D0_ShyGuySays > 360.0) {
        D_800FD5D0_ShyGuySays -= 360.0;
    }
    func_800FAED8_ShyGuySays(arg0->model[0], D_800FD5D0_ShyGuySays);
}
void func_800FAA80_ShyGuySays(s16 arg0) {
    s16 xs[32];
    s16 zs[32];
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* v;
    s16 nx;
    s16 nz;
    s16 n;
    s16 i;
    s16 j;

    m = D_800F2B7C[arg0].unk_6C;
    v = m->unk_04;
    nz = 0;
    nx = 0;
    n = m->unk_72;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nx; j++) {
            if (xs[j] == v->unk_00) {
                break;
            }
        }
        if (j >= nx) {
            xs[nx] = v->unk_00;
            nx++;
        }
        for (j = 0; j < nz; j++) {
            if (zs[j] == v->unk_04) {
                break;
            }
        }
        if (j >= nz) {
            zs[nz] = v->unk_04;
            nz++;
        }
    }
    func_800F7680_ShyGuySays(xs, nx);
    func_800F7680_ShyGuySays(zs, nz);
    D_800FD9B4_ShyGuySays = HuMemDirectMalloc(n * sizeof(ShyGuyGridCell));
    for (i = 0; i < n; i++) {
        D_800FD9B4_ShyGuySays[i].unk_00 = 1;
    }
    v = m->unk_04;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nx; j++) {
            if (xs[j] == v->unk_00) {
                break;
            }
        }
        if (j >= nx) {
            j = nx - 1;
        }
        D_800FD9B4_ShyGuySays[i].unk_02 = j;
        if (j == 0 || j == nx - 1) {
            D_800FD9B4_ShyGuySays[i].unk_00 = 0;
        }
    }
    v = m->unk_04;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nz; j++) {
            if (zs[j] == v->unk_04) {
                break;
            }
        }
        if (j >= nz) {
            j = nz - 1;
        }
        D_800FD9B4_ShyGuySays[i].unk_04 = j;
        if (j == 0 || j == nz - 1) {
            D_800FD9B4_ShyGuySays[i].unk_00 = 0;
        }
    }
    D_800FD9B8_ShyGuySays[0] = abs(xs[0] - xs[1]);
    D_800FD9B8_ShyGuySays[1] = abs(zs[0] - zs[1]);
}

void func_800FAED8_ShyGuySays(s16 arg0, s32 arg1) {
    unk2C0C0StructC0* m = D_800F2B7C[arg0].unk_6C;
    ShyGuyGridCell* cell = D_800FD9B4_ShyGuySays;
    unk2C0C0StructE0* src = m->unk_04;
    unk2C0C0StructE0* dst = m->unk_08[D_800F37F0];
    u16 n = m->unk_72;
    s16 first = 0;
    f32 s1;
    f32 s2;
    f32 ax;
    f32 az;
    u16 i;

    s1 = func_800AEAC0(arg1);
    s2 = func_800AEAC0(arg1 * 2);
    ax = D_800FD9B8_ShyGuySays[0] * D_800FDC64_ShyGuySays->unk_00[6] * D_800F2B7C[arg0].unk_3C;
    az = D_800FD9B8_ShyGuySays[0] * D_800FDC64_ShyGuySays->unk_00[9] * D_800F2B7C[arg0].unk_40;
    if (arg1 == 0) {
        first = 1 - first; /* == 1; spelled so GCC keeps the branch */
    }
    for (i = 0; i < n; src++, dst++, i++, cell++) {
        if (cell->unk_00 != 0) {
            if (cell->unk_04 & 1) {
                dst->unk_00 = src->unk_00 + s1 * ax;
            } else {
                dst->unk_00 = src->unk_00 - s1 * ax;
            }
            if (first) {
                if ((cell->unk_02 & 1) && (cell->unk_04 & 1)) {
                    dst->unk_02 = src->unk_02 + s2 * az;
                } else if ((cell->unk_02 + cell->unk_04) & 1) {
                    dst->unk_02 = src->unk_02 - s2 * az;
                } else {
                    dst->unk_02 = src->unk_02;
                }
            } else {
                if (!(cell->unk_02 & 1) && !(cell->unk_04 & 1)) {
                    dst->unk_02 = src->unk_02 + s2 * az;
                } else if ((cell->unk_02 & 1) && (cell->unk_04 & 1)) {
                    dst->unk_02 = src->unk_02 - s2 * az;
                } else {
                    dst->unk_02 = src->unk_02;
                }
            }
        } else {
            dst->unk_00 = src->unk_00;
            dst->unk_02 = src->unk_02;
            dst->unk_04 = src->unk_04;
        }
    }
}

// decomp-permuter
f32 func_800FB190_ShyGuySays(f32 arg0, f32 arg1)
{
  unk2C0C0StructC0 *m = D_800F2B7C[D_800FD9B0_ShyGuySays].unk_6C;
  unk2C0C0StructE0 *v = m->unk_08[D_800F37F0];
  u16 n = m->unk_72;
  u16 i;
  unsigned int new_var;
  u16 cnt = 0;
  f64 sum = 0.0;
  f32 dx;
  f32 dz;
  for (i = 0; i < n; i++, v++)
  {
    dx = fabsf(v->unk_00 - arg0);
    dz = fabsf(v->unk_04 - arg1);
    if ((dx < (D_800FD9B8_ShyGuySays[0] * 1.5)) && (dz < (D_800FD9B8_ShyGuySays[0] * 1.5)))
    {
      sum += v->unk_02;
      cnt++;
      if (cnt >= 10)
      {
        break;
      }
    }
  }

  new_var = cnt;
  return -(sum * D_800FDC64_ShyGuySays->unk_00[new_var]);
}
u16 func_800FB2C8_ShyGuySays(s32 arg0) {
    void* data;
    u16 ret;

    data = DataRead(arg0);
    ret = func_800678A4(data);
    DataClose(data);
    return ret;
}
void func_800FB30C_ShyGuySays(void) {
    unkStruct_ShyGuySays_06* p;
    u16 i;

    D_800FDC6C_ShyGuySays = func_800FB2C8_ShyGuySays(0x3C0017);
    p = D_800FDC70_ShyGuySays;
    for (i = 0; i < 6; i++, p++) {
        p->unk0 = 0;
        p->unk2 = func_80064EF4(1, 0);
        func_80067208(p->unk2, 0, D_800FDC6C_ShyGuySays, 0);
        func_800674BC(p->unk2, 0, 0x9000);
        func_80066DC4(p->unk2, 0, 0, 0);
        func_80067354(p->unk2, 0, 1.0f, 1.0f);
        func_80067384(p->unk2, 0, i - 0x10);
        func_800672B0(p->unk2, 0, 0);
        p->unk10 = 0;
        p->unk4 = p->unk8 = p->unkC = 0.0f;
        p->unk12 = 0;
    }
}
void func_800FB424_ShyGuySays(void) {
    unkStruct_ShyGuySays_06* p;
    u16 i;

    p = D_800FDC70_ShyGuySays;
    for (i = 0; i < 6; i++, p++) {
        if (p->unk0 != 0) {
            if (p->unk12 & 1) {
                func_80066DF4(p->unk2, 0, 0, p->unk4, p->unk8, p->unkC);
            } else {
                func_80066DC4(p->unk2, 0, p->unk4, p->unk8);
            }
            if (p->unk10 > 0) {
                if (--p->unk10 <= 0) {
                    func_800674BC(p->unk2, 0, 0x8000);
                    p->unk12 = 0;
                    p->unk10 = 0;
                    p->unk0 = 0;
                }
            }
        }
    }
}
s16 func_800FB520_ShyGuySays(f32 arg0, f32 arg1, f32 arg2, s16 arg3, u16 arg4) {
    unkStruct_ShyGuySays_06* p = D_800FDC70_ShyGuySays;
    u16 i;

    for (i = 0; i < 6; i++, p++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            p->unk4 = arg0;
            p->unk8 = arg1;
            p->unkC = arg2;
            p->unk10 = 0;
            p->unk12 = arg4;
            func_80067208(p->unk2, 0, D_800FDC68_ShyGuySays[arg3], 0);
            func_800671DC(p->unk2, 0, 0);
            func_80067480(p->unk2, 0, 0x8000);
            if (arg4 & 1) {
                func_80066DF4(p->unk2, 0, 0, arg0, arg1, arg2);
            } else {
                func_80066DC4(p->unk2, 0, arg0, arg1);
            }
            if (arg4 & 2) {
                func_800672B0(p->unk2, 0, 2);
            } else if (arg4 & 4) {
                func_800672B0(p->unk2, 0, 3);
            } else if (arg4 & 8) {
                func_800672B0(p->unk2, 0, 1);
            } else {
                func_800672B0(p->unk2, 0, 0);
            }
            return i;
        }
    }
    return -1;
}
void func_800FB6E0_ShyGuySays(omObjData* arg0) {
    s16 sp10[2];
    u16 i;

    arg0->func_ptr = &func_800FB840_ShyGuySays;
    D_800FDC68_ShyGuySays[1] = func_800FB2C8_ShyGuySays(0x350011);
    for (i = 0; i < 2; i++) {
        sp10[i] = func_80064EF4_s32(1, 0);
        func_80067208(sp10[i], 0, D_800FDC68_ShyGuySays[1], 0);
        func_800674BC(sp10[i], 0, 0x4000);
        func_80066DC4(sp10[i], 0, i * 50 + 0x87, 0x1E);
        func_80067354(sp10[i], 0, 1.0f, 1.0f);
        func_800674BC(sp10[i], 0, 0x503C);
        func_80067384(sp10[i], 0, 0xFFF0);
    }
    arg0->work[0] = (u16)sp10[0] >> 8;
    arg0->work[1] = (u8)sp10[0];
    arg0->work[2] = (u16)sp10[1] >> 8;
    arg0->work[3] = (u8)sp10[1];
}
void func_800FB840_ShyGuySays(omObjData* arg0) {
    u16 phi_v0;
    s32 phi_s3, phi_s4;
    f32 temp_f20;
    s16 sp10[2];
    u16 i;
    u16* temp_a0;
    
    sp10[0] = (arg0->work[0] << 8) | arg0->work[1];
    sp10[1] = (arg0->work[2] << 8) | arg0->work[3];
    
    for (i = 0; i < ARRAY_COUNT(D_800FD5DC_ShyGuySays); i++) {
        phi_v0 = func_800F740C_ShyGuySays(0);
        temp_a0 = &D_800FD5DC_ShyGuySays[i];
        phi_v0 = (*temp_a0) + (phi_v0 & 0x3);
        *temp_a0 = phi_v0;
        
        if (phi_v0 >= 0x169) {
            *temp_a0 = phi_v0 - 0x168;
        }
        
        if (i == 0) {
            phi_s3 = func_800AEAC0(D_800FD5DC_ShyGuySays[i] * 2) * 10.0f + 120.0f;
            phi_s4 = func_800AEFD0(D_800FD5DC_ShyGuySays[i]) * 6.0f + 15.0f;
        } else {
            phi_s3 = func_800AEAC0(D_800FD5DC_ShyGuySays[i] * 2) * 10.0f + 160.0f;
            phi_s4 = func_800AEFD0(D_800FD5DC_ShyGuySays[i]) * 6.0f + 30.0f;
        }
        
        if (D_800FD5DC_ShyGuySays[i] < 0xB4) {
            func_800672B0(sp10[i], 0, 3);
        } else {
            func_800672B0(sp10[i], 0, 0);
            func_800671DC(sp10[i], 0, 3);
        }
        
        temp_f20 = func_800AEAC0(D_800FD5DC_ShyGuySays[i]) * 0.2 + 0.5;
        func_80066DC4(sp10[i], 0, phi_s3, phi_s4);
        func_80067354(sp10[i], 0, temp_f20, temp_f20);
    }
}

void func_800FBAE4_ShyGuySays(omObjData* arg0) {
    unk2C0C0StructC0* m;
    u16 i;

    arg0->func_ptr = &func_800FBE60_ShyGuySays;
    arg0->model[0] = func_800174C0(0x3C0006, 0x499);
    arg0->model[1] = func_800174C0(0x3C0007, 0x499);
    arg0->model[2] = func_800174C0(0x3C0008, 0x499);
    arg0->model[3] = func_800174C0(0x3C0009, 0x499);
    arg0->model[4] = func_800174C0(0x3C000A, 0x499);
    func_800258EC(arg0->model[1], 4, 4);
    func_800258EC(arg0->model[2], 4, 4);
    func_800258EC(arg0->model[3], 4, 4);
    func_800258EC(arg0->model[4], 4, 4);
    arg0->model[5] = func_800174C0(6, 0x499);
    arg0->model[6] = func_800174C0(0x3C0001, 0x499);
    func_80026040(arg0->model[0]);
    for (i = 0; i < 5; i++) {
        D_800F2B7C[arg0->model[i]].unk_4C = 0.0f;
        D_800FDC38_ShyGuySays[i].unk_00 = func_80025E48(arg0->model[i]);
        D_800FDC38_ShyGuySays[i].unk_02 = func_80025D40(arg0->model[i]);
    }
    D_800F2B7C[arg0->model[3]].unk_48 = D_800FDC38_ShyGuySays[3].unk_02;
    D_800F2B7C[arg0->model[3]].unk_50 = D_800FDC38_ShyGuySays[3].unk_02;
    D_800F2B7C[arg0->model[4]].unk_48 = D_800FDC38_ShyGuySays[4].unk_02;
    D_800F2B7C[arg0->model[4]].unk_50 = D_800FDC38_ShyGuySays[4].unk_02;
    D_800FDC28_ShyGuySays[0] = 1;
    D_800FDC28_ShyGuySays[1] = 1;
    D_800FDC28_ShyGuySays[2] = 1;
    D_800FDC28_ShyGuySays[3] = 0;
    arg0->trans.x = 0.0f;
    arg0->trans.z = arg0->trans.y = 100.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.8f;
    arg0->rot.y = 180.0f;
    D_800FDC4C_ShyGuySays = 0;
    D_800FDC54_ShyGuySays = 30.0f;
    arg0->work[0] = 3;
    arg0->work[1] = 4;
    arg0->work[2] = 5;
    arg0->work[3] = 6;
    m = D_800F2B7C[arg0->model[0]].unk_6C;
    D_800FDC50_ShyGuySays[0] = func_80033718(m, "sentyo_r2-hata_r");
    D_800FDC50_ShyGuySays[1] = func_80033718(m, "sentyo_r2-hata_w");
}

const UnknownBlock8 D_800FD850_ShyGuySays = { { 9, 10, 16, 19 } };

const UnknownBlock8 D_800FD858_ShyGuySays = { { 8, 11, 17, 18 } };

/* func_80060268 ids for rounds 1-15 */
const UnknownBlock36 D_800FD860_ShyGuySays = { {
    0x88, 0x8C, 0x90, 0x94, 0x98, 0x9C, 0xA0, 0xA4, 0xA8,
    0xAC, 0xB0, 0xB4, 0xB8, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB,
} };

void func_800FBE60_ShyGuySays(omObjData* arg0) {
    UnknownBlock8 sp18;
    UnknownBlockCombo48 sp1C;
    f64 var_f12;
    f32 var_f12_2;
    u16 var_s3;
    u32 temp_a0;
    u32 temp_a1;
    u16 i;

    sp18 = D_800FD850_ShyGuySays;
    sp1C.unk_00 = D_800FD858_ShyGuySays;
    sp1C.unk_08 = D_800FD860_ShyGuySays;
    var_s3 = 0;

    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FD5E4_ShyGuySays += 15 + (func_800F740C_ShyGuySays(0) & 0xF);
        if (D_800FD5E4_ShyGuySays < 0 || D_800FD5E4_ShyGuySays >= 360) {
            D_800FD5E4_ShyGuySays -= 360;
        }
    }

    var_f12 = D_800FD5E4_ShyGuySays;
    func_800FD274_ShyGuySays(arg0->model[0], D_800FDC50_ShyGuySays[0], func_800AEAC0(var_f12), sp18.unk_00, sp1C.unk_00.unk_00);

    var_f12 = D_800FD5E4_ShyGuySays;
    func_800FD274_ShyGuySays(arg0->model[0], D_800FDC50_ShyGuySays[1], func_800AEFD0(var_f12), sp18.unk_00, sp1C.unk_00.unk_00);

    if (func_8005FD5C() + D_800F64F8 != 0) {
        return;
    }

    if (D_800FD9A0_ShyGuySays == 2) {
        switch (D_800FDC4C_ShyGuySays) {
            case 0:
                if (D_800FD99C_ShyGuySays <= D_800FD5EC_ShyGuySays && func_800F99C0_ShyGuySays() == 1) {
                    D_800FD99C_ShyGuySays = 0;
                    D_800FD9A8_ShyGuySays++;
                    var_s3 = func_800F740C_ShyGuySays(2);
                    arg0->work[D_800FD9A8_ShyGuySays % 4] = var_s3;
                    temp_a0 = arg0->work[2];
                    temp_a1 = arg0->work[3];
                    if (arg0->work[0] == arg0->work[1] ? (temp_a0 == 1 ? temp_a1 == 1 : temp_a1 == 0)
                                                           : (temp_a0 == 0 ? temp_a1 == 1 : temp_a1 == 0)) {
                        if (var_s3 == 0) {
                            arg0->work[D_800FD9A8_ShyGuySays % 4] = 1;
                            var_s3 = 1;
                        } else {
                            arg0->work[D_800FD9A8_ShyGuySays % 4] = 0;
                            var_s3 = 0;
                        }
                    }
                    if (D_800FD9A8_ShyGuySays < 3) {
                        D_800FD5EC_ShyGuySays -= 2.5;
                    } else {
                        D_800FD5EC_ShyGuySays -= 5.0;
                        if (D_800FD5EC_ShyGuySays < 27.5) {
                            D_800FD5EC_ShyGuySays = 27.5f;
                            if (6.0 < D_800FDC54_ShyGuySays) {
                                D_800FDC54_ShyGuySays -= 3.0;
                            }
                        }
                        if (!func_800F740C_ShyGuySays(4)) {
                            var_s3 = 2;
                        }
                    }
                    if (D_800FD9A8_ShyGuySays < 16) {
                        func_80060268(sp1C.unk_08.unk_00[D_800FD9A8_ShyGuySays - 1]);
                    }
                    PlaySound(0x2FC);
                    switch (var_s3) {
                        case 0:
                            var_s3 = 1;
                            D_800FDC4C_ShyGuySays = 3;
                            break;
                        case 1:
                            var_s3 = 2;
                            D_800FDC4C_ShyGuySays = 3;
                            break;
                        default:
                            var_s3 = 3;
                            D_800FDC4C_ShyGuySays = 1;
                            break;
                    }
                    D_800FD5E8_ShyGuySays = var_s3;
                }
                break;
            case 1:
                if (func_800FD124_ShyGuySays(arg0) == 1) {
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 2;
                }
                break;
            case 2:
                if (D_800FD99C_ShyGuySays > 0) {
                    if (arg0->work[D_800FD9A8_ShyGuySays % 4] == 0) {
                        var_s3 = 4;
                        D_800FD5E8_ShyGuySays = 2;
                        arg0->work[D_800FD9A8_ShyGuySays % 4] = 1;
                    } else {
                        var_s3 = 5;
                        D_800FD5E8_ShyGuySays = 1;
                        arg0->work[D_800FD9A8_ShyGuySays % 4] = 0;
                    }
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 3;
                }
                break;
            case 3:
                if (func_800FD124_ShyGuySays(arg0) == 1) {
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 4;
                }
                break;
            case 4:
                if (D_800FDC54_ShyGuySays <= D_800FD99C_ShyGuySays) {
                    func_800F94A8_ShyGuySays();
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 5;
                }
                break;
            case 5:
                if (D_800FD99C_ShyGuySays >= 8) {
                    func_800F96D4_ShyGuySays();
                    func_800F98EC_ShyGuySays();
                    for (i = 0; i < 4; i++) {
                        if (func_800F9A7C_ShyGuySays(i, D_800FD5E8_ShyGuySays) == 0) {
                            break;
                        }
                    }
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 6;
                } else {
                    func_800F95BC_ShyGuySays();
                    var_s3 = 6;
                }
                break;
            case 6:
                if (func_800FD124_ShyGuySays(arg0) != 0 && func_800F97A8_ShyGuySays() != 0 && func_800F9828_ShyGuySays() != 0) {
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 7;
                }
                break;
            case 7:
                for (i = 0; i < 4; i++) {
                    if (func_800F9A7C_ShyGuySays(i, D_800FD5E8_ShyGuySays) != 0) {
                        continue;
                    }
                    if (D_800FDC28_ShyGuySays[2] == 2) {
                        if (i == 0) {
                            var_f12_2 = 325.0f;
                        } else if (i == 1) {
                            var_f12_2 = 340.0f;
                        } else if (i == 2) {
                            var_f12_2 = 20.0f;
                        } else {
                            var_f12_2 = 45.0f;
                        }
                        if (arg0->rot.y == var_f12_2) {
                            D_800FDC4C_ShyGuySays = 9;
                            D_800FD99C_ShyGuySays = 0;
                            D_800FD5EA_ShyGuySays = i;
                            var_s3 = 8;
                        } else {
                            arg0->rot.y += func_800F74A0_ShyGuySays(var_f12_2, arg0->rot.y, 20.0f);
                            if (360.0 < arg0->rot.y) {
                                arg0->rot.y -= 360.0;
                            } else if (arg0->rot.y < 0.0) {
                                arg0->rot.y += 360.0;
                            }
                            D_800FD99C_ShyGuySays = 0;
                        }
                    } else {
                        var_s3 = 7;
                        D_800FDC4C_ShyGuySays = 8;
                        D_800FD99C_ShyGuySays = 0;
                    }
                    i = 5;
                }
                if (i == 4) {
                    if (D_800FDC28_ShyGuySays[2] == 1) {
                        D_800FD99C_ShyGuySays = 0;
                        D_800FDC4C_ShyGuySays = 0;
                    } else if (arg0->rot.y == 180.0) {
                        if (D_800FD9A4_ShyGuySays != 0) {
                            D_800FD9A6_ShyGuySays = D_800FD9A4_ShyGuySays;
                        }
                        func_800F9D14_ShyGuySays(D_800FD9A6_ShyGuySays);
                        if (D_800FDC1C_ShyGuySays == 0) {
                            if (D_800FD9A4_ShyGuySays < 2) {
                                D_800FD9A0_ShyGuySays = 3;
                                D_800FD998_ShyGuySays->func_ptr = &func_800F6A38_ShyGuySays;
                                func_800601D4(40);
                            }
                        } else {
                            if (D_800FD9C0_ShyGuySays[D_800FDC1E_ShyGuySays].unk_00 != 0 && D_800FD9C0_ShyGuySays[D_800FDC1E_ShyGuySays].unk_04 != 512) {
                                if (D_800FD9A4_ShyGuySays < 2) {
                                    D_800FD9A0_ShyGuySays = 3;
                                    D_800FD998_ShyGuySays->func_ptr = &func_800F6E50_ShyGuySays;
                                    func_800601D4(40);
                                }
                            } else {
                                D_800FD9A0_ShyGuySays = 3;
                                D_800FD998_ShyGuySays->func_ptr = &func_800F6E50_ShyGuySays;
                                func_800601D4(40);
                            }
                        }
                        D_800FD99C_ShyGuySays = 0;
                        D_800FDC4C_ShyGuySays = 8;
                        var_s3 = 9;
                    } else {
                        D_800FD99C_ShyGuySays = 0;
                        arg0->rot.y += func_800F74A0_ShyGuySays(180.0f, arg0->rot.y, 20.0f);
                    }
                }
                break;
            case 8:
                if (func_800FD124_ShyGuySays(arg0) == 1) {
                    D_800FD99C_ShyGuySays = 0;
                    D_800FDC4C_ShyGuySays = 7;
                }
                break;
            case 9:
                if (D_800FD99C_ShyGuySays != 10) {
                    if (D_800FD99C_ShyGuySays >= 15) {
                        D_800FD99C_ShyGuySays = 0;
                        D_800FDC4C_ShyGuySays = 8;
                        D_800FD9A4_ShyGuySays--;
                        func_800F9AFC_ShyGuySays(D_800FD5EA_ShyGuySays);
                    }
                }
                break;
        }
        
        func_800FCA8C_ShyGuySays(arg0, var_s3);
        D_800FD99C_ShyGuySays++;
    } else {
        func_800FCA8C_ShyGuySays(arg0, 0);
    }

    func_800F7A8C_ShyGuySays(arg0->model[3], arg0);
    func_800F7A8C_ShyGuySays(arg0->model[4], arg0);
    func_800F7A8C_ShyGuySays(arg0->model[5], arg0);
    func_80025798(arg0->model[6], arg0->trans.x, arg0->trans.y, arg0->trans.z);

    D_800FD5E0_ShyGuySays++;
    if (D_800FD5EC_ShyGuySays > 360.0f) {
        D_800FD5E0_ShyGuySays -= 360;
    }

    var_f12 = D_800FD5E0_ShyGuySays;
    arg0->trans.y = func_800AEAC0(var_f12) * 24.0 + 100.0;
}

// register allocation (a3/t0, v0/v1) and one sll scheduled after the lui in case 4 (masked 3)
#ifdef NON_MATCHING
void func_800FCA8C_ShyGuySays(omObjData* arg0, u16 arg1) {
    s16 m0 = arg0->model[0];
    s16 m3 = arg0->model[3];
    s16 m4 = arg0->model[4];
    unk_ovl_2D_struct* e;
    unk_ovl_2D_struct* e4;
    unkStructShyGuySays_03* p;

    if (D_800FDC28_ShyGuySays[2] == 1) {
        e = &D_800F2B7C[m0];
        if (D_800FDC28_ShyGuySays[3] != 0) {
            if (--D_800FDC28_ShyGuySays[3] == 0) {
                e->unk_0A = 0;
                e->unk_48 = D_800FDC38_ShyGuySays[1].unk_02;
                e->unk_50 = D_800FDC38_ShyGuySays[1].unk_02;
            }
            return;
        }
        if (e->unk_48 != e->unk_50) {
            return;
        }
        switch (arg1) {
        case 2:
            if (D_800FDC28_ShyGuySays[0] & 1) {
                D_800FDC28_ShyGuySays[0] = 2;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[0], 1);
            }
            break;
        case 5:
            if ((D_800FDC28_ShyGuySays[0] & 2) && (D_800FDC28_ShyGuySays[1] & 2)) {
                D_800FDC28_ShyGuySays[3] = D_800FDC38_ShyGuySays[1].unk_02 * 0.5;
                D_800FDC28_ShyGuySays[0] = 1;
                D_800FDC28_ShyGuySays[1] = 2;
                p = &D_800FDC38_ShyGuySays[1];
                goto anim;
            } else if (D_800FDC28_ShyGuySays[0] & 2) {
                D_800FDC28_ShyGuySays[0] = 1;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[0], -1);
            }
            break;
        case 1:
            if (D_800FDC28_ShyGuySays[1] & 1) {
                D_800FDC28_ShyGuySays[1] = 2;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[1], 1);
            }
            break;
        case 4:
            if (D_800FDC28_ShyGuySays[0] & 2) {
                if (D_800FDC28_ShyGuySays[1] & 2) {
                    D_800FDC28_ShyGuySays[3] = D_800FDC38_ShyGuySays[0].unk_02 * 0.5;
                    D_800FDC28_ShyGuySays[1] = 1;
                    D_800FDC28_ShyGuySays[0] = 2;
                    p = &D_800FDC38_ShyGuySays[0];
                anim:
                    func_80025C20(m0, p->unk_00, p->unk_02 * 0.5, p->unk_02 * 0.5, 0);
                }
            } else if (D_800FDC28_ShyGuySays[1] & 2) {
                D_800FDC28_ShyGuySays[1] = 1;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[1], -1);
            }
            break;
        case 3:
            if ((D_800FDC28_ShyGuySays[0] & 1) && (D_800FDC28_ShyGuySays[1] & 1)) {
                D_800FDC28_ShyGuySays[0] = 2;
                D_800FDC28_ShyGuySays[1] = 2;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[2], 1);
            }
            break;
        case 6:
            if ((D_800FDC28_ShyGuySays[0] & 2) && (D_800FDC28_ShyGuySays[1] & 2)) {
                D_800FDC28_ShyGuySays[0] = 1;
                D_800FDC28_ShyGuySays[1] = 1;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[2], -1);
            } else if (D_800FDC28_ShyGuySays[0] & 2) {
                D_800FDC28_ShyGuySays[0] = 1;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[0], -1);
            } else if (D_800FDC28_ShyGuySays[1] & 2) {
                D_800FDC28_ShyGuySays[1] = 1;
                func_800F79E4_ShyGuySays(m0, &D_800FDC38_ShyGuySays[1], -1);
            }
            break;
        case 7:
            if ((D_800FDC28_ShyGuySays[0] & 1) && (D_800FDC28_ShyGuySays[1] & 1)) {
                D_800FDC28_ShyGuySays[2] = 2;
                func_800258EC(m0, 4, 4);
                func_800258EC(m4, 4, 0);
                func_800F79E4_ShyGuySays(m4, &D_800FDC38_ShyGuySays[4], 1);
                PlaySound(0x2FD);
            }
            break;
        }
    } else {
        e = &D_800F2B7C[m3];
        e4 = &D_800F2B7C[m4];
        if (D_800FDC28_ShyGuySays[3] != 0) {
            if (--D_800FDC28_ShyGuySays[3] == 0) {
                D_800FDC28_ShyGuySays[2] = 1;
                func_800258EC(m0, 4, 0);
                func_800258EC(m4, 4, 4);
            }
            return;
        }
        if (e->unk_48 == e->unk_50 && e4->unk_48 == e4->unk_50) {
            switch (arg1) {
            case 8:
                func_800258EC(m3, 4, 0);
                func_800258EC(m4, 4, 4);
                func_800F79E4_ShyGuySays(m3, &D_800FDC38_ShyGuySays[3], 1);
                D_800F2B7C[m3].unk_4C = 2.0f;
                break;
            case 9:
                func_800258EC(m3, 4, 4);
                func_800258EC(m4, 4, 0);
                func_800F79E4_ShyGuySays(m4, &D_800FDC38_ShyGuySays[4], -1);
                D_800FDC28_ShyGuySays[3] = D_800FDC38_ShyGuySays[4].unk_02 * 0.5;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_ShyGuySays/1D9690", func_800FCA8C_ShyGuySays);
#endif

s16 func_800FD124_ShyGuySays(omObjData* arg0) {
    unk_ovl_2D_struct* a = &D_800F2B7C[arg0->model[0]];
    unk_ovl_2D_struct* b = &D_800F2B7C[arg0->model[3]];
    unk_ovl_2D_struct* c = &D_800F2B7C[arg0->model[4]];

    if (D_800FDC28_ShyGuySays[3] == 0 && a->unk_48 == a->unk_50 && b->unk_48 == b->unk_50 && c->unk_48 == c->unk_50) {
        return 1;
    }
    return 0;
}
f32 func_800FD1D0_ShyGuySays(void) {
    unk_ovl_2D_struct* m = &D_800F2B7C[D_800FDC20_ShyGuySays->model[0]];

    return m->unk_48;
}
s16 func_800FD200_ShyGuySays(void) {
    if (D_800FDC28_ShyGuySays[0] == 2 && D_800FDC28_ShyGuySays[1] == 1) {
        return 1;
    }
    if (D_800FDC28_ShyGuySays[0] == 1 && D_800FDC28_ShyGuySays[1] == 2) {
        return 2;
    }
    if (D_800FDC28_ShyGuySays[0] == 2 && D_800FDC28_ShyGuySays[1] == 2) {
        return 3;
    }
    return 0;
}
void func_800FD274_ShyGuySays(s16 arg0, s16 arg1, f32 arg2, u16* arg3, u16* arg4) {
    unk2C0C0StructC0* temp_t3;
    unk2C0C0StructE0* temp_a3;
    unk2C0C0StructE0* var_a0;
    unk2C0C0StructE0* var_a2;
    s16 sp[10][4];
    s16 temp_v0;
    s16 var_t1;
    s16 i;
    s16 j;

    temp_t3 = D_800F2B7C[arg0].unk_6C;
    var_t1 = 0;
    var_a2 = &temp_t3->unk_04[temp_t3->unk_80[arg1].unk_0A];
    var_a0 = &temp_t3->unk_08[D_800F37F0][temp_t3->unk_80[arg1].unk_0A];

    temp_v0 = temp_t3->unk_80[arg1].unk_0C;
    for (i = 0; i < temp_v0; var_a2++, var_a0++, i++) {
        if (i == *arg3) {
            var_a0->unk_02 = var_a2->unk_02 + arg2 * 20.0f * 0.2;
            var_a0->unk_04 = var_a2->unk_04 - arg2 * 20.0f * 1.2;
            sp[var_t1][0] = var_a2->unk_00;
            sp[var_t1][1] = var_a2->unk_02;
            sp[var_t1][2] = var_a2->unk_04;
            sp[var_t1][3] = i;
            arg3++;
            var_t1++;
        } else if (i == *arg4) {
            var_a0->unk_02 = var_a2->unk_02 - arg2 * 20.0f * 0.2;
            var_a0->unk_04 = var_a2->unk_04 + arg2 * 20.0f * 1.2;
            sp[var_t1][0] = var_a2->unk_00;
            sp[var_t1][1] = var_a2->unk_02;
            sp[var_t1][2] = var_a2->unk_04;
            sp[var_t1][3] = i;
            arg4++;
            var_t1++;
        } else {
            var_a0->unk_02 = var_a2->unk_02;
        }
    }

    for (j = 0; j < var_t1; j++) {
        var_a2 = &temp_t3->unk_04[temp_t3->unk_80[arg1].unk_0A];
        var_a0 = &temp_t3->unk_08[D_800F37F0][temp_t3->unk_80[arg1].unk_0A];
        temp_a3 = var_a0;

        for (i = 0; i < temp_v0; var_a2++, var_a0++, i++) {
            if (sp[j][0] == var_a2->unk_00 && sp[j][1] == var_a2->unk_02 && sp[j][2] == var_a2->unk_04) {
                var_a0->unk_00 = temp_a3[sp[j][3]].unk_00;
                var_a0->unk_02 = temp_a3[sp[j][3]].unk_02;
                var_a0->unk_04 = temp_a3[sp[j][3]].unk_04;
            }
        }
    }
}
