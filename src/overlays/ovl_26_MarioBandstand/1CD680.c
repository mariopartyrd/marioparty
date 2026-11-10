#include "1CCCF0.h"

int abs(int);

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

s32 D_800FCC00_MarioBandstand[3] = { 0x3A0017, 0x3A0018, 0x3A0019 };
s32 D_800FCC0C_MarioBandstand[5] = { 0x2E0001, 0x11, 0x0, 0x0, 0x0 };
Vec D_800FCC20_MarioBandstand[4] = { { 0.0f, 54.5f, 225.0f }, { 0.0f, 120.0f, -300.0f }, { -200.0f, 80.0f, -147.0f }, { 200.0f, 80.0f, -147.0f } };
s32 D_800FCC50_MarioBandstand[4] = { 0x3A000B, 0x3A0002, 0x3A000A, 0x3A0005 };
s32 D_800FCC60_MarioBandstand[3][3] = { { 0x3A000E, 0x3A000F, 0x3A0010 }, { 0x3A0011, 0x3A0012, 0x3A0013 }, { 0x3A0014, 0x3A0015, 0x3A0016 } };
Vec D_800FCC84_MarioBandstand[3][2] = { { { -100.0f, 120.0f, -300.0f }, { 100.0f, 120.0f, -300.0f } }, { { -300.0f, 40.0f, 0.0f }, { -100.0f, 40.0f, 0.0f } }, { { 300.0f, 40.0f, 0.0f }, { 100.0f, 40.0f, 0.0f } } };
s16 D_800FCCCC_MarioBandstand[4] = { 0, 1, 2, 3 };
u8 D_800FCCD4_MarioBandstand[4][6] = { { 0x02, 0x10, 0x20, 0x70, 0x60, 0x10 }, { 0x01, 0x08, 0x20, 0x80, 0x70, 0x20 }, { 0x00, 0x03, 0x10, 0x90, 0x80, 0x30 }, { 0x00, 0x03, 0x10, 0xA0, 0x90, 0x40 } };
u8 D_800FCCEC_MarioBandstand[4] = { 0 }; /* unreferenced filler (retail pads the table above) */
s8 D_800FCCF0_MarioBandstand[12] = { 0, 2, 1, 3, 0, 2, 3, 1, 0, 3, 2, 1 };
s8 D_800FCCFC_MarioBandstand[12] = { 0, 1, 2, 3, 0, 3, 2, 1, 0, 2, 1, 3 };
s8 D_800FCD08_MarioBandstand[12] = { 0, 3, 1, 2, 0, 1, 3, 2, 0, 1, 2, 3 };
s8 D_800FCD14_MarioBandstand[32] = { -1, -1, -1, -1, -1, 0, 1, 2, 3, -1, -1, -1, -1, 4, 5, 6, 7, -1, -1, -1, -1, 8, 9, 10, 11, -1, -1, -1, -1, 0, 0, 0 };
MBBeat D_800FCD34_MarioBandstand[12] = { { 5, 0 }, { 6, 1 }, { 7, 2 }, { 8, 3 }, { 13, 4 }, { 14, 5 }, { 15, 6 }, { 16, 7 }, { 21, 8 }, { 22, 9 }, { 23, 10 }, { 24, 11 } };
u8 D_800FCD64_MarioBandstand[8] = { 0x04, 0x1E, 0x0C, 0x1E, 0x14, 0x1E, 0x00, 0x00 };
u8 D_800FCD6C_MarioBandstand[8] = { 0x04, 0x1E, 0x0F, 0x1E, 0x1D, 0x1E, 0x00, 0x00 };
u8 D_800FCD74_MarioBandstand[8] = { 0x04, 0x1E, 0x0F, 0x1E, 0x1C, 0x1E, 0x00, 0x00 };
u8 D_800FCD7C_MarioBandstand[8] = { 0x04, 0x1E, 0x0D, 0x1E, 0x18, 0x1E, 0x00, 0x00 };
u8 D_800FCD84_MarioBandstand[4] = { 0x01, 0x09, 0x11, 0x00 };
u8 D_800FCD88_MarioBandstand[4] = { 0x01, 0x09, 0x17, 0x00 };
u8 D_800FCD8C_MarioBandstand[4] = { 0x01, 0x09, 0x17, 0x00 };
u8 D_800FCD90_MarioBandstand[4] = { 0x01, 0x09, 0x13, 0x00 };
MBLoop D_800FCD94_MarioBandstand[4] = { { D_800FCD84_MarioBandstand, D_800FCD64_MarioBandstand }, { D_800FCD88_MarioBandstand, D_800FCD6C_MarioBandstand }, { D_800FCD8C_MarioBandstand, D_800FCD74_MarioBandstand }, { D_800FCD90_MarioBandstand, D_800FCD7C_MarioBandstand } };
MBBeat D_800FCDB4_MarioBandstand[18] = { { 5, 919 }, { 6, 921 }, { 7, 922 }, { 8, 926 }, { 16, 927 }, { 17, 928 }, { 18, 929 }, { 19, 930 }, { 20, 931 }, { 21, 932 }, { 22, 933 }, { 30, 936 }, { 31, 937 }, { 32, 938 }, { 33, 939 }, { 34, 940 }, { 35, 941 }, { 36, 942 } };
MBBeat D_800FCDFC_MarioBandstand[17] = { { 5, 898 }, { 6, 899 }, { 7, 900 }, { 8, 902 }, { 16, 903 }, { 17, 904 }, { 18, 905 }, { 19, 906 }, { 20, 907 }, { 21, 908 }, { 22, 909 }, { 29, 910 }, { 30, 911 }, { 31, 913 }, { 32, 916 }, { 33, 917 }, { 34, 918 } };
MBBeat D_800FCE40_MarioBandstand[15] = { { 5, 874 }, { 6, 876 }, { 7, 878 }, { 8, 880 }, { 14, 881 }, { 15, 883 }, { 16, 885 }, { 17, 886 }, { 18, 887 }, { 25, 888 }, { 26, 889 }, { 27, 890 }, { 28, 893 }, { 29, 896 }, { 30, 897 } };
MBSong D_800FCE7C_MarioBandstand[4] = { { D_800FCD34_MarioBandstand, 12 }, { D_800FCDB4_MarioBandstand, 18 }, { D_800FCDFC_MarioBandstand, 17 }, { D_800FCE40_MarioBandstand, 15 } };
u8 D_800FCE9C_MarioBandstand[8] = { 0x04, 0x1E, 0x0D, 0x1E, 0x19, 0x1E, 0x00, 0x00 };
u8 D_800FCEA4_MarioBandstand[8] = { 0x04, 0x1E, 0x0D, 0x1E, 0x19, 0x1E, 0x00, 0x00 };
u8 D_800FCEAC_MarioBandstand[8] = { 0x04, 0x1E, 0x0D, 0x1E, 0x19, 0x1E, 0x00, 0x00 };
u8 D_800FCEB4_MarioBandstand[4] = { 0x01, 0x09, 0x13, 0x00 };
u8 D_800FCEB8_MarioBandstand[4] = { 0x01, 0x09, 0x13, 0x00 };
u8 D_800FCEBC_MarioBandstand[4] = { 0x01, 0x09, 0x13, 0x00 };
MBLoop D_800FCEC0_MarioBandstand[4] = { { D_800FCD84_MarioBandstand, D_800FCD64_MarioBandstand }, { D_800FCEB4_MarioBandstand, D_800FCE9C_MarioBandstand }, { D_800FCEB8_MarioBandstand, D_800FCEA4_MarioBandstand }, { D_800FCEBC_MarioBandstand, D_800FCEAC_MarioBandstand } };
MBBeat D_800FCEE0_MarioBandstand[16] = { { 5, 984 }, { 6, 986 }, { 7, 987 }, { 8, 988 }, { 14, 989 }, { 15, 990 }, { 16, 991 }, { 17, 992 }, { 18, 993 }, { 26, 994 }, { 27, 995 }, { 28, 996 }, { 29, 997 }, { 30, 998 }, { 31, 999 }, { 32, 1000 } };
MBBeat D_800FCF20_MarioBandstand[16] = { { 5, 968 }, { 6, 969 }, { 7, 970 }, { 8, 971 }, { 14, 972 }, { 15, 973 }, { 16, 974 }, { 17, 975 }, { 18, 976 }, { 26, 977 }, { 27, 978 }, { 28, 979 }, { 29, 980 }, { 30, 981 }, { 31, 982 }, { 32, 983 } };
MBBeat D_800FCF60_MarioBandstand[16] = { { 5, 945 }, { 6, 947 }, { 7, 949 }, { 8, 950 }, { 14, 951 }, { 15, 952 }, { 16, 954 }, { 17, 955 }, { 18, 956 }, { 26, 957 }, { 27, 959 }, { 28, 961 }, { 29, 963 }, { 30, 965 }, { 31, 966 }, { 32, 967 } };
MBSong D_800FCFA0_MarioBandstand[4] = { { D_800FCD34_MarioBandstand, 12 }, { D_800FCEE0_MarioBandstand, 16 }, { D_800FCF20_MarioBandstand, 16 }, { D_800FCF60_MarioBandstand, 16 } };
u8 D_800FCFC0_MarioBandstand[4] = { 0x01, 0x07, 0x19, 0x1E };
u8 D_800FCFC4_MarioBandstand[8] = { 0x04, 0x1E, 0x0D, 0x1E, 0x16, 0x1E, 0x00, 0x00 };
u8 D_800FCFCC_MarioBandstand[8] = { 0x06, 0x1E, 0x12, 0x1E, 0x1E, 0x1E, 0x00, 0x00 };
u8 D_800FCFD4_MarioBandstand[8] = { 0x05, 0x1E, 0x11, 0x1E, 0x1D, 0x1E, 0x00, 0x00 };
u8 D_800FCFDC_MarioBandstand[4] = { 0x01, 0x09, 0x13, 0x00 };
u8 D_800FCFE0_MarioBandstand[4] = { 0x01, 0x0D, 0x19, 0x00 };
u8 D_800FCFE4_MarioBandstand[4] = { 0x01, 0x0B, 0x19, 0x00 };
MBLoop D_800FCFE8_MarioBandstand[4] = { { D_800FCD84_MarioBandstand, D_800FCD64_MarioBandstand }, { D_800FCFDC_MarioBandstand, D_800FCFC4_MarioBandstand }, { D_800FCFE0_MarioBandstand, D_800FCFCC_MarioBandstand }, { D_800FCFE4_MarioBandstand, D_800FCFD4_MarioBandstand } };
MBBeat D_800FD008_MarioBandstand[13] = { { 5, 1033 }, { 6, 1035 }, { 7, 1036 }, { 8, 1037 }, { 14, 1038 }, { 15, 1039 }, { 16, 1040 }, { 17, 1041 }, { 18, 1042 }, { 23, 1044 }, { 24, 1045 }, { 25, 1048 }, { 26, 1049 } };
MBBeat D_800FD03C_MarioBandstand[18] = { { 7, 0 }, { 8, 1018 }, { 9, 1019 }, { 10, 1020 }, { 11, 1021 }, { 12, 1022 }, { 19, 1023 }, { 20, 1024 }, { 21, 1025 }, { 22, 1026 }, { 23, 1027 }, { 24, 1028 }, { 31, 0 }, { 32, 1029 }, { 33, 1030 }, { 34, 0 }, { 35, 1031 }, { 36, 1032 } };
MBBeat D_800FD084_MarioBandstand[17] = { { 6, 1001 }, { 7, 1002 }, { 8, 1003 }, { 9, 1004 }, { 10, 1005 }, { 18, 1006 }, { 19, 1007 }, { 20, 1008 }, { 21, 1009 }, { 22, 1010 }, { 23, 1011 }, { 24, 1012 }, { 30, 1013 }, { 31, 1014 }, { 32, 1015 }, { 33, 1016 }, { 34, 1017 } };
MBSong D_800FD0C8_MarioBandstand[4] = { { D_800FCD34_MarioBandstand, 12 }, { D_800FD008_MarioBandstand, 13 }, { D_800FD03C_MarioBandstand, 18 }, { D_800FD084_MarioBandstand, 17 } };
s32 D_800FD0E8_MarioBandstand = 0;
s16 D_800FD0EC_MarioBandstand[5][2] = { { 56, 28 }, { 36, 48 }, { 56, 68 }, { 76, 48 }, { 56, 48 } };
s16 D_800FD100_MarioBandstand[5][2] = { { 56, 26 }, { 34, 48 }, { 56, 70 }, { 78, 48 }, { 56, 48 } };
s32 D_800FD114_MarioBandstand[5] = { 0x3A0024, 0x3A0021, 0x3A0022, 0x3A0023, 0x3A0025 };
s32 D_800FD128_MarioBandstand[6] = { 0x3A001B, 0x3A001C, 0x3A001D, 0x3A001E, 0x3A001F, 0x3A0020 };
s16 D_800FD140_MarioBandstand[4][2] = { { 76, 68 }, { 40, 182 }, { 40, 199 }, { 40, 216 } };
s16 D_800FD150_MarioBandstand[4] = { 182, 199, 216, 0 };
s16 D_800FD158_MarioBandstand[4] = { -1, 1, 2, 3 };
s16 D_800FD160_MarioBandstand[4] = { -1, 1, 2, 3 };
f32 D_800FD168_MarioBandstand = 56.0f;
f32 D_800FD16C_MarioBandstand = 48.0f;
u8 D_800FD170_MarioBandstand[32] = { 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x01, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* ---------------------------------------------------------------------------------------------
   Stage props and the round's lights
   --------------------------------------------------------------------------------------------- */

void func_800F6F70_MarioBandstand(void) {
    D_800FD2A0_MarioBandstand = 0.0f;
    D_800FD2A4_MarioBandstand = -0.01f;
    D_800FD2B8_MarioBandstand = 0;
    D_800FD2D0_MarioBandstand = 0;
    D_800FD708_MarioBandstand = omAddObj(4, 0x2A, 0, -1, func_800F74C8_MarioBandstand);
    D_800FD718_MarioBandstand = omAddObj(8, 0x1C, 0, -1, func_800F8940_MarioBandstand);
}

// NON_MATCHING: retail sign-extends sound before PlaySound (2 instructions short, masked 8); tried s32 sound, (s16) cast, sound reused for the handle (M1c)
#ifdef NON_MATCHING
void func_800F7000_MarioBandstand(void) {
    s16 sound;
    s16 handle;

    if (func_800FC8A8_MarioBandstand(0x4000) == 0) {
        sound = 0x2E0;
        if (D_800FD2B8_MarioBandstand != 0) {
            sound = 0x2DF;
        }
        D_800FD2B8_MarioBandstand ^= 1;
        handle = PlaySound(sound);
        if (handle >= 0) {
            func_80060440(handle, (func_800FCAAC_MarioBandstand() & 0x1FF) - 0x100);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F7000_MarioBandstand);
#endif

// NON_MATCHING: masked 31 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
s16 func_800F7090_MarioBandstand(omObjData* obj, s16 slot) {
    s16 px[16];
    s16 pz[16];
    MBProp* p;
    s32 i;
    s32 j;
    s16 n;
    s32 x;
    s32 z;
    s16 k;
    u32 r;
    s16 model;
    s16 tmp;

    D_800FD51A_MarioBandstand = slot;
    for (i = 0; i < 5; i++) {
        px[i] = 0;
        px[i + 5] = 1;
        px[i + 10] = 2;
    }
    px[15] = func_800FCAAC_MarioBandstand() & 1;
    i = 0x40;
    do {
        i--;
        r = func_800FCAAC_MarioBandstand();
        x = r & 0xF;
        z = (r >> 12) & 0xF;
        tmp = px[x];
        px[x] = px[z];
        px[z] = tmp;
    } while (i != 0);

    p = D_800FD2D8_MarioBandstand;
    for (i = 0; i < 16; i++, p++) {
        k = px[i];
        p->unk2 = func_800FCAD4_MarioBandstand(obj, D_800FCC00_MarioBandstand[k], 0x289, 8, slot, k);
        model = obj->model[slot];
        p->model = model;
        if (k == 2) {
            func_80025830(model, 3.5f, 3.5f, 3.5f);
        } else {
            func_80025830(model, 2.5f, 2.5f, 2.5f);
        }
        slot++;
        p->state = 0;
    }

    n = 0;
    do {
        r = func_800FCAAC_MarioBandstand();
        x = r & 7;
        z = (r >> 7) % 3;
        for (j = 0; j < n; j++) {
            if (px[j] == x && pz[j] == z) {
                break;
            }
        }
        if (j >= n) {
            px[n] = x;
            pz[n] = z;
            n++;
        }
    } while (n < 16);

    p = D_800FD2D8_MarioBandstand;
    for (i = 0; i < 16; i++, p++) {
        p->x = px[i] * 140 - 490;
        p->y = -65;
        p->z = pz[i] * 100 + 460;
        func_80025798(p->model, p->x, p->y, p->z);
    }
    /* Retail clears the offsets one past the last prop (the first coin's vel.y on the N64). */
    p->dx = 0;
    p->dy = 0;
    D_800FD51C_MarioBandstand = slot;
    return slot;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F7090_MarioBandstand);
#endif

void func_800F73E8_MarioBandstand(void) {
    omObjData* obj = D_800FD708_MarioBandstand;
    s32 i;

    if (obj != NULL) {
        for (i = D_800FD51A_MarioBandstand; i < D_800FD51C_MarioBandstand; i++) {
            func_800258EC(obj->model[i], 4, 0);
        }
    }
}

void func_800F7458_MarioBandstand(void) {
    omObjData* obj = D_800FD708_MarioBandstand;
    s32 i;

    if (obj != NULL) {
        for (i = D_800FD51A_MarioBandstand; i < D_800FD51C_MarioBandstand; i++) {
            func_800258EC(obj->model[i], 4, 4);
        }
    }
}

// NON_MATCHING: masked 55 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F74C8_MarioBandstand(omObjData* obj) {
    s32 i;
    s16 m;
    s16 (*light)[2];

    D_800FD518_MarioBandstand = 0;
    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = -1;
    }
    obj->model[0] = func_800174C0(0x3A0000, 0x299);
    obj->model[1] = D_800FD2A8_MarioBandstand[3][0] = func_800174C0(0x3A0001, 0x299);
    func_80025798(D_800FD2A8_MarioBandstand[3][0], 0.0f, 580.0f, 360.0f);
    obj->model[2] = D_800FD2A8_MarioBandstand[2][0] = func_800174C0(0x3A0006, 0x299);
    func_80025798(D_800FD2A8_MarioBandstand[2][0], -600.0f, 0.0f, 380.0f);
    obj->model[3] = D_800FD2A8_MarioBandstand[2][1] = m = func_80023FC8(D_800FD2A8_MarioBandstand[2][0]);
    func_80025798(m, 600.0f, 0.0f, 380.0f);
    light = D_800FD2A8_MarioBandstand;
    obj->model[4] = light[0][0] = func_800174C0(0x14000E, 0x699);
    obj->model[5] = light[0][1] = func_800174C0(0x14000F, 0x699);
    func_80026040(light[0][0]);
    func_800258EC(light[0][1], 4, 4);
    func_80026174(light[0][0], light[0][1], D_800FD2A0_MarioBandstand);
    func_800257E4(light[0][0], 0.0f, 180.0f, 0.0f);
    func_80025798(light[0][0], -500.0f, 0.0f, 330.0f);
    obj->model[6] = light[1][0] = m = func_80023FC8(D_800FD2A8_MarioBandstand[0][0]);
    obj->model[7] = light[1][1] = func_80023FC8(D_800FD2A8_MarioBandstand[0][1]);
    func_80026040(m);
    func_800258EC(light[1][1], 4, 4);
    func_80026174(m, light[1][1], D_800FD2A0_MarioBandstand);
    func_80025798(m, 500.0f, 0.0f, 330.0f);
    D_800FD51E_MarioBandstand = func_800F7090_MarioBandstand(obj, 8);
    obj->func_ptr = func_800F7760_MarioBandstand;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F74C8_MarioBandstand);
#endif

// NON_MATCHING: masked 72 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F7760_MarioBandstand(omObjData* obj) {
    MBProp* p;
    f32 t;
    s32 i;
    s32 moved;

    if (D_800FD2A4_MarioBandstand != 0.0f) {
        t = D_800FD2A0_MarioBandstand;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        func_80026174(D_800FD2A8_MarioBandstand[0][0], D_800FD2A8_MarioBandstand[0][1], t);
        func_80026174(D_800FD2A8_MarioBandstand[1][0], D_800FD2A8_MarioBandstand[1][1], t);
        D_800FD2A0_MarioBandstand += D_800FD2A4_MarioBandstand;
        if (D_800FD2A0_MarioBandstand > 1.04f) {
            D_800FD2A0_MarioBandstand = 1.0f;
            D_800FD2A4_MarioBandstand = 0.0f;
        } else if (D_800FD2A0_MarioBandstand < -0.04f) {
            D_800FD2A0_MarioBandstand = 0.0f;
            D_800FD2A4_MarioBandstand = 0.0f;
        }
    }

    p = D_800FD2D8_MarioBandstand;
    for (i = 0; i < 16; i++, p++) {
        moved = 0;
        switch ((s16)(p->state - 1)) {
        case 0:
        start2:
            p->sub = 0;
            p->timer = (func_800FCAAC_MarioBandstand() & 3) + 1;
            p->state = 2;
            break;
        case 1:
            p->timer--;
            switch (p->sub) {
            case 0:
                if ((s16)p->timer == 0) {
                    p->timer = 4;
                    p->sub = 1;
                }
                break;
            case 1:
                if ((s16)p->timer == 0) {
                    p->timer = 4;
                    p->sub = 2;
                } else {
                    p->dy += 3;
                    moved = 1;
                }
                break;
            case 2:
                if ((s16)p->timer == 0) {
                    p->timer = 4;
                    p->sub = 1;
                } else {
                    p->dy -= 3;
                    moved = 1;
                }
                break;
            }
            break;
        case 2:
        start4:
            p->sub = 0;
            p->timer = (func_800FCAAC_MarioBandstand() & 7) + 1;
            p->state = 4;
            break;
        case 3:
            p->timer--;
            switch (p->sub) {
            case 0:
                if ((s16)p->timer == 0) {
                    p->timer = 5;
                    p->sub = 1;
                }
                break;
            case 1:
                if ((s16)p->timer == 0) {
                    p->timer = 10;
                    p->sub = 2;
                } else {
                    p->dx++;
                    moved = 1;
                }
                break;
            case 2:
                if ((s16)p->timer != 0) {
                    p->dx--;
                    moved = 1;
                } else {
                    p->timer = 10;
                    p->sub = 1;
                }
                break;
            }
            break;
        case 4:
            if ((s16)p->dx == 0 && (s16)p->dy == 0) {
                p->state = 0;
                break;
            }
            if ((s16)p->dx < 0) {
                p->dx = (s16)p->dx + 1;
            } else if ((s16)p->dx > 0) {
                p->dx = (s16)p->dx - 1;
            }
            if ((s16)p->dy < 0) {
                p->dy = (s16)p->dy + 1;
            } else if ((s16)p->dy > 0) {
                p->dy = (s16)p->dy - 1;
            }
            moved = 1;
            break;
        case 5:
            if (rand8() & 1) {
                goto start2;
            }
            goto start4;
        }
        if (moved) {
            func_80025798(p->model, p->x + (s16)p->dx, p->y + (s16)p->dy, p->z);
        }
    }
    func_800F87EC_MarioBandstand(obj);
    func_800F7F7C_MarioBandstand(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F7760_MarioBandstand);
#endif

void func_800F7B88_MarioBandstand(s32 state) {
    MBProp* p;
    s32 i;

    p = D_800FD2D8_MarioBandstand;
    for (i = 0; i < 16; i++, p++) {
        p->state = state;
    }
    if (state == 6) {
        for (i = (func_800FCAAC_MarioBandstand() & 3) + 3; i != 0; i--) {
            func_800F9430_MarioBandstand(0.0f, 0.0f, 0.0f, 1);
        }
    }
}

// NON_MATCHING: masked 24 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F7C1C_MarioBandstand(s32 cmd) {
    s32 i;

    switch (cmd) {
    case 0:
        D_800FD2A4_MarioBandstand = -0.01f;
        break;
    case 1:
        D_800FD2A4_MarioBandstand = 0.01f;
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            func_800258EC(D_800FD2A8_MarioBandstand[i][0], 4, 4);
        }
        func_800258EC(D_800FD2A8_MarioBandstand[2][1], 4, 4);
    case 4:
        func_800F7458_MarioBandstand();
        break;
    case 3:
        for (i = 0; i < 4; i++) {
            func_800258EC(D_800FD2A8_MarioBandstand[i][0], 4, 0);
        }
        func_800258EC(D_800FD2A8_MarioBandstand[2][1], 4, 0);
        func_800F73E8_MarioBandstand();
        break;
    }
    if (cmd >= 100) {
        func_800F7B88_MarioBandstand(cmd - 100);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F7C1C_MarioBandstand);
#endif

/* Ranks the players by score (lowest first), pays the best 10 coins each; returns half the
   rounded score total. */
// NON_MATCHING: masked 56 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
s32 func_800F7D58_MarioBandstand(void) {
    f32 total;
    f32 best;
    f32 score;
    s32 n;
    s32 i;
    MBPlayerWork* w;

    total = 0.0f;
    n = 0;
    best = 32767.0f;
    for (i = 0; i < 4; i++) {
        w = D_800FD6D0_MarioBandstand[i]->unk_50;
        score = (s32)(2.0f * ((f32)w->unk_E4->score / D_800FD70C_MarioBandstand[D_800FD6D0_MarioBandstand[i]->work[0]]) + 0.5f);
        total += score;
        if (score < best) {
            best = score;
            D_800FD520_MarioBandstand.id[0] = i;
            n = 1;
        } else if (best == score) {
            D_800FD520_MarioBandstand.id[n] = i;
            n++;
        }
    }
    best /= 2.0f;
    total /= 2.0f;
    for (i = n; i < 4; i++) {
        D_800FD520_MarioBandstand.id[i] = -1;
    }
    if ((n == 4) & (best >= 10.0f)) {
        for (i = 0; i < 4; i++) {
            D_800FD520_MarioBandstand.id[i] = -1;
        }
        n = 0;
    }
    D_800FD520_MarioBandstand.count = n;
    for (i = 0; i < n; i++) {
        w = D_800FD6D0_MarioBandstand[D_800FD520_MarioBandstand.id[i]]->unk_50;
        GwPlayer[w->unk_58].coins_mg += 10;
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F7D58_MarioBandstand);
#endif

void func_800F7F7C_MarioBandstand(omObjData* obj) {
    f32 s;
    s32 i;

    if (D_800FD2D0_MarioBandstand != 0) {
        D_800FD2CC_MarioBandstand += 0.065;
        if (D_800FD2CC_MarioBandstand > 1.0f) {
            D_800FD2D0_MarioBandstand = 0;
            return;
        }
        s = D_800FD2CC_MarioBandstand * 0.8f;
        for (i = 0; i < 4; i++) {
            if (D_800FD2BC_MarioBandstand[i] >= 0) {
                func_80025830(D_800FD2BC_MarioBandstand[i], D_800FD2CC_MarioBandstand, 0.6f, D_800FD2CC_MarioBandstand);
                func_80025830(D_800FD2C4_MarioBandstand[i], s, 0.6f, s);
            }
        }
    }
}

/* Recolours the crown model's vertices and brightens its "18mt000_IA44" texture (IA4: doubles
   each intensity nibble). */
// NON_MATCHING: masked 30 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F80B0_MarioBandstand(s16 model) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    s16 count = m->unk_76;
    unk2C0C0Struct70* tex;
    u8* p;
    s32 i;
    s32 size;
    u32 v;

    for (i = 0; i < count; i++) {
        m->unk_A8[i].unk_01 = 0xFB;
        m->unk_A8[i].unk_05.r = 0xFB;
        m->unk_A8[i].unk_02 = 0xFF;
        m->unk_A8[i].unk_05.g = 0xFF;
        m->unk_A8[i].unk_03 = 0x8E;
        m->unk_A8[i].unk_05.b = 0x8E;
        m->unk_A8[i].unk_0D = 0xFF;
    }
    tex = func_80038178(m, (u8*)"18mt000_IA44");
    if (tex != NULL) {
        size = tex->unk_1A * tex->unk_1B;
        p = tex->unk_24;
        if ((*(u32*)&tex->unk_18 & 0xFFFF0000) == 0x03010000) {
            for (i = 0; i < size; i++, p++) {
                v = (*p & 0xF) * 2;
                if (v >= 0x10) {
                    v = 0xF;
                }
                *p = v | (*p & 0xF0);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F80B0_MarioBandstand);
#endif

// NON_MATCHING: masked 35 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
s16 func_800F81C0_MarioBandstand(s32 cmd) {
    u16 chr[4];
    omObjData* obj;
    omObjData* player;
    s32 i;
    u16 slot;
    u16 m;
    s16 m2;
    f32 s;

    if (cmd == 0) {
        D_800FD2CC_MarioBandstand = 0.025f;
        obj = D_800FD708_MarioBandstand;
        if (obj == NULL) {
            return 0;
        }
        func_800F92B4_MarioBandstand(D_800FD718_MarioBandstand);
        if (D_800FD520_MarioBandstand.count == 0) {
            return 0;
        }
        slot = D_800FD51E_MarioBandstand;
        for (i = 0; i < D_800FD520_MarioBandstand.count; i++) {
            D_800FD2D0_MarioBandstand = 1;
            if (i == 0) {
                m = LoadFormFile(0x210001, 0x289);
                func_800F80B0_MarioBandstand(m);
                func_80025AD4(m);
            } else {
                m = func_80023FC8(D_800FD2BC_MarioBandstand[0]);
            }
            D_800FD2BC_MarioBandstand[i] = m;
            obj->model[(s16)slot++] = m;
            player = D_800FD6D0_MarioBandstand[D_800FD520_MarioBandstand.id[i]];
            func_80025830(m, D_800FD2CC_MarioBandstand, 0.6f, D_800FD2CC_MarioBandstand);
            if (player->work[0] != 0) {
                func_80025798(m, player->trans.x, player->trans.y + 5.0f, player->trans.z);
            } else {
                func_80025798(m, player->trans.x, 5.0f, player->trans.z);
            }
            m2 = func_80023FC8(D_800FD2BC_MarioBandstand[0]);
            D_800FD2C4_MarioBandstand[i] = m2;
            obj->model[(s16)slot++] = m2;
            s = D_800FD2CC_MarioBandstand * 0.8f;
            func_80025830(m2, s, 0.6f, s);
            if (player->work[0] != 0) {
                func_80025798(m2, player->trans.x, player->trans.y + 5.0f, player->trans.z);
            } else {
                func_80025798(m2, player->trans.x, 5.0f, player->trans.z);
            }
        }
        for (; i < 4; i++) {
            D_800FD2BC_MarioBandstand[i] = -1;
        }
        D_800FD51E_MarioBandstand = slot;
        func_800F853C_MarioBandstand();
    } else if (cmd == 1) {
        for (i = 0; i < D_800FD520_MarioBandstand.count; i++) {
            chr[i] = D_800FD700_MarioBandstand[D_800FD6D0_MarioBandstand[D_800FD520_MarioBandstand.id[i]]->work[0]];
        }
        if (D_800FD520_MarioBandstand.count == 1 && _CheckFlag(0x2B) == 0) {
            GMesCreate(4, chr[0]);
        }
    }
    return D_800FD520_MarioBandstand.count;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F81C0_MarioBandstand);
#endif

// NON_MATCHING: register allocation, retail masks func_800FCAAC's result into a0 (raw 5, masked 0); tried u32 k (M1c)
#ifdef NON_MATCHING
void func_800F853C_MarioBandstand(void) {
    s16 who[8];
    omObjData* obj;
    omObjData* player;
    MBCoin* c;
    s32 k;
    void* data;
    s32 i;
    s32 j;
    u16 slot;
    s16 id;
    s16 base;
    s16 m;

    obj = D_800FD708_MarioBandstand;
    slot = D_800FD51E_MarioBandstand;
    j = 0;
    if (D_800FD520_MarioBandstand.count != 0) {
        for (i = 0; i < 8; i++) {
            who[i] = D_800FD520_MarioBandstand.id[j];
            j++;
            if (j >= D_800FD520_MarioBandstand.count) {
                j = 0;
            }
        }
        c = D_800FD418_MarioBandstand;
        for (i = 0; i < 8; i++, c++) {
            if (i == 0) {
                data = DataRead(0x21);
                id = func_8001E00C(data, 0x28D, 8);
                base = id;
                HuMemDirectFree(data);
            } else {
                id = func_8001E1D0(base, 8);
            }
            m = D_800ECDE0[id].unk_00;
            obj->model[(s16)slot] = m;
            func_80025930(m, 0x70000000, 0x70000000);
            slot++;
            k = func_800FCAAC_MarioBandstand() & 0xF;
            c->pos.x = D_800FD2D8_MarioBandstand[k].x;
            c->pos.y = D_800FD2D8_MarioBandstand[k].y;
            c->pos.z = D_800FD2D8_MarioBandstand[k].z;
            player = D_800FD6D0_MarioBandstand[who[i]];
            c->vel.x = (player->trans.x - c->pos.x) / 30.0f;
            c->vel.y = ((player->trans.y - c->pos.y) + 120.0f) / 30.0f + 45.0f;
            c->vel.z = (player->trans.z - c->pos.z) / 30.0f;
            func_80025798(m, c->pos.x, c->pos.y, c->pos.z);
            c->model = m;
            c->timer = func_800FCAAC_MarioBandstand() & 0xF;
            c->state = 0;
        }
        D_800FD518_MarioBandstand = 1;
        D_800FD51E_MarioBandstand = slot;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F853C_MarioBandstand);
#endif

void func_800F87EC_MarioBandstand(omObjData* obj) {
    MBCoin* c;
    s32 i;

    if (D_800FD518_MarioBandstand != 0) {
        c = D_800FD418_MarioBandstand;
        for (i = 0; i < 8; c++, i++) {
            switch (c->state) {
            case 0:
                if (c->timer != 0) {
                    c->timer--;
                } else {
                    func_800258EC(c->model, 4, 0);
                    c->timer = 0x1E;
                    c->state = 1;
                }
                break;
            case 1:
                if (c->timer != 0) {
                    c->timer--;
                    c->vel.y -= 3.0f;
                    c->pos.x += c->vel.x;
                    c->pos.y += c->vel.y;
                    c->pos.z += c->vel.z;
                    func_80025798(c->model, c->pos.x, c->pos.y, c->pos.z);
                } else {
                    func_800258EC(c->model, 4, 4);
                    c->state = 2;
                    PlaySound(0xFC);
                }
                break;
            case 2:
                break;
            }
        }
    }
}

/* ---------------------------------------------------------------------------------------------
   Thrown items
   --------------------------------------------------------------------------------------------- */

// NON_MATCHING: register allocation (raw 20, masked 10): retail keeps the 5-loop bound in s5 and the swap indices in s4/s5; tried s32 type, a bound local, b as bound (M1c)
#ifdef NON_MATCHING
void func_800F8940_MarioBandstand(omObjData* obj) {
    s16 shared[3];
    u8 types[8];
    MBItem* it;
    s32 i;
    s32 slot;
    s32 a;
    s32 b;
    u8 tmp;
    u8 type;
    u16 m;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = -1;
    }
    obj->unk_50 = func_80023684(8 * sizeof(MBItem), 0x7918);
    func_8009B770(obj->unk_50, 0, 8 * sizeof(MBItem));
    it = obj->unk_50;
    for (i = 0; i < 5; i++) {
        types[i] = 0;
    }
    for (; i < 8; i++) {
        types[i] = 1;
    }
    i = 0x40;
    do {
        i--;
        a = func_800FCAAC_MarioBandstand() & 7;
        b = func_800FCAAC_MarioBandstand() & 7;
        tmp = types[a];
        types[a] = types[b];
        types[b] = tmp;
    } while (i != 0);
    slot = 1;
    shared[0] = -1;
    shared[1] = -1;
    shared[2] = -1;
    for (i = 0; i < 8; i++, it++) {
        type = types[i];
        it->state = 0;
        it->kind = 0;
        it->type = type;
        it->vel.x = 0.0f;
        it->vel.y = 0.0f;
        it->vel.z = 0.0f;
        it->rotX = 0.0f;
        it->rotY = 180.0f;
        it->rotZ = 0.0f;
        if (shared[2] < 0) {
            m = LoadFormFile(0x1C, 0x299);
            shared[2] = m;
        } else {
            m = func_80023FC8(shared[2]);
        }
        obj->model[slot++] = m;
        it->model2 = m;
        func_800258EC(m, 4, 4);
        func_80025830(m, 0.3f, 0.3f, 0.3f);
        if (shared[type] < 0) {
            m = LoadFormFile(D_800FCC0C_MarioBandstand[type], 0x699);
            shared[type] = m;
        } else {
            m = func_80023FC8(shared[type]);
        }
        obj->model[slot++] = m;
        it->model = m;
        func_800258EC(m, 4, 4);
        func_80025830(m, 0.5f, 0.5f, 0.5f);
    }
    D_800FD2BA_MarioBandstand = 0;
    obj->func_ptr = func_800F93A4_MarioBandstand;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F8940_MarioBandstand);
#endif

/* An item thrown at the stage (kind 0): flies, bounces off the stage, falls out. */
void func_800F8C14_MarioBandstand(MBItem* it) {
    unk2C0C0StructB8* b8;
    f32 r;

    switch (it->state) {
    case 1:
        func_800258EC(it->model, 4, 0);
        it->state = 2;
        break;
    case 2:
        if (it->timer != 0) {
            it->timer--;
            r = it->rotX + 25.0f;
            if (r > 360.0f) {
                r -= 360.0f;
            }
            it->rotX = r;
            func_800257E4(it->model, r, it->rotY, it->rotZ);
            it->pos.x += it->vel.x;
            it->pos.y += it->vel.y;
            it->pos.z += it->vel.z;
            func_80025798(it->model, it->pos.x, it->pos.y, it->pos.z);
            it->vel.y -= 3.6f;
            break;
        }
        it->vel.x /= 2.0f;
        it->vel.y += fabs(it->vel.y / 4.0f);
        it->vel.z = 0.0f - it->vel.z / 2.0f;
        it->rotY = 0.0f - it->rotY;
        it->timer = 0x12;
        it->state = 3;
        func_80025CA8(it->model2, 0.0f);
        b8 = D_800F2B7C[it->model2].unk_6C->unk_B8;
        if (b8 != NULL) {
            b8->unk_08 = 0.0f;
        }
        func_800258EC(it->model2, 4, 0);
        func_80025798(it->model2, it->pos.x, it->pos.y, it->pos.z);
        func_800F7000_MarioBandstand();
        func_80060F04((s8)it->kind >> 4, 0xA, 0, 0xA);
        break;
    case 3:
        if (func_80025D40(it->model2) <= func_80025D18(it->model2)) {
            func_800258EC(it->model2, 4, 4);
        }
        if (it->timer != 0) {
            it->timer--;
            r = it->rotX - 12.0f;
            if (r < 0.0f) {
                r += 360.0f;
            }
            it->rotX = r;
            func_800257E4(it->model, r, it->rotY, it->rotZ);
            it->pos.x += it->vel.x;
            it->pos.y += it->vel.y;
            it->pos.z += it->vel.z;
            func_80025798(it->model, it->pos.x, it->pos.y, it->pos.z);
            it->vel.y -= 3.6f;
            if ((u8)it->timer & 1) {
                func_800258EC(it->model, 4, 0);
            } else {
                func_800258EC(it->model, 4, 4);
            }
            break;
        }
        func_800258EC(it->model, 4, 4);
        it->state = 0;
        break;
    case 10:
        func_800258EC(it->model, 4, 4);
        func_800258EC(it->model2, 4, 4);
        it->state = 0;
        break;
    }
}

/* An item that falls onto the stage (kind 1). */
void func_800F8FCC_MarioBandstand(MBItem* it) {
    f32 r;

    switch (it->state) {
    case 1:
        if (it->timer != 0) {
            it->timer--;
            break;
        }
        func_800258EC(it->model, 4, 0);
        it->state = 2;
        break;
    case 2:
        r = it->rotX + 25.0f;
        if (r > 360.0f) {
            r -= 360.0f;
        }
        it->rotX = r;
        func_800257E4(it->model, r, it->rotY, it->rotZ);
        it->pos.x += it->vel.x;
        it->pos.y += it->vel.y;
        it->pos.z += it->vel.z;
        it->vel.y -= 3.6f;
        if (it->pos.z < 360.0f) {
            func_800F7000_MarioBandstand();
            it->pos.z = 360.0f;
            it->state = 3;
            it->vel.x *= 0.2f;
            it->vel.z = (0.0f - it->vel.z) * 0.2f;
            if (it->vel.y > 0.0f) {
                it->vel.y = 0.0f;
            }
        }
        func_80025798(it->model, it->pos.x, it->pos.y, it->pos.z);
        break;
    case 3:
        it->rotX -= 10.0f;
        if (it->rotX < 0.0f) {
            it->rotX += 360.0f;
        }
        func_800257E4(it->model, it->rotX, it->rotY, it->rotZ);
        it->pos.x += it->vel.x;
        it->pos.y += it->vel.y;
        it->pos.z += it->vel.z;
        it->vel.y -= 3.6f;
        func_80025798(it->model, it->pos.x, it->pos.y, it->pos.z);
        if (++it->timer & 1) {
            func_800258EC(it->model, 4, 0);
        } else {
            func_800258EC(it->model, 4, 4);
        }
        if (it->pos.y < -60.0f) {
            func_800258EC(it->model, 4, 4);
            it->state = 0;
        }
        break;
    }
}

/* Frees the items' models (the object's model slots that hold them). */
// NON_MATCHING: masked 43 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F92B4_MarioBandstand(omObjData* obj) {
    MBItem* it = obj->unk_50;
    s16* model;
    s32 n;
    s32 i;
    s16 m2;

    n = 0;
    do {
        it->state = 0;
        m2 = it->model2;
        model = obj->model;
        for (i = 0; i < obj->mdlcnt; i++, model++) {
            if (*model == it->model) {
                *model = -1;
                func_8002456C(it->model);
                break;
            }
        }
        model = obj->model;
        for (i = 0; i < obj->mdlcnt; i++, model++) {
            if (*model == m2) {
                *model = -1;
                func_8002456C(m2);
                break;
            }
        }
        n++;
        it++;
    } while (n < 8);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F92B4_MarioBandstand);
#endif

void func_800F93A4_MarioBandstand(omObjData* obj) {
    MBItem* it = obj->unk_50;
    s32 i;

    for (i = 0; i < 8; i++, it++) {
        if (it->state != 0) {
            switch (it->kind & 0xF) {
            case 0:
                func_800F8C14_MarioBandstand(it);
                break;
            case 1:
                func_800F8FCC_MarioBandstand(it);
                break;
            }
        }
    }
}

/* Starts a free item: kind (low nibble of `kind`) 0 = thrown from the audience at (x, y, z),
   1 = dropped onto a random prop. */
// NON_MATCHING: masked 79 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F9430_MarioBandstand(f32 x, f32 y, f32 z, s32 kind) {
    MBItem* it;
    s32 n;
    s16 i;
    s16 idx;
    s16 px;
    f32 dz;
    f32 a;
    f32 t;
    f32 vz;
    u8 k;

    i = D_800FD2BA_MarioBandstand;
    for (n = 0; n < 8; n++) {
        it = &((MBItem*)D_800FD718_MarioBandstand->unk_50)[i];
        if (it->state == 0) {
            break;
        }
        i++;
        if (i >= 8) {
            i = 0;
        }
    }
    if (n < 8) {
        k = kind;
        it->kind = k;
        switch (k & 0xF) {
        case 0:
            t = (s32)(func_800FCAAC_MarioBandstand() & 7) * 140 - 490;
            it->pos.x = t;
            it->pos.y = -65.0f;
            it->pos.z = 460.0f;
            func_80025798(it->model, t, -65.0f, 460.0f);
            dz = z - 460.0f;
            a = func_800B0CD8(x - t, dz);
            it->rotX = 0.0f;
            it->rotY = a;
            it->rotZ = 0.0f;
            func_800257E4(it->model, it->rotX, it->rotY, it->rotZ);
            it->vel.x = func_800AEAC0(a) * 25.0f;
            vz = func_800AEFD0(a) * 25.0f;
            it->vel.z = vz;
            if (dz != 0.0f && vz != 0.0f) {
                t = fabsf(dz / vz);
                it->timer = t;
                if (t != 0.0f) {
                    it->vel.y = (y - -65.0f) / t + t * 1.8f;
                    break;
                }
            } else {
                it->timer = 0xF;
            }
            it->vel.y = 60.0f;
            break;
        case 1:
            n = 0x10;
            do {
                n--;
                idx = func_800FCAAC_MarioBandstand() & 0xF;
                px = D_800FD2D8_MarioBandstand[idx].x;
            } while (((u32)(px + 0xD2) >= 0x1A5) & (n != 0));
            if (n != 0) {
                it->pos.x = px;
                it->pos.z = D_800FD2D8_MarioBandstand[idx].z;
            } else {
                it->pos.x = (s32)(func_800FCAAC_MarioBandstand() % 210);
                it->pos.z = 800.0f;
            }
            it->pos.y = (s16)((rand8() & 7) - 0x36);
            it->vel.x = (s32)(func_800FCAAC_MarioBandstand() & 0x1F) - 0x10;
            it->vel.z = -26.6f;
            it->vel.y = (rand8() & 0xF) + 0x28;
            it->rotY = func_800B0CD8(it->vel.x, it->vel.z);
            it->timer = func_800FCAAC_MarioBandstand() & 0x3F;
            break;
        default:
            return;
        }
        it->state = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F9430_MarioBandstand);
#endif

/* ---------------------------------------------------------------------------------------------
   Players
   --------------------------------------------------------------------------------------------- */

void func_800F97D0_MarioBandstand(void) {
    s32 i;

    D_800FD538_MarioBandstand = -1;
    D_800FD53C_MarioBandstand = -1;
    D_800FD540_MarioBandstand = -1;
    D_800FD544_MarioBandstand = 0;
    D_800FD548_MarioBandstand = -1;
    for (i = 0; i < 4; i++) {
        D_800FD532_MarioBandstand[i] = (u8)D_800FCCCC_MarioBandstand[GwPlayer[i].group];
    }
    D_800FD530_MarioBandstand = 0;
    for (i = 0; i < 4; i++) {
        D_800FD6D0_MarioBandstand[i] = omAddObj(8, 0x12, 0x2A, -1, func_800F98C4_MarioBandstand);
    }
}

// NON_MATCHING: masked 73 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F98C4_MarioBandstand(omObjData* obj) {
    MBPlayerWork* w;
    MBPlayerCpu* cpu;
    Vec* pos;
    s16 player;
    u8 chr;
    u8 kind;
    s32 dir;
    s32 file;
    s32 i;
    u16 m;
    s16 m0;

    player = D_800FD530_MarioBandstand;
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = -1;
    }
    obj->unk_50 = func_80023684(sizeof(MBPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(MBPlayerWork));
    w = obj->unk_50;
    w->unk_D8 = func_80023684(obj->mtncnt * sizeof(*w->unk_D8), 0x7918);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
        w->unk_D8[i][0] = 0;
        w->unk_D8[i][1] = 0;
    }
    w->unk_E4 = func_80023684(sizeof(MBPlayerCpu), 0x7918);
    func_8009B770(w->unk_E4, 0, sizeof(MBPlayerCpu));
    cpu = w->unk_E4;
    kind = D_800FD532_MarioBandstand[player];
    obj->work[0] = kind;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->work[3] = 0;
    pos = &D_800FCC20_MarioBandstand[kind];
    D_800FD700_MarioBandstand[kind] = chr;
    obj->model[0] = LoadFormFile(dir | file, 0x699);
    omSetTra(obj, pos->x, pos->y, pos->z);
    if (D_800FD714_MarioBandstand < 0) {
        m = func_800174F4(0x20, 0x699);
        D_800FD714_MarioBandstand = m;
    } else {
        m = func_80023FC8(D_800FD714_MarioBandstand);
    }
    obj->model[1] = m;
    func_800370D4(m);
    func_80025798(m, pos->x, pos->y, pos->z);
    switch ((u32)dir >> 16) {
    case 5:
        w->unk_A0 = 0.7f;
        break;
    case 3:
        w->unk_A0 = 0.9f;
        break;
    case 4:
        w->unk_A0 = 0.8f;
        break;
    default:
        w->unk_A0 = 1.0f;
        break;
    }
    m = LoadFormFile(D_800FCC50_MarioBandstand[kind], 0x699);
    obj->model[2] = m;
    switch (kind) {
    case 1:
        func_80025798(m, obj->trans.x, obj->trans.y, obj->trans.z + 70.0f);
        m = LoadFormFile(0x3A0007, 0x699);
        obj->model[4] = m;
        func_80025798(m, obj->trans.x, obj->trans.y, obj->trans.z);
        m = func_80023FC8(m);
        obj->model[3] = m;
        goto hook;
    case 2:
        func_8002859C(m, obj->model[0], "item_hook");
        func_800258EC(m, 0x4000, 0x4000);
        m = LoadFormFile(0x3A0004, 0x699);
        obj->model[3] = m;
        func_80025798(m, obj->trans.x, obj->trans.y, obj->trans.z);
        break;
    case 0:
    case 3:
    hook:
        func_8002859C(m, obj->model[0], "item_hook");
        func_800258EC(m, 0x4000, 0x4000);
        break;
    }
    func_8001874C(obj, 0, dir, 1, 0);
    switch (kind) {
    case 0:
        func_8001874C(obj, 0x10, dir | 0x83, 1, 0);
        func_8001874C(obj, 0x11, dir | 0x84, 1, 0);
        func_8001874C(obj, 0x12, dir | 0x85, 1, 0);
        func_8001874C(obj, 0x13, dir | 0x86, 1, 0);
        func_8001874C(obj, 0x16, dir | 0x87, 1, 0);
        func_8001874C(obj, 0x14, dir | 0x9D, 1, 0);
        D_800FD54C_MarioBandstand[0] = obj->motion[0x10];
        D_800FD54C_MarioBandstand[3] = obj->motion[0x11];
        D_800FD54C_MarioBandstand[2] = obj->motion[0x12];
        D_800FD54C_MarioBandstand[1] = obj->motion[0x13];
        D_800FD54C_MarioBandstand[4] = obj->motion[0x14];
        break;
    case 1:
        func_8001874C(obj, 0x10, 0x3A0009, 1, 0);
        func_8001874C(obj, 0x11, 0x3A0008, 1, 0);
        func_8001874C(obj, 0x13, dir | 0x91, 1, 0);
        func_8001874C(obj, 0x14, dir | 0x8C, 1, 0);
        func_8001874C(obj, 0x15, dir | 0x8B, 1, 0);
        break;
    case 2:
        func_8001874C(obj, 0x10, 0x3A0004, 1, 0);
        func_8001874C(obj, 0x14, dir | 0x89, 1, 0);
        func_8001874C(obj, 0x15, dir | 0x88, 1, 0);
        break;
    case 3:
        func_8001874C(obj, 0x14, dir | 0x8F, 1, 0);
        func_8001874C(obj, 0x15, dir | 0x8E, 1, 0);
        break;
    }
    if (kind != 0) {
        func_800FA7EC_MarioBandstand(obj, 0x14, 0);
    } else {
        m0 = obj->model[0];
        func_80025BB8(m0, obj->motion[0x16]);
        func_80025EB4(m0, 8, 8);
    }
    func_800FA028_MarioBandstand(obj, 7);
    w->unk_56 = GwPlayer[player].port;
    w->unk_58 = player;
    if (GwPlayer[player].flags & 1) {
        cpu->port = w->unk_56;
        cpu->unkA = 0;
        cpu->level = GwPlayer[w->unk_58].cpu_difficulty;
    }
    cpu->unk10 = 0;
    w->unk_DC = 0;
    obj->func_ptr = func_800FAC2C_MarioBandstand;
    D_800FD530_MarioBandstand++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800F98C4_MarioBandstand);
#endif

/* The backing musicians next to a player's instrument (kinds 1-3: two of them for kind 1). */
// NON_MATCHING: masked 66 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FA028_MarioBandstand(omObjData* obj, s32 slot) {
    s32 count;
    s32 j;
    u16 kind;
    Vec* pos;
    s32* motions;
    u16 m;
    u16 h;
    s16 clap;
    char* name;

    if (obj->work[0] == 0) {
        return;
    }
    kind = obj->work[0] - 1;
    count = 2;
    if (kind != 0) {
        count = 1;
    }
    for (j = 0; j < count; j++) {
        motions = D_800FCC60_MarioBandstand[kind];
        if (j == 0) {
            m = LoadFormFile(0x3A000D, 0x699);
            func_8001775C(obj, 0x17, motions[0]);
            func_8001775C(obj, 0x18, motions[1]);
            func_8001775C(obj, 0x19, motions[2]);
        } else {
            m = func_80023FC8(obj->model[5]);
        }
        obj->model[5 + j] = m;
        pos = &D_800FCC84_MarioBandstand[kind][j];
        func_80025798(m, pos->x, pos->y, pos->z);
        func_80025BB8(m, obj->motion[0x17]);
        func_80025EB4(m, 2, 2);
        if (D_800FD714_MarioBandstand >= 0) {
            h = func_80023FC8(D_800FD714_MarioBandstand);
            obj->model[slot++] = h;
            func_800370D4(h);
            func_80025798(h, pos->x, pos->y, pos->z);
            func_80025830(h, 0.8f, 0.8f, 0.8f);
        }
        switch (kind) {
        case 0:
            h = func_80023FC8(obj->model[2]);
            obj->model[slot++] = h;
            func_80025798(h, pos->x, pos->y, pos->z + 60.0f);
            func_80025830(h, 0.8f, 0.8f, 0.8f);
            clap = m;
            h = func_80023FC8(obj->model[3]);
            obj->model[slot++] = h;
            func_8002859C(h, clap, "129_000-i-hook-R");
            func_800258EC(h, 0x4000, 0x4000);
            h = func_80023FC8(obj->model[3]);
            obj->model[slot++] = h;
            name = "129_000-i-hook-L";
            break;
        case 1:
            clap = m;
            h = func_80023FC8(obj->model[2]);
            obj->model[slot++] = h;
            func_8002859C(h, clap, "129_000-i-hook-R");
            func_800258EC(h, 0x4000, 0x4000);
            h = LoadFormFile(0x3A0003, 0x699);
            obj->model[slot++] = h;
            name = "129_000-i-hook-L";
            break;
        case 2:
            h = LoadFormFile(0x3A000C, 0x699);
            obj->model[slot++] = h;
            clap = m;
            name = "129_000-i-hook-R";
            break;
        default:
            continue;
        }
        func_8002859C(h, clap, name);
        func_800258EC(h, 0x4000, 0x4000);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FA028_MarioBandstand);
#endif

/* The stick's direction for a human player: 0 up, 1 left, 2 down, 3 right, 4 centred, -1 none. */
s32 func_800FA448_MarioBandstand(omObjData* obj) {
    s8 port = ((MBPlayerWork*)obj->unk_50)->unk_56;
    s32 sx = ContStkX[port];
    s32 sy = ContStkY[port];
    s32 ax = abs(sx);
    s32 ay = abs(sy);
    s32 dir;

    dir = -1;
    if ((ax < 0x10) & (ay < 0x10)) {
        dir = 4;
    } else if (ay < ax) {
        if ((ay < 0x20) & (ax >= 0x20)) {
            dir = (sx >= 0) ? 3 : 1;
        }
    } else if ((ax < 0x20) & (ay >= 0x20)) {
        dir = (sy < 0) ? 2 : 0;
    }
    return dir;
}

/* The conductor (kind 0): the intro bow, then baton strokes on the beat. */
void func_800FA4F8_MarioBandstand(omObjData* obj) {
    u16 m = obj->model[0];
    unk_ovl_2D_struct* mdl;
    f32 t;

    switch (D_800FD544_MarioBandstand) {
    case 0:
        if (func_800FC8A8_MarioBandstand(0x2000) != 0) {
            func_80025BB8(m, obj->motion[0x16]);
            D_800FD558_MarioBandstand = 1;
            D_800FD55C_MarioBandstand = 0;
            D_800FD544_MarioBandstand++;
        }
        break;
    case 1:
        t = func_80025D18(m);
        if (func_80025D40(m) <= t) {
            func_80025BB8(m, obj->motion[0x14]);
            func_80025EB4(m, 2, 2);
            D_800FD538_MarioBandstand = 4;
            D_800FD53C_MarioBandstand = 4;
            D_800FD544_MarioBandstand++;
        }
        break;
    case 2:
        if (func_800FC8A8_MarioBandstand(0x4000) != 0) {
            mdl = &D_800F2B7C[(s16)m];
            if (mdl->unk_0C != -1) {
                mdl->unk_0C = -1;
            }
            func_80025BB8(m, obj->motion[0x16]);
            func_80025CA8(m, func_80025D40(m) - 1.0f);
            func_80025EB4(m, 4, 4);
            D_800FD544_MarioBandstand++;
            break;
        }
        if (D_800FD558_MarioBandstand != 0) {
            if (func_800FC8A8_MarioBandstand(0x800) == 0) {
                D_800FD558_MarioBandstand = 0;
            }
        } else if (func_800FC8A8_MarioBandstand(0x800) != 0) {
            if (D_800FD55C_MarioBandstand != 0) {
                func_80025BB8(m, D_800FD54C_MarioBandstand[D_800FD53C_MarioBandstand]);
                func_80025C20(m, func_80025E48(obj->motion[0x14]), 0, 0xF, 2);
                D_800FD538_MarioBandstand = D_800FD53C_MarioBandstand;
                D_800FD53C_MarioBandstand = 4;
                D_800FD548_MarioBandstand = 4;
            } else {
                D_800FD55C_MarioBandstand = 1;
            }
            D_800FD558_MarioBandstand = 1;
        }
        break;
    }
}

// decomp-permuter
void func_800FA790_MarioBandstand(s16 model, s16 motion, s16 mode, f32 speed)
{
  float new_var;
  unk_ovl_2D_struct *m = &D_800F2B7C[model];
  m->unk_08 = (u16) D_800F2B7C[motion].unk_08;
  new_var = 0.0f;
  m->unk_48 = new_var;
  m->unk_50 = new_var;
  m->unk_0A = mode;
  m->unk_4C = speed;
}

/* A musician's animation: 0x14 idle, 0x15 a note (alternating strokes for kind 1). */
void func_800FA7EC_MarioBandstand(omObjData* obj, s32 mode, s32 half) {
    f32 speed;
    u8 kind = obj->work[0];
    u16 m;

    speed = 1.0f;
    if (half) {
        speed = 0.5f;
    }
    switch (mode) {
    case 0x15:
    case 0x16:
        obj->work[2] = 1;
        break;
    case 0x14:
        obj->work[2] = 0;
        break;
    }
    m = obj->model[0];
    switch (kind) {
    case 0:
        break;
    case 1:
        switch (mode) {
        case 0x15:
            if (obj->work[3] != 0) {
                func_800FA790_MarioBandstand(m, obj->motion[0x15], 0, speed);
                func_800FA790_MarioBandstand(obj->model[4], obj->motion[0x10], 0, speed);
            } else {
                func_800FA790_MarioBandstand(m, obj->motion[0x13], 0, speed);
                func_800FA790_MarioBandstand(obj->model[4], obj->motion[0x11], 0, speed);
            }
            obj->work[3] ^= 1;
            break;
        case 0x14:
        default:
            func_800FA790_MarioBandstand(m, obj->motion[0x14], 2, 1.0f);
            func_800FA790_MarioBandstand(obj->model[4], obj->motion[0x10], 2, 0.5f);
            break;
        }
        break;
    case 2:
        switch (mode) {
        case 0x15:
            func_800FA790_MarioBandstand(m, obj->motion[0x15], 0, speed);
            func_800FA790_MarioBandstand(obj->model[3], obj->motion[0x10], 0, speed);
            break;
        case 0x14:
        default:
            func_80025BB8(m, obj->motion[0x14]);
            func_80025EB4(m, 2, 2);
            func_800FA790_MarioBandstand(obj->model[3], obj->motion[0x10], 2, 0.5f);
            break;
        }
        break;
    case 3:
        switch (mode) {
        case 0x15:
            func_800FA790_MarioBandstand(m, obj->motion[0x15], 0, speed);
            break;
        case 0x14:
        default:
            func_80025BB8(m, obj->motion[0x14]);
            func_80025EB4(m, 2, 2);
            break;
        }
        break;
    }
}

// NON_MATCHING: masked 24 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FAA58_MarioBandstand(omObjData* obj) {
    s16 motion;
    s16 m;
    f32 t;

    switch (obj->work[1]) {
    case 0:
        if (func_800FC8A8_MarioBandstand(0x2000) != 0) {
            motion = obj->motion[0x18];
            obj->work[1] = 1;
            m = obj->model[5];
            if (m > 0) {
                func_80025C20(m, func_80025E48(motion), 0, 0x1E, 2);
            }
            m = obj->model[6];
            if (m > 0) {
                func_80025C20(m, func_80025E48(motion), 0, 0x1E, 2);
            }
        }
        break;
    case 1:
        if (func_800FC8A8_MarioBandstand(0x1000) != 0) {
            obj->work[1] = 2;
        }
        break;
    case 2:
        if (func_800FC8A8_MarioBandstand(0x4000) != 0) {
            motion = obj->motion[0x19];
            obj->work[1] = 3;
            m = obj->model[5];
            if (m > 0) {
                func_80025BB8(m, motion);
            }
            m = obj->model[6];
            if (m > 0) {
                func_80025BB8(m, motion);
            }
        }
        break;
    }
    if (obj->work[0] != 0) {
        if (obj->work[2] != 0) {
            m = obj->model[0];
            t = func_80025D18(m);
            if (func_80025D40(m) <= t) {
                func_800FA7EC_MarioBandstand(obj, 0x14, 0);
            }
        }
    } else {
        func_800FA4F8_MarioBandstand(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FAA58_MarioBandstand);
#endif

void func_800FAC2C_MarioBandstand(omObjData* obj) {
    MBBeatInfo info;
    MBPlayerWork* w = obj->unk_50;
    MBPlayerCpu* cpu = w->unk_E4;
    u16 kind = obj->work[0];
    s32 note;
    s32 btn;
    s32 d;
    s16 m;

    func_800FAA58_MarioBandstand(obj);
    if (D_800ED430 != 1) {
        return;
    }
    info.idx = cpu->unk2;
    note = func_800FB99C_MarioBandstand(kind, &info);
    cpu->unk2 = info.idx;
    if (note != cpu->unkC) {
        if (cpu->unkC != 0 && cpu->unkE != cpu->unkC) {
            cpu->score += 10;
            func_800F9430_MarioBandstand(obj->trans.x, obj->trans.y + 100.0f, obj->trans.z + 50.0f, w->unk_58 << 4);
        }
        cpu->unkC = note;
    }
    if (cpu->unk10 != 0) {
        cpu->unk10--;
        return;
    }
    if (kind != 0) {
        if (GwPlayer[w->unk_58].flags & 1) {
            btn = func_800FAFEC_MarioBandstand(obj, note, info.diff);
        } else {
            btn = ContBtnTrg[w->unk_56];
        }
        if (btn & 0x8000) {
            if (note != 0) {
                cpu->unk10 = 0xA;
                cpu->unk0 = info.diff;
                cpu->unkE = note;
                PlaySound((s16)note);
                d = info.diff;
                if (d < 0) {
                    d = -d;
                }
                cpu->score += d;
                if (d < 5) {
                    func_800FC8B8_MarioBandstand(kind, &info);
                    func_800FA7EC_MarioBandstand(obj, 0x15, (u32)(info.len - 8) >= 0x10);
                } else {
                    func_800F9430_MarioBandstand(obj->trans.x, obj->trans.y + 100.0f, obj->trans.z + 50.0f, w->unk_58 << 4);
                }
            }
        }
    } else {
        if (GwPlayer[w->unk_58].flags & 1) {
            btn = func_800FB0D8_MarioBandstand(obj, note, info.diff);
        } else {
            btn = func_800FA448_MarioBandstand(obj);
        }
        if ((u32)btn < 4) {
            if (note != 0) {
                if (D_800FD548_MarioBandstand != btn) {
                    cpu->unk10 = 0xA;
                    D_800FD548_MarioBandstand = btn;
                    PlaySound(0x2DE);
                    m = obj->model[0];
                    cpu->unkE = note;
                    note--;
                    d = abs(info.diff);
                    if ((d < 7) & (note == btn)) {
                        func_800FC870_MarioBandstand(note);
                        cpu->unk0 = info.diff;
                        d -= (d >= 2);
                    } else {
                        func_800F9430_MarioBandstand(obj->trans.x, obj->trans.y + 100.0f, obj->trans.z + 50.0f, w->unk_58 << 4);
                        d = 10;
                    }
                    cpu->score += d;
                    func_80025BB8(m, D_800FD54C_MarioBandstand[D_800FD53C_MarioBandstand]);
                    func_80025C20(m, func_80025E48(D_800FD54C_MarioBandstand[btn]), 0, 0xF, 2);
                    D_800FD538_MarioBandstand = D_800FD53C_MarioBandstand;
                    D_800FD53C_MarioBandstand = btn;
                }
            } else {
                D_800FD548_MarioBandstand = 4;
            }
        }
    }
}

/* CPU press for a musician: hits the A button with a chance from its level and the timing. */
s32 func_800FAFEC_MarioBandstand(omObjData* obj, s32 note, s32 diff) {
    MBPlayerCpu* cpu = ((MBPlayerWork*)obj->unk_50)->unk_E4;
    u8* chance = D_800FCCD4_MarioBandstand[cpu->level];
    s32 btn = 0;
    u32 r;
    s32 hit;

    if (cpu->unkE != note) {
        r = (u8)func_800FCAAC_MarioBandstand();
        if ((u32)(diff + 7) >= 0x12) {
            hit = r < chance[0];
        } else if (diff < -3) {
            hit = r < chance[1];
        } else if (diff < -1) {
            hit = r < chance[2];
        } else if (diff <= 0) {
            hit = r < chance[3];
        } else if (diff < 4) {
            hit = r < chance[4];
        } else {
            hit = r < chance[5];
        }
        if (hit) {
            btn |= 0x8000;
        }
    }
    return btn;
}

/* CPU stick for the conductor: the note's direction with the same chances. */
s32 func_800FB0D8_MarioBandstand(omObjData* obj, s32 note, s32 diff) {
    MBPlayerCpu* cpu = ((MBPlayerWork*)obj->unk_50)->unk_E4;
    u8* chance = D_800FCCD4_MarioBandstand[cpu->level];
    s32 dir = 4;
    u32 r;
    s32 hit;

    if (cpu->unkE != note) {
        r = (u8)func_800FCAAC_MarioBandstand();
        if ((u32)(diff + 7) >= 0x12) {
            hit = r < chance[0];
        } else if (diff < -3) {
            hit = r < chance[1];
        } else if (diff < -1) {
            hit = r < chance[2];
        } else if (diff <= 0) {
            hit = r < chance[3];
        } else if (diff < 4) {
            hit = r < chance[4];
        } else {
            hit = r < chance[5];
        }
        if (hit) {
            dir = note - 1;
        }
    }
    return dir;
}

/* ---------------------------------------------------------------------------------------------
   The song: note tracks read back from the audio driver, beat lists, the score sprites
   --------------------------------------------------------------------------------------------- */

void func_800FB1D0_MarioBandstand(void) {
    D_800FD678_MarioBandstand = 0;
    D_800FD71C_MarioBandstand = omAddObj(8, 0, 0, -1, func_800FC744_MarioBandstand);
}

// NON_MATCHING: masked 52 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FB214_MarioBandstand(void) {
    MBTrack* t;
    s32 song;
    s32 i;
    s32 seq;

    song = func_800FCAAC_MarioBandstand() % 3;
    D_800FD680_MarioBandstand = song;
    switch (song) {
    case 0:
        for (i = 0; i < 4; i++) {
            D_800FD580_MarioBandstand[i] = D_800FCD94_MarioBandstand[i].start;
            D_800FD570_MarioBandstand[i] = D_800FCD94_MarioBandstand[i].ev;
        }
        D_800FD568_MarioBandstand = D_800FCE7C_MarioBandstand;
        D_800FD590_MarioBandstand = D_800FCCF0_MarioBandstand;
        seq = 0x17;
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            D_800FD580_MarioBandstand[i] = D_800FCEC0_MarioBandstand[i].start;
            D_800FD570_MarioBandstand[i] = D_800FCEC0_MarioBandstand[i].ev;
        }
        D_800FD568_MarioBandstand = D_800FCFA0_MarioBandstand;
        D_800FD590_MarioBandstand = D_800FCCFC_MarioBandstand;
        seq = 0x2D;
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            D_800FD580_MarioBandstand[i] = D_800FCFE8_MarioBandstand[i].start;
            D_800FD570_MarioBandstand[i] = D_800FCFE8_MarioBandstand[i].ev;
        }
        D_800FD568_MarioBandstand = D_800FD0C8_MarioBandstand;
        D_800FD590_MarioBandstand = D_800FCD08_MarioBandstand;
        seq = 0x2E;
        break;
    }
    func_80060128(seq);
    D_800FD678_MarioBandstand = 0x2000;
    func_800FBB14_MarioBandstand();
    D_800FD67C_MarioBandstand = (func_8005FD5C() & 0xFFFF) + D_800F64F8;
    t = D_800FD598_MarioBandstand;
    for (i = 0; i < 4; i++, t++) {
        t->count = 0;
        t->timer = 0x96;
        t->unk28 = 0;
        t->idx = 0;
        t->note = -1;
        t->unk2E = 0;
        t->unk30 = 0;
        t->unk32 = 0;
        t->unk34 = 0;
        t->flags = 0;
    }
    for (i = 0; i < 4; i++) {
        D_800FD70C_MarioBandstand[i] = D_800FD568_MarioBandstand[i].count;
    }
    if (song == 2) {
        D_800FD70C_MarioBandstand[2] -= 3;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FB214_MarioBandstand);
#endif

/* Follows the song: reads each channel's state from the audio driver and records note changes. */
// NON_MATCHING: masked 44 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FB4D8_MarioBandstand(void) {
    B980ChlInfo info;
    MBTrack* t;
    s32 i;
    u16 note;
    s32 r;
    u8* ev;

    if (D_800FD678_MarioBandstand & 0x4000) {
        return;
    }
    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 != D_800FD67C_MarioBandstand) {
        if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 != 0) {
            func_8000C5C4();
            D_800FD0E8_MarioBandstand = 8;
        } else {
            func_8000C64C(0);
        }
        D_800FD67C_MarioBandstand = (func_8005FD5C() & 0xFFFF) + D_800F64F8;
    }
    r = func_8000C144();
    if (r != 1) {
        if (r != 0x100 && (D_800FD678_MarioBandstand & 0x8000)) {
            func_800FBD1C_MarioBandstand();
            D_800FD678_MarioBandstand = (D_800FD678_MarioBandstand & ~0x8000) | 0x4000;
        }
        return;
    }
    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 != 0) {
        return;
    }
    if (D_800FD0E8_MarioBandstand != 0) {
        D_800FD0E8_MarioBandstand--;
        return;
    }
    t = D_800FD598_MarioBandstand;
    for (i = 0; i < 4; i++, t++) {
        t->timer++;
        t->unk28++;
        switch (i) {
        case 0:
            if (t->timer == -4) {
                D_800FD678_MarioBandstand &= ~0x1000;
            }
            func_8000C748(7, &info);
            note = info.pan;
            break;
        case 1:
            func_8000C748(4, &info);
            note = info.vol;
            break;
        case 2:
            func_8000C748(6, &info);
            note = info.fxmix;
            break;
        case 3:
            func_8000C748(5, &info);
            note = info.pan;
            break;
        }
        if (note != t->note) {
            D_800FD678_MarioBandstand |= 1 << i;
            t->flags |= 1;
            t->note = note;
            if (i == 0) {
                D_800FD678_MarioBandstand |= 0x400;
            }
        } else {
            D_800FD678_MarioBandstand &= ~(1 << i);
            t->flags &= ~1;
            if (i == 0) {
                D_800FD678_MarioBandstand &= ~0x400;
            }
        }
        if (t->flags & 2) {
            t->unk26++;
            if (t->flags & 1) {
                t->ev[t->count][0] = note;
                t->ev[t->count][1] = (u8)t->unk28;
                t->count++;
                t->unk26 = 0;
            }
            ev = &D_800FD570_MarioBandstand[i][t->idx * 2];
            if (note == ev[0]) {
                t->timer = ev[1];
                t->timer = -ev[1];
                t->idx++;
                if (i == 0) {
                    D_800FD678_MarioBandstand &= ~0x800;
                }
                t->flags &= ~2;
                t->base = note + 1;
            }
        } else if (note == D_800FD580_MarioBandstand[i][t->idx]) {
            t->unk26 = 0;
            if (!(D_800FD678_MarioBandstand & 0x1000)) {
                D_800FD678_MarioBandstand |= 0x9800;
            }
            t->flags |= 2;
            t->count = 0;
            t->unk28 = 0;
            t->ev[t->count][0] = (u8)t->note;
            t->ev[t->count][1] = (u8)t->unk28;
            t->count++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FB4D8_MarioBandstand);
#endif

// NON_MATCHING: 1 instruction short, masked 7: retail loads the timer test through its own lui and the table base separately; tried s32 d, s16 timer local (kept), s32 diff, s32 return (M1c)
#ifdef NON_MATCHING
s16 func_800FB8EC_MarioBandstand(s32 track) {
    MBTrack* t;
    s32 k;
    s32 diff;
    s32 d;
    s16 timer;

    diff = 0;
    if (!(D_800FD678_MarioBandstand & 0x8000)) {
        return 0;
    }
    if ((u16)(D_800FD598_MarioBandstand[0].timer + 0x13) < 0x75) {
        t = &D_800FD598_MarioBandstand[track];
        k = t->note - t->base;
        timer = t->timer;
        diff = timer - t->ev[k][1];
        k++;
        if (k < t->count) {
            d = timer - t->ev[k][1];
            if (d >= -7) {
                diff = d;
            }
        }
    }
    return diff;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FB8EC_MarioBandstand);
#endif

/* The next beat of a track: fills `info` (timing difference, length, beat index) and returns the
   note (the conductor's direction + 1 for track 0). */
// NON_MATCHING: masked 40 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
s32 func_800FB99C_MarioBandstand(s32 track, MBBeatInfo* info) {
    MBTrack* t;
    MBSong* song;
    MBBeat* b;
    s32 pos;
    s32 k;
    s32 i;
    s32 n;
    s32 t0;
    s16 d;
    s16 ret;

    ret = 0;
    if (!(D_800FD678_MarioBandstand & 0x8000)) {
        return 0;
    }
    if ((u16)(D_800FD598_MarioBandstand[0].timer + 0x13) < 0x75) {
        t = &D_800FD598_MarioBandstand[track];
        pos = t->note;
        k = pos - t->base;
        t0 = t->ev[k][1];
        info->diff = (u16)t->timer - t0;
        k++;
        if (k < t->count) {
            d = t->timer - t->ev[k][1];
            info->len = t->ev[k][1] - t0;
            if (d >= -7) {
                pos++;
                info->diff = d;
            }
        } else {
            info->len = D_800FD570_MarioBandstand[track][t->idx * 2 + 1];
        }
        info->unk8 = pos - (u16)t->base;
        song = &D_800FD568_MarioBandstand[track];
        n = song->count;
        i = info->idx;
        b = &song->beats[i];
        for (; i < n; i++, b++) {
            if (b->time >= pos) {
                break;
            }
        }
        info->idx = i;
        if (i < n) {
            if (track != 0) {
                return b->note;
            }
            ret = D_800FD590_MarioBandstand[b->note] + 1;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FB99C_MarioBandstand);
#endif

// NON_MATCHING: masked 18 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FBB14_MarioBandstand(void) {
    s16 g;
    s16 i;
    s32 j;
    void* data;
    s16 img;

    D_800FD6B4_MarioBandstand = 0;
    g = func_80064EF4(3, 0);
    D_800FD6A0_MarioBandstand[0] = g;
    for (i = 0; i < 3; i++) {
        func_80067208(g, i, D_800FD688_MarioBandstand[0], 0);
        func_800672B0(g, i, 0);
        func_800674BC(g, i, 0x1000);
        func_80067480(g, i, 0xA);
        func_80066DC4(g, i, 0x9C, D_800FD150_MarioBandstand[i]);
        func_8006752C(g, i, 0xB4);
    }
    D_800FD560_MarioBandstand = 0;
    D_800FD562_MarioBandstand = 0;
    D_800FD564_MarioBandstand = 0;
    func_800FC4E0_MarioBandstand();
    D_800FD6B8_MarioBandstand = 0;
    D_800FD6B9_MarioBandstand = 0;
    g = func_80064EF4(4, 0);
    D_800FD6A0_MarioBandstand[8] = g;
    for (j = 0; j < 4; j++) {
        data = DataRead(D_800FD128_MarioBandstand[D_800FD700_MarioBandstand[j]]);
        img = func_800678A4(data);
        HuMemDirectFree(data);
        func_80067208(g, j, img, 0);
        func_800672B0(g, j, 0);
        func_800674BC(g, j, 0xC);
        func_80066DC4(g, j, D_800FD140_MarioBandstand[j][0], D_800FD140_MarioBandstand[j][1]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FBB14_MarioBandstand);
#endif

void func_800FBD1C_MarioBandstand(void) {
    s16* p;
    s32 i;

    for (i = 0; i < 9; i++) {
        p = &D_800FD6A0_MarioBandstand[i];
        if (*p >= 0) {
            func_80064D38(*p);
            *p = -1;
        }
    }
}

/* Moves the conductor's cursor sprite toward the next beat's position on the score. */
// NON_MATCHING: masked 200 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FBD8C_MarioBandstand(void) {
    s32 k;
    s32 time;
    s32 dt;
    s32 cell;
    f32 x;
    f32 y;
    f32 n;

    if ((u16)(D_800FD598_MarioBandstand[0].timer + 0x13) >= 0x75) {
        func_80066DC4(D_800FD6A0_MarioBandstand[7], 0, 0x154, 0xC7);
        D_800FD168_MarioBandstand = 56.0f;
        D_800FD16C_MarioBandstand = 48.0f;
    }
    k = D_800FD598_MarioBandstand[0].note - (D_800FD598_MarioBandstand[0].base - 1);
    if (k < D_800FD598_MarioBandstand[0].count) {
        time = D_800FD598_MarioBandstand[0].ev[k][1];
    } else {
        time = D_800FD598_MarioBandstand[0].ev[D_800FD598_MarioBandstand[0].count - 1][1] + 0x1E;
    }
    dt = time - D_800FD598_MarioBandstand[0].timer;
    cell = D_800FCD14_MarioBandstand[(s16)D_800FD598_MarioBandstand[0].note + 1];
    if (cell < 0) {
        cell = 4;
    } else {
        cell = D_800FD590_MarioBandstand[cell];
    }
    x = D_800FD100_MarioBandstand[cell][0];
    y = D_800FD100_MarioBandstand[cell][1];
    if (dt > 0) {
        n = dt;
        D_800FD168_MarioBandstand += (x - D_800FD168_MarioBandstand) / n;
        y = (y - D_800FD16C_MarioBandstand) / n + D_800FD16C_MarioBandstand;
    } else {
        D_800FD168_MarioBandstand = x;
    }
    D_800FD16C_MarioBandstand = y;
    func_80066DC4(D_800FD6A0_MarioBandstand[7], 0, (s32)D_800FD168_MarioBandstand, (s32)D_800FD16C_MarioBandstand);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FBD8C_MarioBandstand);
#endif

/* The score display: the playhead, each track's note marks and their fade-out. */
// NON_MATCHING: masked 82 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FBF68_MarioBandstand(omObjData* obj) {
    MBTrack* t;
    s16* gp;
    s16 i;
    u16 slot;
    u16 anim;
    s16 g;
    s16 note;

    if (!(D_800FD678_MarioBandstand & 0x8000)) {
        return;
    }
    gp = &D_800FD6A0_MarioBandstand[4];
    g = *gp;
    if ((u16)(D_800FD598_MarioBandstand[0].timer + 0x13) < 0x75) {
        if (g < 0) {
            g = func_80064EF4(1, 0);
            *gp = g;
            func_80067208(g, 0, D_800FD688_MarioBandstand[4], 0);
            func_800672B0(g, 0, 0);
            func_800674BC(g, 0, 0xC);
            func_80067354(g, 0, 0.5f, 1.1f);
        }
        func_80066DC4(g, 0, ((D_800FD598_MarioBandstand[0].timer * 13) >> 3) + 0x58, 0xC7);
    } else if (g >= 0) {
        func_80064D38(g);
        D_800FD6A0_MarioBandstand[4] = -1;
        t = &D_800FD598_MarioBandstand[1];
        for (i = 1; i < 4; i++, t++) {
            if (t->unk2E != 0) {
                gp = &D_800FD6A0_MarioBandstand[(s16)D_800FD158_MarioBandstand[i]];
                if (*gp >= 0) {
                    func_80064D38(*gp);
                    *gp = -1;
                }
                t->unk2E = 0;
            }
            t->unk30 = 0;
            t->unk32 = 0;
            t->unk34 = 0;
        }
    }
    func_800FBD8C_MarioBandstand();
    t = D_800FD598_MarioBandstand;
    for (i = 0; i < 4; i++, t++) {
        slot = D_800FD158_MarioBandstand[i];
        anim = D_800FD160_MarioBandstand[i];
        if ((D_800FD678_MarioBandstand & 0x1000) && (t->flags & 1)) {
            t->flags &= ~1;
            if (i == 0) {
                func_800FC880_MarioBandstand(D_800FD6B8_MarioBandstand);
                D_800FD6B8_MarioBandstand++;
            } else {
                if ((D_800FD680_MarioBandstand == 2) & (i == 2)) {
                    note = t->note;
                    if ((note == 1) | (note == 0x19)) {
                        goto marks;
                    }
                    if (note == 0x1C) {
                        goto marks;
                    }
                }
                gp = &D_800FD6A0_MarioBandstand[(s16)slot];
                if (*gp < 0) {
                    g = func_80064EF4(0x10, 0);
                    *gp = g;
                } else {
                    g = (u16)D_800FD6A0_MarioBandstand[(s16)slot];
                }
                func_80067208(g, t->unk2E, D_800FD688_MarioBandstand[(s16)anim], 0);
                func_800672B0(g, t->unk2E, 0);
                func_800674BC(g, t->unk2E, 0xC);
                func_80067480(g, t->unk2E, 0xA);
                t->unk30 = t->unk2E + 1;
                func_80066DC4(g, t->unk2E, ((t->unk28 * 13) >> 3) + 0x58, D_800FD150_MarioBandstand[i - 1]);
                t->unk2E++;
            }
        }
    marks:
        if (i == 0) {
            g = D_800FD6A0_MarioBandstand[6];
            if (g >= 0) {
                if (D_800FD564_MarioBandstand != 0) {
                    func_80067354(g, D_800FD564_MarioBandstand - 1, 1.0f, 1.0f);
                    D_800FD564_MarioBandstand = 0;
                }
                if (D_800FD562_MarioBandstand != 0) {
                    D_800FD564_MarioBandstand = D_800FD562_MarioBandstand;
                    func_80067354(g, D_800FD562_MarioBandstand - 1, 1.3f, 1.3f);
                    D_800FD562_MarioBandstand = 0;
                }
                if (D_800FD560_MarioBandstand != 0) {
                    D_800FD562_MarioBandstand = D_800FD560_MarioBandstand;
                    func_80067354(g, D_800FD560_MarioBandstand - 1, 1.7f, 1.7f);
                    D_800FD560_MarioBandstand = 0;
                }
            }
        } else {
            g = D_800FD6A0_MarioBandstand[(s16)slot];
            if (g >= 0) {
                if (t->unk34 != 0) {
                    func_80067354(g, (u16)t->unk34 - 1, 0.5f, 0.5f);
                    t->unk34 = 0;
                }
                if (t->unk32 != 0) {
                    t->unk34 = t->unk32;
                    func_80067354(g, (u16)t->unk32 - 1, 0.72f, 0.72f);
                    t->unk32 = 0;
                }
                if (t->unk30 != 0) {
                    t->unk32 = t->unk30;
                    func_80067354(g, (u16)t->unk30 - 1, 0.85f, 0.85f);
                    t->unk30 = 0;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FBF68_MarioBandstand);
#endif

// NON_MATCHING: masked 7 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800FC4E0_MarioBandstand(void) {
    void* data;
    s16 img;
    s16 g;
    s16 i;

    data = DataRead(0x3A001A);
    img = func_800678A4(data);
    HuMemDirectFree(data);
    g = func_80064EF4(1, 0);
    D_800FD6A0_MarioBandstand[5] = g;
    func_80067208(g, 0, img, 0);
    func_800672B0(g, 0, 0);
    func_800674BC(g, 0, 0x100C);
    func_80066DC4(g, 0, 0x38, 0x30);
    func_8006752C(g, 0, 0xB4);
    data = DataRead(0x3A0026);
    img = func_800678A4(data);
    HuMemDirectFree(data);
    g = func_80064EF4(4, 0);
    D_800FD6A0_MarioBandstand[6] = g;
    for (i = 0; i < 4; i++) {
        func_80067208(g, i, img, 0);
        func_800672B0(g, i, 0);
        func_800674BC(g, i, 0x100C);
        func_80066DC4(g, i, D_800FD0EC_MarioBandstand[i][0], D_800FD0EC_MarioBandstand[i][1]);
        func_8006752C(g, i, 0xB4);
        func_80067354(g, i, 1.0f, 1.0f);
    }
    data = DataRead(0x3A0027);
    img = func_800678A4(data);
    HuMemDirectFree(data);
    g = func_80064EF4(1, 0);
    D_800FD6A0_MarioBandstand[7] = g;
    func_80067208(g, 0, img, 0);
    func_800672B0(g, 0, 0);
    func_800674BC(g, 0, 0xC);
    func_80066DC4(g, 0, 0x154, 0xC7);
    func_80067354(g, 0, 1.0f, 1.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CD680", func_800FC4E0_MarioBandstand);
#endif

// decomp-permuter
void func_800FC744_MarioBandstand(omObjData *obj)
{
  void *data;
  unsigned long new_var;
  s32 i;
  s16 k;
  for (i = 0; i < obj->mdlcnt; i++)
  {
    obj->model[i] = -1;
  }

  for (i = 0; i < 9; i++)
  {
    D_800FD6A0_MarioBandstand[i] = -1;
  }

  k = 0;
  for (i = 0; i < (new_var = 5); i++)
  {
    data = DataRead(D_800FD114_MarioBandstand[i]);
    D_800FD688_MarioBandstand[k] = func_800678A4(data);
    HuMemDirectFree(data);
    k++;
  }

  obj->func_ptr = func_800FBF68_MarioBandstand;
}

s8 func_800FC854_MarioBandstand(s8 i) {
    return D_800FD590_MarioBandstand[i];
}

void func_800FC870_MarioBandstand(s32 dir) {
    D_800FD560_MarioBandstand = dir + 1;
}

void func_800FC880_MarioBandstand(s32 i) {
    D_800FD560_MarioBandstand = D_800FD590_MarioBandstand[i] + 1;
}

s32 func_800FC8A8_MarioBandstand(s32 mask) {
    return mask & D_800FD678_MarioBandstand;
}

void func_800FC8B8_MarioBandstand(s32 track, MBBeatInfo* info) {
    MBTrack* t = &D_800FD598_MarioBandstand[track];

    if (track != 0 && t->unk2E != 0) {
        t->unk30 = info->unk8 + 1;
        if ((D_800FD680_MarioBandstand == 2) & (track == 2)) {
            t->unk30 = D_800FD170_MarioBandstand[info->idx] + 1;
        }
    }
}
