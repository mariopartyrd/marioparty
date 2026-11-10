#include "common.h"
#include "2F40C0.h"

u32 D_800F9490_TestingRoom = 0;
u32 D_800F9494_TestingRoom = 0;
s32 D_800F9498_TestingRoom = 0x744;
u32 D_800F949C_TestingRoom = 0;
s32 D_800F94A0_TestingRoom = 0;
f32 D_800F94A4_TestingRoom = 60.0f;

void func_800F65E0_TestingRoom(void) {
    u8 temp_s0;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_80009500();
    D_800B899C = 0;
    func_80009618(1);
    D_800B8955 = 0;
    func_800090B8(D_800ED440);
    
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800F6BD8_TestingRoom);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 2, 0, -1, &func_800F6D04_TestingRoom);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800F6E38_TestingRoom);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800F6F1C_TestingRoom);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800F7010_TestingRoom);
    
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 0xA, 0x3C, -1, &func_800F7970_TestingRoom);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, -1, &func_800F7A44_TestingRoom);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, -1, &func_800F7AFC_TestingRoom);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, -1, &func_800F7B78_TestingRoom);
    
    D_800EDE70[D_800EE984++] = omAddObj(3, 5, 0, -1, &func_800F7C38_TestingRoom);
    D_800EDE70[D_800EE984++] = omAddObj(3, 1, 0, -1, &func_800F7BF4_TestingRoom);
    
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    D_800B895C = 10.0f;
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6A44_TestingRoom(void) {
    s32 i;
    f32* tempVar;
    f32* anotherTemp;

    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (D_800F9494_TestingRoom >= 0x1F) {
            func_80009458();
        }
        D_800F9494_TestingRoom += 2;
        break;
    case 1:
        D_800F9498_TestingRoom -= 2;
        if ((ContBtn[0] & 0x30) == 0x30) { //ContBtn maybe not an array
            omOvlReturnEx(1);
        }
        break;
    case 2:
        if (D_800F949C_TestingRoom == 0) {
            func_8000C250(0xB4);
        }
        
        if (D_800F949C_TestingRoom > 0xB4) {
            func_80009448();
        }
        
        D_800F949C_TestingRoom += 2;
        break;
    case 3:
        if (D_800F94A0_TestingRoom == 0) {
            func_8000C250(0xB4);
        }
        D_800F94A0_TestingRoom += 2;
        break;
    }

    for (i = 0; i < D_800F2BC0; i++) {
        anotherTemp = &((unkGlobalStruct_00*) D_800F3FB0[i]->unk_50)->unk_60;
        tempVar = &CRot.y;
        *anotherTemp = *tempVar;
    }
}

void func_800F6BD8_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x380004, 0x99);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = &func_800F6A44_TestingRoom;
    temp_s1->unk_04 = 1;
    Center.x = 8.0f;
    Center.y = 110.0f;
    Center.z = -86.0f;
    CRot.x = 312.7f;
    CZoom = 2616.0f;
    func_800090A4(arg0);
    func_80008FB8(arg0, 0.6f);
    func_80008FC4(arg0, 25.0f);
    temp_s1->unk_05 = 0;
}

void func_800F6D04_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x380008, 0x899);
    arg0->trans.x = -1500.0f;
    arg0->trans.y = 75.0f;
    arg0->trans.z = 1200.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = &func_800F7EDC_TestingRoom;
    temp_s1->unk_04 = 1;
    func_80009058(arg0, 160.0f, 160.0f, -100.0f, -100.0f, 100.0f, 100.0f);
    func_80008FB8(arg0, 0.3f);
    func_8000941C(arg0, 1.0f, 1.0f, 1.0f);
    temp_s1->unk_05 = 1;
}

void func_800F6E38_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x380000, 0x899);
    arg0->trans.x = 0.0f;
    arg0->trans.y = 0.0f;
    arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = &func_800F9400_TestingRoom;
    temp_s1->unk_04 = 1;
    func_80009000(arg0, 4, 0.0f);
    func_800090A4(arg0);
    func_80008FB8(arg0, 0.5f);
    func_8000941C(arg0, 1.0f, 1.0f, 1.0f);
    func_80008FC4(arg0, 20.0f);
    temp_s1->unk_05 = 2;
}

void func_800F6F1C_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x380006, 0x899);
    arg0->trans.x = 0.0f;
    arg0->trans.y = 125.0f;
    arg0->trans.z = 1700.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, 1700.0f);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = &func_800F7F50_TestingRoom;
    temp_s1->unk_04 = 1;
    func_80009000(arg0, 4, 0.0f);
    func_80008FB8(arg0, 0.5f);
    func_8000941C(arg0, 1.0f, 1.0f, 1.0f);
    temp_s1->unk_05 = 3;
}

void func_800F7010_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x380006, 0x899);
    arg0->trans.z = 1000.0f;
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = NULL;
    temp_s1->unk_04 = 1;
    func_80009090(arg0);
    func_80009058(arg0, 250.0f, 250.0f, -250.0f, -250.0f, 250.0f, 250.0f);
    func_80008FB8(arg0, 0.5f);
    func_80008FC4(arg0, 15.0f);
    func_8000941C(arg0, 2.0f, 2.0f, 2.0f);
    temp_s1->unk_05 = 4;
}

void func_800F7108_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x380006, 0x899);
    arg0->trans.x = 0.0f;
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = NULL;
    temp_s1->unk_04 = 1;
    func_80009090(arg0);
    func_80009058(arg0, 250.0f, 250.0f, -250.0f, -250.0f, 250.0f, 250.0f);
    func_80008FB8(arg0, 0.5f);
    func_80008FC4(arg0, 15.0f);
    func_8000941C(arg0, 2.0f, 2.0f, 2.0f);
    temp_s1->unk_05 = 4;
}

void func_800F71F4_TestingRoom(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x38000C, 0x899);
    arg0->trans.x = -1600.0f;
    arg0->trans.y = 0.0f;
    arg0->trans.z = 2000.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, 2000.0f);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = NULL;
    temp_s1->unk_04 = 1;
    func_80009000(arg0, 4, 0.0f);
    func_80008FB8(arg0, 0.5f);
    func_8000941C(arg0, 1.0f, 1.0f, 1.0f);
    temp_s1->unk_05 = 5;
}

void func_800F72DC_TestingRoom(omObjData* arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    func_8000979C(arg0, arg1, arg2, arg3 & 0xFFFF, 0xA99, 0xA99);
    arg0->model[3] = LoadFormFile(0x19, 0xA8D);
    arg0->model[4] = LoadFormFile(0x1A, 0xA8D);
    arg0->model[6] = LoadFormFile(0x1B, 0xA8D);
    arg0->model[5] = LoadFormFile(0x1C, 0xA8D);
    arg0->model[7] = LoadFormFile(0x1E, 0xA8D);
    arg0->model[8] = LoadFormFile(0x1D, 0xA8D);
    func_800187D0(arg0, 0, arg1, 1, 0);
    func_800187D0(arg0, 1, arg1 | 1, 1, 0);
    func_800187D0(arg0, 2, arg1 | 3, 1, 0);
    func_800187D0(arg0, 5, arg1 | 4, 0, 0);
    func_800187D0(arg0, 6, arg1 | 5, 1, 0x13);
    func_800187D0(arg0, 7, arg1 | 6, 1, 0x22);
    func_800187D0(arg0, 8, arg1 | 9, 1, 0x1B);
    func_800187D0(arg0, 9, arg1 | 0xA, 1, 0x27);
    func_800187D0(arg0, 0x10, arg1 | 0x17, 1, 0);
    func_800187D0(arg0, 0x11, arg1 | 0x18, 0, 0);
    func_800187D0(arg0, 0x12, arg1 | 0x1C, 2, 0);
    func_800187D0(arg0, 0x13, arg1 | 0x1D, 2, 0);
    func_800187D0(arg0, 0xA, arg1 | 0x1E, 1, 0x27);
    func_800187D0(arg0, 0x16, arg1 | 0x24, 1, 0);
    func_8001874C(arg0, 0x15, arg1 | 0x62, 0, 0);
    func_8001874C(arg0, 0x14, arg1 | 0x5F, 2, 0);
    func_8001874C(arg0, 3, arg1 | 0x60, 1, 0);
    func_8001874C(arg0, 4, arg1 | 0x61, 1, 0);
    func_8001874C(arg0, 0x1E, arg1 | 0x63, 2, 0);
    func_8001874C(arg0, 0x1F, arg1 | 0x64, 2, 0);
    func_8001874C(arg0, 0x20, arg1 | 0x67, 0, 0);
    func_8001874C(arg0, 0x21, arg1 | 0x68, 2, 0);
    func_8001874C(arg0, 0x22, arg1 | 0x69, 2, 0);
    arg0->trans.x = arg4;
    arg0->trans.y = 10.0f;
    arg0->trans.z = arg6;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg6);
    func_800090C4(arg0, 0, 2);
    func_800090C4(arg0, 1, 2);
    func_800090C4(arg0, 2, 2);
    func_800090C4(arg0, 3, 2);
    func_800090C4(arg0, 4, 2);
    func_800090C4(arg0, 5, 2);
    func_800090C4(arg0, 6, 2);
}

void func_800F7690_TestingRoom(omObjData* arg0, s32 file, f32 x, f32 y, f32 z, s32 team) {
    TRWork* w;

    arg0->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(arg0->unk_50, 0, 0x6C);
    arg0->func_ptr = &func_800F8804_TestingRoom;
    w = arg0->unk_50;
    arg0->model[0] = func_800174C0(file, 0x99);
    arg0->trans.x = x;
    arg0->trans.y = y;
    arg0->trans.z = z;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0;
    w->unk_5C = 0;
    w->unk_38 = 1000.0f;
    w->unk_52 = team;
    w->unk_60 = 0;
    w->unk_4C = 0.5f;
    w->unk_50 = 0x40;
    w->unk_54 = 1;
    w->unk_58 = 0.5f;
}

void func_800F77BC_TestingRoom(omObjData* arg0, s32 file, f32 scale, f32 arg3, s32 arg4, s32 arg5) {
    TRWork* w;

    arg0->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(arg0->unk_50, 0, 0x6C);
    arg0->func_ptr = &func_800F8360_TestingRoom;
    w = arg0->unk_50;
    arg0->model[0] = func_800174C0(file, 0x99);
    arg0->model[1] = func_800174F4(6, 0xA99);
    func_80009340(arg0, 2, 0x25, 0x289, 8);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    w->unk_44 = 0.1f;
    w->unk_48 = 40.0f;
    w->unk_34 = 500.0f;
    w->unk_3C = arg3;
    w->unk_52 = 7;
    w->unk_5C = arg4;
    w->unk_4C = 0.5f;
    w->unk_60 = arg5;
    func_8000941C(arg0, scale, scale, scale);
    func_800093FC(arg0, 0.0f, 1000.0f, 0.0f);
    w->unk_3C = func_80029518(func_800B0CD8(arg0->trans.x, arg0->trans.z));
    w->unk_40 = 10.0f;
    w->unk_38 = 0.0f;
    w->unk_54 = 1;
    w->unk_5C = 0;
}

void func_800F7970_TestingRoom(omObjData* arg0) {
    s32 file1 = D_800C59AC[GwPlayer[0].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[0].character].unk_00;

    D_800F9490_TestingRoom = osGetTime();
    func_8000960C(1);
    func_800F72DC_TestingRoom(arg0, dir, file1, 0, -500.0f, 20.0f, 501.0f);
    D_800F9490_TestingRoom = osGetTime() - D_800F9490_TestingRoom;
}

void func_800F7A44_TestingRoom(omObjData* arg0) {
    s32 file1 = D_800C59AC[GwPlayer[1].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[1].character].unk_00;

    func_8000960C(0);
    func_800F72DC_TestingRoom(arg0, dir, file1, 1, 500.0f, 20.0f, 501.0f);
    ((TRWork*)arg0->unk_50)->unk_50 = 0x200;
}

void func_800F7AFC_TestingRoom(omObjData* arg0) {
    s32 file1 = D_800C59AC[GwPlayer[2].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[2].character].unk_00;

    func_800F72DC_TestingRoom(arg0, dir, file1, 2, -500.0f, 20.0f, -501.0f);
}

void func_800F7B78_TestingRoom(omObjData* arg0) {
    s32 file1 = D_800C59AC[GwPlayer[3].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[3].character].unk_00;

    func_800F72DC_TestingRoom(arg0, dir, file1, 3, 500.0f, 20.0f, -501.0f);
}

void func_800F7BF4_TestingRoom(omObjData* arg0) {
    func_800F7690_TestingRoom(arg0, 0x38000A, 1000.0f, 37.5f, 1300.0f, 3);
}

void func_800F7C38_TestingRoom(omObjData* arg0) {
    func_800F77BC_TestingRoom(arg0, 0xA, 1.0f, 180.0f, 0, 0x96);
}

void func_800F7C68_TestingRoom(omObjData* arg0, f32 dx, f32 dz) {
    f32 rot;
    unkGlobalStruct_02* g;
    omObjData* obj;
    TRWork* w;
    TRWork* w2;
    s16 i;
    f32 x, z, dist, angle;

    rot = 0.0f;
    g = arg0->unk_50;
    arg0->rot.y = rot;
    for (i = 0; i < D_800F2BC0; i++) {
        obj = D_800F3FB0[i];
        w = obj->unk_50;
        if ((s8)w->unk_53 == g->unk_05) {
            x = obj->trans.x - arg0->trans.x;
            z = obj->trans.z - arg0->trans.z;
            dist = func_800B1750(x * x + z * z);
            angle = func_800B0CD8(x, z) + rot;
            obj->trans.x = func_800AEAC0(angle) * dist + arg0->trans.x + dx;
            obj->trans.z = func_800AEFD0(angle) * dist + arg0->trans.z + dz;
            w->unk_3C = rot + w->unk_3C;
        }
    }
    for (i = 0; i < D_800EE984; i++) {
        obj = D_800EDE70[i];
        w2 = obj->unk_50;
        if (w2->unk_53 == g->unk_05) {
            x = obj->trans.x - arg0->trans.x;
            z = obj->trans.z - arg0->trans.z;
            dist = func_800B1750(x * x + z * z);
            angle = func_800B0CD8(x, z) + rot;
            obj->trans.x = func_800AEAC0(angle) * dist + arg0->trans.x + dx;
            obj->trans.z = func_800AEFD0(angle) * dist + arg0->trans.z + dz;
            w2->unk_3C = rot + w2->unk_3C;
        }
    }
}

void func_800F7EBC_TestingRoom(omObjData* arg0) {
    func_800F7C68_TestingRoom(arg0, 0.0f, 0.0f);
}

void func_800F7EDC_TestingRoom(omObjData* arg0) {
    arg0->trans.y += D_800F94A4_TestingRoom;
    if (arg0->trans.y <= 0.0f) {
        D_800F94A4_TestingRoom = 10.0f;
    } else if (arg0->trans.y > 500.0f) {
        D_800F94A4_TestingRoom = -60.0f;
    }
}

void func_800F7F50_TestingRoom(void) {
}

void func_800F7F58_TestingRoom(omObjData* arg0) {
    Vec3f n;
    TRWork* w = arg0->unk_50;
    f32 x, y, z, vy, speed, floorY, angle, h;

    if (w->unk_54 != 0) {
        x = func_800AEAC0(w->unk_3C) * 600.0f;
        y = arg0->trans.y;
        z = func_800AEFD0(w->unk_3C) * 600.0f;
        floorY = -10000.0f;
        vy = w->unk_38;
        angle = w->unk_3C;
        speed = w->unk_40;
        angle = func_80029518(angle + 2.0f);
        if (vy < 1000.0f) {
            if (vy > 1.0f) {
                vy = 1.0f;
            }
            y += vy * vy * (vy >= 0.0f ? -35.0f : 35.0f);
            vy += 0.04f;
            x += func_800AEAC0(angle) * speed;
            z += func_800AEFD0(angle) * speed;
            h = func_800F85E4_TestingRoom(arg0, x, y, z, &n);
            if (h != -65536.0f) {
                floorY = h;
                if (y < h) {
                    y = floorY;
                    if (fabs(vy) < 0.6) {
                        vy = 1000.0f;
                    } else {
                        vy = -vy * 0.2f;
                    }
                    speed -= w->unk_44;
                } else {
                    w->unk_53 = 0xFF;
                }
            } else {
                w->unk_53 = 0xFF;
            }
        } else {
            h = func_800F85E4_TestingRoom(arg0, x, y, z, &n);
            if (h != -65536.0f) {
                if (y < h + 35.0f) {
                    y = h;
                } else {
                    vy = 0.2f;
                    w->unk_53 = 0xFF;
                }
            } else {
                vy = 0.2f;
            }
            floorY = y;
        }
        if ((speed < D_800B8990) | (y < -1000.0f)) {
            w->unk_54 = 0;
            func_800090D8(arg0, 0, 0);
            func_800090D8(arg0, 1, 0);
        }
        arg0->trans.x = x;
        arg0->trans.y = y;
        arg0->trans.z = z;
        w->unk_38 = vy;
        w->unk_3C = angle;
        w->unk_40 = speed;
        arg0->rot.y = func_80029518(arg0->rot.y + 4.0f);
        if ((arg0->model[1] != 0) & (floorY != -10000.0f)) {
            func_80025798(arg0->model[1], x, floorY - 4.0f, z);
            func_80025830(arg0->model[1], 0.3f, 0.3f, 0.3f);
            func_80037178(arg0->model[1], &n);
        }
    }
}

void func_800F8360_TestingRoom(omObjData* arg0) {
    TRWork* w = arg0->unk_50;
    omObjData* p0 = D_800F3FB0[0];
    s32 st;

    if (w->unk_54 == 0) {
        st = D_800ED430;
        if (st == 1) {
            if (w->unk_5C > w->unk_60) {
                func_800093FC(arg0, 0.0f, 1000.0f, 0.0f);
                w->unk_3C = func_80029518(func_800B0CD8(p0->trans.x, p0->trans.z));
                w->unk_40 = 3.0f;
                w->unk_38 = 0.0f;
                w->unk_54 = 1;
                w->unk_5C = 0;
                func_800090D8(arg0, 0, 1);
                func_800090D8(arg0, 1, 1);
                func_800F7F58_TestingRoom(arg0);
                w->unk_60 -= 50;
                if (w->unk_60 <= 0) {
                    w->unk_60 = st;
                }
            }
            w->unk_5C++;
        }
    } else {
        func_800F7F58_TestingRoom(arg0);
    }
}

void func_800F846C_TestingRoom(omObjData* arg0, Vec4f* p) {
    TRWork* w = arg0->unk_50;
    Vec3f d;
    Vec4f unused;
    omObjData* obj;
    TRWork* ow;
    u16 i;
    f32 dx, dy, dz, pen;

    if ((TR_WORD50(w) & 0x204000) == 0x4000) {
        for (i = 0; i < D_800F2BC0; i++) {
            obj = D_800F3FB0[i];
            ow = obj->unk_50;
            dx = obj->trans.x - p->x;
            dy = obj->trans.y - p->y;
            dz = obj->trans.z - p->z;
            pen = func_800B1750(dx * dx + dy * dy + dz * dz) - (w->unk_48 + ow->unk_48);
            if (pen < 0.0f) {
                d.x = dx;
                d.y = 0.0f;
                d.z = dz;
                func_8002956C(&d);
                D_800ED6B8 += pen * d.x;
                D_800F5254 += pen * d.z;
            }
        }
    }
}

f32 func_800F85E4_TestingRoom(omObjData* arg0, f32 x, f32 y, f32 z, Vec3f* n) {
    Vec4f probe;
    TRColVtx* verts;
    TRColTri* tri;
    s16 mdl;
    TRWork* w = arg0->unk_50;
    f32 floorY = -10000.0f;
    f32 h;

    probe.x = x;
    probe.y = y;
    probe.z = z;
    probe.w = w->unk_48;
    func_800F846C_TestingRoom(arg0, &probe);
    probe.x = x + D_800ED6B8;
    probe.y = y;
    probe.z = z + D_800F5254;
    ((s32 (*)())func_80004D1C)(arg0, &probe, D_800B8988);
    mdl = *D_800F2AF8[D_800B8954]->model;
    verts = (TRColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
    func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
    goto next;
loop:
    h = func_80029764(x, y, z, verts, tri);
    if (floorY < h) {
        floorY = h;
        func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], n);
    }
next:
    if ((tri = func_8002B3A8(&D_800EDEC0)) != NULL) {
        goto loop;
    }
    if (floorY == -10000.0f) {
        floorY = -65536.0f;
    }
    h = func_800051D4(arg0, x, y, z, n);
    if (floorY < h) {
        floorY = h;
    }
    return floorY;
}

void func_800F8804_TestingRoom(omObjData* arg0) {
    Vec3f n;
    Vec3f unused[2];
    f32 x = arg0->trans.x;
    f32 y = arg0->trans.y;
    f32 z = arg0->trans.z;
    TRWork* w = arg0->unk_50;
    f32 vy, h;

    if (!(w->unk_50 & 0x20)) {
        D_800ED6B8 = D_800F5254 = 0.0f;
        x += func_800AEAC0(w->unk_3C) * w->unk_40;
        z += func_800AEFD0(w->unk_3C) * w->unk_40;
        if (w->unk_38 < 1000.0f) {
            vy = w->unk_38;
            if (vy > 2.0f) {
                vy = 2.0f;
            }
            y += vy * vy * (w->unk_38 >= 0.0f ? -35.0f : 35.0f);
            h = func_800F85E4_TestingRoom(arg0, x, y, z, &n);
            if (y < h) {
                w->unk_38 = 1000.0f;
                y = h;
            }
            w->unk_38 += D_800B8968 * 1.5f;
        } else {
            if (w->unk_40 < D_800B8990) {
                w->unk_40 += 2.0f * D_800B8960;
                if (D_800B8990 < w->unk_40) {
                    w->unk_40 = D_800B8990;
                }
            } else if (D_800B8990 < w->unk_40) {
                w->unk_40 -= 2.0f * D_800B8960;
                if (w->unk_40 < D_800B8990) {
                    w->unk_40 = D_800B8990;
                }
            }
            y = func_800F85E4_TestingRoom(arg0, x, y, z, &n);
        }
        arg0->trans.x = x + D_800ED6B8;
        arg0->trans.y = y;
        arg0->trans.z = z + D_800F5254;
        arg0->rot.y = w->unk_3C;
    }
}

void func_800F8A60_TestingRoom(Matrix4f m, Vec3f* p, omObjData* obj) {
    Matrix4f unused;
    f32 rx = obj->rot.x;
    f32 ry = obj->rot.y;
    f32 rz = obj->rot.z;
    f32 tx = obj->trans.x;
    f32 ty = obj->trans.y;
    f32 tz = obj->trans.z;
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;

    if ((tx != 0.0f) | (ty != 0.0f) || tz != 0.0f) {
        func_8009EA40(m, tx, ty, tz);
    } else {
        func_800A2A50(m);
    }
    if ((rx != 0.0f) | (ry != 0.0f) || rz != 0.0f) {
        MtxRotate(m, rx, ry, rz);
    }
    p->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    p->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    p->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

void func_800F8C6C_TestingRoom(omObjData* arg0, f32 dx, f32 dz) {
    if ((dx > 0.25f) | (dz > 0.25f)) {
        func_80010C4C(0xF4);
    }
    arg0->rot.x += dx;
    arg0->rot.z += dz;
}

f32 func_800F8D18_TestingRoom(omObjData* arg0) {
    Matrix4f m;
    Vec3f p;
    omObjData* obj;
    TRWork* w;
    f32 tilt = 0.0f;
    u8 id = ((unkGlobalStruct_02*)arg0->unk_50)->unk_05;
    f32 rot = arg0->rot.x;
    s16 i;
    f32 dx, dz, dist, angle;

    for (i = 0; i < D_800F2BC0; i++) {
        obj = D_800F3FB0[i];
        w = obj->unk_50;
        if ((s8)w->unk_53 != id) {
            continue;
        }
        p.x = arg0->trans.x;
        p.y = 310.0f;
        p.z = arg0->trans.z;
        func_800F8A60_TestingRoom(m, &p, arg0);
        dx = p.x - obj->trans.x;
        dz = p.z - obj->trans.z;
        dist = func_800B1750(dx * dx + dz * dz);
        if (dist == 0.0f) {
            continue;
        }
        angle = func_800B0CD8(obj->trans.x, -obj->trans.z);
        if (dist > 300.0f) {
            w->unk_38 = -D_800B8964 * 0.5f;
            w->unk_3C = func_800B0CD8(obj->trans.x, obj->trans.z);
            func_800184BC(obj, 6);
            w->unk_40 = D_800B8984;
            w->unk_50 |= 0x10;
        }
        if ((angle > 120.0f) | (angle < -120.0f)) {
            tilt += dist / 300.0f;
            break;
        }
        if ((angle < 60.0f) & (angle > -60.0f)) {
            tilt += -dist / 300.0f;
            break;
        }
    }
    if ((fabs(rot) > 20.0) & (tilt != 0.0f)) {
        tilt = 0.0f;
    } else if ((rot != 0.0f) & (tilt == 0.0f)) {
        tilt = -rot / 20.0f;
    }
    return tilt;
}

f32 func_800F908C_TestingRoom(omObjData* arg0) {
    Matrix4f m;
    Vec3f p;
    omObjData* obj;
    TRWork* w;
    f32 tilt = 0.0f;
    u8 id = ((unkGlobalStruct_02*)arg0->unk_50)->unk_05;
    f32 rot = arg0->rot.z;
    s16 i;
    f32 dx, dz, dist, angle;

    for (i = 0; i < D_800F2BC0; i++) {
        obj = D_800F3FB0[i];
        w = obj->unk_50;
        if ((s8)w->unk_53 != id) {
            continue;
        }
        p.x = arg0->trans.x;
        p.y = 310.0f;
        p.z = arg0->trans.z;
        func_800F8A60_TestingRoom(m, &p, arg0);
        dx = p.x - obj->trans.x;
        dz = p.z - obj->trans.z;
        dist = func_800B1750(dx * dx + dz * dz);
        if (dist == 0.0f) {
            continue;
        }
        angle = func_800B0CD8(obj->trans.x, -obj->trans.z);
        if (dist > 300.0f) {
            w->unk_38 = -D_800B8964 * 0.5f;
            w->unk_3C = func_800B0CD8(obj->trans.x, obj->trans.z);
            func_800184BC(obj, 6);
            w->unk_40 = D_800B8984;
            w->unk_50 |= 0x10;
        }
        if ((angle < 150.0f) & (angle > 30.0f)) {
            tilt += -dist / 300.0f;
            break;
        }
        if ((angle > -150.0f) & (angle < -30.0f)) {
            tilt += dist / 300.0f;
            break;
        }
    }
    if ((fabs(rot) > 20.0) & (tilt != 0.0f)) {
        tilt = 0.0f;
    } else if ((rot != 0.0f) & (tilt == 0.0f)) {
        tilt = -rot / 20.0f;
    }
    return tilt;
}

void func_800F9400_TestingRoom(omObjData* arg0) {
    if (D_800ED430 == 1) {
        func_80008FC4(arg0, 0.0f);
        D_800F94D0_TestingRoom = func_800F8D18_TestingRoom(arg0);
        D_800F94D4_TestingRoom = func_800F908C_TestingRoom(arg0);
        func_800F8C6C_TestingRoom(arg0, D_800F94D0_TestingRoom, D_800F94D4_TestingRoom);
    } else {
        func_80008FC4(arg0, 0.0f);
    }
}
