#include "common.h"


s32 func_8000B13C(void);
s32 func_8000B210(void);
extern OSMesg D_800CD9C8;
extern OSMesgQueue D_800CDA90;
extern s8 D_800ECB2C;
void func_800130A4(Addr*);
void alSeqpDelete(s32);
void alSndpDelete(s32);
extern s32 D_800CDAD4;
extern s32 D_800CDAEC;
extern s32 D_800CEA8C;
extern s32 D_800CEAA0;
extern s32 D_800CDACC;
extern s32 D_800CDAEC;
extern s32 D_800CDAF0;
extern f32 D_800CDAF4;
extern f32 D_800CDAF8;
extern s16 D_800CDAFE;
extern s16 D_800CDB02;

//FXDO related
typedef struct FXDO_Unk {
/* 0x00 */ char unk_00[4];
/* 0x04 */ s32 unk_04;
} FXDO_Unk; //unk size

typedef struct unkB980Struct1 {
    /* 0x00 */ s32 unk_00; /* script position */
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14[3];
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 unk_1F;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ char unk_52[1];
    /* 0x53 */ s8 unk_53;
} unkB980Struct1; //sizeof 0x54

typedef struct unkB980Struct2 {
    /* 0x00 */ s32 unk_00; /* the voice's sound */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s8 unk_22;
    /* 0x23 */ s8 unk_23;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u8 unk_26;
    /* 0x27 */ u8 unk_27;
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ s8 unk_29;
    /* 0x2A */ char unk_2A[1];
    /* 0x2B */ s8 unk_2B;
} unkB980Struct2; //sizeof 0x2C

extern FXDO_Unk* D_800CDAC8;
extern unkB980Struct2* D_800CEA94;
extern s32 D_800CEAA4;
extern unkB980Struct1* D_800CEAC0;

typedef struct FXD0_Unk2 {
    void* FXD0_header;
    void* unk_04;
    s32 unk_08;
} FXD0_Unk2;

extern FXD0_Unk2 D_800CDAA8;

void func_8001249C(s16, u8);
s32 func_8000AFF8(s32, s32, s32);
s32 alHeapDBAlloc(s32, s32, FXD0_Unk2*, s32, s32);
s32 func_8000AFA0(s32);

typedef struct B980ArgCfg {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ u16 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
} B980ArgCfg;

typedef struct B980Cfg1898 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x1C];
    /* 0x20 */ s32 unk_20;
} B980Cfg1898;

/* The view at 0x800C18A0 (file_1ACF0_struct's layout with N64-width pointers). */
typedef struct B980Cfg18A0 {
    /* 0x00 */ Addr* unk_00;
    /* 0x04 */ Addr* unk_04;
    /* 0x08 */ s32 unk_08[16];
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
} B980Cfg18A0;

typedef struct B980Cnt {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} B980Cnt;

s32 func_80061FA0(OSIoMesg*, s32, s32, s32, void*, s32, OSMesgQueue*);
void alHeapInit(FXD0_Unk2*, Addr*, Addr*);
s32 func_80012CF0(Addr*, FXD0_Unk2*);
void func_80013010(Addr*);
s32 func_8000AE50(void);
s32 func_8000B3E8(void);
s32 func_8000D65C(void);
extern B980Cnt D_800CDAB8;
extern s32 D_800CDABC;
extern s32 D_800CDAC0;
extern s32 D_800CDAC4;
extern s32 D_800CEA9C;



typedef struct B980ChlInfo {
    /* 0x00 */ s32 program;
    /* 0x04 */ u8 vol;
    /* 0x05 */ u8 pan;
    /* 0x06 */ u8 fxmix;
} B980ChlInfo;

typedef struct B980Rom {
    /* 0x00 */ s32 seq;
    /* 0x04 */ s32 seqEnd;
    /* 0x08 */ s32 ctl;
    /* 0x0C */ s32 ctlEnd;
    /* 0x10 */ s32 tbl;
} B980Rom;

/* 0x800C1870-0x800C1900: the sound engine's configuration block. Retail addresses it through
   overlapping labels and negative indices (D_800C18D4[-0x18] is D_800C1874), so it is one object
   in retail order on every build (after the flag word D_800C1870); the labels are views into it. On the host the three slots that
   hold pointers (heap base and length, the 0x208-byte record) live in host-only variables. */
s32 D_800C1870 = 0; /* state flags */
struct {
    s32 w[32];
    u8 D_800C18F4;
    u8 pad[3];
    s32 tail[2];
} B980Config = {
    {
        0, 0, 0, 0, 0,                      /* 1874 B980Rom: seq, seqEnd, ctl, ctlEnd, tbl */
        0, 0, 0, 0, 0, 0, 0, 0,             /* 1888 */
        32000, 0x18, 0x200, 1, 0, 0x1000, 0x20, 0x800, 1, 1, 0x3C, /* 18A8 */
        0x18, 0x100, 2, 0xB, 0x180, 0, 0, 0, /* 18D4 */
    },
    1, { 0, 0, 0 }, { 0, 0 },
};
/* N64: distinct objects, as retail's code addresses them; undefined_syms.txt places each label
   at its offset in D_800C1870. */
extern Addr D_800C1874;
extern s32 D_800C1878[];
extern s32 D_800C1880[];
extern s32 D_800C1888[];
extern s32 D_800C188C[];
extern s32 D_800C1890[];
extern B980Cfg1898 D_800C1898;
extern B980Cfg18A0 D_800C18A0;
extern s32 D_800C18A8;
extern s32 D_800C18AC[];
extern s32 D_800C18B4[];
extern s32 D_800C18B8;
extern s32 D_800C18D4[];
extern s32 D_800C18DC[];
extern s32 D_800C18E0[];
extern u8 D_800C18F4;
#define B980_HEAP_BASE D_800C18A0.unk_00
#define B980_HEAP_LEN D_800C18A0.unk_04
#define B980_RECORD D_800C1898.unk_20

typedef struct ALSeqpConfig {
    /* 0x00 */ s32 maxVoices;
    /* 0x04 */ s32 maxEvents;
    /* 0x08 */ u8 maxChannels;
    /* 0x09 */ u8 debugFlags;
    /* 0x0C */ FXD0_Unk2* heap;
    /* 0x10 */ void* initOsc;
    /* 0x14 */ void* updateOsc;
    /* 0x18 */ void* stopOsc;
} ALSeqpConfig;

typedef struct B980SeqEnt {
    /* 0x00 */ s32 offset;
    /* 0x04 */ s32 len;
} B980SeqEnt;

typedef struct B980SeqHdr {
    /* 0x00 */ s16 magic;
    /* 0x02 */ s16 count;
    /* 0x04 */ B980SeqEnt seq[1];
} B980SeqHdr;

typedef struct B980BankEnt {
    /* 0x00 */ u8 bank;
    /* 0x01 */ u8 vol;
    /* 0x04 */ s32 ctl;
    /* 0x08 */ s32 ctlSize;
    /* 0x0C */ s32 tbl;
} B980BankEnt;

// oscillator state (initOsc/updateOsc/stopOsc of the sequence player)
typedef struct B980Osc {
    /* 0x00 */ struct B980Osc* next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 stateFlags;
    /* 0x06 */ u16 maxCount;
    /* 0x08 */ u16 curCount;
    /* 0x0C */ union {
        struct { u8 halfdepth; u8 baseVol; } tsin;
        struct { u8 curVal; u8 hiVal; u8 loVal; } tsqr;
        struct { u8 baseVol; u8 depth; } tsaw;
        struct { f32 depthcents; } vsin;
        struct { f32 loRatio; f32 hiRatio; } vsqr;
        struct { s32 cents; s32 centsrange; } vsaw;
    } data;
} B980Osc; // sizeof 0x14

void alCSPNew(s32, ALSeqpConfig*);
void alSeqFileNew(B980SeqHdr*, s32);
void alBnkfNew(s32, s32);
s32 func_8000C808(B980Osc** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay);
f32 func_8000D618(u8);
f32 alCents2Ratio(s32);
s32 func_8000CCC0(B980Osc* osc, f32* updateVal);
void func_8000D600(B980Osc*);

typedef struct ALSndpConfig {
    /* 0x00 */ s32 maxSounds;
    /* 0x04 */ s32 maxEvents;
    /* 0x08 */ FXD0_Unk2* heap;
} ALSndpConfig;

typedef struct B980SndHdr {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 ctl;
    /* 0x08 */ s32 ctlSize;
    /* 0x0C */ s32 tbl;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} B980SndHdr; // sizeof 0x24

// ALWaveTable
typedef struct B980Wave {
    /* 0x00 */ s32 base;
    /* 0x04 */ s32 len;
    /* 0x08 */ u8 type;
    /* 0x09 */ u8 flags;
    /* 0x0C */ s32 loop;
    /* 0x10 */ s32 book;
} B980Wave;

// ALSound
typedef struct B980Sound {
    /* 0x00 */ s32 envelope;
    /* 0x04 */ s32 keyMap;
    /* 0x08 */ B980Wave* wavetable;
    /* 0x0C */ u8 samplePan;
    /* 0x0D */ u8 sampleVolume;
    /* 0x0E */ u8 flags;
} B980Sound; // sizeof 0x10

void func_80010110(s16);

// sound-effect table entry (D_800CEA90 when it holds a 0x543x sound list)
typedef struct B980SfxEnt {
    /* 0x00 */ s8 b0;
    /* 0x01 */ s8 b1;
    /* 0x02 */ u8 b2;
    /* 0x03 */ u8 b3;
    /* 0x04 */ u16 flags;
    /* 0x06 */ u16 rate;
} B980SfxEnt;

typedef struct B980SfxExt {
    /* 0x00 */ u8 b0;
    /* 0x01 */ u8 b1;
    /* 0x02 */ u8 b2;
    /* 0x03 */ u8 b3;
    /* 0x04 */ char unk_04[4];
} B980SfxExt;

typedef struct B980SndParam {
    /* 0x00 */ s32 sound;
    /* 0x04 */ f32 pitch;
    /* 0x08 */ s32 flags;
    /* 0x0C */ s16 id;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 vol;
    /* 0x12 */ s8 pan;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ s8 unk_15;
    /* 0x16 */ s8 unk_16;
    /* 0x17 */ s8 unk_17;
    /* 0x18 */ u8 unk_18;
} B980SndParam;

// ALInstrument / ALBank / ALBankFile
typedef struct B980Inst {
    /* 0x00 */ u8 volume;
    /* 0x01 */ u8 pan;
    /* 0x02 */ u8 priority;
    /* 0x03 */ u8 flags;
    /* 0x04 */ u8 trem[4];
    /* 0x08 */ u8 vib[4];
    /* 0x0C */ s16 bendRange;
    /* 0x0E */ s16 soundCount;
    /* 0x10 */ B980Sound* soundArray[1];
} B980Inst;

typedef struct B980Bank {
    /* 0x00 */ s16 instCount;
    /* 0x02 */ u8 flags;
    /* 0x03 */ u8 pad;
    /* 0x04 */ s32 sampleRate;
    /* 0x08 */ B980Inst* percussion;
    /* 0x0C */ B980Inst* instArray[1];
} B980Bank;

typedef struct B980BankFile {
    /* 0x00 */ s16 revision;
    /* 0x02 */ s16 bankCount;
    /* 0x04 */ B980Bank* bankArray[1];
} B980BankFile;

extern s16 D_800CEAB6;
void alSndpSetPitch(s32, f32);
void alSndpSetVol(s32, s16);
void alSndpSetFXMix(s32, u8);
void alSndpSetPan(s32, u8);
s16 alSndpGetSound(s32);
s32 alSndpGetState(s32);
void alSndpDeallocate(s32, s16);
void alSndpStop(s32);
void func_8001165C(void);
void func_8000F4E0(void);
void func_8000DE5C(s16);
void func_8000DDEC(void);

// echo slot
typedef struct B980SfxSlot {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 voice;
    /* 0x04 */ s8 vol;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ s8 mode;
    /* 0x08 */ s8 delay;
    /* 0x09 */ s8 count;
    /* 0x0A */ char unk_0A[2];
} B980SfxSlot; // sizeof 0xC

s32 func_80010C4C(s16);
void func_800123DC(s16, s8);
s16 func_80010040(s16);
s32 guRandom(void);
void func_80012574(s16, s16);
void func_80012654(s16, s8);
void func_80011164(s16);
void func_80012140(s16, s8);
void func_800108C8(s16, s8);
void func_80010A68(s16, s16);
void func_80010B38(s16, s8);
void func_80012260(s16, f32);
void func_800117AC(s16);
void func_8000F198(s16);
void func_80011D48(s16, s16, f32);
s16 func_80010C78(s16, s32);
s16 func_80010ED4(s16, s16);
void func_80010148(unkB980Struct2*, unkB980Struct1*);
void func_80010734(unkB980Struct2*, unkB980Struct1*);
void func_8001085C(unkB980Struct2*, unkB980Struct1*);

typedef struct B980SfxState {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ char unk_0F[1];
} B980SfxState; // sizeof 0x10

extern B980SfxState* D_800CEAC4;
extern f32 D_800CEAC8;
extern f32 D_800CEACC;
extern f32 D_800CEAD0;
extern f32 D_800CEAD4;
extern s16 D_800CEAD8;
extern s16 D_800CEADA;
extern f32 D_800CEADC;
extern f32 D_800CEAE0;
extern B980SfxSlot* D_800CEAE4;
extern f32 D_800CEAE8;
extern f32 D_800CEAEC;
extern s32 D_800CEAF0;
extern s8 D_800CEAF4;
extern s8 D_800CEAF5;
extern s8 D_800CEAF6;
void func_8000F238(void);
void func_8000E818(s16*, s16*, s16, s16);
s16 func_8000E448(B980SndParam*, s32);
s16 alSndpAllocate(s32, s32);
void alSndpSetPriority(s32, s16, u8);
void alSndpSetSound(s32, s16);
void alSndpPlay(s32);
void func_8000F780(s16, s16, s8);
void func_8000F844(s16);
void func_8000F294(s16, s8);
void func_8000E92C(s16);
B980SfxEnt* func_8000DF98(s16, B980SndParam*);
B980Sound* func_8000E2D0(B980BankFile*, u8, u8, u8);
B980Sound* func_8000E340(B980BankFile*, s16);

void func_800643D0(s32, ALSndpConfig*); /* the sound player handle; s32 on the N64 */
s32 func_8000DA04(s32);
s32 func_8000DA7C(void);
s32 func_8000DB24(B980SndHdr*);
s32 func_8000DC44(B980SndHdr*);
s32 func_8000DCCC(B980SndHdr*);
s16 func_8000E21C(B980BankFile*);
s32 func_8000F078(void);
s32 func_8000F118(void);
extern void* D_800CEA88;
extern B980SeqHdr* D_800CEA90;
extern s32 D_800CEA98;
extern f32 D_800CEAA8;
extern f32 D_800CEAAC;
extern s16 D_800CEAB0;
extern s16 D_800CEAB2;
extern s16 D_800CEAB4;
extern s8 D_800CEAB8;
extern u8 D_800CEAB9;
extern s8 D_800CEABA;
extern s32* D_800CEABC;
extern s8 D_800CEABB;
s32 func_8000B7EC(s32);
extern s32 D_800CDAD0;
extern s32 D_800CDAD8;
extern s32 D_800CDADC;
extern B980SeqHdr* D_800CDAE0;
extern B980BankEnt* D_800CDAE4;
extern s32 D_800CDAE8;
extern B980Osc* D_800CDB04;
extern B980Osc D_800CDB10;
extern B980Osc D_800CDB24[];
extern s32 D_800CD9C0;
extern s16 D_800CDAFC;
extern s16 D_800CDB00;
void alSeqpSetBank(s32, s32);
void alCSeqNew(s32, s32);
void alSeqpSetSeq(s32, s32);
void alSeqpSetVol(s32, s16);
void alSeqpPlay(s32);
void alSeqpStop(s32);
s32 alSeqpGetState(s32);
void func_8000B844(void);
void alSeqpSetTempo(s32, s32);
s32 alCSPGetTempo(s32);
s32 alSeqpGetChlProgram(s32, u8);
u8 alSeqpGetChlVol(s32, u8);
u8 alSeqpGetChlPan(s32, u8);
u8 alSeqpGetChlFXMix(s32, u8);
void alSeqpSetChlFXMix(s32, u8, s32);
s16 func_8000BEEC(s16, s32, s32);
s32 func_8000C144(void);


void func_8000AD80(s32 devAddr, void* vAddr, s32 size) {
    OSIoMesg mesg;

    osInvalDCache(vAddr, size);
    func_80061FA0(&mesg, 0, 0, devAddr, vAddr, size, &D_800CDA90);
    osRecvMesg(&D_800CDA90, NULL, 1);
}
s32 func_8000ADFC(s8 arg0) {
    s32 r;

    if (arg0 > 0) {
        r = arg0 << 8;
        r |= 0xFF;
    } else {
        r = 0;
    }
    return r;
}
void func_8000AE20(s16* arg0, s16 arg1) {
    if (*arg0 < 0) {
        *arg0 = 0;
    } else if (*arg0 > arg1) {
        *arg0 = arg1;
    }
}
s32 func_8000AE50(void) {
    s32 idx;

    D_800CDAC8 = (FXDO_Unk*)func_8000AFA0(8);
    if (D_800CDAC8 == NULL) {
        return 1;
    }
    D_800CDAC8->unk_04 = 0;
    if (D_800C1898.unk_00 != 0) {
        func_8000AD80(D_800C1898.unk_00, D_800CDAC8, 8);
        if (*(s32*)D_800CDAC8->unk_00 != 0x46584430) {
            D_800CDAC8->unk_04 = 0;
        }
    }
    if (D_800C18B4[0] >= 20) {
        idx = D_800C18B4[0] - 20;
        if (idx < D_800CDAC8->unk_04) {
            idx = D_800C1898.unk_00 + idx * 0x208 + 0x10;
            B980_RECORD = func_8000AFA0(0x208);
            if (B980_RECORD == 0) {
                return 1;
            }
            func_8000AD80(idx, (void*)B980_RECORD, 0x208);
            return 0;
        }
    } else if (D_800C18B4[0] < 6) {
        D_800C18B4[1] = 0;
        return 0;
    } else if (D_800C18B4[0] == 6 && D_800C18B4[1] != 0) {
        return 0;
    }
    func_8000AFF8(0, 0, 0x20);
    return 100;
}
s32 func_8000AFA0(s32 arg0) {
    s32 temp_v0 = alHeapDBAlloc(0, 0, &D_800CDAA8, 1, arg0);

    if (temp_v0 == 0) {
        func_8000AFF8(0, 0, 1);
    }
    return temp_v0;
}

s32 func_8000AFF8(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

void func_8000B000(s32 arg0) {
    D_800CDACC = arg0;
}

s32 func_8000B00C(s32 arg0, s32 arg1, Addr* arg2, Addr* arg3) {
    D_800C18A0.unk_48 = arg0;
    D_800C18A0.unk_4C = arg1;
    D_800C18A0.unk_50 = 1;
    B980_HEAP_BASE = arg2;
    B980_HEAP_LEN = arg3;
    return func_8000B13C();
}

void func_8000B044(B980ArgCfg* arg0) {
    D_800C18AC[0] = arg0->unk_04;
    D_800C18AC[1] = arg0->unk_08;
    D_800C18AC[2] = arg0->unk_10;
    D_800C18AC[3] = arg0->unk_14;
    D_800C18AC[10] = arg0->unk_18;
    D_800C18AC[11] = arg0->unk_1C;
    D_800C18AC[12] = arg0->unk_20;
    D_800C18AC[13] = arg0->unk_24;
    D_800C18AC[14] = arg0->unk_28;
    D_800C18AC[5] = arg0->unk_2C;
    D_800C18AC[6] = arg0->unk_30;
    D_800C18AC[8] = arg0->unk_34;
    D_800C18AC[4] = arg0->unk_38;
    D_800C18AC[-1] = arg0->unk_0C;
}
void func_8000B0C0(B980ArgCfg* arg0) {
    arg0->unk_04 = D_800C18AC[0];
    arg0->unk_08 = D_800C18AC[1];
    arg0->unk_10 = D_800C18AC[2];
    arg0->unk_14 = D_800C18AC[3];
    arg0->unk_18 = D_800C18AC[10];
    arg0->unk_1C = D_800C18AC[11];
    arg0->unk_20 = D_800C18AC[12];
    arg0->unk_24 = D_800C18AC[13];
    arg0->unk_28 = D_800C18AC[14];
    arg0->unk_2C = D_800C18AC[5];
    arg0->unk_30 = D_800C18AC[6];
    arg0->unk_34 = D_800C18AC[8];
    arg0->unk_38 = D_800C18AC[4];
    arg0->unk_0C = D_800C18AC[-1];
}
s32 func_8000B13C() {
    osCreateMesgQueue(&D_800CDA90, &D_800CD9C8, 50);
    D_800ECB2C = 0;
    if (B980_HEAP_BASE != 0) {
        if (B980_HEAP_LEN != 0) {
            return func_8000B210();
        }
    }
    return 1;
}

s32 func_8000B198() {
    if (D_800CDAEC == 0) {
        if (D_800CEAA0 == 0) {
            if (D_800C1870 & 0x8000) {
                alSeqpDelete(D_800CDAD4);
                alSndpDelete(D_800CEA8C);
                func_800130A4(&D_800C1874);
                D_800C1870 = 0;
                return 0;
            }
        } else {
            return 1;
        }
        return 0;
    }
    return 1;
}

s32 func_8000B210(void) {
    s32 ret;

    alHeapInit(&D_800CDAA8, B980_HEAP_BASE, B980_HEAP_LEN);
    D_800CDAB8.unk_00 = D_800CDAB8.unk_04 = D_800CDAB8.unk_08 = D_800CDAB8.unk_0C = 0;
    if ((ret = func_8000AE50()) != 0) {
        return ret;
    }
    if ((ret = func_80012CF0(&D_800C1874, &D_800CDAA8)) != 0) {
        return ret;
    }
    if ((ret = func_8000B3E8()) != 0) {
        return ret;
    }
    if ((ret = func_8000D65C()) != 0) {
        return ret;
    }
    func_80013010(&D_800C1874);
    D_800C1870 = 0x8000;
    return 0;
}
Addr* func_8000B2BC() {
    return &D_800C1874;
}

s32 func_8000B2C8() {
    if (D_800C1870 & 0x8000) {
        return D_800CDAC8->unk_04;
    }
    return 0;
}

s32 func_8000B2F0() {
    return 0x610032;
}

s32 func_8000B2FC() {
    return D_800CDAA8.unk_08 - (D_800CDAA8.unk_04 - D_800CDAA8.FXD0_header);
}

s32 func_8000B31C(void) {
    return D_800CDAB8.unk_00;
}
void func_8000B328(void) {
    D_800CDAB8.unk_00 = 0;
}
s32 func_8000B334(void) {
    return D_800CDABC;
}
s32 func_8000B340(void) {
    return D_800CDAC0;
}
s32 func_8000B34C(void) {
    return D_800CDAC4;
}
s32 func_8000B358(void) {
    return D_800CDACC;
}
void func_8000B364(s32 arg0) {
    s32 i;

    D_800ECB2C = arg0 & 1;
    for (i = 0; i < D_800CEA9C; i++) {
        unkB980Struct2* p = &D_800CEA94[i];
        if (p->unk_0C == 1) {
            p->unk_08 |= 4;
        }
    }
}
s32 func_8000B3E0(void) {
    return 0;
}
// register allocation: seqMax/bankSize swap s1/s2 (masked 0)
#ifdef NON_MATCHING
s32 func_8000B3E8(void) {
    ALSeqpConfig cfg;
    s32 bankSize;
    s32 seqMax;
    s32 sel;
    s32 ctlAddr;
    s32 tblAddr;
    s32 size;
    s32 i;
    s16 count;
    B980BankEnt* bank;
    B980Osc* link;

    sel = 0;
    D_800CDAF0 = 0;
    D_800CDAEC = 0;
    D_800CDAF4 = 0.0f;
    D_800CDB02 = 0x7FFF;
    D_800CDAD4 = func_8000AFA0(0x7C);
    if (D_800CDAD4 == 0) {
        return 1;
    }
    cfg.maxVoices = D_800C18D4[0];
    cfg.maxEvents = D_800C18D4[1];
    cfg.maxChannels = 16;
    cfg.debugFlags = 0;
    cfg.heap = &D_800CDAA8;
    cfg.initOsc = func_8000C808;
    cfg.updateOsc = func_8000CCC0;
    cfg.stopOsc = func_8000D600;
    alCSPNew(D_800CDAD4, &cfg);
    if (D_800C18D4[-0x18] == 0) { // D_800C1874
        return 0;
    }
    if (func_8000B7EC(4) != 0) {
        return 1;
    }
    count = D_800CDAE0->count;
    switch (D_800CDAE0->magic) {
        case 0x5331:
            if (func_8000B7EC(count * 8 + 4) != 0) {
                return 1;
            }
            seqMax = 0;
            alSeqFileNew(D_800CDAE0, ((B980Rom*)&D_800C1874)->seq);
            for (i = 0; i < count; i++) {
                if (seqMax < D_800CDAE0->seq[i].len) {
                    seqMax = D_800CDAE0->seq[i].len;
                }
            }
            bankSize = D_800C1880[0] - D_800C1880[-1];
            tblAddr = D_800C1880[1];
            ctlAddr = D_800C1880[-1];
            size = bankSize;
            break;
        case 0x5332:
            size = count;
            if (func_8000B7EC(size * 24 + 4) != 0) {
                return 1;
            }
            D_800CDAE4 = (B980BankEnt*)&D_800CDAE0->seq[count];
            seqMax = 0;
            bankSize = 0;
            for (i = 0; i < count; i++) {
                if (D_800CDAE0->seq[i].len >= 0) {
                    D_800CDAE0->seq[i].offset += ((B980Rom*)&D_800C1874)->seq;
                    bank = &D_800CDAE4[i];
                    bank->ctl += ((B980Rom*)&D_800C1874)->seq;
                    bank->tbl += ((B980Rom*)&D_800C1874)->seq;
                    sel = i;
                    if (bankSize < bank->ctlSize) {
                        bankSize = bank->ctlSize;
                    }
                    if (seqMax < D_800CDAE0->seq[i].len) {
                        seqMax = D_800CDAE0->seq[i].len;
                    }
                }
            }
            ctlAddr = D_800CDAE4[sel].ctl;
            tblAddr = D_800CDAE4[sel].tbl;
            size = D_800CDAE4[sel].ctlSize;
            break;
        default:
            seqMax = D_800C1878[0] - D_800C1878[-1];
            bankSize = D_800C1878[2] - D_800C1878[1];
            D_800CDAE0->count = 1;
            ctlAddr = D_800C1878[1];
            tblAddr = D_800C1878[3];
            size = bankSize;
            break;
    }
    if (bankSize == 0 || seqMax == 0) {
        return 0;
    }
    if ((D_800CDADC = func_8000AFA0(0xF8)) == 0
        || (D_800CDAD8 = func_8000AFA0(seqMax + (seqMax & 1))) == 0
        || (D_800CDAD0 = func_8000AFA0(bankSize + (bankSize & 1))) == 0) {
        return 1;
    }
    func_8000AD80(ctlAddr, (void*)D_800CDAD0, size + (size & 1));
    alBnkfNew(D_800CDAD0, tblAddr);
    D_800CDAE8 = ctlAddr;
    D_800CDB04 = &D_800CDB10;
    link = &D_800CDB10;
    for (i = 0; i < 197; i++) {
        link->next = &D_800CDB24[i];
        link = &D_800CDB24[i];
    }
    link->next = NULL;
    D_800CDAF0 = 0x8000;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/B980", func_8000B3E8);
#endif

s32 func_8000B7EC(s32 size) {
    B980SeqHdr* p;

    size += size & 1;
    D_800CDAE0 = p = (B980SeqHdr*)func_8000AFA0(size);
    if (p == NULL) {
        return 1;
    }
    func_8000AD80(((B980Rom*)&D_800C1874)->seq, p, size);
    return 0;
}

void func_8000B844(void) {
    B980BankEnt* bankEnt;
    B980SeqEnt* seqEnt;
    s32 ctlAddr;
    s32 tblAddr;
    s32 size;
    s32 off;
    s32 addr;
    u8 bank;

    if (D_800CDAF0 & 0x10) {
        return;
    }
    bank = 0;
    if (D_800CDAE0->magic == 0x5332) {
        bankEnt = &D_800CDAE4[D_800CDAFC];
        ctlAddr = bankEnt->ctl;
        tblAddr = bankEnt->tbl;
        size = bankEnt->ctlSize;
        bank = bankEnt->bank;
        if (ctlAddr != D_800CDAE8) {
            if (D_800CDAF0 & 0x100) {
                off = size - D_800CD9C0;
                if (D_800CD9C0 > 0x4000) {
                    size = 0x4000;
                } else {
                    size = D_800CD9C0;
                }
                func_8000AD80(ctlAddr + off, (void*)(off + D_800CDAD0), size);
                D_800CD9C0 -= size;
                if (D_800CD9C0 != 0) {
                    return;
                }
                D_800CDAF0 &= ~0x100;
            } else if (size > 0x4000) {
                D_800CD9C0 = size - 0x4000;
                D_800CDAF0 |= 0x100;
                func_8000AD80(ctlAddr, (void*)D_800CDAD0, 0x4000);
                return;
            } else {
                func_8000AD80(ctlAddr, (void*)D_800CDAD0, size);
            }
            alBnkfNew(D_800CDAD0, tblAddr);
            D_800CDAE8 = ctlAddr;
            return;
        }
    }
    if (!(D_800CDAF0 & 0x200)) {
        D_800CDAF0 |= 0x200;
        switch (D_800CDAE0->magic) {
            case 0x5331:
            case 0x5332:
                seqEnt = &D_800CDAE0->seq[D_800CDAFC];
                size = seqEnt->len;
                addr = seqEnt->offset;
                break;
            default:
                off = D_800C1878[0];
                addr = D_800C1878[-1];
                size = off - addr;
                break;
        }
        func_8000AD80(addr, (void*)D_800CDAD8, size + (size & 1));
        return;
    }
    alSeqpSetBank(D_800CDAD4, ((s32*)D_800CDAD0)[bank + 1]);
    alCSeqNew(D_800CDADC, D_800CDAD8);
    alSeqpSetSeq(D_800CDAD4, D_800CDADC);
    if (D_800CDAF0 & 8) {
        alSeqpSetVol(D_800CDAD4, 0);
    } else {
        alSeqpSetVol(D_800CDAD4, (D_800CDB02 * D_800CDB00) / 32767);
    }
    if (D_800CDAF0 & 2) {
        D_800CDAF0 &= ~1;
    } else {
        alSeqpPlay(D_800CDAD4);
        D_800CDAF0 = 0x8000;
    }
}

void func_8000BB30(void) {
    s32 state;
    s16 vol;

    state = alSeqpGetState(D_800CDAD4);
    switch (state) {
        case 1:
            if (D_800CDAEC != 2) {
                D_800CDAEC = 1;
            }
            break;
        case 2:
            D_800CDAEC = state;
            if (D_800CDAF0 & 3) {
                D_800CDAEC = 1;
            }
            break;
        default:
            if (D_800CDAF0 & 1) {
                D_800CDAEC = 1;
                func_8000B844();
            } else {
                D_800CDAEC = 0;
                if (D_800CDAF0 & 2) {
                    D_800CDAEC = 1;
                }
            }
            break;
    }
    if (D_800CDAF0 & 4) {
        if (state == 0) {
            alSeqpPlay(D_800CDAD4);
            D_800CDAF0 &= ~4;
        }
        D_800CDAEC = 1;
    }
    if (state != 0) {
        if (D_800CDAF4 > 0.0f) {
            D_800CDAF8 += D_800CDAF4;
            if (D_800CDB02 <= D_800CDAF8) {
                alSeqpStop(D_800CDAD4);
                D_800CDAEC = 2;
                D_800CDAF4 = 0.0f;
            } else if (D_800CDAF8 != 0.0f) {
                vol = D_800CDB02 - D_800CDAF8;
                if (D_800CDAFE != vol) {
                    alSeqpSetVol(D_800CDAD4, (vol * D_800CDB00) / 32767);
                    D_800CDAFE = vol;
                }
            }
        }
        if (D_800CDAF4 < 0.0f && !(D_800CDAF0 & 8)) {
            D_800CDAF8 -= D_800CDAF4;
            if (D_800CDB02 <= D_800CDAF8) {
                D_800CDAF4 = 0.0f;
                vol = D_800CDB02;
            } else {
                vol = D_800CDAF8;
            }
            if (D_800CDAFE != vol) {
                alSeqpSetVol(D_800CDAD4, (vol * D_800CDB00) / 32767);
                D_800CDAFE = vol;
            }
        }
    }
}

void func_8000BE6C(void) {
    alSeqpStop(D_800CDAD4);
    alSeqpDelete(D_800CDAD4);
}

void func_8000BE98(s32 seq, s32 seqEnd, s32 ctl, s32 ctlEnd, s32 tbl) {
    (*(s32(*)[5])D_800C1874)[0] = seq;
    (*(s32(*)[5])D_800C1874)[1] = seqEnd;
    (*(s32(*)[5])D_800C1874)[2] = ctl;
    (*(s32(*)[5])D_800C1874)[3] = ctlEnd;
    (*(s32(*)[5])D_800C1874)[4] = tbl;
}

s16 func_8000BEBC(s16 arg0) {
    return func_8000BEEC(arg0, 0, 0);
}

s16 func_8000BEEC(s16 idx, s32 mode, s32 param) {
    s8 vol;

    if (!(D_800CDAF0 & 0x8000)) {
        return -1;
    }
    if ((idx >= D_800CDAE0->count) | (idx < 0)) {
        return -1;
    }
    D_800CDAF0 = 0x8010;
    switch (D_800CDAE0->magic) {
        case 0x5332:
            if (D_800CDAE0->seq[idx].len < 0) {
                D_800CDAF0 = 0x8000;
                return -1;
            }
            vol = D_800CDAE4[idx].vol;
            break;
        case 0x5331:
            if (D_800CDAE0->seq[idx].len < 0) {
                return -1;
            }
            vol = 0x7F;
            break;
        default:
            vol = 0x7F;
            break;
    }
    D_800CDB00 = func_8000ADFC(vol);
    switch (mode) {
        case 1:
            if (func_8000C144() == 1) {
                func_8000C250(param);
            }
            break;
        case 2:
            if (param >= 2) {
                D_800CDAF8 = 0;
                D_800CDAFE = 0;
                D_800CDAF4 = -((f32)D_800CDB02 / (f32)param);
                D_800CDAF0 |= 8;
            }
            break;
        case 3:
            D_800CDB00 = func_8000ADFC(param);
        default:
            D_800CDAF4 = 0.0f;
            break;
    }
    if (mode != 1 && func_8000C144() == 1) {
        alSeqpStop(D_800CDAD4);
    }
    D_800CDAEC = 1;
    D_800CDAFC = idx;
    D_800CDAF0 = (D_800CDAF0 | 1) & ~0x10;
    return 0;
}

s32 func_8000C144(void) {
    if (D_800CDAF0 & 2) {
        return 0x100;
    }
    if (D_800CDAF0 & 1) {
        return 0x200;
    }
    return D_800CDAEC;
}

s16 func_8000C184(void) {
    if (D_800CDAF0 & 0x8000) {
        return D_800CDAE0->count;
    }
    return 0;
}

s16 func_8000C1AC(void) {
    return D_800CDAFC;
}

void func_8000C1B8(void) {
    u8 i;

    if (D_800CDAF0 & 0x8000) {
        D_800CDAF0 |= 0x10;
        if (func_8000C144() == 1) {
            for (i = 0; i < 16; i++) {
                alSeqpSetChlFXMix(D_800CDAD4, i, 0);
            }
            alSeqpStop(D_800CDAD4);
            D_800CDAEC = 2;
        }
        D_800CDAF0 = 0x8000;
    }
}

void func_8000C250(s16 arg0) {
    if ((D_800CDAEC == 1) && !(D_800CDAF0 & 2)) {
        if (arg0 < 0) {
            arg0 = 1;
        }
        D_800CDAF8 = 0;
        D_800CDAFE = D_800CDB02;
        D_800CDAF4 = (f32) D_800CDB02 / arg0;
    }
}

// decomp-permuter
s16 func_8000C2D4(void)
{
  s32 new_var;
  f32 rate;
  s32 frames;
  if ((D_800CDAEC != 1) || (D_800CDAF4 == 0.0f))
  {
    return 0;
  }
  if (D_800CDAF4 < 0.0f)
  {
    rate = -D_800CDAF4;
  }
  else
  {
    rate = D_800CDAF4;
  }
  frames = (new_var = (D_800CDB02 / rate) - (D_800CDAF8 / rate));
  if (D_800CDAF4 < 0.0f)
  {
    frames = -frames;
  }
  if (D_800CDAF4)
  {
    new_var = frames;
    return new_var;
  }
  else
  {
    new_var = frames;
    return new_var;
  }
}

void func_8000C390(s8 arg0) {
    if (D_800CDAF0 & 0x8000) {
        D_800CDB00 = func_8000ADFC(arg0);
        alSeqpSetVol(D_800CDAD4, (D_800CDB02 * D_800CDB00) / 32767);
    }
}

void func_8000C414(s8 arg0) {
    if (D_800CDAF0 & 0x8000) {
        D_800CDAF4 = 0.0f;
        D_800CDB02 = func_8000ADFC(arg0);
        alSeqpSetVol(D_800CDAD4, (D_800CDB02 * D_800CDB00) / 32767);
    }
}

s8 func_8000C4A0(void) {
    return D_800CDB00 / 256;
}

void func_8000C4BC(s16 bpm) {
    if (D_800CDAF0 & 0x8000) {
        if (bpm <= 0) {
            bpm = 1;
        }
        alSeqpSetTempo(D_800CDAD4, 60.0f / bpm * 1000.0f * 1000.0f);
    }
}

s16 func_8000C544(void) {
    s32 tempo;

    if (D_800CDAF0 & 0x8000) {
        tempo = alCSPGetTempo(D_800CDAD4);
        if (tempo == 0) {
            return 0;
        }
        return 60.0f / (tempo / 1000000.0f);
    }
    return 0;
}

void func_8000C5C4(void) {
    D_800CDAF0 |= 0x10;
    D_800CDAF0 &= ~4;
    if (!(D_800CDAF0 & 2)) {
        if (func_8000C144() == 1) {
            alSeqpStop(D_800CDAD4);
        }
        D_800CDAF0 |= 2;
    }
    D_800CDAF0 &= ~0x10;
}

void func_8000C64C(s16 frames) {
    s32 tmp;
    s32 flags;

    if (D_800CDAF0 & 2) {
        tmp = D_800CDAF0 | 0x10;
        flags = tmp & ~2;
        D_800CDAF0 = flags;
        if (tmp & 1) {
            D_800CDAF0 = flags & ~0x10;
        } else {
            if (frames != 0 && D_800CDAF4 <= 0.0f) {
                D_800CDAF8 = 0.0f;
                D_800CDAFE = 0;
                alSeqpSetVol(D_800CDAD4, 0);
                D_800CDAF4 = -((f32)D_800CDB02 / frames);
            }
            D_800CDAF0 |= 4;
            D_800CDAEC = 1;
            D_800CDAF0 &= ~0x10;
        }
    }
}

// decomp-permuter
void func_8000C748(u8 chan, B980ChlInfo *info)
{
  if (D_800CDAF0 & 0x8000)
  {
    D_800CDAF0 |= 0x10;
    if (D_800CDAEC == 1)
    {
      if (D_800CDAF0 || info)
      {
        info->program = alSeqpGetChlProgram(D_800CDAD4, chan);
        info->vol = alSeqpGetChlVol(D_800CDAD4, chan);
        info->pan = alSeqpGetChlPan(D_800CDAD4, chan);
        info->fxmix = alSeqpGetChlFXMix(D_800CDAD4, chan);
        D_800CDAF0 &= ~0x10;
      }
      else
      {
        info->program = alSeqpGetChlProgram(D_800CDAD4, chan);
        info->vol = alSeqpGetChlVol(D_800CDAD4, chan);
        info->pan = alSeqpGetChlPan(D_800CDAD4, chan);
        info->fxmix = alSeqpGetChlFXMix(D_800CDAD4, chan);
        D_800CDAF0 &= ~0x10;
      }
    }
  }
}

s32 func_8000C808(B980Osc** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay) {
    B980Osc* osc;
    s32 deltaTime = 0;
    s32 cents;

    if (D_800CDB04 != NULL) {
        osc = D_800CDB04;
        D_800CDB04 = osc->next;
        osc->type = oscType;
        *oscState = osc;
        deltaTime = oscDelay << 14;
        switch (oscType) {
            case 1:
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127 - osc->data.tsin.halfdepth;
                *initVal = osc->data.tsin.baseVol;
                break;
            case 6:
            case 7:
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127;
                *initVal = 127.0f;
                break;
            case 2:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 0;
                osc->data.tsqr.loVal = 127 - oscDepth;
                osc->data.tsqr.hiVal = 127;
                osc->data.tsqr.curVal = 127;
                *initVal = 127.0f;
                break;
            case 3:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                osc->data.tsaw.depth = oscDepth;
                osc->data.tsaw.baseVol = 127;
                *initVal = 127.0f;
                break;
            case 4:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                osc->data.tsaw.depth = oscDepth;
                osc->data.tsaw.baseVol = 127 - oscDepth;
                *initVal = osc->data.tsaw.baseVol;
                break;
            case 5:
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127 - osc->data.tsin.halfdepth;
                osc->stateFlags = 0;
                *initVal = osc->data.tsin.baseVol;
                break;
            case 8:
            case 9:
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                osc->data.tsin.halfdepth = oscDepth >> 1;
                osc->data.tsin.baseVol = 127;
                osc->stateFlags = 0;
                *initVal = osc->data.tsin.baseVol;
                break;
            case 0x80:
            case 0x8A:
                osc->data.vsin.depthcents = func_8000D618(oscDepth);
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                *initVal = 1.0f;
                break;
            case 0x81:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 0;
                cents = func_8000D618(oscDepth);
                osc->data.vsqr.loRatio = alCents2Ratio(-cents);
                osc->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = osc->data.vsqr.hiRatio;
                break;
            case 0x82:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                cents = func_8000D618(oscDepth);
                osc->data.vsaw.cents = cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(osc->data.vsaw.cents);
                break;
            case 0x83:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                cents = func_8000D618(oscDepth);
                osc->data.vsaw.cents = -cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(osc->data.vsaw.cents);
                break;
            case 0x85:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 0;
                cents = func_8000D618(oscDepth);
                osc->data.vsqr.loRatio = alCents2Ratio(-cents);
                osc->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = 1.0f;
                break;
            case 0x86:
                osc->maxCount = 256 - oscRate;
                osc->curCount = osc->maxCount;
                osc->stateFlags = 1;
                cents = func_8000D618(oscDepth);
                osc->data.vsqr.loRatio = alCents2Ratio(-cents);
                osc->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = 1.0f;
                break;
            case 0x87:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                cents = func_8000D618(oscDepth);
                osc->data.vsaw.cents = cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = 1.0f;
                break;
            case 0x88:
                osc->maxCount = 256 - oscRate;
                osc->curCount = 0;
                cents = func_8000D618(oscDepth);
                osc->data.vsaw.cents = -cents;
                osc->data.vsaw.centsrange = 2 * cents;
                *initVal = 1.0f;
                break;
            case 0x84:
                osc->data.vsin.depthcents = func_8000D618(oscDepth);
                osc->stateFlags = 0;
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                *initVal = 1.0f;
                break;
            case 0x89:
                osc->data.vsin.depthcents = func_8000D618(oscDepth);
                osc->stateFlags = 2;
                osc->curCount = 0;
                osc->maxCount = (259 - oscRate) / 4;
                *initVal = 1.0f;
                break;
            case 0xC9:
                cents = func_8000D618(oscDepth);
                osc->data.vsin.depthcents = cents;
                osc->curCount = 0;
                osc->maxCount = 259 - oscRate;
                osc->stateFlags = oscDelay;
                *initVal = alCents2Ratio(-cents);
                deltaTime = 0x4000;
                break;
            default:
                deltaTime = 0xFF << 14;
                break;
        }
    }
    return deltaTime;
}

// float register allocation: tmpFlt lands in $f2 instead of $f12 (masked 0 apart from FPU registers)
#ifdef NON_MATCHING
s32 func_8000CCC0(B980Osc* osc, f32* updateVal) {
    f32 tmpFlt;
    s32 deltaTime = 16000;

    switch (osc->type) {
        case 1:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853;
            tmpFlt = sinf(tmpFlt) * (f32)osc->data.tsin.halfdepth;
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 6:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 3.14159265;
            tmpFlt = sinf(tmpFlt) * (f32)osc->data.tsin.halfdepth;
            if (tmpFlt < 0.0f) {
                *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            } else {
                *updateVal = (f32)osc->data.tsin.baseVol - tmpFlt;
            }
            break;
        case 7:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 3.14159265;
            tmpFlt = sinf(tmpFlt) * (f32)osc->data.tsin.halfdepth;
            if (tmpFlt < 0.0f) {
                *updateVal = (f32)osc->data.tsin.baseVol - tmpFlt;
            } else {
                *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            }
            break;
        case 2:
            if (osc->stateFlags == 0) {
                *updateVal = (f32)osc->data.tsqr.loVal;
                osc->stateFlags = 1;
            } else {
                *updateVal = (f32)osc->data.tsqr.hiVal;
                osc->stateFlags = 0;
            }
            deltaTime *= osc->maxCount;
            break;
        case 3:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.tsaw.depth;
            *updateVal = (f32)osc->data.tsaw.baseVol - tmpFlt;
            break;
        case 4:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.tsaw.depth;
            *updateVal = (f32)osc->data.tsaw.baseVol + tmpFlt;
            break;
        case 5:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 3;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt *= (f32)osc->data.tsin.halfdepth;
                    break;
                case 1:
                    tmpFlt = (1.0f - tmpFlt) * (f32)osc->data.tsin.halfdepth;
                    break;
                case 2:
                    tmpFlt = -tmpFlt * (f32)osc->data.tsin.halfdepth;
                    break;
                case 3:
                    tmpFlt = (tmpFlt - 1.0f) * (f32)osc->data.tsin.halfdepth;
                    break;
            }
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 8:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 1;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt = -tmpFlt * (f32)osc->data.tsin.halfdepth;
                    break;
                case 1:
                    tmpFlt = (tmpFlt - 1.0f) * (f32)osc->data.tsin.halfdepth;
                    break;
            }
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 9:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 1;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt *= (f32)osc->data.tsin.halfdepth;
                    break;
                case 1:
                    tmpFlt = (1.0f - tmpFlt) * (f32)osc->data.tsin.halfdepth;
                    break;
            }
            *updateVal = (f32)osc->data.tsin.baseVol + tmpFlt;
            break;
        case 0x80:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853;
            tmpFlt = sinf(tmpFlt) * osc->data.vsin.depthcents;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x8A:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853;
            tmpFlt = sinf(tmpFlt) * -osc->data.vsin.depthcents;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x81:
        case 0x85:
        case 0x86:
            if (osc->stateFlags == 0) {
                osc->stateFlags = 1;
                *updateVal = osc->data.vsqr.loRatio;
            } else {
                osc->stateFlags = 0;
                *updateVal = osc->data.vsqr.hiRatio;
            }
            deltaTime *= osc->maxCount;
            break;
        case 0x82:
        case 0x87:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.vsaw.centsrange;
            tmpFlt = (f32)osc->data.vsaw.cents - tmpFlt;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x83:
        case 0x88:
            osc->curCount++;
            if (osc->curCount > osc->maxCount) {
                osc->curCount = 0;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            tmpFlt *= (f32)osc->data.vsaw.centsrange;
            tmpFlt += (f32)osc->data.vsaw.cents;
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0x84:
        case 0x89:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
                osc->stateFlags = (osc->stateFlags + 1) & 3;
            }
            tmpFlt = (f32)osc->curCount / (f32)osc->maxCount;
            switch (osc->stateFlags) {
                case 0:
                    tmpFlt *= osc->data.vsin.depthcents;
                    break;
                case 1:
                    tmpFlt = (1.0f - tmpFlt) * osc->data.vsin.depthcents;
                    break;
                case 2:
                    tmpFlt = -tmpFlt * osc->data.vsin.depthcents;
                    break;
                case 3:
                    tmpFlt = (tmpFlt - 1.0f) * osc->data.vsin.depthcents;
                    break;
            }
            *updateVal = alCents2Ratio(tmpFlt);
            break;
        case 0xC9:
            osc->curCount++;
            if (osc->curCount >= osc->maxCount) {
                osc->curCount = 0;
            }
            if (osc->stateFlags != 0) {
                if (osc->curCount == 0) {
                    osc->data.vsin.depthcents = func_8000D618(0x61);
                    osc->maxCount = 14;
                    *updateVal = 1.0f;
                    deltaTime = osc->stateFlags << 14;
                    osc->stateFlags = 0;
                } else {
                    tmpFlt = osc->data.vsin.depthcents
                             - (f32)osc->curCount / (f32)osc->maxCount * osc->data.vsin.depthcents;
                    *updateVal = alCents2Ratio(-tmpFlt);
                }
            } else {
                tmpFlt = (f32)osc->curCount / (f32)osc->maxCount * 6.2831853;
                tmpFlt = sinf(tmpFlt) * osc->data.vsin.depthcents;
                *updateVal = alCents2Ratio(tmpFlt);
            }
            break;
    }
    return deltaTime;
}
#else
INCLUDE_ASM("asm/nonmatchings/B980", func_8000CCC0);
#endif

void func_8000D600(B980Osc* osc) {
    osc->next = D_800CDB04;
    D_800CDB04 = osc;
}

f32 func_8000D618(u8 depth) {
    f32 x = 1.03099303;
    f32 cents = 1.0f;

    while (depth) {
        if (depth & 1) {
            cents *= x;
        }
        x *= x;
        depth >>= 1;
    }
    return cents;
}

s32 func_8000D65C(void) {
    ALSndpConfig cfg;
    unkB980Struct2* voice;
    B980SndHdr* hdr;
    s32 size;
    s32 addr;
    s32 i;

    D_800CEAA4 = 0;
    D_800CEABC = 0;
    D_800CEA98 = 0;
    D_800CEA9C = D_800C18DC[0] + D_800C18DC[1];
    cfg.maxSounds = D_800CEA9C;
    cfg.maxEvents = D_800C18DC[2];
    cfg.heap = &D_800CDAA8;
    D_800CEA8C = func_8000AFA0(0x54);
    if (D_800CEA8C == 0) {
        return 1;
    }
    func_800643D0(D_800CEA8C, &cfg);
    D_800CEA94 = (unkB980Struct2*)func_8000AFA0(D_800CEA9C * sizeof(unkB980Struct2));
    if (D_800CEA94 == NULL) {
        return 1;
    }
    D_800CEAB4 = 0;
    D_800CEAB8 = 0x7F;
    D_800CEAB9 = 0x40;
    D_800CEABA = 0;
    D_800CEAB0 = 0x7FFF;
    D_800CEAB2 = 0x7FFF;
    D_800CEAA0 = 0;
    D_800CEAA8 = 0;
    for (i = 0; i < D_800CEA9C; i++) {
        voice = &D_800CEA94[i];
        voice->unk_0C = 0;
        voice->unk_10 = 0;
        voice->unk_08 = 0;
        voice->unk_16 = -1;
        voice->unk_26 = 0;
        voice->unk_22 = D_800CEAB8;
        voice->unk_25 = voice->unk_24 = D_800CEAB9;
        voice->unk_28 = D_800CEABA;
        voice->unk_18 = D_800CEAB4;
        voice->unk_1A = D_800CEAB4;
        voice->unk_1C = 1.0f;
        voice->unk_29 = 0;
    }
    if (func_8000F078() != 0) {
        return 1;
    }
    if (func_8000DA04(4) != 0) {
        return 1;
    }
    switch (D_800CEA90->magic) {
        case 0x5431:
            if (D_800C188C[0] == 0) {
                return 0;
            }
            size = D_800CEA90->count;
            if (func_8000DA04(size * 8 + 4) != 0) {
                return 1;
            }
            if ((i = func_8000DA7C()) != 0) {
                return i - 1;
            }
            break;
        case 0x5432:
        case 0x5433:
            size = D_800CEA90->count * 8 + 4;
            if (func_8000DA04(size) != 0) {
                return 1;
            }
            addr = size + D_800C1888[0] + size % 8;
            size = sizeof(B980SndHdr);
            hdr = (B980SndHdr*)func_8000AFA0(sizeof(B980SndHdr));
            if (hdr == NULL) {
                return 1;
            }
            func_8000AD80(addr, hdr, size);
            hdr->ctl = D_800C1888[0] + hdr->ctl;
            hdr->tbl = D_800C1888[0] + hdr->tbl;
            if ((i = func_8000DB24(hdr)) != 0) {
                return i - 1;
            }
            if (func_8000DCCC(hdr) != 0) {
                return 1;
            }
            if (D_800CEA90->magic != 0x5432) {
                if ((i = func_8000DC44(hdr)) != 0) {
                    return i - 1;
                }
                if (func_8000F118() != 0) {
                    return 1;
                }
            }
            break;
        default:
            if (D_800C188C[0] == 0) {
                return 0;
            }
            if ((i = func_8000DA7C()) != 0) {
                return i - 1;
            }
            D_800CEA90->count = func_8000E21C(D_800CEA88);
            break;
    }
    D_800CEAA4 = 0x8000;
    return 0;
}

s32 func_8000DA04(s32 size) {
    size += size & 1;
    D_800CEA90 = (B980SeqHdr*)func_8000AFA0(size);
    if (D_800CEA90 == NULL) {
        return 1;
    }
    if (D_800C1888[0] == 0) {
        D_800CEA90->magic = 0;
    } else {
        func_8000AD80(D_800C1888[0], D_800CEA90, size);
    }
    return 0;
}

s32 func_8000DA7C(void) {
    s32 size;

    size = D_800C1890[0] - D_800C1890[-1];
    if (size == 0) {
        return 1;
    }
    size += size & 1;
    D_800CEA88 = (void*)func_8000AFA0(size);
    if (D_800CEA88 == NULL) {
        return 2;
    }
    func_8000AD80(D_800C188C[0], D_800CEA88, size);
    if (*(s16*)D_800CEA88 != 0x4231) {
        return 1;
    }
    alBnkfNew((s32)D_800CEA88, D_800C188C[2]);
    return 0;
}

s32 func_8000DB24(B980SndHdr* hdr) {
    s32 size;
    s32 i;
    B980Sound* snd;
    B980Wave* wave;

    size = hdr->ctlSize;
    if (size == 0) {
        return 1;
    }
    size += size & 1;
    D_800CEA88 = (void*)func_8000AFA0(size);
    if (D_800CEA88 == NULL) {
        return 2;
    }
    D_800C188C[0] = hdr->ctl;
    func_8000AD80(D_800C188C[0], D_800CEA88, size);
    for (i = 0; i < hdr->count; i++) {
        snd = &((B980Sound*)D_800CEA88)[i];
        if (snd->flags == 0) {
            snd->flags = 1;
            snd->envelope += (s32)D_800CEA88;
            snd->wavetable = (B980Wave*)((s32)snd->wavetable + (s32)D_800CEA88);
            wave = snd->wavetable;
            if (wave->flags == 0) {
                wave->flags = 1;
                wave->base += hdr->tbl;
                wave->book += (s32)D_800CEA88;
                if (wave->loop != 0) {
                    wave->loop += (s32)D_800CEA88;
                }
            }
        }
    }
    return 0;
}

s32 func_8000DC44(B980SndHdr* hdr) {
    s32 size;

    if (hdr->unk_1C == 0 || hdr->unk_20 == 0) {
        return 1;
    }
    size = hdr->unk_20;
    size += size & 1;
    D_800CEA98 = func_8000AFA0(size);
    if (D_800CEA98 == 0) {
        return 2;
    }
    hdr->unk_1C += D_800C1888[0];
    func_8000AD80(hdr->unk_1C, (void*)D_800CEA98, size);
    return 0;
}

s32 func_8000DCCC(B980SndHdr* hdr) {
    s32 size;
    s32 i;

    if (hdr->unk_14 == 0 || hdr->unk_18 == 0) {
        return 0;
    }
    size = hdr->unk_18;
    size += size & 1;
    D_800CEABC = (s32*)func_8000AFA0(size);
    if (D_800CEABC == NULL) {
        return 1;
    }
    hdr->unk_14 += D_800C1888[0];
    func_8000AD80(hdr->unk_14, D_800CEABC, size);
    D_800CEABC[0] = (s32)D_800CEABC + D_800CEABC[0];
    D_800CEABC[1] = (s32)D_800CEABC + D_800CEABC[1];
    D_800CEAC0 = (unkB980Struct1*)func_8000AFA0(D_800CEA9C * sizeof(unkB980Struct1));
    if (D_800CEAC0 == NULL) {
        return 1;
    }
    for (i = 0; i < D_800CEA9C; i++) {
        func_80010110(i);
    }
    D_800CEABB = 0;
    return 0;
}

void func_8000DDEC(void) {
    s32 i;

    for (i = 0; i < D_800CEA9C; i++) {
        unkB980Struct2* p = &D_800CEA94[i];
        if (p->unk_0C == 1) {
            p->unk_08 |= 2;
        }
    }
}

void func_8000DE5C(s16 idx) {
    B980SndParam param;
    unkB980Struct2* voice;

    if (D_800CEAA4 & 0x10) {
        return;
    }
    voice = &D_800CEA94[idx];
    voice->unk_08 &= ~0x1000;
    voice->unk_0C = 0;
    func_8000DF98(voice->unk_14, &param);
    if ((voice->unk_00 = param.sound) == 0) {
        return;
    }
    voice->unk_16 = alSndpAllocate(D_800CEA8C, voice->unk_00);
    if (voice->unk_16 < 0) {
        return;
    }
    alSndpSetPriority(D_800CEA8C, voice->unk_16, voice->unk_26 + 11);
    func_8000F780(param.unk_0E, idx, voice->unk_29);
    if (!(param.flags & 0x100)) {
        func_8000F844(idx);
        func_8000F294(idx, param.unk_16);
    }
    voice->unk_08 |= 0xF;
    func_8000E92C(idx);
    alSndpSetSound(D_800CEA8C, voice->unk_16);
    alSndpPlay(D_800CEA8C);
    voice->unk_0C = 1;
}

// decomp-permuter
B980SfxEnt *func_8000DF98(s16 id, B980SndParam *param)
{
  B980SfxEnt *ent;
  int new_var;
  B980SfxEnt *e;
  B980SfxExt *ext;
  param->id = id;
  param->vol = 0x7F;
  param->pan = 0x40;
  param->unk_0E = -1;
  param->flags = 0;
  param->unk_15 = 0;
  param->unk_16 = 0;
  param->unk_14 = 0;
  param->unk_17 = 0;
  param->unk_18 = 0;
  switch (D_800CEA90->magic)
  {
    case 0x5431:
      new_var = (((s32) D_800CEA90) + (id * 8)) + 4;
      ent = (B980SfxEnt *) new_var;
      param->sound = (s32) func_8000E2D0(D_800CEA88, ent->b0, ent->b1, ent->b2);
      param->pitch = ((f32) ent->rate) / ((f32) D_800C18A8);
      param->unk_13 = ent->b3;
      break;

    case 0x5432:

    case 0x5433:
      ent = (e = (B980SfxEnt *) ((((s32) D_800CEA90) + (id * 8)) + 4));
      param->sound = (s32) (&((B980Sound *) D_800CEA88)[e->flags & 0x1FFF]);
      if (e->flags & 0x8000)
    {
      param->flags |= 0x10;
    }
      if (e->flags & 0x4000)
    {
      param->flags |= 0x40;
    }
      if (e->flags & 0x2000)
    {
      param->unk_18 = 1;
    }
      if ((e->b0 < 0) && (D_800CEABC != 0))
    {
      param->unk_0E = ((e->b0 & 0x7F) << 8) + ((u8) e->b1);
    }
    else
    {
      param->vol = e->b1 & 0x7F;
      param->pan = e->b0 & 0x7F;
      if (e->b1 < 0)
      {
        param->flags |= 0x100;
      }
    }
      param->unk_14 = e->b2;
      param->pitch = ((f32) e->rate) / ((f32) D_800C18A8);
      param->unk_13 = e->b3;
      if ((D_800CEA90->magic != 0x5432) && (D_800CEA98 != 0))
    {
      ext = &((B980SfxExt *) D_800CEA98)[id];
      param->unk_15 = ext->b0;
      param->unk_16 = ext->b1;
      param->unk_17 = ext->b2;
      param->unk_18 = ext->b3;
    }
      break;

    default:
      ent = 0;
      param->sound = (s32) func_8000E340(D_800CEA88, id);
      param->pitch = 1.0f;
      param->unk_13 = 0x50;
      break;

  }

  return ent;
}

s16 func_8000E21C(B980BankFile* bankFile) {
    s16 total = 0;
    s16 i;
    s16 j;
    s16 nBanks;
    s16 nInsts;
    B980Bank* bank;

    nBanks = bankFile->bankCount;
    for (i = 0; i < nBanks; i++) {
        bank = bankFile->bankArray[i];
        nInsts = bank->instCount;
        for (j = 0; j < nInsts; j++) {
            total += bank->instArray[j]->soundCount;
        }
    }
    return total;
}

B980Sound* func_8000E2D0(B980BankFile* bankFile, u8 bankNo, u8 instNo, u8 soundNo) {
    B980Bank* bank;
    B980Inst* inst;

    if (bankFile->bankCount < bankNo) {
        return NULL;
    }
    bank = bankFile->bankArray[bankNo];
    if (bank->instCount < instNo) {
        return NULL;
    }
    inst = bank->instArray[instNo];
    if (inst->soundCount < soundNo) {
        return NULL;
    }
    return inst->soundArray[soundNo];
}

B980Sound* func_8000E340(B980BankFile* bankFile, s16 idx) {
    s16 n = 0;
    s16 i;
    s16 j;
    s16 k;
    s16 nBanks;
    s16 nInsts;
    s16 nSounds;
    B980Bank* bank;
    B980Inst* inst;
    B980Sound* snd;

    nBanks = bankFile->bankCount;
    for (i = 0; i < nBanks; i++) {
        bank = bankFile->bankArray[i];
        nInsts = bank->instCount;
        for (j = 0; j < nInsts; j++) {
            inst = bank->instArray[j];
            nSounds = inst->soundCount;
            for (k = 0; k < nSounds; k++) {
                snd = inst->soundArray[k];
                if (n == idx) {
                    return snd;
                }
                n++;
            }
        }
    }
    return NULL;
}

s16 func_8000E448(B980SndParam* param, s32 noAge) {
    s16 keys[16];
    s16 ids[16];
    s32 i;
    s32 j;
    unkB980Struct2* voice;
    u8 prio;

    i = param->unk_13 & 0xF;
    prio = param->unk_13 >> 4;
    voice = NULL;
    i &= -(D_800C18E0[0] != 0);
    if (i != 0 || D_800C18E0[-1] < 2) {
        if (D_800C18E0[0] < i) {
            return -1;
        }
        if (D_800C18DC[0] != 0) {
            i = i + D_800C18DC[0] - 1;
        }
        voice = &D_800CEA94[i];
        if (voice->unk_0C == 1 && voice->unk_26 > prio) {
            return -1;
        }
        return i;
    }
    for (i = 0; i < D_800C18DC[0]; i++) {
        voice = &D_800CEA94[i];
        if (voice->unk_0C != 1) {
            break;
        }
        keys[i] = voice->unk_27;
        ids[i] = i;
    }
    if (i == D_800C18DC[0]) {
        func_8000E818(keys, ids, 0, D_800C18DC[0] - 1);
        for (j = 0; j < D_800C18DC[0]; j++) {
            i = ids[j];
            voice = &D_800CEA94[i];
            if (prio >= voice->unk_26) {
                break;
            }
        }
        prio = 0xFF;
        if (j == D_800C18DC[0]) {
            return -1;
        }
    }
    if (noAge != 0) {
        return i;
    }
    voice->unk_27 = D_800C18F4++;
    if (D_800C18F4 != 0) {
        return i;
    }
    if (prio == 0xFF) {
        voice->unk_27 = D_800C18DC[0];
        for (j = D_800C18DC[0] - 1; j >= 0; j--) {
            if (ids[j] != i) {
                D_800CEA94[ids[j]].unk_27 = j;
            }
        }
    } else {
        prio = 0;
        for (j = 0; j < D_800C18DC[0]; j++) {
            voice = &D_800CEA94[j];
            if (voice->unk_0C == 1) {
                keys[prio] = voice->unk_27;
                ids[prio] = j;
                prio++;
            }
        }
        func_8000E818(keys, ids, 0, prio - 1);
        D_800CEA94[i].unk_27 = prio;
        for (j = prio - 1; j >= 0; j--) {
            D_800CEA94[ids[j]].unk_27 = j;
        }
    }
    return i;
}

void func_8000E818(s16* keys, s16* ids, s16 lo, s16 hi) {
    s32 i;
    s32 j;
    s32 dir = 1;
    s16 a;
    s16 b;
    s16 c;

    if (lo < hi) {
        i = lo;
        j = hi;
        do {
            if (keys[i] > keys[j]) {
                a = keys[i];
                keys[i] = keys[j];
                keys[j] = a;
                c = ids[i];
                ids[i] = ids[j];
                ids[j] = c;
                if (dir) {
                    dir = 0;
                } else {
                    dir = 1;
                }
            }
            if (dir != 0) {
                j--;
            } else {
                i++;
            }
        } while (i < j);
        func_8000E818(keys, ids, lo, i - 1);
        func_8000E818(keys, ids, i + 1, hi);
    }
}

void func_8000E92C(s16 idx) {
    unkB980Struct2* voice = &D_800CEA94[idx];
    f32 pitch;
    s16 vol;
    s16 pan;

    if (voice->unk_16 < 0) {
        voice->unk_08 &= ~0xF;
        return;
    }
    if (voice->unk_08 & 1) {
        pitch = alCents2Ratio(voice->unk_18 + voice->unk_1A) * voice->unk_1C;
        alSndpSetSound(D_800CEA8C, voice->unk_16);
        alSndpSetPitch(D_800CEA8C, pitch * voice->unk_04);
        voice->unk_08 &= ~1;
    }
    if (voice->unk_08 & 2) {
        vol = voice->unk_20 * voice->unk_22 * voice->unk_23 / 16129;
        if ((D_800CEAA4 & 1) && !(voice->unk_08 & 0x100)) {
            vol = vol * D_800CEAB6 / 127;
        }
        alSndpSetSound(D_800CEA8C, voice->unk_16);
        if (voice->unk_08 & 0x100) {
            alSndpSetVol(D_800CEA8C, vol);
        } else {
            alSndpSetVol(D_800CEA8C, vol * D_800CEAB2 / 32767);
        }
        voice->unk_08 &= ~2;
    }
    if (voice->unk_08 & 8) {
        alSndpSetSound(D_800CEA8C, voice->unk_16);
        alSndpSetFXMix(D_800CEA8C, voice->unk_28);
        voice->unk_08 &= ~8;
    }
    if (voice->unk_08 & 4) {
        if (D_800ECB2C & 1) {
            alSndpSetSound(D_800CEA8C, voice->unk_16);
            alSndpSetPan(D_800CEA8C, 64);
        } else {
            pan = voice->unk_25 - 64 + voice->unk_24;
            if (pan < 0) {
                pan = 0;
            }
            if (pan >= 0x80) {
                pan = 0x7F;
            }
            alSndpSetSound(D_800CEA8C, voice->unk_16);
            alSndpSetPan(D_800CEA8C, pan);
        }
        voice->unk_08 &= ~4;
    }
}

void func_8000EC14(void) {
    s16 cur;
    s16 i;
    s32 state;
    unkB980Struct2* voice;

    cur = alSndpGetSound(D_800CEA8C);
    D_800CEAA0 = 0;
    for (i = 0; i < D_800CEA9C; i++) {
        voice = &D_800CEA94[i];
        if (voice->unk_16 >= 0) {
            alSndpSetSound(D_800CEA8C, voice->unk_16);
            state = voice->unk_0C = voice->unk_10 = alSndpGetState(D_800CEA8C);
            switch (state) {
                case 0:
                    alSndpDeallocate(D_800CEA8C, voice->unk_16);
                    voice->unk_16 = -1;
                    voice->unk_08 &= ~0x2000;
                    break;
                case 2:
                    if (voice->unk_08 & 0x1000) {
                        voice->unk_0C = 1;
                    }
                    voice->unk_08 &= ~0x2000;
                    D_800CEAA0++;
                    break;
                case 1:
                    if (voice->unk_08 & 0x2000) {
                        alSndpStop(D_800CEA8C);
                    } else if (!(D_800CEAA4 & 1)) {
                        func_8000F844(i);
                    }
                    D_800CEAA0++;
                    break;
            }
            if (voice->unk_08 & 0xF) {
                func_8000E92C(i);
            }
        }
        if ((D_800CEAA4 & 1) && !(voice->unk_08 & 0x100)) {
            if (D_800CEAB6 >= 0) {
                voice->unk_08 |= 2;
                func_8000E92C(i);
            }
        } else if ((voice->unk_08 & 0x1000) && voice->unk_16 < 0) {
            func_8000DE5C(i);
            D_800CEAA0++;
        }
    }
    if (D_800CEAA4 & 1) {
        if (D_800CEAB6 > 0) {
            D_800CEAB6 >>= 1;
            if (D_800CEAB6 < 10) {
                D_800CEAB6 = 0;
            }
        } else if (D_800CEAB6 == 0) {
            D_800CEAB6 = -1;
        }
    } else {
        func_8000F4E0();
        if (D_800CEAA8 > 0.0f) {
            D_800CEAAC += D_800CEAA8;
            if (D_800CEAB0 <= D_800CEAAC) {
                func_8001165C();
                D_800CEAA8 = 0.0f;
                D_800CEAB2 = D_800CEAB0;
            } else {
                i = D_800CEAB0 - D_800CEAAC;
                if (D_800CEAB2 != i) {
                    D_800CEAB2 = i;
                    func_8000DDEC();
                }
            }
        }
        if (D_800CEAA8 < 0.0f) {
            D_800CEAAC -= D_800CEAA8;
            if (D_800CEAB0 <= D_800CEAAC) {
                D_800CEAA8 = 0.0f;
                i = D_800CEAB0;
            } else {
                i = D_800CEAAC;
            }
            if (D_800CEAB2 != i) {
                D_800CEAB2 = i;
                func_8000DDEC();
            }
        }
    }
    if (cur >= 0) {
        alSndpSetSound(D_800CEA8C, cur);
    }
}

s32 func_8000F078(void) {
    D_800CEAC4 = (B980SfxState*)func_8000AFA0(D_800CEA9C * 16);
    if (D_800CEAC4 == NULL) {
        return 1;
    }
    D_800CEAC8 = 50.0f;
    D_800CEACC = 500.0f;
    D_800CEAD0 = 0;
    D_800CEAD4 = 0;
    D_800CEAD8 = 0;
    D_800CEADA = 10;
    D_800CEADC = 1224.0f;
    D_800CEAE0 = 1.0f;
    return 0;
}

s32 func_8000F118(void) {
    D_800CEAE4 = (B980SfxSlot*)func_8000AFA0(D_800CEA9C * sizeof(B980SfxSlot));
    if (D_800CEAE4 == NULL) {
        return 1;
    }
    D_800CEAF0 = D_800CEA9C;
    func_8000F238();
    D_800CEAF4 = D_800CEAF5 = 0;
    D_800CEAE8 = D_800CEAEC = 0.0f;
    D_800CEAF0 = 0;
    return 0;
}

void func_8000F198(s16 idx) {
    s32 i;
    B980SfxSlot* slot;

    if (D_800CEAF0 != 0) {
        for (i = 0; i < D_800CEAF0; i++) {
            slot = &D_800CEAE4[i];
            if (slot->id == D_800CEA94[idx].unk_14 && slot->voice == idx) {
                slot->id = -1;
                return;
            }
        }
    }
}

void func_8000F238(void) {
    s32 i;

    if (D_800CEAF0 != 0) {
        for (i = 0; i < D_800CEAF0; i++) {
            D_800CEAE4[i].id = -1;
        }
        D_800CEAF6 = 0;
    }
}

// decomp-permuter
void func_8000F294(s16 idx, s8 mode)
{
  s32 i;
  s32 slot = 0;
  B980SfxSlot *s;
  unkB980Struct2 *voice;
  if ((((((D_800CEAF0 == 0) || (D_800CEA94[idx].unk_08 & 0x20)) || (D_800CEAF4 <= 0)) || (D_800CEAF5 < 2)) || (D_800CEAE8 == 0.0f)) || (D_800CEAEC == 0.0f))
  {
    return;
  }
  if ((idx != 0) || (D_800C18DC[0] < 2))
  {
    for (i = 0; i < D_800CEAF0; i++)
    {
      s = &D_800CEAE4[i];
      if ((s->id >= 0) && (s->voice == idx))
      {
        slot = i;
        break;
      }
    }

    if (mode == 0)
    {
      if (i < D_800CEAF0)
      {
 do { D_800CEAE4[slot].id = -1; } while (0);
      }
      return;
    }
    if (i != D_800CEAF0)
    {
      if (voice->unk_22)
      {
        goto fill;
      }
      else
      {
        goto fill;
      }
    }
  }
  else
    if (mode == 0)
  {
    return;
  }
  slot = (s8) (D_800CEAF6++);
  fill:
  if (D_800CEAF6 >= D_800CEAF0)
  {
    D_800CEAF6 = 0;
  }

  voice = &D_800CEA94[idx];
  s = &D_800CEAE4[slot];
  s->id = voice->unk_14;
  s->voice = idx;
  s->vol = voice->unk_22;
  s->unk_05 = voice->unk_23;
  s->unk_06 = voice->unk_25;
  s->mode = mode;
  s->delay = D_800CEAF4;
  s->count = D_800CEAF5;
}

// retail places the v < 0 arm after the success arm; voiceIdx extension reuse (masked 7)
#ifdef NON_MATCHING
void func_8000F4E0(void) {
    s32 i;
    B980SfxSlot* s;
    s16 voiceIdx;
    s32 fixed;
    s16 v;

    if (D_800CEAF0 == 0) {
        return;
    }
    for (i = 0; i < D_800CEAF0; i++) {
        s = &D_800CEAE4[i];
        if (s->id < 0) {
            continue;
        }
        if (--s->delay != 0) {
            continue;
        }
        if (--s->count == 0) {
            s->id = -1;
            continue;
        }
        voiceIdx = s->voice;
        fixed = 0;
        if (D_800C18DC[0] >= 2) {
            fixed = voiceIdx < D_800C18DC[0];
        }
        if (!fixed && (D_800CEA94[voiceIdx].unk_08 & 0x1000)) {
            s->id = -1;
            continue;
        }
        if (s->count == D_800CEAF5 - 1) {
            s->vol = s->vol * D_800CEAEC * s->mode / 127.0f;
        } else {
            s->vol = s->vol * D_800CEAE8;
        }
        if (s->vol < 6) {
            s->id = -1;
            continue;
        }
        if (fixed) {
            D_800CEA94[voiceIdx].unk_26++;
            v = func_80010C4C(s->id);
            D_800CEA94[voiceIdx].unk_26--;
        } else {
            v = func_80010C4C(s->id);
        }
        if (v < 0) {
            s->id = -1;
        } else {
            func_800123DC(v, s->vol);
            func_8001249C(v, s->unk_06);
            D_800CEA94[v].unk_23 = s->unk_05;
            s->delay = D_800CEAF4;
            D_800CEA94[v].unk_08 |= 0x20;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/B980", func_8000F4E0);
#endif

void func_8000F780(s16 script, s16 idx, s8 mode) {
    unkB980Struct1* p;

    if (D_800CEABC == NULL) {
        return;
    }
    p = &D_800CEAC0[idx];
    if (mode != 3) {
        p->unk_0A = -1;
    }
    p->unk_04 = 0;
    p->unk_08 = script;
    if (script >= 0) {
        p->unk_00 = ((u16*)D_800CEABC[0])[script] + (s32)D_800CEABC;
        p->unk_0C = 0;
        p->unk_1A = 0;
        p->unk_1C = 0;
        p->unk_2C = 1.0f;
        p->unk_30 = 0;
        p->unk_40 = 1.0f;
        p->unk_0E = 0;
        p->unk_10 = 0x7F;
        p->unk_12 = 0x40;
        p->unk_53 = 0;
    }
}

// register allocation: voice-index temporaries in s2/s0 instead of a0/s2 (masked 0)
#ifdef NON_MATCHING
void func_8000F844(s16 idx) {
    unkB980Struct1* seq;
    unkB980Struct2* voice;
    u8* p;
    s32 tbl;
    s16 id;
    s16 n;
    s16 r;
    u8 cmd;
    u8* cnt;

    if (D_800CEABC == NULL) {
        return;
    }
    seq = &D_800CEAC0[idx];
    if (seq->unk_08 < 0) {
        return;
    }
    if (D_800CEABB != 0) {
        if (seq->unk_53 != 0) {
            seq->unk_53--;
            return;
        }
        seq->unk_53 = D_800CEABB;
    }
    voice = &D_800CEA94[idx];
    p = (u8*)seq->unk_00;
    while (seq->unk_0C == 0) {
        cmd = *p++;
        seq->unk_0C = (p[0] << 8) + p[1];
        p += 2;
        switch (cmd) {
            case 0x82:
                break;
            case 0x83:
                id = (p[0] << 8) + p[1];
                p += 2;
                if (id != voice->unk_14 && seq->unk_0A < 0 && seq->unk_1A < 3) {
                    r = func_80010040(id);
                    if (r < 0 || r == idx) {
                        break;
                    }
                    {
                        n = func_80010ED4(id, D_800CEA94[idx].unk_2B);
                        seq->unk_14[seq->unk_1A++] = n;
                        D_800CEA94[n].unk_29 = 3;
                        D_800CEAC0[n].unk_0A = idx;
                        D_800CEA94[n].unk_22 = voice->unk_22;
                        D_800CEA94[n].unk_23 = voice->unk_23;
                        D_800CEA94[n].unk_25 = voice->unk_25;
                        D_800CEA94[n].unk_1A = voice->unk_1A;
                        D_800CEA94[n].unk_28 = voice->unk_28;
                    }
                }
                break;
            case 0x84:
                cnt = &seq->unk_1C;
                if (seq->unk_1C == 1) {
                    seq->unk_1C = 0;
                    p += 3;
                    break;
                }
                if (*cnt != 0) {
                    *cnt = *cnt - 1;
                } else if (p[0] != 0) {
                    *cnt = p[0];
                } else {
                    p += 3;
                    break;
                }
                p += (s16)((p[1] << 8) + p[2]) - 3;
                break;
            case 0x85:
                p += (s16)((p[0] << 8) + p[1]) - 3;
                break;
            case 0x88:
                seq->unk_1D = *p++;
                seq->unk_1F = *p++;
                seq->unk_1E = *p++;
                break;
            case 0x89:
                seq->unk_2C = (s16)((p[0] << 8) + p[1]) / 100.0f;
                p += 2;
                break;
            case 0x90:
                seq->unk_10 = *p;
                p++;
                break;
            case 0x91:
                seq->unk_10 += (s8)*p;
                p++;
                break;
            case 0x98:
                seq->unk_12 = *p;
                p++;
                break;
            case 0x99:
                seq->unk_12 += (s8)*p;
                p++;
                break;
            case 0x9A:
                if (*p++ & 1) {
                    seq->unk_04 |= 8;
                } else {
                    seq->unk_04 |= 0x10;
                }
                seq->unk_50 = (p[0] << 8) + p[1];
                seq->unk_4E = seq->unk_50 * seq->unk_12 / 127;
                p += 2;
                break;
            case 0xA0:
                seq->unk_0E = (p[0] << 8) + p[1];
                p += 2;
                break;
            case 0xA1:
                seq->unk_0E += (p[0] << 8) + p[1];
                p += 2;
                break;
            case 0xA2:
                if (*p++ != 0) {
                    seq->unk_26 = 0;
                    seq->unk_28 = -200.0f;
                    seq->unk_22 = 0x105 - seq->unk_1F;
                    seq->unk_24 = func_8000D618(seq->unk_1E);
                    seq->unk_20 = 0;
                    seq->unk_04 |= 2;
                } else {
                    seq->unk_04 &= ~2;
                }
                break;
            case 0xA3:
                seq->unk_30 = *p++;
                seq->unk_32 = (p[0] << 8) + p[1];
                seq->unk_36 = (p[2] << 8) + p[3];
                seq->unk_34 = 0;
                p += 4;
                break;
            case 0xA4:
                tbl = D_800CEABC[1];
                seq->unk_3C = seq->unk_38 = ((u16*)tbl)[p[0]] + tbl;
                seq->unk_44 = (p[1] << 8) + p[2];
                seq->unk_46 = (p[3] << 8) + p[4];
                seq->unk_4C = 0;
                seq->unk_4A = 0;
                seq->unk_04 |= 0x20;
                p += 5;
                break;
            case 0xA5:
                seq->unk_40 = (s16)((p[0] << 8) + p[1]) / 100.0f;
                p += 2;
                break;
            case 0xA6:
                seq->unk_04 &= ~0x20;
                break;
            case 0xA8:
                voice->unk_28 = *p++;
                voice->unk_08 |= 8;
                break;
            case 0x80:
                seq->unk_04 |= 0x100;
            case 0x81:
                seq->unk_04 |= 0x200;
                seq->unk_08 = -1;
                seq->unk_0C = 1;
                break;
            default:
                seq->unk_04 |= 0x300;
                seq->unk_08 = -1;
                seq->unk_0C = 1;
                break;
        }
    }
    seq->unk_0C--;
    seq->unk_00 = (s32)p;
    func_80010148(voice, seq);
    func_80010734(voice, seq);
    func_8001085C(voice, seq);
    if (seq->unk_04 & 0x100) {
        while (seq->unk_1A > 0) {
            n = seq->unk_14[--seq->unk_1A];
            if (D_800CEAC0[n].unk_0A == idx) {
                voice = &D_800CEA94[n];
                if (voice->unk_0C == 1) {
                    if (voice->unk_08 & 0x1000) {
                        voice->unk_08 &= ~0x1000;
                        voice->unk_0C = voice->unk_10;
                    } else if (voice->unk_16 >= 0) {
                        alSndpSetSound(D_800CEA8C, voice->unk_16);
                        alSndpStop(D_800CEA8C);
                        voice->unk_08 |= 0x2000;
                    }
                    voice->unk_29 = 0;
                    func_80010110(n);
                }
            }
        }
        voice = &D_800CEA94[idx];
        if (voice->unk_16 >= 0) {
            alSndpSetSound(D_800CEA8C, voice->unk_16);
            alSndpStop(D_800CEA8C);
            voice->unk_08 |= 0x2000;
        }
        voice->unk_29 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/B980", func_8000F844);
#endif

s16 func_80010040(s16 id) {
    B980SndParam param;
    s16 v;
    s8 k;

    if ((id >= D_800CEA90->count) | (id < 0)) {
        return -1;
    }
    func_8000DF98(id, &param);
    v = func_8000E448(&param, 1);
    if (v < 0) {
        return -1;
    }
    if (param.unk_17 & 0xF) {
        if (param.unk_17 & 0xF0) {
            k = D_800CEA94[v].unk_2B;
            if (k != -1) {
                v += ((param.unk_17 & 0xF0) >> 4) * k;
            }
        }
    }
    return v;
}

void func_80010110(s16 idx) {
    unkB980Struct1* seq = &D_800CEAC0[idx];

    seq->unk_08 = -1;
    seq->unk_04 = 0;
}

// FPU register allocation: pitch/t in $f6/$f4 instead of $f4/$f12 (masked 0 apart from FPU registers)
#ifdef NON_MATCHING
void func_80010148(unkB980Struct2* voice, unkB980Struct1* seq) {
    f32 pitch = 0.0f;
    f32 t;
    f32 half;
    s16 cents;
    s16 x;

    if (seq->unk_04 & 2) {
        switch (seq->unk_1D) {
            case 1:
                seq->unk_20 += 2;
                if (seq->unk_20 >= seq->unk_22) {
                    seq->unk_20 = 0;
                    break;
                }
                pitch = sinf((f32)seq->unk_20 / (f32)seq->unk_22 * 6.2831853) * seq->unk_24 * seq->unk_2C;
                break;
            case 2:
                if (seq->unk_20 >= seq->unk_22 / 4) {
                    if (++seq->unk_26 >= 4) {
                        seq->unk_26 = 0;
                    }
                    seq->unk_20 = 0;
                }
                t = (f32)seq->unk_20 / (f32)(seq->unk_22 / 4);
                switch (seq->unk_26) {
                    case 1:
                        t = 1.0f - t;
                        break;
                    case 2:
                        t = -t;
                        break;
                    case 3:
                        t = -(1.0f - t);
                        break;
                }
                pitch = seq->unk_24 * t * seq->unk_2C;
                seq->unk_20 += 2;
                break;
            case 3:
                if (seq->unk_20 >= seq->unk_22) {
                    seq->unk_20 = 0;
                }
                half = seq->unk_22 / 2.0f;
                x = seq->unk_20;
                t = x - half;
                pitch = seq->unk_24 * (t / half) * seq->unk_2C;
                seq->unk_20 = x + 2;
                break;
            case 4:
                if (seq->unk_20 >= seq->unk_22) {
                    seq->unk_20 = 0;
                    seq->unk_26 = ~seq->unk_26;
                }
                if (seq->unk_26 == 0) {
                    pitch = seq->unk_24 * seq->unk_2C;
                } else {
                    pitch = seq->unk_24 * -seq->unk_2C;
                }
                seq->unk_20 += 2;
                break;
            case 5:
                if (seq->unk_20 >= seq->unk_22 / 2 || seq->unk_28 == -200.0f) {
                    seq->unk_20 = 0;
                    seq->unk_28 = (100 - guRandom() % 200) / 100.0f;
                }
                pitch = seq->unk_24 * seq->unk_28 * seq->unk_2C;
                seq->unk_20 += 2;
                break;
        }
    }
    if (seq->unk_30 == 1) {
        if (++seq->unk_34 >= seq->unk_36) {
            seq->unk_30 = 0;
            seq->unk_0E += seq->unk_32;
            pitch = 0.1f;
        } else {
            pitch += (f32)seq->unk_34 / (f32)seq->unk_36 * seq->unk_32;
        }
    }
    if (seq->unk_04 & 0x20) {
        if (seq->unk_44 != 0) {
            seq->unk_44--;
        } else {
            if (seq->unk_4C == 0) {
                seq->unk_4C = *(s8*)seq->unk_38;
                if (seq->unk_4C == 0) {
                    seq->unk_38 = seq->unk_3C;
                    seq->unk_4C = *(s8*)seq->unk_38;
                }
                seq->unk_48 = (((u8*)seq->unk_38)[1] << 8) + ((u8*)seq->unk_38)[2];
                seq->unk_48 = seq->unk_48 * seq->unk_40;
                seq->unk_38 += 3;
            }
            if (seq->unk_4C == -0x80) {
                pitch += seq->unk_46 + seq->unk_4A;
            } else if (seq->unk_4C > 0) {
                seq->unk_4C--;
                pitch += seq->unk_46 + seq->unk_48;
                seq->unk_4A = seq->unk_48;
            } else {
                seq->unk_4C++;
                seq->unk_4A += seq->unk_48;
                pitch += seq->unk_46 + seq->unk_4A;
            }
        }
    }
    pitch += seq->unk_0E;
    if (pitch > 1200.0f) {
        pitch = 1200.0f;
    }
    cents = pitch;
    if (voice->unk_18 != cents) {
        voice->unk_18 = cents;
        voice->unk_08 |= 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/B980", func_80010148);
#endif

void func_80010734(unkB980Struct2* voice, unkB980Struct1* seq) {
    s16 v;

    func_8000AE20(&seq->unk_12, 0x7F);
    if (seq->unk_04 & 0x18) {
        if (seq->unk_04 & 8) {
            if (++seq->unk_4E >= seq->unk_50) {
                seq->unk_4E = seq->unk_50;
                seq->unk_04 &= ~8;
            }
        } else {
            if (--seq->unk_4E <= 0) {
                seq->unk_4E = 0;
                seq->unk_04 &= ~0x10;
            }
        }
        v = seq->unk_4E * 127.0f / seq->unk_50;
        func_8000AE20(&v, 0x7F);
        seq->unk_12 = (u8)v;
    }
    if (voice->unk_24 != seq->unk_12) {
        voice->unk_24 = seq->unk_12;
        voice->unk_08 |= 4;
    }
}

void func_8001085C(unkB980Struct2* voice, unkB980Struct1* seq) {
    s32 v;

    func_8000AE20(&seq->unk_10, 0x7F);
    v = func_8000ADFC(seq->unk_10);
    if (voice->unk_20 != (s16)v) {
        voice->unk_20 = v;
        voice->unk_08 |= 2;
    }
}

void func_800108C8(s16 arg0, s8 arg1) {
    unkB980Struct1* temp_s1;
    s16 var_v0;
    s16 temp_a0;

    temp_s1 = &D_800CEAC0[arg0];
    var_v0 = temp_s1->unk_1A;

    while (var_v0 > 0) {
        var_v0--;
        temp_a0 = temp_s1->unk_14[var_v0];
        if (D_800CEAC0[temp_a0].unk_0A == arg0) {
            func_800123DC(temp_a0, arg1);
        }
    }
}

void func_80010998(s16 arg0, u8 arg1) {
    unkB980Struct1* temp_s1;
    s16 var_v0;
    s16 temp_a0;

    temp_s1 = &D_800CEAC0[arg0];
    var_v0 = temp_s1->unk_1A;

    while (var_v0 > 0) {
        var_v0--;
        temp_a0 = temp_s1->unk_14[var_v0];
        if (D_800CEAC0[temp_a0].unk_0A == arg0) {
            func_8001249C(temp_a0, arg1);
        }
    }
}

void func_80010A68(s16 arg0, s16 arg1) {
    unkB980Struct1* temp_s1;
    s16 var_v0;
    s16 temp_a0;

    temp_s1 = &D_800CEAC0[arg0];
    var_v0 = temp_s1->unk_1A;

    while (var_v0 > 0) {
        var_v0--;
        temp_a0 = temp_s1->unk_14[var_v0];
        if (D_800CEAC0[temp_a0].unk_0A == arg0) {
            func_80012574(temp_a0, arg1);
        }
    }
}

void func_80010B38(s16 arg0, s8 arg1) {
    unkB980Struct1* temp_s1;
    s16 var_v0;
    s16 temp_a0;

    temp_s1 = &D_800CEAC0[arg0];
    var_v0 = temp_s1->unk_1A;

    while (var_v0 > 0) {
        var_v0--;
        temp_a0 = temp_s1->unk_14[var_v0];
        if (D_800CEAC0[temp_a0].unk_0A == arg0) {
            func_80012654(temp_a0, arg1);
        }
    }
}

void func_80010C08(void) {
    func_8001165C();
    alSndpDelete(D_800CEA8C);
}

void func_80010C30(s32 base, s32 ctl, s32 ctlEnd, s32 tbl) {
    D_800C1888[0] = base;
    D_800C1888[1] = ctl;
    D_800C1888[2] = ctlEnd;
    D_800C1888[3] = tbl;
}

s32 func_80010C4C(s16 id) {
    return func_80010C78(id, 0);
}

s16 func_80010C78(s16 id, s32 keepLock) {
    B980SndParam param;
    unkB980Struct2* voice;
    B980SfxState* st;
    s16 v;

    if (!(D_800CEAA4 & 0x8000)) {
        return -1;
    }
    if ((id >= D_800CEA90->count) | (id < 0)) {
        return -1;
    }
    func_8000DF98(id, &param);
    switch (D_800CEA90->magic) {
        case 0x5431:
        case 0x5432:
        case 0x5433:
            v = func_8000E448(&param, 0);
            if (v < 0) {
                return -1;
            }
            break;
        default:
            v = (u8)(param.unk_13 & 0xF);
            break;
    }
    voice = &D_800CEA94[v];
    if (voice->unk_0C == 1 && !(voice->unk_08 & 0x1000)) {
        func_80011164(v);
    } else {
        voice->unk_08 = 0;
    }
    D_800CEAA4 |= 0x10;
    voice->unk_14 = id;
    voice->unk_22 = D_800CEAB8;
    voice->unk_20 = func_8000ADFC(param.vol);
    voice->unk_23 = 0x7F;
    voice->unk_25 = D_800CEAB9;
    voice->unk_24 = param.pan;
    voice->unk_1A = D_800CEAB4;
    voice->unk_18 = 0;
    voice->unk_1C = 1.0f;
    voice->unk_04 = param.pitch;
    voice->unk_0C = 1;
    voice->unk_26 = param.unk_13 >> 4;
    voice->unk_2B = -1;
    if (param.unk_15 != 0) {
        voice->unk_28 = param.unk_15;
    } else {
        voice->unk_28 = D_800CEABA;
    }
    st = &D_800CEAC4[v];
    st->unk_00 = st->unk_04 = 0.0f;
    st->unk_0E = param.unk_14;
    st->unk_08 = -1.0f;
    if (param.unk_0E < 0) {
        voice->unk_29 = 1;
    } else {
        voice->unk_29 = 2;
    }
    voice->unk_08 |= 0x1000 | param.flags;
    if (keepLock == 0) {
        D_800CEAA4 &= ~0x10;
    }
    return v;
}

// the chanOfs != -1 test's sign extension is reused by the mult in retail only (masked 0, raw 3)
#ifdef NON_MATCHING
s16 func_80010ED4(s16 id, s16 chanOfs) {
    B980SndParam param;
    unkB980Struct2* voice;
    B980SfxState* st;
    s16 v;
    s32 hi;

    if (!(D_800CEAA4 & 0x8000)) {
        return -1;
    }
    if ((id >= D_800CEA90->count) | (id < 0)) {
        return -1;
    }
    func_8000DF98(id, &param);
    switch (D_800CEA90->magic) {
        case 0x5431:
        case 0x5432:
        case 0x5433:
            v = func_8000E448(&param, 0);
            if (v < 0) {
                return -1;
            }
            break;
        default:
            v = (u8)(param.unk_13 & 0xF);
            break;
    }
    if (param.unk_17 & 0xF) {
        hi = param.unk_17 & 0xF0;
        if (hi != 0 && chanOfs != -1) {
            v += (hi >> 4) * chanOfs;
        }
    }
    voice = &D_800CEA94[v];
    if (voice->unk_0C == 1 && !(voice->unk_08 & 0x1000)) {
        func_80011164(v);
    } else {
        voice->unk_08 = 0;
    }
    D_800CEAA4 |= 0x10;
    voice->unk_14 = id;
    voice->unk_22 = D_800CEAB8;
    voice->unk_20 = func_8000ADFC(param.vol);
    voice->unk_23 = 0x7F;
    voice->unk_25 = D_800CEAB9;
    voice->unk_24 = param.pan;
    voice->unk_1A = D_800CEAB4;
    voice->unk_18 = 0;
    voice->unk_1C = 1.0f;
    voice->unk_04 = param.pitch;
    voice->unk_0C = 1;
    voice->unk_26 = param.unk_13 >> 4;
    voice->unk_2B = chanOfs;
    if (param.unk_15 != 0) {
        voice->unk_28 = param.unk_15;
    } else {
        voice->unk_28 = D_800CEABA;
    }
    st = &D_800CEAC4[v];
    st->unk_00 = st->unk_04 = 0.0f;
    st->unk_0E = param.unk_14;
    st->unk_08 = -1.0f;
    if (param.unk_0E < 0) {
        voice->unk_29 = 1;
    } else {
        voice->unk_29 = 2;
    }
    voice->unk_08 |= 0x1000 | param.flags;
    D_800CEAA4 &= ~0x10;
    return v;
}
#else
INCLUDE_ASM("asm/nonmatchings/B980", func_80010ED4);
#endif

void func_80011164(s16 idx) {
    unkB980Struct2* voice;
    unkB980Struct1* seq;
    s16 n;

    voice = &D_800CEA94[idx];
    if (voice->unk_16 < 0) {
        return;
    }
    alSndpSetSound(D_800CEA8C, voice->unk_16);
    alSndpStop(D_800CEA8C);
    voice->unk_08 = 0x2000;
    if (voice->unk_29 == 2) {
        seq = &D_800CEAC0[idx];
        while (seq->unk_1A > 0) {
            n = seq->unk_14[--seq->unk_1A];
            if (D_800CEAC0[n].unk_0A == idx) {
                voice = &D_800CEA94[n];
                if (voice->unk_0C == 1) {
                    if (voice->unk_08 & 0x1000) {
                        voice->unk_08 &= ~0x1000;
                        voice->unk_0C = voice->unk_10;
                    } else if (voice->unk_16 >= 0) {
                        alSndpSetSound(D_800CEA8C, voice->unk_16);
                        alSndpStop(D_800CEA8C);
                        voice->unk_08 |= 0x2000;
                    }
                    voice->unk_29 = 0;
                    func_80010110(n);
                }
            }
        }
    }
    D_800CEA94[idx].unk_29 = 0;
    if (D_800CEABC != NULL) {
        func_80010110(idx);
    }
}

void func_8001136C(f32 arg0, s32 arg1, s16 arg2) {
    if (arg0 >= 0.0f) {
        D_800CEADC = arg0;
    }
    if (arg2 >= 0) {
        D_800CEADA = arg2;
    }
    if (arg1 >= 0) {
        D_800CEAE0 = arg1;
    }
}

void func_800113C4(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    if (arg0 >= 0) {
        D_800CEAD8 = arg0;
        if (arg0 >= 360) {
            D_800CEAD8 = 0;
        }
    }
    if (arg1 >= 0.0f) {
        D_800CEAC8 = arg1;
    }
    if (arg2 >= 0.0f) {
        D_800CEACC = arg2 - arg1;
    }
    if (arg3 >= 0.0f) {
        D_800CEAD0 = arg3;
    }
    if (arg4 >= 0.0f) {
        D_800CEAD4 = arg4 - D_800CEAD0;
        if (D_800CEAD4 < 0.0f) {
            D_800CEAD4 = 0.0f;
        }
    }
}

s16 func_800114A4(s16 id, s16 arg1, f32 arg2) {
    s16 v;

    v = func_80010C78(id, 1);
    if (v < 0) {
        D_800CEAA4 &= ~0x10;
        return -1;
    }
    func_80011D48(v, arg1, arg2);
    return v;
}

s16 func_80011530(s16 id) {
    s16 i;

    for (i = 0; i < D_800CEA9C; i++) {
        if (D_800CEA94[i].unk_0C != 0 && D_800CEA94[i].unk_14 == id) {
            return i;
        }
    }
    return -1;
}

s32 func_800115BC(void) {
    return D_800CEAA0;
}

s32 func_800115C8(s16 idx) {
    unkB980Struct2* voice = &D_800CEA94[idx];

    if ((D_800CEAA4 & 1) && voice->unk_0C != 0) {
        return 0x100;
    }
    if (voice->unk_08 & 0x1000) {
        return 0x200;
    }
    return voice->unk_0C;
}

s16 func_80011634(void) {
    if (D_800CEAA4 & 0x8000) {
        return D_800CEA90->count;
    }
    return 0;
}

void func_8001165C(void) {
    unkB980Struct2* voice;
    s16 i;

    if (D_800CEAA4 & 0x8000) {
        D_800CEAA4 |= 0x10;
        for (i = 0; i < D_800CEA9C; i++) {
            voice = &D_800CEA94[i];
            if (voice->unk_0C == 1) {
                if (voice->unk_08 & 0x1000) {
                    voice->unk_08 &= ~0x1000;
                    voice->unk_0C = voice->unk_10;
                } else if (voice->unk_16 >= 0) {
                    alSndpSetSound(D_800CEA8C, voice->unk_16);
                    alSndpStop(D_800CEA8C);
                    voice->unk_08 |= 0x2000;
                }
                if (D_800CEABC != NULL) {
                    func_80010110(i);
                }
                voice->unk_29 = 0;
            }
        }
        func_8000F238();
        D_800CEAA4 &= ~0x10;
    }
}

void func_800117AC(s16 idx) {
    unkB980Struct2* voice;
    unkB980Struct1* seq;
    s16 n;

    if (!(D_800CEAA4 & 0x8000)) {
        return;
    }
    voice = &D_800CEA94[idx];
    if (voice->unk_0C != 1) {
        return;
    }
    D_800CEAA4 |= 0x10;
    if (voice->unk_08 & 0x1000) {
        voice->unk_08 &= ~0x1000;
        voice->unk_0C = voice->unk_10;
    } else {
        if (voice->unk_16 >= 0) {
            alSndpSetSound(D_800CEA8C, voice->unk_16);
            alSndpStop(D_800CEA8C);
            voice->unk_08 |= 0x2000;
        }
        if (voice->unk_29 == 2) {
            seq = &D_800CEAC0[idx];
            while (seq->unk_1A > 0) {
                n = seq->unk_14[--seq->unk_1A];
                if (D_800CEAC0[n].unk_0A == idx) {
                    voice = &D_800CEA94[n];
                    if (voice->unk_0C == 1) {
                        if (voice->unk_08 & 0x1000) {
                            voice->unk_08 &= ~0x1000;
                            voice->unk_0C = voice->unk_10;
                        } else if (voice->unk_16 >= 0) {
                            alSndpSetSound(D_800CEA8C, voice->unk_16);
                            alSndpStop(D_800CEA8C);
                            voice->unk_08 |= 0x2000;
                        }
                        voice->unk_29 = 0;
                        func_80010110(n);
                    }
                }
            }
        }
    }
    D_800CEA94[idx].unk_29 = 0;
    if (D_800CEABC != NULL) {
        func_80010110(idx);
    }
    func_8000F198(idx);
    D_800CEAA4 &= ~0x10;
}

void func_80011A30(s16 frames) {
    if (frames < 0) {
        frames = 1;
    }
    D_800CEAAC = 0;
    D_800CEAA8 = (f32)D_800CEAB0 / frames;
}

// decomp-permuter
s16 func_80011A80(void)
{
  f32 rate;
  f32 new_var;
  s32 frames;
  s32 ret;
  if (D_800CEAA8 != 0.0f)
  {
 do { } while (0);
    if (D_800CEAA8 < 0.0f)
    {
      rate = -D_800CEAA8;
    }
    else
    {
      rate = D_800CEAA8;
    }
    frames = (D_800CEAB0 / rate) - (D_800CEAAC / rate);
    new_var = D_800CEAA8;
    ret = frames;
    if (new_var < 0.0f)
    {
      ret = -ret;
    }
    frames = ret;
    return frames;
  }
  return 0;
}

void func_80011B2C(void) {
    s32 i;
    unkB980Struct2* voice;

    if (!(D_800CEAA4 & 1)) {
        D_800CEAA4 |= 0x11;
        for (i = 0; i < D_800CEA9C; i++) {
            voice = &D_800CEA94[i];
            if (voice->unk_0C == 1 && (voice->unk_08 & 0x40)) {
                func_800117AC(i);
            }
        }
        D_800CEAB6 = 0x40;
        D_800CEAA4 &= ~0x10;
    }
}

// decomp-permuter
void func_80011C04(s16 frames)
{
  s32 i;
  unkB980Struct2 *voice;
  if (D_800CEAA4 & 1)
  {
    D_800CEAA4 |= 0x10;
    for (i = 0; i < D_800CEA9C; i++)
    {
      voice = &D_800CEA94[i];
      if (voice->unk_0C == 1)
      {
        voice->unk_08 |= 2;
      }
    }

    D_800CEAA4 &= ~1;
    if ((frames != 0) && (!(D_800CEAA8 > 0.0f)))
    {
 do { } while (0);
      D_800CEAAC = 0;
      D_800CEAB2 = 0;
      func_8000DDEC();
      D_800CEAA8 = -(((f32) D_800CEAB0) / frames);
    }
    D_800CEAA4 &= ~0x10;
  }
}

void func_80011D48(s16 idx, s16 angle, f32 dist) {
    B980SfxState* st;
    f32 d;
    f32 f8;
    f32 den;
    s16 vol;
    u8 pan;
    s8 minVol;
    unkB980Struct2* voice;

    st = &D_800CEAC4[idx];
    voice = &D_800CEA94[idx];
    if (voice->unk_0C != 1) {
        return;
    }
    D_800CEAA4 |= 0x10;
    if (dist < 0.0f) {
        dist = -dist;
    }
    d = dist - D_800CEAC8;
    if (d < 0.0f) {
        d = 0.0f;
    }
    vol = 0;
    if (d <= D_800CEACC) {
        vol = (D_800CEACC - d) * 128.0f / D_800CEACC;
        if (vol >= 0x80) {
            vol = 0x7F;
        }
        minVol = st->unk_0E & 0x7F;
        if (vol < minVol) {
            if (st->unk_0E & 0x80) {
                vol = minVol;
            } else {
                vol = 0;
            }
        }
    }
    func_80012140(idx, vol);
    angle += D_800CEAD8;
    if (angle >= 360) {
        angle -= 360;
    }
    if (angle >= 181) {
        angle = 360 - angle;
    }
    pan = (angle << 7) / 180;
    if (pan >= 0x80) {
        pan = 0x7F;
    }
    if (D_800CEAD4 != 0.0f) {
        d = dist - D_800CEAD0;
        if (d < 0.0f) {
            d = 0.0f;
        }
        if (d < D_800CEAD4) {
            pan = 64.0f - (64 - pan) * (d / D_800CEAD4);
        }
    }
    func_8001249C(idx, pan);
    if (st->unk_00 + st->unk_04 != 0.0f) {
        d = st->unk_00 * D_800CEAE0;
        f8 = st->unk_04 * D_800CEAE0;
        if (st->unk_08 >= 0.0f && st->unk_08 < dist) {
            d = -d;
            f8 = -f8;
            if (st->unk_0C < D_800CEADA) {
                st->unk_0C = st->unk_0C + (dist - st->unk_08);
                f8 += 2.0f * -f8 * ((f32)(D_800CEADA - st->unk_0C) / D_800CEADA);
            }
        } else {
            st->unk_0C = 0;
        }
        d = D_800CEADC - d;
        den = D_800CEADC - f8;
        func_80012260(idx, d / den);
    }
    st->unk_08 = dist;
    D_800CEAA4 &= ~0x10;
}

void func_80012140(s16 arg0, s8 arg1) {
    unkB980Struct2* voice;
    unkB980Struct1* seq;
    s16 i;
    s16 n;

    voice = &D_800CEA94[arg0];
    if (!(voice->unk_08 & 0x1000)) {
        voice->unk_08 |= 2;
        if (voice->unk_29 == 2) {
            seq = &D_800CEAC0[arg0];
            i = seq->unk_1A;
            while (i > 0) {
                i--;
                n = seq->unk_14[i];
                if (D_800CEAC0[n].unk_0A == arg0) {
                    D_800CEA94[n].unk_23 = arg1;
                    D_800CEA94[n].unk_08 |= 2;
                }
            }
        }
    }
    voice->unk_23 = arg1;
}

void func_80012260(s16 arg0, f32 arg1) {
    unkB980Struct2* voice;
    unkB980Struct1* seq;
    s16 i;
    s16 n;

    if (!(arg1 < 0.0f)) {
        voice = &D_800CEA94[arg0];
        if (!(voice->unk_08 & 0x1000)) {
            voice->unk_08 |= 1;
            if (voice->unk_29 == 2) {
                seq = &D_800CEAC0[arg0];
                i = seq->unk_1A;
                while (i > 0) {
                    i--;
                    n = seq->unk_14[i];
                    if (D_800CEAC0[n].unk_0A == arg0) {
                        D_800CEA94[n].unk_1C = arg1;
                        D_800CEA94[n].unk_08 |= 1;
                    }
                }
            }
        }
        voice->unk_1C = arg1;
    }
}

void func_80012394(s16 idx, f32 a, f32 b) {
    D_800CEAC4[idx].unk_00 = a;
    D_800CEAC4[idx].unk_04 = b;
    if (b < 0.0f) {
        D_800CEAC4[idx].unk_04 = -b;
    }
}

void func_800123DC(s16 arg0, s8 arg1) {
    unkB980Struct2* voice = &D_800CEA94[arg0];

    if (voice->unk_0C != 1) {
        return;
    }
    D_800CEAA4 |= 0x10;
    if (!(voice->unk_08 & 0x1000)) {
        voice->unk_08 |= 2;
        if (voice->unk_29 == 2) {
            func_800108C8(arg0, arg1);
        }
    }
    voice->unk_22 = arg1;
    D_800CEAA4 &= ~0x10;
}

void func_8001249C(s16 arg0, u8 arg1) {
    unkB980Struct2* temp_s0 = &D_800CEA94[arg0];
    u8 var_s1 = arg1;

    if (temp_s0->unk_0C != 1) {
        return;
    }

    D_800CEAA4 |= 0x10;

    if (var_s1 > 127) {
        var_s1 = 127;
    }

    if (!(temp_s0->unk_08 & 0x1000)) {
        temp_s0->unk_08 |= 4;
        if (temp_s0->unk_29 == 2) {
            func_80010998(arg0, var_s1);
        }
    }

    temp_s0->unk_25 = var_s1;
    D_800CEAA4 &= ~0x10;
}

void func_80012574(s16 arg0, s16 arg1) {
    unkB980Struct2* voice = &D_800CEA94[arg0];

    if (voice->unk_0C != 1) {
        return;
    }
    D_800CEAA4 |= 0x10;
    if (arg1 > 1200) {
        arg1 = 1200;
    }
    if (!(voice->unk_08 & 0x1000)) {
        voice->unk_08 |= 1;
        if (voice->unk_29 == 2) {
            func_80010A68(arg0, arg1);
        }
    }
    voice->unk_1A = arg1;
    D_800CEAA4 &= ~0x10;
}

void func_80012654(s16 arg0, s8 arg1) {
    unkB980Struct2* voice = &D_800CEA94[arg0];

    if (voice->unk_0C != 1 || (voice->unk_08 & 0x10)) {
        return;
    }
    D_800CEAA4 |= 0x10;
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (!(voice->unk_08 & 0x1000)) {
        voice->unk_08 |= 8;
        if (voice->unk_29 == 2) {
            func_80010B38(arg0, arg1);
        }
    }
    voice->unk_28 = arg1;
    D_800CEAA4 &= ~0x10;
}

void func_80012738(s8 arg0) {
    D_800CEAA4 |= 0x10;
    D_800CEAB0 = D_800CEAB2 = func_8000ADFC(arg0);
    func_8000DDEC();
    D_800CEAA8 = 0;
    D_800CEAA4 &= ~0x10;
}

void func_800127A0(s8 arg0) {
    s32 i;
    unkB980Struct2* voice;

    D_800CEAA4 |= 0x10;
    D_800CEAB8 = arg0;
    for (i = 0; i < D_800CEA9C; i++) {
        voice = &D_800CEA94[i];
        if (voice->unk_0C == 1) {
            if (!(voice->unk_08 & 0x1000) && voice->unk_22 != D_800CEAB8) {
                voice->unk_08 |= 2;
            }
            voice->unk_22 = D_800CEAB8;
        }
    }
    D_800CEAA4 &= ~0x10;
}

void func_8001286C(u8 arg0) {
    s32 i;
    unkB980Struct2* voice;

    D_800CEAA4 |= 0x10;
    if (arg0 > 127) {
        arg0 = 127;
    }
    for (i = 0; i < D_800CEA9C; i++) {
        voice = &D_800CEA94[i];
        if (voice->unk_0C == 1) {
            if (!(voice->unk_08 & 0x1000) && voice->unk_25 != arg0) {
                voice->unk_08 |= 4;
            }
            voice->unk_25 = arg0;
        }
    }
    D_800CEAB9 = arg0;
    D_800CEAA4 &= ~0x10;
}

void func_8001293C(s16 arg0) {
    s32 i;
    unkB980Struct2* voice;

    D_800CEAA4 |= 0x10;
    if (arg0 > 1200) {
        arg0 = 1200;
    }
    for (i = 0; i < D_800CEA9C; i++) {
        voice = &D_800CEA94[i];
        if (voice->unk_0C == 1) {
            if (!(voice->unk_08 & 0x1000) && voice->unk_1A != arg0) {
                voice->unk_08 |= 1;
            }
            voice->unk_1A = arg0;
        }
    }
    D_800CEAB4 = arg0;
    D_800CEAA4 &= ~0x10;
}

void func_80012A18(s8 arg0) {
    s32 i;
    unkB980Struct2* voice;

    D_800CEAA4 |= 0x10;
    if (arg0 < 0) {
        arg0 = 0;
    }
    for (i = 0; i < D_800CEA9C; i++) {
        voice = &D_800CEA94[i];
        if (voice->unk_0C == 1 && !(voice->unk_08 & 0x10)) {
            if (!(voice->unk_08 & 0x1000) && voice->unk_28 != (u8)arg0) {
                voice->unk_08 |= 8;
            }
            voice->unk_28 = arg0;
        }
    }
    D_800CEABA = arg0;
    D_800CEAA4 &= ~0x10;
}

s8 func_80012AF8(void) {
    return D_800CEAB8;
}

u8 func_80012B04(void) {
    return D_800CEAB9;
}

s16 func_80012B10(void) {
    return D_800CEAB4;
}

s8 func_80012B1C(void) {
    return D_800CEABA;
}

void func_80012B28(s8 delay, s8 count, s8 decay, s8 first) {
    if ((D_800CEAA4 & 0x8000) && D_800CEA90->magic == 0x5433) {
        D_800CEAF0 = D_800CEA9C;
        func_8000F238();
        if (delay == 0 || count == 0 || decay == 0 || first == 0) {
            D_800CEAF0 = 0;
        }
        D_800CEAF4 = delay;
        D_800CEAF5 = count;
        D_800CEAE8 = decay / 127.0f;
        D_800CEAEC = first / 127.0f;
    }
}

void func_80012C70(s8 arg0) {
    D_800CEABB = arg0;
}

s32 func_80012C7C(s16 id) {
    B980SndParam param;

    if (!(D_800CEAA4 & 0x8000)) {
        return -1;
    }
    if ((id >= D_800CEA90->count) | (id < 0)) {
        return -1;
    }
    func_8000DF98(id, &param);
    return param.unk_18;
}
