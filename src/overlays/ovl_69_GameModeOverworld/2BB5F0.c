#include "engine/process.h"
#include "2BB5C0.h"

typedef struct OverworldModel {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ s32 file; /* -1 ends the table */
} OverworldModel; /* size 0x14 */

typedef struct OverworldCamKey {
    /* 0x00 */ f32 zoom; /* 0 ends the path */
    /* 0x04 */ Vec3f center;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f pos;
    /* 0x28 */ f32 time;
} OverworldCamKey; /* size 0x2C */



f32 func_80022D9C(f32* vals, f32* times, f32 t);


f32 func_800B1750(f32);


s16 func_8005B470(s16 win);
void func_80071FF4(s32 arg0, u8 arg1);
void func_8005B414(void);
void func_8005CEDC(s32 flag);
void func_8005CE8C(s32);
void func_8005B388(void);
void func_800F7E24_GameModeOverworld(void);
void func_800F7DF0_GameModeOverworld(void);
void func_800F7DB8_GameModeOverworld(s16 arg0);
void func_800F8BA0_GameModeOverworld(OverworldCamKey* path, f32 speed);
extern u8 D_800F9941_GameModeOverworld;
extern s16 D_800FA1E0_GameModeOverworld;
extern u8 D_800FA201_GameModeOverworld;
extern OverworldCamKey D_800F9AD0_GameModeOverworld[];
extern OverworldCamKey D_800F9C30_GameModeOverworld[];
extern OverworldCamKey D_800F9D64_GameModeOverworld[];
extern OverworldCamKey D_800F9E6C_GameModeOverworld[];
extern OverworldCamKey D_800F9F74_GameModeOverworld[];
extern OverworldCamKey D_800FA07C_GameModeOverworld[];




/* .data (address order) */
u8 D_800F9940_GameModeOverworld = 0;
u8 D_800F9941_GameModeOverworld = 0;
Vec2f D_800F9944_GameModeOverworld[7] = { { 581.0f, 2844.0f }, { 661.0f, 1714.0f }, { 701.0f, 404.0f }, { 581.0f, -376.0f }, { 181.0f, -706.0f }, { 21.0f, -706.0f }, { 0.0f, 0.0f } };
Vec2f D_800F997C_GameModeOverworld[10] = { { 131.0f, 914.0f }, { -119.0f, 1304.0f }, { -559.0f, 1394.0f }, { -999.0f, 1124.0f }, { -539.0f, 2014.0f }, { 111.0f, 2064.0f }, { 51.0f, 1634.0f }, { 371.0f, 1164.0f }, { 131.0f, 914.0f }, { 0.0f, 0.0f } };
Vec2f D_800F99CC_GameModeOverworld[10] = { { 201.0f, 914.0f }, { -159.0f, 614.0f }, { -599.0f, 464.0f }, { -949.0f, 544.0f }, { -959.0f, 1364.0f }, { -779.0f, 1494.0f }, { -459.0f, 1444.0f }, { 1.0f, 1254.0f }, { 201.0f, 914.0f }, { 0.0f, 0.0f } };
OverworldModel D_800F9A1C_GameModeOverworld[9] = {
    { 0.0f, 0.0f, 0.0f, 0.0f, 0x90019 },
    { 0.0f, 378.0f, 0.0f, 0.0f, 0x90000 },
    { -900.0f, 95.0f, 50.0f, 45.0f, 0x9001b },
    { 1325.0f, 34.5f, 450.0f, 0.0f, 0x9001c },
    { 190.0f, 315.0f, -1350.0f, 0.0f, 0x9001e },
    { -400.0f, 35.0f, 985.0f, 75.0f, 0x9001d },
    { 681.0f, -100.0f, 324.0f, 0.0f, 0xa00f3 },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0x9001f },
    { 0.0f, 0.0f, 0.0f, 0.0f, -1 },
};
OverworldCamKey D_800F9AD0_GameModeOverworld[8] = {
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4480.0f, { -356.0f, 568.0f, -712.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 3380.0f, { -196.0f, 650.0f, -324.0f }, { 299.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 1940.0f, { 0.0f, 58.0f, 0.0f }, { 270.0f, 30.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 320.0f, { 0.0f, -269.0f, 0.0f }, { 270.0f, 80.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 320.0f, { 0.0f, -269.0f, 0.0f }, { 270.0f, 100.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
OverworldCamKey D_800F9C30_GameModeOverworld[7] = {
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 4080.0f, { 412.0f, -215.0f, 733.0f }, { 331.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 1400.0f, { -137.0f, 56.0f, 1078.0f }, { 350.0f, 66.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 580.0f, { -138.0f, 86.0f, 1048.0f }, { 358.0f, 77.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 580.0f, { -138.0f, 86.0f, 1048.0f }, { 358.0f, 77.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
OverworldCamKey D_800F9D64_GameModeOverworld[6] = {
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 3100.0f, { -705.0f, 292.0f, 281.0f }, { 350.0f, 45.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 300.0f, { -744.0f, 109.0f, 197.0f }, { 363.0f, 49.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 300.0f, { -744.0f, 109.0f, 197.0f }, { 363.0f, 49.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
OverworldCamKey D_800F9E6C_GameModeOverworld[6] = {
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 3520.0f, { 1185.0f, 207.0f, 217.0f }, { 350.0f, 10.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 620.0f, { 1321.0f, 64.0f, 535.0f }, { 357.0f, 4.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 620.0f, { 1321.0f, 64.0f, 535.0f }, { 357.0f, 4.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
OverworldCamKey D_800F9F74_GameModeOverworld[6] = {
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 2740.0f, { 365.0f, 340.0f, -653.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 580.0f, { 192.0f, 356.0f, -1315.0f }, { 364.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 580.0f, { 192.0f, 356.0f, -1315.0f }, { 364.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
OverworldCamKey D_800FA07C_GameModeOverworld[5] = {
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 7120.0f, { 55.0f, 59.0f, 61.0f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 2560.0f, { 417.46487f, -203.62753f, 381.2375f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 2560.0f, { 417.46487f, -203.62753f, 381.2375f }, { 341.0f, 28.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
s16 D_800FA158_GameModeOverworld = 0;
s16 D_800FA15A_GameModeOverworld = 0; /* unreferenced */
s16 D_800FA15C_GameModeOverworld[5][2] = { { 0, 1 }, { 4, -1 }, { 2, 1 }, { 0, 0 }, { 0, 0 } };


void func_80060F04(s32, s32, s32, s32);
void func_800F6FC8_GameModeOverworld(void);
void func_800F907C_GameModeOverworld(void);
void func_800F9474_GameModeOverworld(void);
void func_800F6F14_GameModeOverworld(void);
void func_800F7214_GameModeOverworld(void);
extern OverworldModel D_800F9A1C_GameModeOverworld[];
extern s16 D_800FA1E8_GameModeOverworld[8];
extern Vec2f D_800F9944_GameModeOverworld[];
extern Vec2f D_800F997C_GameModeOverworld[];
extern Vec2f D_800F99CC_GameModeOverworld[];
extern u8 D_800F9940_GameModeOverworld;
extern s16 D_800FA158_GameModeOverworld;
extern s16 D_800FA15C_GameModeOverworld[][2];


void func_80025F10(s16, s32);
unk2C0C0Struct50* func_80026A0C(s16, char*); /* a model node (24740.c), not an Object */
void func_800F731C_GameModeOverworld(void);
void func_800F86EC_GameModeOverworld(void);
extern char D_800FA180_GameModeOverworld[];

void func_800F6610_GameModeOverworld(void) {
    omObjData* temp_s1;

    InitCameras(1);
    func_80029090(1);
    func_8001DE70(0x19);
    omInitObjMan(0x32, 0x14);
    func_80060088();
    func_8006CEA0();
    temp_s1 = omAddObj(0x7FDA, 0, 0, -1, func_800F884C_GameModeOverworld);
    omSetStatBit(temp_s1, 0xA0);
    omSysPauseEnableFlag = 1;
    omAddObj(0x2710, 0, 0, -1, &func_800F8AB8_GameModeOverworld);
    CZoom = 7120.0f;
    Center.x = 54.9103f;
    Center.y = 59.226612f;
    Center.z = 61.478203f;
    CRot.x = 341.0f;
    CRot.y = 28.0f;
    CRot.z = 0.0f;
    func_8001D494(0, 20.0f, 80.0f, 13000.0f);
    D_800FA1D0_GameModeOverworld.x = D_800FA1D0_GameModeOverworld.y = D_800FA1D0_GameModeOverworld.z = 0.0f;
    D_800FA1DC_GameModeOverworld = 2000.0f;
    D_800FA1C4_GameModeOverworld.x = D_800FA1C4_GameModeOverworld.y = D_800FA1C4_GameModeOverworld.z = 0.0f;
    func_8001D494(1, 10.0f, 80.0f, 8000.0f);
    func_800F884C_GameModeOverworld(temp_s1);
    D_800ECC22 = 1;
    func_8005AF60();
    func_80023448(3);
    func_800234B8(0U, 0x78U, 0x78U, 0x78U);
    func_800234B8(1U, 0x40U, 0x40U, 0x60U);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_80023504(2, -100.0f, 100.0f, 100.0f);
    func_800234B8(2U, 0U, 0U, 0U);
    func_800234B8(3U, 0U, 0U, 0U);
    omAddPrcObj(func_800F6968_GameModeOverworld, 0x3F00U, 0x1000, 0);
    D_800FA1C0_GameModeOverworld = 0;
    D_800FA1C2_GameModeOverworld = 0;
    D_800FA1E2_GameModeOverworld = 0;
    D_800FA1FC_GameModeOverworld = -1;
    D_800FA202_GameModeOverworld = 0;
    D_800FA200_GameModeOverworld = 0;
    if ((GwCommon.starNum >= 100) && (_CheckFlag(3) == 0) && (_CheckFlag(0x17) != 0)) {
        SetBoardFeatureFlag(3);
        SetBoardFeatureFlag(4);
    }
    D_800FA203_GameModeOverworld = _CheckFlag(3);
    D_800FA204_GameModeOverworld = _CheckFlag(4);
    D_800FA205_GameModeOverworld = _CheckFlag(0x18);
    if (D_800FA204_GameModeOverworld != 0) {
        D_800FA1E2_GameModeOverworld = 1;
    }
    ClearBoardFeatureFlag(0);
    ClearBoardFeatureFlag(0x29);
    ClearBoardFeatureFlag(0x2B);
    ClearBoardFeatureFlag(0x2C);
    if (_CheckFlag(0x36) != 0) {
        ClearBoardFeatureFlag(0x36);
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6968_GameModeOverworld(void) {
    OverworldModel* m;
    void* data;
    f32 t;
    f32 speed;
    f32 amp;
    f32 angle;
    s16 prev;
    s16 i;
    s16 id;

    for (i = 0; D_800F9A1C_GameModeOverworld[i].file != -1; i++) {
        m = &D_800F9A1C_GameModeOverworld[i];
        id = D_800FA1E8_GameModeOverworld[i] = LoadFormFile(m->file, 0x289);
        if (D_800F2B7C[id].unk_08 != -1) {
            func_80025EB4(id, 1, 1);
        }
        func_80025798(D_800FA1E8_GameModeOverworld[i], m->x, m->y, m->z);
        func_800257E4(D_800FA1E8_GameModeOverworld[i], 0.0f, m->rotY, 0.0f);
        func_80025F10(D_800FA1E8_GameModeOverworld[i], 1);
        if (i != 3) {
            func_80025B34(D_800FA1E8_GameModeOverworld[i]);
        }
    }
    omPrcSetStatBit(omAddPrcObj(func_800F6F14_GameModeOverworld, 0x3F00, 0x800, 0), 0xA0);
    omAddPrcObj(func_800F6FC8_GameModeOverworld, 0x3F00, 0x800, 0);
    data = DataRead(0x90021);
    func_80038A9C(D_800F2B7C[D_800FA1E8_GameModeOverworld[3]].unk_6C, data, 0, "02tt004a_DEF");
    DataClose(data);
    func_80025AD4(D_800FA1E8_GameModeOverworld[3]);
    func_80025B34(D_800FA1E8_GameModeOverworld[3]);
    omAddPrcObj(func_800F7214_GameModeOverworld, 0x3F00, 0x1000, 0);
    if (D_800FA203_GameModeOverworld == 0 || D_800FA205_GameModeOverworld != 0) {
        omAddPrcObj(func_800F907C_GameModeOverworld, 0x3F00, 0x800, 0)->user_data = D_800F997C_GameModeOverworld;
        omAddPrcObj(func_800F907C_GameModeOverworld, 0x3F00, 0x800, 0)->user_data = D_800F99CC_GameModeOverworld;
        omAddPrcObj(func_800F9474_GameModeOverworld, 0x3F00, 0x800, 0)->user_data = D_800F9944_GameModeOverworld;
        omAddPrcObj(func_800F9474_GameModeOverworld, 0x3F00, 0x800, 0)->user_data = D_800F9944_GameModeOverworld;
        omAddPrcObj(func_800F9474_GameModeOverworld, 0x3F00, 0x800, 0)->user_data = D_800F9944_GameModeOverworld;
        func_800258EC(D_800FA1E8_GameModeOverworld[7], 4, 4);
        SetFadeInTypeAndTime(0xFF, 0x10);
        func_8002890C(0x40, 0xF0, 0xFF);
        func_80060128(2);
    } else {
        if (D_800FA204_GameModeOverworld != 0) {
            for (i = 0; i < 4; i++) {
                func_80060F04(i, 2, 1, 0x3C);
            }
            HuPrcSleep(5);
            PlaySound(0x4C);
            HuPrcSleep(0xA);
        }
        func_80060128(0x2F);
        func_8002890C(0, 0xA0, 0xAF);
        SetFadeInTypeAndTime(3, 0x10);
    }
    angle = 180.0f;
    prev = -1;
    while (1) {
        HuPrcVSleep();
        if (D_800FA1E2_GameModeOverworld != prev || D_800FA200_GameModeOverworld == 0) {
            func_80025830(D_800FA1E8_GameModeOverworld[prev + 1], 1.0f, 1.0f, 1.0f);
            m = &D_800F9A1C_GameModeOverworld[prev + 1];
            func_80025798(D_800FA1E8_GameModeOverworld[prev + 1], m->x, m->y, m->z);
            angle = 180.0f;
        } else {
            m = &D_800F9A1C_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1];
            if (D_800FA204_GameModeOverworld == 0) {
                if (angle > 180.0f) {
                    amp = 0.2f;
                    speed = 15.0f;
                } else {
                    amp = 0.05f;
                    speed = 18.0f;
                }
            } else if (angle > 180.0f) {
                amp = 0.1f;
                speed = 10.0f;
            } else {
                amp = 0.05f;
                speed = 12.0f;
            }
            t = func_800AEAC0(angle) * amp + 1.0f;
            func_80025830(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], t, t, t);
            if (D_800FA1E2_GameModeOverworld != 0) {
                func_80025798(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], m->x, t * m->y, m->z);
            }
            angle += speed;
        }
        prev = (u16)D_800FA1E2_GameModeOverworld;
    }
}
void func_800F6F14_GameModeOverworld(void) {
    f32 var_f20, var_f24;
    u16 temp_s1;

    temp_s1 = LoadFormFile(0x9001A, 0x299);
    func_80026040(temp_s1);
    func_80025F10(temp_s1, 1);
    var_f20 = 0.0f;
    var_f24 = var_f20;
    while (1) {
      HuPrcVSleep();
        func_80027C1C(temp_s1, var_f24, var_f20, 0x20, 0x20);
        var_f20 += 0.5f;      
    }

}

void func_800F6FC8_GameModeOverworld(void) {
    f32 dx;
    f32 dz;
    f32 angle;
    f32 z;
    f32 x;
    f32 y;
    s16 i;

    x = D_800F9A1C_GameModeOverworld[6].x;
    y = D_800F9A1C_GameModeOverworld[6].y;
    z = D_800F9A1C_GameModeOverworld[6].z;
    angle = 0.0f;
    do {
        HuPrcVSleep();
        func_80025798(D_800FA1E8_GameModeOverworld[6], x, y + func_800AEAC0(angle) * 5.0f, z);
        func_800257E4(D_800FA1E8_GameModeOverworld[6], func_800AEAC0(angle / 2.0f) * 3.0f, 0.0f, 0.0f);
        angle += 10.0f;
    } while (D_800F9940_GameModeOverworld == 0);
    for (i = 0; i < 300; i++) {
        HuPrcVSleep();
        if (i == 45) {
            D_800FA1C0_GameModeOverworld = 4;
        }
        dx = (731.0f - x) / 300.0f * i;
        dz = (2704.0f - z) / 300.0f * i;
        func_80025798(D_800FA1E8_GameModeOverworld[6], x + dx, y + func_800AEAC0(angle) * 5.0f, z + dz);
        func_800257E4(D_800FA1E8_GameModeOverworld[6], func_800AEAC0(angle / 2.0f) * 3.0f, 0.0f, 0.0f);
        angle += 20.0f;
    }
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F7214_GameModeOverworld(void) {
    s32 temp_s0;
    Vec3f pad;

    temp_s0 = LoadFormFile(0x7000A, 0x202B9);
    func_80025EB4(temp_s0, 2, 2);
    func_80025F10(temp_s0, 1);

    pad.x = 291.0f;
    pad.y = 0.0f;
    pad.z = 2234.0f;
    
    func_80025798(temp_s0, pad.x, pad.y, pad.z);
    func_80025830(temp_s0, 3.0f, 3.0f, 3.0f);
    func_800257E4(temp_s0, 0.0f, 45.0f, 0.0f);
    omAddPrcObj(func_800F731C_GameModeOverworld, 0x3F00, 0x1000, 0);
    func_80026A0C(temp_s0, "c100_1-atama")->unk_44.x = -20.0f; /* the head's rotation x */
    while (1) {
        HuPrcVSleep();
    }
}

// retail keeps raw and s16 copies of both window ids; allocation and branch layout differ (masked 168)
#ifdef NON_MATCHING
void func_800F731C_GameModeOverworld(void) {
    u16 sel;
    u16 shown;
    s16 win;
    s16 win2;
    s16 cur;
    s32 msg;
    s32 choice;
    s8 cursor;
    s16 i;
    f32 s;
    u8 port;

    shown = 0;
    D_800ECC22 = 0;
    win = func_8007194C(0x46, 0xC2, 2);
    D_800FA1E0_GameModeOverworld = win;
    port = func_8005B470(win);
    GwPlayer[0].port = port;
    D_800FA201_GameModeOverworld = port;
    win2 = func_8007194C(0x46, 0xBE, 5);
    func_8005B470(win2);
    func_8006E288(win, 1);
    func_8006E288(win2, 1);
    if (D_800FA204_GameModeOverworld == 0) {
        if (D_800FA203_GameModeOverworld == 0 || D_800FA205_GameModeOverworld != 0) {
            if (_CheckFlag(2) == 0) {
                SetBoardFeatureFlag(2);
                msg = 0x96;
            } else {
                msg = 0x97;
            }
        } else {
            msg = 0x97;
        }
    } else {
        msg = 0x9F;
    }
    LoadStringIntoWindow(win, (void*)(s32)msg, -1, -1);
    func_80071FF4(win, 0xC0);
    func_80071FF4(win2, 0xC0);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_80071C8C(win, 1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    omAddPrcObj(func_800F7E24_GameModeOverworld, 0x3F00, 0x800, 0);
    HuPrcVSleep();
    D_800ECC22 = 1;
    D_800F9940_GameModeOverworld = 0;
    sel = D_800FA1E2_GameModeOverworld;
    while (1) {
        HuPrcVSleep();
        if (D_800FA1C0_GameModeOverworld == 2) {
            break;
        }
        cur = D_800FA1E2_GameModeOverworld;
        if (cur != (s16)sel) {
            sel = cur;
            func_8006EB40(win);
            switch (cur) {
            case 0:
                LoadStringIntoWindow(win, (void*)0x98, -1, -1);
                shown = 1;
                break;
            case 1:
                LoadStringIntoWindow(win, (void*)0x9C, -1, -1);
                break;
            case 2:
                LoadStringIntoWindow(win, (void*)0x9D, -1, -1);
                break;
            case 3:
                LoadStringIntoWindow(win, (void*)0x9E, -1, -1);
                break;
            case 4:
                LoadStringIntoWindow(win, (void*)0x9B, -1, -1);
                break;
            case 5:
                LoadStringIntoWindow(win, (void*)0xA0, -1, -1);
                break;
            }
        }
        if (D_800FA1C0_GameModeOverworld != 1 || !(ContBtnTrg[D_800FA201_GameModeOverworld] & 0x8000) ||
            D_800F9941_GameModeOverworld != 0) {
            continue;
        }
        PlaySound(0xF6);
        switch (D_800FA1E2_GameModeOverworld) {
        case 0:
            if (shown == 0) {
                func_8006EB40(win);
                LoadStringIntoWindow(win, (void*)0x98, -1, -1);
                shown = 1;
                break;
            }
            D_800FA1C0_GameModeOverworld = 3;
            D_800FA1FC_GameModeOverworld = 0x6A;
            D_800ECC22 = 0;
            func_80071E80(win, 1);
            func_8006EB40(win2);
            if (_CheckFlag(0x40) == 0) {
                LoadStringIntoWindow(win2, (void*)0x99, -1, -1);
                cursor = _CheckFlag(1) == 0;
            } else {
                LoadStringIntoWindow(win2, (void*)0x9A, -1, -1);
                cursor = 0;
            }
            while (func_8006FCC0(win2) != 0) {
                HuPrcVSleep();
            }
            func_80071C8C(win2, 1);
            choice = func_8006FCF0(win2, cursor, 0);
            D_800ECC22 = 1;
            if ((s16)choice == -1) {
                func_80071E80(win2, 1);
                func_80071C8C(win, 1);
                func_8006EB40(win);
                LoadStringIntoWindow(win, (void*)0x98, -1, -1);
                D_800FA1C0_GameModeOverworld = 1;
                break;
            }
            if (_CheckFlag(0x40) == 0) {
                /* without flag 0x40 the menu has no first entry: 0 and 1 mean 1 and 2 */
                if ((s16)choice != 0) {
                    goto two;
                }
                goto one;
            }
            switch ((s16)choice) {
            case 0:
                D_800FA202_GameModeOverworld = 2;
                func_8005B414();
                SetBoardFeatureFlag(0);
                break;
            case 1:
            one:
                ClearBoardFeatureFlag(0);
                D_800FA202_GameModeOverworld = 0;
                break;
            case 2:
            two:
                D_800FA202_GameModeOverworld = 1;
                break;
            }
            func_80072080(win);
            func_800F7DB8_GameModeOverworld(win2);
            D_800FA1C0_GameModeOverworld = 2;
            func_8002890C(0, 0, 0);
            omAddPrcObj(func_800F7DF0_GameModeOverworld, 0x3F00, 0x800, 0);
            func_800F8BA0_GameModeOverworld(D_800F9AD0_GameModeOverworld, 150.0f);
            D_800FA1C0_GameModeOverworld = 4;
            break;
        case 1:
            D_800FA1C0_GameModeOverworld = 2;
            D_800FA1FC_GameModeOverworld = 0x6D;
            func_800F7DB8_GameModeOverworld(win);
            func_800F8BA0_GameModeOverworld(D_800F9D64_GameModeOverworld, 150.0f);
            func_80025EB4(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], 1, 0);
            D_800FA1C0_GameModeOverworld = 4;
            for (i = 0; i < 25; i++) {
                HuPrcVSleep();
                s = i * 0.1f + 1.0f;
                func_80025830(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], s, s, s);
            }
            break;
        case 2:
            D_800FA1C0_GameModeOverworld = 2;
            D_800FA1FC_GameModeOverworld = 0x6B;
            func_800F7DB8_GameModeOverworld(win);
            func_800F8BA0_GameModeOverworld(D_800F9E6C_GameModeOverworld, 150.0f);
            func_80025EB4(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], 1, 0);
            HuPrcVSleep();
            D_800FA1C0_GameModeOverworld = 4;
            for (i = 0; i < 25; i++) {
                HuPrcVSleep();
                s = i * 0.1f + 1.0f;
                func_80025830(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], s, s, s);
            }
            break;
        case 3:
            D_800FA1C0_GameModeOverworld = 2;
            D_800FA1FC_GameModeOverworld = 0x6E;
            func_800F7DB8_GameModeOverworld(win);
            func_800F8BA0_GameModeOverworld(D_800F9F74_GameModeOverworld, 150.0f);
            func_80025EB4(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], 1, 0);
            D_800FA1C0_GameModeOverworld = 4;
            for (i = 0; i < 25; i++) {
                HuPrcVSleep();
                s = i * 0.1f + 1.0f;
                func_80025830(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], s, s, s);
            }
            break;
        case 4:
            D_800FA1C0_GameModeOverworld = 2;
            D_800FA1FC_GameModeOverworld = 0x6C;
            func_800F7DB8_GameModeOverworld(win);
            func_800F8BA0_GameModeOverworld(D_800F9C30_GameModeOverworld, 150.0f);
            func_80025EB4(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], 1, 0);
            D_800FA1C0_GameModeOverworld = 4;
            for (i = 0; i < 25; i++) {
                HuPrcVSleep();
                s = i * 0.1f + 1.0f;
                func_80025830(D_800FA1E8_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1], s, s, s);
            }
            break;
        case 5:
            D_800FA1C0_GameModeOverworld = 3;
            D_800FA1FC_GameModeOverworld = 0x72;
            D_800ECC22 = 0;
            func_80071E80(win, 1);
            func_8006EB40(win);
            if (func_8005CE48(0) != 0) {
                msg = 0xA2;
            } else {
                msg = 0xA1;
            }
            LoadStringIntoWindow(win, (void*)(s32)msg, -1, -1);
            while (func_8006FCC0(win) != 0) {
                HuPrcVSleep();
            }
            func_80071C8C(win, 1);
            choice = func_8006FCF0(win, 0, 0);
            D_800ECC22 = 1;
            func_8005CEDC(1);
            if ((s16)choice == -1 || (func_8005CE48(0) == 0 && (s16)choice == 1)) {
                func_80071E80(win, 1);
                func_8006EB40(win);
                LoadStringIntoWindow(win, (void*)0xA0, -1, -1);
                func_80071C8C(win, 1);
                D_800FA1C0_GameModeOverworld = 1;
                break;
            }
            D_800FA1C0_GameModeOverworld = 2;
            GwSystem.curBoardIndex = 10;
            if (func_8005CE48(0) != 0 && (s16)choice == 0) {
                func_8005B388();
                func_8005CE8C(1);
            }
            func_800F7DB8_GameModeOverworld(win);
            D_800F9940_GameModeOverworld = 1;
            func_800F8BA0_GameModeOverworld(D_800FA07C_GameModeOverworld, 75.0f);
            while (1) {
                HuPrcVSleep();
            }
        }
    }
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_GameModeOverworld/2BB5F0", func_800F731C_GameModeOverworld);
#endif
void func_800F7DB8_GameModeOverworld(s16 arg0) {
    func_80071E80(arg0, 1);
    func_80072080(arg0);
}

void func_800F7DF0_GameModeOverworld(void) {
    HuPrcSleep(0x37);
    PlaySound(0);
    while (1) {
        HuPrcVSleep(); 
    }
}

s16 func_800F8758_GameModeOverworld(u8 arg0);
s16 func_800F87D0_GameModeOverworld(u8 arg0);

// FPU allocation and the evaluation order of (cur != 0) & near (masked 70)
#ifdef NON_MATCHING
void func_800F7E24_GameModeOverworld(void) {
    Vec3f pos;
    Vec2f scr;
    f32 dirX[6];
    f32 dirY[6];
    f32 curX, curY;
    f32 dx, dy, len;
    f32 sx, sy;
    f32 best;
    f32 d;
    f32 t;
    s32 spr;
    s32 near;
    u16 id;
    s16 cur;
    s16 sel;
    s16 i;

    sel = 0;
    spr = func_80019060((s16)InitSprite(0x90023), 0, 1);
    id = spr;
    func_80018D84(id, 0x3A98);
    cur = D_800FA1E2_GameModeOverworld;
    pos.x = D_800F9A1C_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1].x;
    pos.y = D_800F9A1C_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1].y + 200.0f;
    pos.z = D_800F9A1C_GameModeOverworld[D_800FA1E2_GameModeOverworld + 1].z;
    Convert3DTo2D(0, &pos, &scr);
    curX = scr.x;
    curY = scr.y;
    SetBasicSpritePos(id, curX, curY);
    SetBasicSpriteSize(id, 0.0f, 0.0f);
    for (i = 0; i < 11; i++) {
        HuPrcVSleep();
        t = i / 10.0f;
        SetBasicSpriteSize(spr & 0xFFFF, t, t);
    }
    D_800FA1C0_GameModeOverworld = 1;
    D_800FA200_GameModeOverworld = 1;
    for (i = 0; i < 6; i++) {
        dirX[i] = dirY[i] = 0.0f;
    }
    while (1) {
        HuPrcVSleep();
        if (D_800FA1C0_GameModeOverworld == 2) {
            break;
        }
        if (D_800FA204_GameModeOverworld != 0 ||
            ((s16)(func_800F8758_GameModeOverworld(D_800FA201_GameModeOverworld) / 10) == 0 &&
             (s16)(func_800F87D0_GameModeOverworld(D_800FA201_GameModeOverworld) / 10) == 0) ||
            D_800FA1C0_GameModeOverworld == 3) {
            continue;
        }
        for (i = 0; i < 6; i++) {
            if (cur != i) {
                pos.x = D_800F9A1C_GameModeOverworld[i + 1].x;
                pos.y = D_800F9A1C_GameModeOverworld[i + 1].y + 100.0f;
                pos.z = D_800F9A1C_GameModeOverworld[i + 1].z;
                Convert3DTo2D(0, &pos, &scr);
                dx = curX - scr.x;
                dy = curY - scr.y;
                len = func_800B1750(dx * dx + dy * dy);
                dirX[i] = dx / len;
                dirY[i] = dy / len;
            }
        }
        sx = -func_800F8758_GameModeOverworld(D_800FA201_GameModeOverworld);
        sy = func_800F87D0_GameModeOverworld(D_800FA201_GameModeOverworld);
        len = func_800B1750(sx * sx + sy * sy);
        sx /= len;
        sy /= len;
        best = 10.0f;
        dx = sx - dirX[0];
        dy = sy - dirY[0];
        near = func_800B1750(dx * dx + dy * dy) < 0.5f;
        if (near & (cur != 0)) {
            best = 0.0f;
            sel = 0;
        } else if (cur != 5) {
            dx = sx - dirX[5];
            dy = sy - dirY[5];
            if (func_800B1750(dx * dx + dy * dy) < 0.3f) {
                best = 0.0f;
                sel = 5;
            } else {
                for (i = 1; i < 5; i++) {
                    if (cur != i) {
                        dx = sx - dirX[i];
                        dy = sy - dirY[i];
                        d = func_800B1750(dx * dx + dy * dy);
                        if (d < best) {
                            best = d;
                            sel = i;
                        }
                    }
                }
            }
        } else {
            for (i = 1; i < 6; i++) {
                if (cur != i) {
                    dx = sx - dirX[i];
                    dy = sy - dirY[i];
                    d = func_800B1750(dx * dx + dy * dy);
                    if (d < best) {
                        best = d;
                        sel = i;
                    }
                }
            }
        }
        if (best < 0.5f) {
            PlaySound(0xF5);
            D_800F9941_GameModeOverworld = 1;
            cur = sel;
            pos.x = D_800F9A1C_GameModeOverworld[cur + 1].x;
            pos.y = D_800F9A1C_GameModeOverworld[cur + 1].y + 100.0f;
            pos.z = D_800F9A1C_GameModeOverworld[cur + 1].z;
            Convert3DTo2D(0, &pos, &scr);
            for (i = 1; i < 6; i++) {
                t = i / 5.0f;
                SetBasicSpritePos(spr & 0xFFFF, curX + (scr.x - curX) * t, curY + (scr.y - curY) * t);
                HuPrcVSleep();
            }
            curX = scr.x;
            curY = scr.y;
            SetBasicSpritePos(spr & 0xFFFF, curX, curY);
            D_800FA1E2_GameModeOverworld = cur;
            D_800F9941_GameModeOverworld = 0;
            for (i = 0; (s16)(func_800F8758_GameModeOverworld(D_800FA201_GameModeOverworld) / 10) != 0 ||
                        (s16)(func_800F87D0_GameModeOverworld(D_800FA201_GameModeOverworld) / 10) != 0;) {
                HuPrcVSleep();
                if (++i >= 10) {
                    break;
                }
            }
        }
    }
    i = 10;
    D_800FA200_GameModeOverworld = 0;
    do {
        HuPrcVSleep();
        t = i * 0.1f;
        SetBasicSpriteSize(spr & 0xFFFF, t, t);
        i--;
    } while (i >= 0);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_GameModeOverworld/2BB5F0", func_800F7E24_GameModeOverworld);
#endif
void func_800F86A8_GameModeOverworld(omObjData* arg0) {
    arg0->model[0] = -1;
    SetFadeInTypeAndTime(0xFF, 0x10);
    arg0->func_ptr = &func_800F86EC_GameModeOverworld;
}


void func_800F86EC_GameModeOverworld(void) {
    if (D_800FA1C0_GameModeOverworld == 4) {
        func_80070ED4();
        if (D_800FA1FC_GameModeOverworld == -1) {
            omOvlReturnEx(1);
            return;
        }
        omOvlCallEx(D_800FA1FC_GameModeOverworld, D_800FA202_GameModeOverworld, 0x11);
    }
}

s16 func_800F8758_GameModeOverworld(u8 arg0) {
    if ((ContBtn[arg0] & 0x300) == 0) {
        return ContStkX[arg0];
    }
    
    if ((ContBtn[arg0] & 0x200) != 0) {
        return -0x50;
    } else {
        return -((ContBtn[arg0] & 0x100) != 0) & 0x50;
    }
}

s16 func_800F87D0_GameModeOverworld(u8 arg0) {
    if ((ContBtn[arg0] & 0xC00) == 0) {
        return ContStkY[arg0];
    }
    
    if ((ContBtn[arg0] & 0x800) != 0) {
        return 0x50;
    } else {
        return -((ContBtn[arg0] & 0x400) != 0) & -0x50;
    }
}

void func_800F884C_GameModeOverworld(omObjData* arg0) {
    Vec3f sp10;
    Vec3f sp20;
    Vec3f sp30;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f24_2;


    temp_f22 = CRot.x;
    temp_f24 = CRot.y;
    temp_f20 = func_800AEAC0(temp_f24);
    sp10.x = Center.x + (temp_f20 * func_800AEFD0(temp_f22) * CZoom);
    sp10.y = (-func_800AEAC0(temp_f22) * CZoom) + Center.y;
    temp_f20_2 = func_800AEFD0(temp_f24);
    sp10.z = (temp_f20_2 * func_800AEFD0(temp_f22) * CZoom) + Center.z;
    sp20.x = Center.x;
    sp20.y = Center.y;
    sp20.z = Center.z;
    temp_f20_3 = func_800AEAC0(temp_f24);
    sp30.x = temp_f20_3 * func_800AEAC0(temp_f22);
    sp30.y = func_800AEFD0(temp_f22);
    temp_f20_4 = func_800AEFD0(temp_f24);
    sp30.z = temp_f20_4 * func_800AEAC0(temp_f22);
    func_8001D420(0, &sp10, &sp20, &sp30);
    func_8001D57C(0);
    temp_f22_2 = D_800FA1D0_GameModeOverworld.x;
    temp_f24_2 = D_800FA1D0_GameModeOverworld.y;
    temp_f20_5 = func_800AEAC0(temp_f24_2);
    sp10.x = D_800FA1C4_GameModeOverworld.x + (temp_f20_5 * func_800AEFD0(temp_f22_2) * D_800FA1DC_GameModeOverworld);
    sp10.y = (-func_800AEAC0(temp_f22_2) * D_800FA1DC_GameModeOverworld) + D_800FA1C4_GameModeOverworld.y;
    temp_f20_6 = func_800AEFD0(temp_f24_2);
    sp10.z = D_800FA1C4_GameModeOverworld.z + (temp_f20_6 * func_800AEFD0(temp_f22_2) * D_800FA1DC_GameModeOverworld);
    sp20.x = D_800FA1C4_GameModeOverworld.x;
    sp20.y = D_800FA1C4_GameModeOverworld.y;
    sp20.z = D_800FA1C4_GameModeOverworld.z;
    sp30.x = func_800AEAC0(temp_f24_2) * func_800AEAC0(temp_f22_2);
    sp30.y = func_800AEFD0(temp_f22_2);
    sp30.z = func_800AEFD0(temp_f24_2) * func_800AEAC0(temp_f22_2);
    func_8001D420(1, &sp10, &sp20, &sp30);
    func_8001D57C(1);
}

void func_800F8AB8_GameModeOverworld(omObjData* arg0) {
    if ((D_800FA1C0_GameModeOverworld == 4) || (D_800FA1C2_GameModeOverworld != 0) || (D_800F5144 != 0)) {
        func_800726AC(0, 0x14);
        arg0->func_ptr = &func_800F8B38_GameModeOverworld;
        if (D_800FA204_GameModeOverworld == 0) {
            func_800601D4(0x28);
        }
    }
}

void func_800F8B38_GameModeOverworld(void) {
    if (func_80072718() == 0) {
        func_80070ED4();
        if (D_800FA1FC_GameModeOverworld == -1) {
            omOvlReturnEx(1);
            return;
        }
        omOvlCallEx(D_800FA1FC_GameModeOverworld, D_800FA202_GameModeOverworld, 0x11);
    }
}

// scheduling of the index arithmetic (masked 31)
#ifdef NON_MATCHING
void func_800F8BA0_GameModeOverworld(OverworldCamKey* path, f32 speed) {
    f32 vals[4];
    f32 times[4];
    OverworldCamKey* prev;
    OverworldCamKey* k;
    f32 total;
    f32 end;
    f32 dx, dy, dz, d;
    f32 s;
    f32 ft;
    s16 i;
    s16 seg;
    s16 t;

    prev = NULL;
    total = 0.0f;
    i = 0;
    k = path;
    while (k->zoom != 0.0f) {
        s = func_800AEAC0(k->rot.y);
        k->pos.x = s * func_800AEFD0(k->rot.x) * k->zoom + k->center.x;
        k->pos.y = -func_800AEAC0(k->rot.x) * k->zoom + k->center.y;
        k->pos.z = func_800AEFD0(k->rot.y) * func_800AEFD0(k->rot.x) * k->zoom + k->center.z;
        if (i > 0) {
            dx = prev->pos.x - k->pos.x;
            dy = prev->pos.y - k->pos.y;
            dz = prev->pos.z - k->pos.z;
            d = func_800B1750(dx * dx + dy * dy + dz * dz);
            if (d == 0.0f) {
                d = speed * 10.0f;
            }
            total += d / speed;
            k->time = total;
        }
        prev = k;
        i++;
        k = &path[i];
    }
    end = total - 10.0f;
    seg = 1;
    for (t = 10; t < end; t++) {
        if (path[seg + 1].time < t) {
            seg++;
        }
        k = &path[seg];
        times[0] = k[-1].time;
        times[1] = k[0].time;
        times[2] = k[1].time;
        times[3] = k[2].time;
        ft = t;
        vals[0] = k[-1].center.x;
        vals[1] = k[0].center.x;
        vals[2] = k[1].center.x;
        vals[3] = k[2].center.x;
        Center.x = func_80022D9C(vals, times, ft);
        vals[0] = k[-1].center.y;
        vals[1] = k[0].center.y;
        vals[2] = k[1].center.y;
        vals[3] = k[2].center.y;
        Center.y = func_80022D9C(vals, times, ft);
        vals[0] = k[-1].center.z;
        vals[1] = k[0].center.z;
        vals[2] = k[1].center.z;
        vals[3] = k[2].center.z;
        Center.z = func_80022D9C(vals, times, ft);
        vals[0] = k[-1].rot.x;
        vals[1] = k[0].rot.x;
        vals[2] = k[1].rot.x;
        vals[3] = k[2].rot.x;
        CRot.x = func_80022D9C(vals, times, ft);
        vals[0] = k[-1].rot.y;
        vals[1] = k[0].rot.y;
        vals[2] = k[1].rot.y;
        vals[3] = k[2].rot.y;
        CRot.y = func_80022D9C(vals, times, ft);
        vals[0] = k[-1].rot.z;
        vals[1] = k[0].rot.z;
        vals[2] = k[1].rot.z;
        vals[3] = k[2].rot.z;
        CRot.z = func_80022D9C(vals, times, ft);
        vals[0] = k[-1].zoom;
        vals[1] = k[0].zoom;
        vals[2] = k[1].zoom;
        vals[3] = k[2].zoom;
        CZoom = func_80022D9C(vals, times, ft);
        HuPrcVSleep();
    }
    k = &path[(s16)(seg + 1)];
    CRot.x = k->rot.x;
    CRot.y = k->rot.y;
    CRot.z = k->rot.z;
    CZoom = k->zoom;
    Center.x = k->center.x;
    Center.y = k->center.y;
    Center.z = k->center.z;
    D_800ECC22 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_GameModeOverworld/2BB5F0", func_800F8BA0_GameModeOverworld);
#endif
// loop layout and scheduling (masked 56)
#ifdef NON_MATCHING
void func_800F907C_GameModeOverworld(void) {
    Vec2f* pts;
    Vec2f* tgt;
    f32 x, z, sx, sz, dx, dz, d;
    f32 px, pz;
    f32 lastX, lastZ;
    f32 a, b;
    f32 ang;
    s16 bird;
    u16 shadow;
    s16 idx;

    idx = 0;
    pts = HuPrcCurrentGet()->user_data;
    bird = LoadFormFile(0x120006, 0x299);
    func_80025F10(bird, 1);
    func_80025830(bird, 0.8f, 0.8f, 0.8f);
    func_80025EB4(bird, 2, 2);
    D_800F2B7C[bird].unk_4C = 2.0f;
    shadow = LoadFormFile(6, 0x299);
    func_80025830(shadow, 0.5f, 0.5f, 0.5f);
    func_80025F10(shadow, 1);
    x = pts[0].x;
    z = pts[0].y;
    lastZ = 0.0f;
    a = rand8();
    lastX = 0.0f;
    b = rand8();
    while (1) {
        tgt = &pts[idx + 1];
        dx = tgt->x - x;
        dz = tgt->y - z;
        d = func_800B1750(dx * dx + dz * dz);
        sx = dx / d * 3.0f;
        sz = dz / d * 3.0f;
        x += sx;
        while (1) {
            z += sz;
            px = x + func_800AEAC0(a) * 20.0f;
            pz = z + func_800AEFD0(a) * 20.0f;
            func_80025798(bird, px, func_800AEAC0(b) * 20.0f + 100.0f, pz);
            func_80025798(shadow, px, 0.0f, pz);
            dx = x - pts[idx + 1].x;
            dz = z - pts[idx + 1].y;
            if (func_800B1750(dx * dx + dz * dz) <= 3.0f) {
                break;
            }
            if ((lastX != px) | (lastZ != pz)) {
                ang = func_800B0CD8(lastX - px, lastZ - pz);
            }
            func_800257E4(bird, 0.0f, ang, 0.0f);
            lastX = px;
            lastZ = pz;
            a += 5.0f;
            b += 10.0f;
            HuPrcVSleep();
            x += sx;
        }
        idx++;
        if (pts[idx + 1].x == 0.0f && pts[idx + 1].y == 0.0f) {
            idx = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_GameModeOverworld/2BB5F0", func_800F907C_GameModeOverworld);
#endif
// loop layout and scheduling (masked 40)
#ifdef NON_MATCHING
void func_800F9474_GameModeOverworld(void) {
    Vec2f* pts;
    Vec2f* tgt;
    f32 x, z, ux, uz, dx, dz, d;
    f32 lastX, lastZ;
    f32 phase, step, amp;
    f32 ang;
    s16 fish;
    u16 pos;
    u16 dir;

    lastZ = 0.0f;
    pts = HuPrcCurrentGet()->user_data;
    fish = LoadFormFile(0x90022, 0x299);
    func_80025F10(fish, 1);
    func_80025EB4(fish, 2, 2);
    pos = D_800FA15C_GameModeOverworld[D_800FA158_GameModeOverworld][0];
    dir = D_800FA15C_GameModeOverworld[D_800FA158_GameModeOverworld][1];
    D_800FA158_GameModeOverworld++;
    x = pts[(s16)pos].x;
    z = pts[(s16)pos].y;
    lastX = 0.0f;
    phase = ((rand8() & 0xFF) * 45) >> 6;
    step = 15.0f;
    amp = (rand8() & 0xFF) * 21.0f / 256.0f + 9.0f;
    while (1) {
        rand8();
        tgt = &pts[(s16)pos + (s16)dir];
        rand8();
        dx = tgt->x - x;
        dz = tgt->y - z;
        d = func_800B1750(dx * dx + dz * dz);
        ux = dx / d;
        uz = dz / d;
        while (1) {
            x += ux * (func_800AEAC0(phase) * amp + 10.0f);
            z += uz * (func_800AEAC0(phase) * amp + 10.0f);
            func_80025798(fish, x, -300.0f, z);
            dx = x - pts[(s16)pos + (s16)dir].x;
            dz = z - pts[(s16)pos + (s16)dir].y;
            if (func_800B1750(dx * dx + dz * dz) <= 40.0f) {
                break;
            }
            if ((lastX != x) | (lastZ != z)) {
                ang = func_800B0CD8(lastX - x, lastZ - z);
            }
            func_800257E4(fish, 0.0f, ang + 180.0f, 0.0f);
            lastX = x;
            lastZ = z;
            phase += step;
            if (phase == 90.0f) {
                amp *= 0.5f;
                step = 5.0f;
                D_800F2B7C[fish].unk_4C = 1.0f;
            }
            if (phase >= 180.0f) {
                step = 15.0f;
                phase = 0.0f;
                amp = (rand8() & 0xFF) * 21.0f / 256.0f + 9.0f;
                D_800F2B7C[fish].unk_4C = 5.0f;
            }
            HuPrcVSleep();
        }
        pos += dir;
        if ((s16)pos == 0 || (pts[(s16)pos + (s16)dir].x == 0.0f && pts[(s16)pos + (s16)dir].y == 0.0f)) {
            dir = -dir;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_GameModeOverworld/2BB5F0", func_800F9474_GameModeOverworld);
#endif
