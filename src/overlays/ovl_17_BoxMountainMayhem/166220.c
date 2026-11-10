#include "BoxMountainMayhem.h"

u16 D_800FBFC0_BoxMountainMayhem = 0;

void func_800F65E0_BoxMountainMayhem(void) {
    D_800FC0F0_BoxMountainMayhem = -1;
    func_80029090(4);
    func_8001DE70(0x40);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_80009500();
    omInitObjMan(0x30, 0);
    func_80060088();
    func_800FB440_BoxMountainMayhem(1859.0f, -10.0f, -45.0f, 0.0f, -245.0f, 500.0f, 245.0f);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 25.0f, 80.0f, 8000.0f);
    func_8002578C(0);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    omAddObj(0, 0, 0, -1, func_800F67C0_BoxMountainMayhem);
    func_800F9068_BoxMountainMayhem();
    func_800F7E70_BoxMountainMayhem();
    func_800F7110_BoxMountainMayhem();
    func_800FA3F0_BoxMountainMayhem();
    omAddObj(0x2710, 0, 0, -1, func_800F70C0_BoxMountainMayhem);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FC0E2_BoxMountainMayhem = 3;
}

void func_800F67C0_BoxMountainMayhem(omObjData* obj) {
    D_800FC0E0_BoxMountainMayhem = 0;
    D_800FC0E6_BoxMountainMayhem = 30;
    D_800FC0E8_BoxMountainMayhem = 30;
    D_800ED430 = 0;
    obj->func_ptr = func_800F67F4_BoxMountainMayhem;
}

void func_800F67F4_BoxMountainMayhem(omObjData* obj) {
    if (D_800C5982 == 1) {
        return;
    }
    switch (D_800FC0E0_BoxMountainMayhem) {
    case 0:
        func_800F691C_BoxMountainMayhem();
        break;
    case 1:
        D_800FC0E8_BoxMountainMayhem--;
        if (D_800FC0E8_BoxMountainMayhem == 0) {
            if (D_800FC0E6_BoxMountainMayhem != 0) {
                func_80079078(--D_800FC0E6_BoxMountainMayhem);
            }
            D_800FC0E8_BoxMountainMayhem = 30;
        }
        if (D_800FC0E6_BoxMountainMayhem == 0
            || (func_800FA2A0_BoxMountainMayhem() == 0 && func_800F84D0_BoxMountainMayhem() == 0)) {
            D_800FC0E0_BoxMountainMayhem = 2;
            D_800FC0E4_BoxMountainMayhem = 1;
        }
        func_800FB9B4_BoxMountainMayhem();
        break;
    case 2:
        func_800F6A00_BoxMountainMayhem();
        func_800FB9B4_BoxMountainMayhem();
        break;
    }
}

void func_800F691C_BoxMountainMayhem(void) {
    s32 stat;

    switch (D_800FC0E2_BoxMountainMayhem) {
    case 1:
    case 3:
        if (func_80072718() == 0) {
            D_800FC0E2_BoxMountainMayhem = 4;
            GMesCreate(0);
        }
        break;
    case 4:
        stat = GMesStatAllGet();
        if (stat == 0) {
            D_800FC0E0_BoxMountainMayhem = 1;
            D_800ED430 = 1;
        } else if ((stat & 2) && D_800FC0F0_BoxMountainMayhem < 0) {
            D_800FC0F0_BoxMountainMayhem = GMesCreate(8, D_800FC0E6_BoxMountainMayhem, 0xA0, 0x1C);
            func_80060128(0x1B);
        }
        break;
    }
}

void func_800F6A00_BoxMountainMayhem(void) {
    BMMPlayerWork* work;
    omObjData* obj;
    s32 flag;
    s32 i;
    s32 count;
    s32 done;
    f32 angle;
    u16 motion;
    u16 coins;

    flag = _CheckFlag(0x2B);
    switch (D_800FC0E4_BoxMountainMayhem) {
    case 1:
        func_800601D4(0x28);
        func_800790C0();
        for (i = 0; i < 4; i++) {
            obj = D_800FC278_BoxMountainMayhem[i];
            obj->work[3] = 1;
        }
        D_800FC0E4_BoxMountainMayhem = 2;
        D_800FC0EC_BoxMountainMayhem = 450;
        break;
    case 2:
        D_800FC0EA_BoxMountainMayhem = 0;
        for (i = 0; i < 4; i++) {
            obj = D_800FC278_BoxMountainMayhem[i];
            if (BMM_PLAYER(obj)->unk_38 != 1000.0f) {
                D_800FC0EA_BoxMountainMayhem = 1;
            }
            if (func_80018490(obj, 0) == 0) {
                D_800FC0EA_BoxMountainMayhem = 1;
            }
            if (D_800FC0EA_BoxMountainMayhem != 0) {
                break;
            }
        }
        for (i = 0; i < 4; i++) {
            obj = D_800FC1E0_BoxMountainMayhem[i];
            if (BMM_BODY(obj)->unk_54 != 0) {
                D_800FC0EA_BoxMountainMayhem = 1;
                break;
            }
        }
        D_800FC0EC_BoxMountainMayhem--;
        if (D_800FC0EA_BoxMountainMayhem == 0 || D_800FC0EC_BoxMountainMayhem == 0) {
            D_800ED430 = 2;
            D_800FC0E4_BoxMountainMayhem = 3;
            D_800FC0EC_BoxMountainMayhem = 150;
        }
        break;
    case 3:
        count = 0;
        done = 0;
        for (i = 0; i < 4; i++) {
            obj = D_800FC278_BoxMountainMayhem[i];
            if (obj == NULL) {
                continue;
            }
            work = BMM_PLAYER(obj);
            work->unk_40 = 0.0f;
            angle = work->unk_3C;
            count++;
            if (angle == -45.0f) {
                done++;
                continue;
            }
            if (angle < -45.0f) {
                work->unk_3C = angle + 20.0f;
            } else if (angle > 135.0f) {
                work->unk_3C = angle += 20.0f;
                if (angle > 180.0f) {
                    work->unk_3C = angle - 360.0f;
                }
            } else {
                work->unk_3C -= 20.0f;
            }
            if (work->unk_3C > -65.0f && work->unk_3C < -25.0f) {
                work->unk_3C = -45.0f;
            }
        }
        if (count == done) {
            if (flag != 0) {
                GMesCreate(2);
                D_800FC0E4_BoxMountainMayhem = 8;
            } else {
                GMesCreate(D_800FC0E6_BoxMountainMayhem != 0 ? 2 : 0x10);
                D_800FC0E4_BoxMountainMayhem = 5;
            }
        }
        break;
    case 5:
        i = GMesStatAllGet();
        if (i == 0 || (i & 2)) {
            count = 0;
            for (i = 0; i < 4; i++) {
                obj = D_800FC278_BoxMountainMayhem[i];
                if (obj == NULL) {
                    continue;
                }
                work = BMM_PLAYER(obj);
                coins = GwPlayer[work->unk_58].coins_mg;
                count += coins;
                if (coins != 0) {
                    D_800FC0EA_BoxMountainMayhem = 105;
                    motion = 13;
                } else {
                    motion = 14;
                    D_800FC0EA_BoxMountainMayhem = 120;
                }
                if (flag == 0) {
                    func_800184BC(obj, motion);
                    func_80017DB0(obj);
                }
            }
            if (flag == 0) {
                if (D_800FC0E6_BoxMountainMayhem != 0) {
                    func_80060128(0x36);
                } else if (count != 0) {
                    func_80060128(0x3C);
                } else {
                    func_80060128(0x34);
                }
            }
            D_800FC0E4_BoxMountainMayhem = 8;
        }
        break;
    case 8:
        i = 0;
        if (flag != 0) {
            i = GMesWait() == 0;
        } else {
            i += --D_800FC0EA_BoxMountainMayhem == 0;
        }
        if (i) {
            D_800FC0E4_BoxMountainMayhem = 9;
            func_800726AC(0, 0x10);
        }
        break;
    case 9:
        if (func_80072718() == 0) {
            D_800FBFC0_BoxMountainMayhem = 1;
        }
        break;
    }
}

// decomp-permuter
void func_800F6ECC_BoxMountainMayhem(void)
{
  BMMPlayerWork *work;
  omObjData *obj;
  s32 i;
  s32 count;
  s32 done;
  f32 angle;
  u16 motion;
  D_800FC0EC_BoxMountainMayhem--;
  count = 0;
  done = 0;
  for (i = 0; i < 4; i++)
  {
    obj = D_800FC278_BoxMountainMayhem[i];
    if (obj == 0)
    {
      continue;
    }
    work = (BMMPlayerWork *) obj->unk_50;
    work->unk_40 = 0.0f;
    angle = work->unk_3C;
    count++;
    if (angle == (-45.0f))
    {
      done++;
      continue;
    }
    if (angle < (-45.0f))
    {
      work->unk_3C = angle + 20.0f;
    }
    else
      if (angle > 135.0f)
    {
      work->unk_3C = (angle += 20.0f);
      if (angle > 180.0f)
      {
        work->unk_3C = angle - 360.0f;
      }
    }
    else
    {
      work->unk_3C -= 20.0f;
    }
    if ((work->unk_3C > (-65.0f)) && (work->unk_3C < (-25.0f)))
    {
      work->unk_3C = -45.0f;
    }
  }

  if (count == done)
  {
    for (i = 0; i < 4; i++)
    {
      obj = D_800FC278_BoxMountainMayhem[i];
      if (obj != 0)
      {
        motion = 14;
        work = (BMMPlayerWork *) obj->unk_50;
        if (((u16) GwPlayer[work->unk_58].coins_mg) != 0)
        {
          motion = 13;
        }
        func_800184BC(obj, motion);
        func_80017DB0(obj);
      }
    }

    GMesCreate((D_800FC0E6_BoxMountainMayhem != 0) ? (2) : (0x10));
    D_800FC0E4_BoxMountainMayhem = 5;
  }
}

void func_800F70C0_BoxMountainMayhem(omObjData* obj) {
    if (D_800F5144 != 0 || D_800FBFC0_BoxMountainMayhem != 0) {
        func_800601D4(10);
        omOvlReturnEx(1);
    }
}

/* Zero padding after func_800F6A00's jump table in retail .rodata. */
const u32 D_800FC0B4_BoxMountainMayhem[3] = { 0, 0, 0 };
