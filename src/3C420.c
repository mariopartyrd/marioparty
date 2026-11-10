#include "common.h"

#include "engine/pad.h"
#include "spaces.h"

extern s16 D_800EE320;
s32 func_8004D02C(s16 arg0, f32 arg1);
void func_8003BB48(void);
void func_8003BEB4(void);


void* func_8003B820() {
    Object* temp_v0_2;
    unk_ProcessUserData08* temp_v0;

    temp_v0 = MallocTemp(sizeof(*temp_v0)); /* 8 on the N64; a pointer field */
    temp_v0->unk00 = 0;
    temp_v0_2 = MBModelCreate(0x24, NULL);
    temp_v0->unk04 = temp_v0_2;
    func_800258EC(*temp_v0_2->unk_3C->unk_40, 0x180, 0);
    func_80025AD4(*temp_v0->unk04->unk_3C->unk_40);
    func_80025F60(*temp_v0->unk04->unk_3C->unk_40, 0x1400);
    return temp_v0;
}

void func_8003B8A4(unk_ProcessUserData08* arg0) {
    MBModelKill(arg0->unk04);
    FreeTemp(arg0);
}

unk_8003B8D4Struct* func_8003B8D4(void) {
    unk_8003B8D4Struct* temp_v0;

    temp_v0 = MallocTemp(sizeof(*temp_v0)); /* 0x6C on the N64; pointers and a message queue */
    temp_v0->unk00 = 0;
    temp_v0->unk02 = 0;
    temp_v0->unk04 = 0;
    temp_v0->unk08 = 0;
    temp_v0->unk0C = 0;
    temp_v0->unk68 = 0;
    return temp_v0;
}

void func_8003B908(unk_8003B8D4Struct* arg0) {
    Process* temp_a0_2;
    s16 temp_v0;
    s32 var_s0;
    unk_ProcessUserData08** var_s1;
    unk_ProcessUserData08* temp_a0;

    temp_v0 = arg0->unk02;
    if (temp_v0 != 0) {
        var_s1 = arg0->unk04;
        for (var_s0 = 0; var_s0 < arg0->unk02; var_s0++) {
            temp_a0 = *var_s1;
            var_s1++;
            func_8003B8A4(temp_a0);
        }
        FreeTemp(arg0->unk04);
    }
    temp_a0_2 = arg0->unk08;
    if (temp_a0_2 != NULL) {
        EndProcess(temp_a0_2);
    }
    FreeTemp(arg0);
}

void func_8003B994(unk_8003B8D4Struct* arg0, unk_ProcessUserData08* arg1, s16 arg2) {
    unk_ProcessUserData08** temp_a0_2;
    unk_ProcessUserData08** temp_v0;
    unk_ProcessUserData08** temp_v0_2;
    unk_ProcessUserData08** var_a0;
    unk_ProcessUserData08** var_a1;
    s32 var_v1;
    u16 temp_a0;

    temp_a0 = arg0->unk02 + 1;
    arg0->unk02 = temp_a0;
    temp_v0 = MallocTemp((temp_a0 << 0x10) >> 0xE);
    temp_v0_2 = arg0->unk04;
    var_a0 = temp_v0;
    if (temp_v0_2 != NULL) {
        var_a1 = temp_v0_2;
        for (var_v1 = 0; var_v1 < (arg0->unk02 - 1); var_v1++) {
            *var_a0 = *var_a1;
            var_a1++;
            var_a0++;
        }
    }
    *var_a0 = arg1;
    temp_a0_2 = arg0->unk04;
    if (temp_a0_2 != NULL) {
        FreeTemp(temp_a0_2);
    }
    arg0->unk04 = temp_v0;
    arg1->unk00 = arg2;
    if (arg2 & 1) {
        arg0->unk0C = arg0->unk02 - 1;
    }
}

void func_8003BA68(unk_8003B8D4Struct* arg0, unk_ProcessUserData08* arg1) {
    unk_ProcessUserData08** list;
    unk_ProcessUserData08** dst;
    unk_ProcessUserData08** src;
    s32 i;

    list = NULL;
    if (arg0->unk02 >= 2) {
        arg0->unk02--;
        list = MallocTemp(arg0->unk02 * sizeof(unk_ProcessUserData08*));
        dst = list;
        src = arg0->unk04;
        for (i = 0; i <= arg0->unk02; i++) {
            if (*src == arg1) {
                src++;
            } else {
                *dst = *src;
                src++;
                dst++;
            }
        }
    } else {
        arg0->unk02 = 0;
    }
    if (arg0->unk04 != NULL) {
        FreeTemp(arg0->unk04);
    }
    arg0->unk04 = list;
}
unk_ProcessUserData08* func_8003BB30(unk_8003B8D4Struct* arg0, s16 arg1) {
    return arg0->unk04[arg1];
}
// GCC hoists the 360.0f constant out of the loop into $f24; retail reloads it
#ifdef NON_MATCHING
void func_8003BB48(void) {
    OSMesg msg;
    unk_8003B8D4Struct* w;
    f32 angle;
    f32 scale;
    s16 fade;
    s16 repeat;
    s16 prev;
    s32 ret;
    s32 i;

    fade = -1;
    w = HuPrcCurrentGet()->user_data;
    prev = w->unk0C;
    angle = 0.0f;
    repeat = 0;
    do {
        HuPrcVSleep();
        if (fade < 0) {
            if (repeat == 0) {
                if ((ret = osRecvMesg(&w->unk10, &msg, OS_MESG_NOBLOCK)) == -1) {
                    msg = (OSMesg)ret;
                }
                if (w->unk00 & 1) {
                    repeat = 8;
                }
            } else {
                msg = (OSMesg)-1;
                repeat--;
            }
            switch ((s32)msg) {
                case -2:
                    w->unk0C++;
                    if (w->unk0C >= w->unk02) {
                        w->unk0C = 0;
                    }
                    break;
                case -3:
                    w->unk0C--;
                    if (w->unk0C < 0) {
                        w->unk0C = w->unk02 - 1;
                    }
                    break;
                case -4:
                    if (w->unk0C >= 0) {
                        PlaySound(0xF7);
                        D_800EE320 = 0;
                        fade = 30;
                    }
                    break;
                case -5:
                    PlaySound(0xF8);
                    w->unk0C = -1;
                    fade = 0;
                    break;
                case -6:
                    w->unk0C = -1;
                    break;
                case -1:
                    break;
                default:
                    if ((s32)msg < w->unk02) {
                        w->unk0C = (s32)msg;
                    }
                    break;
            }
            if (prev != w->unk0C) {
                PlaySound(0xF5);
                if (prev >= 0) {
                    func_800A0D00(&func_8003BB30(w, prev)->unk04->xScale, 1.0f, 1.0f, 1.0f);
                    angle = 0.0f;
                }
                prev = w->unk0C;
            }
        }
        if (prev >= 0) {
            if (fade >= 0) {
                angle += 50.0f;
            } else {
                angle += 15.0f;
            }
            if (angle > 360.0f) {
                angle -= 360.0f;
            }
            scale = func_800AEFD0(angle) * 0.3f + 1.2f;
            func_800A0D00(&func_8003BB30(w, prev)->unk04->xScale, scale, 1.0f, scale);
        }
        if (fade > 0) {
            fade--;
            scale = fade * (1.0f / 30.0f);
            for (i = 0; i < w->unk02; i++) {
                if (i != prev) {
                    Vec3f* s = (Vec3f*)&func_8003BB30(w, i)->unk04->xScale;
                    func_800A0F00(s, scale, s);
                }
            }
        }
    } while (fade != 0);
    EndProcess(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/3C420", func_8003BB48);
#endif
s32 func_8003BE84(unk_8003B8D4Struct* arg0, s32 arg1) {
    if (arg0->unk08 != NULL) {
        return osSendMesg(&arg0->unk10, (OSMesg)arg1, OS_MESG_NOBLOCK);
    }
    return -1;
}
// decomp-permuter
void func_8003BEB4(void)
{
  Vec3f stick;
  Vec3f diff;
  unk_8003B8D4Struct *w;
  int new_var2;
  GW_PLAYER *player;
  s32 sel;
  s32 i;
  int new_var;
  s16 loop;
  loop = 1;
  w = HuPrcCurrentGet()->user_data;
  player = w->unk68;
  sel = w->unk0C;
  do
  {
    HuPrcVSleep();
    stick.x = ContStkX[w->unk0E];
    stick.z = -((f32) ContStkY[w->unk0E]);
    stick.y = 0.0f;
    if (((s16) func_8004D02C(w->unk0E, 40.0f)) != 0)
    {
      for (i = 0; i < w->unk02; i++)
      {
        func_800A0E80(&diff, &func_8003BB30(w, i)->unk04->coords, &player->player_obj->coords);
        diff.y = 0.0f;
        if (func_8003D8CC(&stick, &diff) <= 38.0f)
        {
          if (sel != i)
          {
            sel = i;
            func_8003BE84(w, sel);
          }
          break;
        }
      }

    }
    new_var2 = ((ContDStkTrg[w->unk0E] & 0x8000) != 0) & (sel >= 0);
    if (new_var2)
    {
      sel = -4;
      func_8003BE84(w, new_var = -4);
      loop = 0;
 do { } while (0);
    }
  }
  while (loop);
  EndProcess(0);
}
s32 func_8003C060(unk_8003B8D4Struct* arg0, s16 arg1, s16 arg2) {
    GW_PLAYER* player;

    if (arg0->unk08 == NULL) {
        arg0->unk08 = omAddPrcObj(func_8003BB48, 0xEFFF, 0, 0);
        arg0->unk08->user_data = arg0;
        osCreateMesgQueue(&arg0->unk10, arg0->unk28, ARRAY_COUNT(arg0->unk28));
        arg0->unk00 |= arg2;
        player = GetPlayerStruct(arg1);
        if (player->flags & 1) {
            arg0->unk00 |= 1;
            func_8003BE84(arg0, -1);
        } else {
            arg0->unk0E = player->port;
            omAddPrcObj(func_8003BEB4, 0xEFFF, 0, 0)->user_data = arg0;
        }
        return player->flags & 1;
    }
    return -1;
}
s32 DirectionPrompt(unk_8003B8D4Struct* arg0) {
    if (arg0->unk08 != NULL) {
        HuPrcChildLink(HuPrcCurrentGet(), arg0->unk08);
        HuPrcChildWatch();
    }
    return arg0->unk0C;
}
void func_8003C198(unk_ProcessUserData08* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3) {
    Vec3f dir;

    func_8004CCD0(arg1, arg2, &dir);
    func_800A0D50(&arg0->unk04->unk_18, &dir);
    func_800A0F00(&dir, arg3, &dir);
    func_800A0E00(&arg0->unk04->coords, &dir, arg1);
}
unk_8003B8D4Struct* func_8003C218(s16 arg0, void* arg1) {
    s16* spaces = arg1;
    GW_PLAYER* player;
    unk_8003B8D4Struct* w;
    unk_ProcessUserData08* arrow;

    player = GetPlayerStruct(arg0);
    w = func_8003B8D4();
    w->unk68 = player;
    while (*spaces >= 0) {
        arrow = func_8003B820();
        func_8003C198(arrow, &player->player_obj->coords, &BoardSpaceGet(*spaces)->coords, 200.0f);
        func_8003B994(w, arrow, 0);
        spaces++;
    }
    return w;
}