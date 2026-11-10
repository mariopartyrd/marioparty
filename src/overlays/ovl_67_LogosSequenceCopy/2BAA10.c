#include "logos.h"

void func_800532E0(void);
void func_800F6BA0_LogosSequenceCopy(void);
s32 func_800F6C94_LogosSequenceCopy(s32 arg0, s32 arg1, s32 arg2);
u8 func_8007FF58(void);
void func_80081990(someStruct*, u8*, OSMesgQueue*);
void LeoBootGame(void*);
extern OSThread D_800F77D0_LogosSequenceCopy;
extern OSMesg D_800F6FA8_LogosSequenceCopy;
extern OSMesg D_800F6FC8_LogosSequenceCopy;
extern OSMesgQueue D_800F6FB0_LogosSequenceCopy;

s32 D_800F6F70_LogosSequenceCopy = 0;
s32 D_800F6F74_LogosSequenceCopy[] = {0x00110000, 0x00110001, 0x00110002};

typedef struct UnkStruct {
    s32 unk_00[4]; /* an nnsched client: pointer-wide, as it is 24 bytes on the host */
} UnkStruct; //sizeof 0x10

void func_800F6610_LogosSequenceCopy(unkLogoStruct* arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    void* temp_s6;
    s32 i;
    u8 character;

    temp_s6 = DataRead(0x110005);
    sprintf(pfStrBuf, "%02d", arg2);

    for (i = 0; i < 2; i++) {
        character = pfStrBuf[i];
        arg0->unkC[arg1] = func_800678A4(temp_s6);
        func_80067208(arg0->unkA, arg1, arg0->unkC[arg1], ASCII_DIGIT_TO_INT(character));
        func_80067384(arg0->unkA, arg1, 0xA);
        func_800674BC(arg0->unkA, arg1, 0x1000);
        func_80066DC4(arg0->unkA, arg1, arg3, arg4);
        func_80067558(arg0->unkA, arg1, 255, 255, 255, 255);
        arg1 += 1;
        arg3 += 0x10;        
    }

    DataClose(temp_s6);
}


void func_800F6778_LogosSequenceCopy(void) {
    unkLogoStruct* temp_s1;
    void* data;
    s32 var_s3;

    SetFadeInTypeAndTime(0, 0);
    func_800532E0();
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    temp_s1 = func_800533F8(6, 0);
    switch (D_800F6F70_LogosSequenceCopy) {
    case -1:
        var_s3 = 2;
        break;
    case 0x2C:
        var_s3 = 1;
        break;
    case 0x25: /* retail: this 64DD error code hangs here */
        while (1) {
        }
    default:
        var_s3 = 0;
        break;
    }
    data = DataRead(D_800F6F74_LogosSequenceCopy[var_s3]);
    temp_s1->unkC[0] = func_800678A4(data);
    func_80067208(temp_s1->unkA, 0, temp_s1->unkC[0], 0);
    func_80067384(temp_s1->unkA, 0, 0xA);
    func_800674BC(temp_s1->unkA, 0, 0x1000);
    func_80066DC4(temp_s1->unkA, 0, 0xA0, 0x64);
    func_80067558(temp_s1->unkA, 0, 255, 255, 255, 255);
    DataClose(data);
    data = DataRead(0x110003);
    temp_s1->unkC[1] = func_800678A4(data);
    func_80067208(temp_s1->unkA, 1, temp_s1->unkC[1], 0);
    func_80067384(temp_s1->unkA, 1, 0xA);
    func_800674BC(temp_s1->unkA, 1, 0x1000);
    func_80066DC4(temp_s1->unkA, 1, 0xA0, 0xA0);
    func_80067558(temp_s1->unkA, 1, 255, 255, 255, 255);
    DataClose(data);
    switch (var_s3) {
    case 0:
    case 2:
            data = DataRead(0x110006);
            temp_s1->unkC[2] = func_800678A4(data);
            func_80067208(temp_s1->unkA, 2, temp_s1->unkC[2], 0);
            func_80067384(temp_s1->unkA, 2, 0xA);
            func_800674BC(temp_s1->unkA, 2, 0x1000);
            func_80066DC4(temp_s1->unkA, 2, 0xA0, 0xBE);
            func_80067558(temp_s1->unkA, 2, 255, 255, 255, 255);
            DataClose(data);
        break;
    }
    if (D_800F6F70_LogosSequenceCopy >= 0) {
        data = DataRead(0x110004);
        temp_s1->unkC[3] = func_800678A4(data);
        func_80067208(temp_s1->unkA, 3, temp_s1->unkC[3], 0);
        func_80067384(temp_s1->unkA, 3, 0xA);
        func_800674BC(temp_s1->unkA, 3, 0x1000);
        func_80066DC4(temp_s1->unkA, 3, 0xA0, 0x3C);
        func_80067558(temp_s1->unkA, 3, 255, 255, 255, 255);
        DataClose(data);
        /* the error code's low half (retail reads it as an s16 at offset 2) */
        func_800F6610_LogosSequenceCopy(temp_s1, 4, (s16)D_800F6F70_LogosSequenceCopy, 0xB0, 0x3C);
    }
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F6AD4_LogosSequenceCopy(void) {
    s32 var_s0;

    var_s0 = 1;
    omInitObjMan(0xA, 0xA);
    LeoDriveExistBool = func_800827C0() == 1;
    if (LeoDriveExistBool != 0) {
        D_800F6F70_LogosSequenceCopy = LeoDriveExist(0x95, 0x96, &D_800ECDE8, 8);
        if (D_800F6F70_LogosSequenceCopy != 0) {
            LeoDriveExistBool = 0;
        } else if (osGetMemSize() < 0x800000) { //if memsize is less than 8MB
            omAddPrcObj(func_800F6778_LogosSequenceCopy, 0x5000, 0, 0);
            D_800F6F70_LogosSequenceCopy = 0x2C;
            var_s0 = 0;
        }
    }
    if (var_s0 != 0) {
        omOvlGotoEx(0x66, 0, 0x91);
    }
}

void func_800F6BA0_LogosSequenceCopy(void) {
    UnkStruct sp10; //could be incorrect
    s32 mesg;

    osCreateMesgQueue(&D_800F7980_LogosSequenceCopy, &D_800F7998_LogosSequenceCopy, 1);
    //TODO: fix type of sp10 so it's consistent across repo
    func_800639F8((void*)&sp10, &D_800F7980_LogosSequenceCopy, 2);
    osRecvMesg(&D_800F7980_LogosSequenceCopy, (OSMesg) &mesg, 1);
    if (mesg == 2) {
        func_8007FEA4();
    }
    func_80063A5C(&sp10);
    osDestroyThread(NULL);
}

void func_800F6C1C_LogosSequenceCopy(void) {
    osCreateThread(&D_800F77D0_LogosSequenceCopy, 1, (void (*)(void*))func_800F6BA0_LogosSequenceCopy, NULL,
                   (u8*)&D_800F6FC8_LogosSequenceCopy + 0x808, 10); /* top of the 0x800-byte stack below the thread */
    osStartThread(&D_800F77D0_LogosSequenceCopy);
}
void func_800F6C6C_LogosSequenceCopy(void) {
    osSendMesg(&D_800F7980_LogosSequenceCopy, 0, 1);
}

s32 func_800F6C94_LogosSequenceCopy(s32 arg0, s32 arg1, s32 arg2) {
    someStruct sp18;
    s32 sp38;

    func_800819F0(&sp18, 0, arg1, arg0, arg2, &D_800F6F90_LogosSequenceCopy);
    osRecvMesg(&D_800F6F90_LogosSequenceCopy, (OSMesg) &sp38, 1);
    return sp38;
}

s32 func_800F6CEC_LogosSequenceCopy(void) {
    someStruct sp10;
    u8 sp30[0x20];
    s32 sp50;
    s16 i;
    s32* leoRam = ((s32*)0x80400000);

    osCreateMesgQueue(&D_800F6F90_LogosSequenceCopy, &D_800F6FA8_LogosSequenceCopy, 1);
    i = 30;
    do {
        func_8007FF58();
        func_80081990(&sp10, sp30, &D_800F6F90_LogosSequenceCopy);
        osRecvMesg(&D_800F6F90_LogosSequenceCopy, (OSMesg*)&sp50, 1);
        if (sp50 == 0) {
            break;
        }
        if (sp50 != 0x2B) {
            return sp50;
        }
        osRecvMesg(&D_800F6FB0_LogosSequenceCopy, NULL, 1);
        i--;
    } while (i != 0);
    if (i == 0) {
        return sp50;
    }
    if (bcmp(sp30, "ELBE", 4) != 0) {
        return -1;
    }
    sp50 = func_800F6C94_LogosSequenceCopy((s32)(s32)leoRam, 0x31, 1);
    if (sp50 != 0) {
        return sp50;
    }
    sp50 = func_800F6C94_LogosSequenceCopy((s32)(s32)leoRam, leoRam[0], leoRam[1]);
    if (sp50 != 0) {
        return sp50;
    }
    LeoBootGame(((void*)0x80400000));
    return -1;
}
s32 func_8000B358(void);
void func_8006073C(void);
void func_800F6778_LogosSequenceCopy(void);
void func_800F6C1C_LogosSequenceCopy(void);
void func_800F6C6C_LogosSequenceCopy(void);
s32 func_800F6CEC_LogosSequenceCopy(void);

extern s32 D_800F6F70_LogosSequenceCopy;
extern OSMesgQueue D_800F6FB0_LogosSequenceCopy;
extern void* D_800F6FC8_LogosSequenceCopy;
extern s32 LeoDriveExistBool;

void func_800F6E10_LogosSequenceCopy(void) {
    UnkStruct sp10;
    s32 i;
    s32 var_s1;

    var_s1 = 1;
    omInitObjMan(0xA, 0xA);

    if (LeoDriveExistBool != 0) {
        osCreateMesgQueue(&D_800F6FB0_LogosSequenceCopy, &D_800F6FC8_LogosSequenceCopy, 1);
        //TODO: fix type of sp10 so it's consistent across repo
        func_800639F8((void*)&sp10, &D_800F6FB0_LogosSequenceCopy, 1);
        func_80060198();
        func_8006073C();
        
        for (i = 5; i != 0; i--) {
            osRecvMesg(&D_800F6FB0_LogosSequenceCopy, NULL, 1);
        }

        while (func_8000B358() != 0) {
            osRecvMesg(&D_800F6FB0_LogosSequenceCopy, NULL, 1);
        }

        func_800F6C1C_LogosSequenceCopy();
        D_800F6F70_LogosSequenceCopy = func_800F6CEC_LogosSequenceCopy();
        func_800F6C6C_LogosSequenceCopy();
        func_80063A5C(&sp10);

        if ((D_800F6F70_LogosSequenceCopy != 0) && (D_800F6F70_LogosSequenceCopy != 0x2A)) {
            omAddPrcObj(func_800F6778_LogosSequenceCopy, 0x5000U, 0, 0);
            var_s1 = 0;
        }
    }

    if (var_s1 != 0) {
        omOvlReturnEx(1);
    }
}
