#include "common.h"
#include "engine/ovlman.h"
#include "engine/pad.h"

/* Debug "sequential play": ovl_7A's menu, but steps through the minigames in order (skipping the
   flagged ones) from objmain's D_800C596E. */

/* One minigame of the debug menus. */
typedef struct DebugMg {
    /* 0x00 */ u32 info; /* bytes: skip flag, minigame number (1-based), ?, ? */
    /* 0x04 */ s32 ovl;
    /* 0x08 */ u32 mes; /* message id << 16 */
    /* 0x0C */ char* name;
} DebugMg;

/* A light colour cycling between two colours (func_800F6C60's object work; unused). */
typedef struct LightFade {
    /* 0x00 */ s16 light;
    /* 0x02 */ u16 from[3];
    /* 0x08 */ u16 to[3];
    /* 0x0E */ s16 dir[3];
    /* 0x14 */ u8 down[3];
    /* 0x17 */ s8 cur[3];
    /* 0x1C */ f32 timer;
    /* 0x20 */ f32 speed;
    /* 0x24 */ u8 done[3];
    /* 0x27 */ u8 unk27;
} LightFade; /* size = 0x28 */

/* Per minigame: the team of each player, and unknown bytes. */
typedef struct DebugMgSetup {
    /* 0x00 */ u8 group[4];
    /* 0x04 */ u8 unk4[4];
    /* 0x08 */ s16 unk8[4];
} DebugMgSetup;

extern s16 D_800C596E; /* next minigame */

void func_80018E98(u16, s32);
s32 func_80024198(s32, Gfx*, s32);
void func_800295FC(void*, void*, void*, Vec3f*);

void func_800F69FC_DebugSequentialPlay(omObjData* arg0, u16 arg1);
void func_800F6BBC_DebugSequentialPlay(void);
void func_800F6C60_DebugSequentialPlay(omObjData*, s16, f32, u8*, u8*);
void func_800F6D78_DebugSequentialPlay(omObjData*);
void func_800F6EF4_DebugSequentialPlay(u16);
void func_800F70D0_DebugSequentialPlay(u16);
void func_800F72D0_DebugSequentialPlay(omObjData*);
void func_800F73EC_DebugSequentialPlay(omObjData*);
void func_800F75DC_DebugSequentialPlay(void);
void func_800F7680_DebugSequentialPlay(u16);
void func_800F773C_DebugSequentialPlay(void);
void func_800F7788_DebugSequentialPlay(void);
void func_800F782C_DebugSequentialPlay(void);
void func_800F78FC_DebugSequentialPlay(void);
void func_800F7B5C_DebugSequentialPlay(void);
void func_800F7D70_DebugSequentialPlay(void);
void func_800F7FC0_DebugSequentialPlay(f32, f32, f32, f32, f32, f32, f32, f32);
void func_800F8070_DebugSequentialPlay(void);
void func_800F80A8_DebugSequentialPlay(s32);
void func_800F698C_DebugSequentialPlay(omObjData*);
void func_800F69A8_DebugSequentialPlay(omObjData*);
void func_800F69C4_DebugSequentialPlay(omObjData*);
void func_800F69E0_DebugSequentialPlay(omObjData*);

/* .data */
DebugMg D_800F80D0_DebugSequentialPlay[] = {
    { 0x00010B00, 0, 0x03250000, "01:SHINKEI SUIJYAKU" },
    { 0x00020B00, 1, 0x03260000, "02:ICHIKA BACHIKA" },
    { 0x00030B00, 2, 0x03270000, "03:SLOT MACHINE" },
    { 0x00040B00, 3, 0x03280000, "04:ANAHORI MARIO" },
    { 0x00050B00, 4, 0x03290000, "05:SUMOGRI MARIO" },
    { 0x00060C00, 5, 0x032A0000, "06:NOKONOKO TAMATEBAKO" },
    { 0x01000B00, 1000, 0x00640000, "07:" },
    { 0x01070B00, 6, 0x032B0000, "08:SAME GAME" },
    { 0x01000B00, 1000, 0x00640000, "09:PAKKUNFLOWER WO SUKUE" },
    { 0x00080B00, 7, 0x032C0000, "10:BOMHEI WATASHI" },
    { 0x01090C00, 8, 0x032D0000, "11:YOSI NO SHITAAWASE" },
    { 0x000A0C00, 9, 0x032E0000, "12:AMIDAKUJI" },
    { 0x000B0C00, 10, 0x032F0000, "13:LEADER WA DAREDA" },
    { 0x000C0C00, 11, 0x03300000, "14:ISUTORI GAME" },
    { 0x000D0C00, 12, 0x03310000, "15:MARIO NO JIKAHATSUDEN" },
    { 0x000E0C00, 13, 0x03320000, "16:DIGITAL KATANUKI" },
    { 0x000F0C00, 14, 0x03330000, "17:MARIO HYAKUMENSOU" },
    { 0x00100C00, 15, 0x03340000, "18:PAKKUNFLOWER TATAKI" },
    { 0x01000B00, 1000, 0x00640000, "19:HONOO NO KURIBO BOKUJYO" },
    { 0x01000B00, 1000, 0x00640000, "20:" },
    { 0x00110C00, 16, 0x03350000, "21:KOOPA NO KIMOCHI" },
    { 0x00120C00, 17, 0x03360000, "22:BOWLING GOGO" },
    { 0x00130B00, 18, 0x03370000, "23:HIPDROP" },
    { 0x00140C00, 19, 0x03380000, "24:KOOPA FUUSEN" },
    { 0x00150C00, 20, 0x03390000, "25:TEN COUNT COIN" },
    { 0x00160C00, 21, 0x033A0000, "26:HAMMER COIN" },
    { 0x00170C00, 22, 0x033B0000, "27:KUZURERU YUKA WO KAKENUKERO" },
    { 0x01000B00, 1000, 0x00640000, "28:BOUTAKATOBI DE JUMP" },
    { 0x00180C00, 23, 0x033C0000, "29:BLOCKYAMANO OTAKARA SAGASHI" },
    { 0x00190C00, 24, 0x033D0000, "30:PLATE WATARI" },
    { 0x001A0C00, 25, 0x033E0000, "31:BOUWATARI" },
    { 0x001B0C00, 26, 0x033F0000, "32:IROIRO KINOKO" },
    { 0x01000B00, 1000, 0x00640000, "33:" },
    { 0x011C0B00, 1000, 0x03400000, "34:YOUGAN TANIZOKO OKKOTI" },
    { 0x00380C00, 27, 0x035C0000, "35:HAMMERBROS ITEM NO TOU" },
    { 0x001D0C00, 28, 0x03410000, "36:KOSODORO GAME" },
    { 0x001E0B00, 29, 0x03420000, "37:SLIDER RACE" },
    { 0x001F0C00, 30, 0x03430000, "38:NOKKARE BALL" },
    { 0x00200C00, 31, 0x03440000, "39:TSUNAWATARI DE DANGEROUS" },
    { 0x00210C00, 32, 0x03450000, "40:NOKONOKO POLE" },
    { 0x00220C00, 33, 0x03460000, "41:NOKONOKO KOROKORO" },
    { 0x00230B00, 34, 0x03470000, "42:PUKAPUKA ISLAND" },
    { 0x00240C00, 35, 0x03480000, "43:CRANE GAME" },
    { 0x01000B00, 1000, 0x035D0000, "44:BUMGEE JUMP" },
    { 0x01000B00, 1000, 0x00640000, "45:" },
    { 0x01250B00, 1000, 0x03490000, "46:CHIE NO HIMO" },
    { 0x00370B00, 36, 0x035B0000, "47:HAPPY FLOWER" },
    { 0x01000B00, 1000, 0x00640000, "48:OTAKARA KIBAKO" },
    { 0x01000B00, 1000, 0x00640000, "49:HUWAHUWA BALOON" },
    { 0x00260C00, 37, 0x034A0000, "50:THROTTLE RACING" },
    { 0x00270C00, 38, 0x034B0000, "51:MARIO ORCHESTRA" },
    { 0x00280C00, 39, 0x034C0000, "52:MUKADE GOGO" },
    { 0x00290C00, 40, 0x034D0000, "53:SENCHOUSAN NO MEIREIDESU" },
    { 0x01000B00, 1000, 0x00640000, "54:PK SOCCER" },
    { 0x002A0C00, 41, 0x034E0000, "55:LIMBO DANCE" },
    { 0x002B0C00, 42, 0x034F0000, "56:BOMHEI BASKET" },
    { 0x002C0C00, 43, 0x03500000, "57:ITEM FISHING" },
    { 0x002D0C00, 44, 0x03510000, "58:MINI SOCCER" },
    { 0x002E0C00, 45, 0x03520000, "59:OTAKARA TOUCHDOWN" },
    { 0x002F0C00, 46, 0x03530000, "60:NAWANAWA PYONPYON" },
    { 0x001C0B00, 52, 0x03400000, "61:HASHIRE! NOKKARE BALL" },
    { 0x00250B00, 52, 0x03490000, "62:ISOGE! NOKKARE BALL" },
    { 0x01000B00, 1000, 0x00640000, "63:BOMBER MARIO" },
    { 0x00300C00, 47, 0x03540000, "64:TRUCK RACE" },
    { 0x01310B00, 1000, 0x03550000, "65:TOUR DE MARIO" },
    { 0x00320C00, 48, 0x03560000, "66:MARIO BLUE" },
    { 0x00330C00, 49, 0x03570000, "67:JURASIC PAKKUN" },
    { 0x00340C00, 50, 0x03580000, "68:TSUNAHIKI DE DANGEROUS" },
    { 0x00350C00, 51, 0x03590000, "69:MARIO BOAT" },
    { 0x00360B00, 52, 0x035A0000, "70:SUSUME! NOKKARE BALL" },
    { 0x00000C00, 105, 0x00640000, "71:KINOKO DANI" },
    { 0x00000C00, 54, 0x00640000, "72:MB01" },
    { 0x00000C00, 55, 0x00640000, "73:MB02" },
    { 0x00000C00, 56, 0x00640000, "74:MB03" },
    { 0x00000C00, 57, 0x00640000, "75:MB04" },
    { 0x00000C00, 58, 0x00640000, "76:MB05" },
    { 0x00000C00, 59, 0x00640000, "77:MB06" },
    { 0x00000C00, 60, 0x00640000, "78:MB07" },
    { 0x00000C00, 61, 0x00640000, "79:MB08" },
    { 0x00000C00, 99, 0x00640000, "80:STAFFROLL" },
    { 0x00000C00, 112, 0x00640000, "81@MOTION CHECK" },
    { 0x00000C00, 98, 0x00640000, "82:MB OPENING" },
    { 0x00000C00, 65, 0x00640000, "83:MB ENDING" },
    { 0x00000C00, 111, 0x00640000, "84:INST" },
    { 0x00000B00, 123, 0x00640000, "85:RESULT" },
    { 0x00000B00, 127, 0x00640000, "86:TRIAL MODE" },
    { 0x00000B00, 120, 0x00640000, "87:MQOPEN" },
    { 0x00000B00, 113, 0x00640000, "88:MQ00" },
    { 0x01000B00, 1000, 0x00640000, "89:" },
    { 0x00000C00, 122, 0x00640000, "90*RANDOM PLAY" },
};

DebugMgSetup D_800F8670_DebugSequentialPlay[] = {
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 2, 3 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
    { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 5, 5, 5, 5 } },
};

/* Per player: the x and y of the player's panel (s16 values stored as words). */
s32 D_800F8C10_DebugSequentialPlay[4] = { 24, 162, 24, 162 };
s32 D_800F8C20_DebugSequentialPlay[4] = { 44, 44, 104, 104 };
u8 D_800F8C30_DebugSequentialPlay[6] = { 9, 160, 12, 200, 0, 0 }; /* light colours */
u16 D_800F8C36_DebugSequentialPlay = 0; /* all four players are CPUs */
u16 D_800F8C38_DebugSequentialPlay = 0; /* faded in */
u16 D_800F8C3A_DebugSequentialPlay = 0; /* start the minigame once faded out */
s32 D_800F8C3C_DebugSequentialPlay = 0;
u16 D_800F8C40_DebugSequentialPlay = 0; /* leave the menu */

/* .bss */
extern s16 D_800F92D4_DebugSequentialPlay;
extern s16 D_800F92D6_DebugSequentialPlay;
extern s16 D_800F92D8_DebugSequentialPlay;
extern s16 D_800F92DA_DebugSequentialPlay;
extern u16 D_800F92E0_DebugSequentialPlay[4][4]; /* per player: the four team digit sprites */
extern u8 D_800F9306_DebugSequentialPlay; /* random minigame */
extern s16 D_800F9308_DebugSequentialPlay;
extern s16 D_800F930A_DebugSequentialPlay;
extern u8 D_800F9310_DebugSequentialPlay[0x200];
extern s16 D_800F9510_DebugSequentialPlay[4]; /* coins won in the last minigame */
extern Process* D_800F9518_DebugSequentialPlay;
extern Gfx* D_800F9570_DebugSequentialPlay[8];
extern Vtx* D_800F9590_DebugSequentialPlay[8]; /* 15 x 15 water grid */
extern s32 D_800F95B0_DebugSequentialPlay;
extern f32 D_800F95B4_DebugSequentialPlay;
extern f32 D_800F95B8_DebugSequentialPlay;
extern f32 D_800F95BC_DebugSequentialPlay;
extern f32 D_800F95C0_DebugSequentialPlay;

void func_800F65E0_DebugSequentialPlay(void) {
    s32 i;
    u16 n;

    n = 0;
    omInitObjMan(0x24, 0xF);
    for (i = 0; i < 4; i++) {
        D_800F9510_DebugSequentialPlay[i] = GwPlayer[i].coins_mg;
    }
    func_80060088();
    func_8001DE70(30);
    func_80029090(3);
    func_8006CEA0();
    func_800F7FC0_DebugSequentialPlay(45.0f, 1100.0f, 90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].flags & 1) {
            n++;
        }
    }
    if (n == 4) {
        D_800F8C36_DebugSequentialPlay = 1;
    }
    func_80023448(3);
    func_800234B8(0, 0, 0, 0);
    func_800234B8(1, 0, 0, 0);
    func_80023504(1, 0.0f, 100.0f, 0.0f);
    func_800234B8(2, D_800F8C30_DebugSequentialPlay[0], D_800F8C30_DebugSequentialPlay[1], D_800F8C30_DebugSequentialPlay[2]);
    func_80023504(2, -88.0f, -65.0f, 47.0f);
    func_800234B8(3, D_800F8C30_DebugSequentialPlay[3], D_800F8C30_DebugSequentialPlay[4], D_800F8C30_DebugSequentialPlay[5]);
    func_80023504(3, -64.0f, -50.0f, 87.0f);
    func_8005D98C(0, 4);
    D_800F9518_DebugSequentialPlay = omAddPrcObj(func_800F7788_DebugSequentialPlay, 0x3FFF, 0, 0);
    omSetStatBit(omAddObj(100, 0, 0, -1, func_800F8070_DebugSequentialPlay), 0xA0);
    omAddObj(10, 0, 0, 0, func_800F698C_DebugSequentialPlay);
    omAddObj(10, 0, 0, 0, func_800F69A8_DebugSequentialPlay);
    omAddObj(10, 0, 0, 0, func_800F69C4_DebugSequentialPlay);
    omAddObj(10, 0, 0, 0, func_800F69E0_DebugSequentialPlay);
    omAddObj(0, 0, 0, -1, func_800F72D0_DebugSequentialPlay);
    omAddObj(10000, 0, 0, -1, func_800F773C_DebugSequentialPlay);
    InitSprite(0x8000E);
    D_800F92D6_DebugSequentialPlay = InitSprite(0x21);
    D_800F92D8_DebugSequentialPlay = InitSprite(0x7C);
    D_800F92DA_DebugSequentialPlay = InitSprite(0x7B);
    SetFadeInTypeAndTime(0xFF, 0x10);
}

void func_800F698C_DebugSequentialPlay(omObjData* arg0) {
    func_800F69FC_DebugSequentialPlay(arg0, 0);
}

void func_800F69A8_DebugSequentialPlay(omObjData* arg0) {
    func_800F69FC_DebugSequentialPlay(arg0, 1);
}

void func_800F69C4_DebugSequentialPlay(omObjData* arg0) {
    func_800F69FC_DebugSequentialPlay(arg0, 2);
}

void func_800F69E0_DebugSequentialPlay(omObjData* arg0) {
    func_800F69FC_DebugSequentialPlay(arg0, 3);
}

void func_800F69FC_DebugSequentialPlay(omObjData* arg0, u16 arg1) {
    u16 spr;
    u16 i;

    spr = func_80019060(D_800F92D4_DebugSequentialPlay, GwPlayer[arg1].character, 1);
    ShowBasicSprite(spr);
    func_80018CF8(spr, 0xFF);
    SetBasicSpritePos(spr, D_800F8C10_DebugSequentialPlay[arg1], D_800F8C20_DebugSequentialPlay[arg1]);
    spr = func_80019060(D_800F92D6_DebugSequentialPlay, 0, 1);
    ShowBasicSprite(spr);
    func_80018CF8(spr, 0xFF);
    SetBasicSpritePos(spr, D_800F8C10_DebugSequentialPlay[arg1] + 0x40, D_800F8C20_DebugSequentialPlay[arg1] + 0x30);
    for (i = 0; i < 4; i++) {
        D_800F92E0_DebugSequentialPlay[arg1][i] = func_80019060(D_800F92DA_DebugSequentialPlay, 0, 1);
    }
    func_800F6EF4_DebugSequentialPlay(arg1);
    func_800F70D0_DebugSequentialPlay(arg1);
    func_8006D010(D_800F8C10_DebugSequentialPlay[arg1] + 0x4B, D_800F8C20_DebugSequentialPlay[arg1] + 0x1B, 0x3A, 0xC, 0, 0);
    arg0->func_ptr = func_800F6BBC_DebugSequentialPlay;
}

void func_800F6BBC_DebugSequentialPlay(void) {
}

void func_800F6BC4_DebugSequentialPlay(omObjData* arg0) {
    u8 from[3];
    u8 to[3];
    s32 i;

    for (i = 0; i < 3; i++) {
        from[i] = D_800F8C30_DebugSequentialPlay[i];
    }
    to[0] = 190;
    to[1] = 190;
    to[2] = 12;
    func_800F6C60_DebugSequentialPlay(arg0, 2, 1.0f, from, to);
}

void func_800F6C30_DebugSequentialPlay(omObjData* arg0) {
    u8 from[3];
    u8 to[3];

    /* retail passes both arrays uninitialised */
    func_800F6C60_DebugSequentialPlay(arg0, 3, 0.1f, from, to);
}

void func_800F6C60_DebugSequentialPlay(omObjData* arg0, s16 light, f32 speed, u8* from, u8* to) {
    LightFade* w;
    s32 i;

    w = arg0->unk_50 = func_80023684(sizeof(LightFade), 0x7918);
    w->light = light;
    w->speed = speed;
    w->timer = 0.0f;
    for (i = 0; i < 3; i++) {
        w->from[i] = w->cur[i] = from[i];
        w->to[i] = to[i];
        w->down[i] = 0;
        w->done[i] = 0;
        if (from[i] < to[i]) {
            w->dir[i] = 1;
        } else if (from[i] > to[i]) {
            w->dir[i] = -1;
        } else {
            w->dir[i] = 0;
        }
    }
    arg0->func_ptr = func_800F6D78_DebugSequentialPlay;
}

void func_800F6D78_DebugSequentialPlay(omObjData* arg0) {
    LightFade* w = arg0->unk_50;
    s32 i;

    if ((w->timer += w->speed) >= 1.0f) {
        w->timer = 0.0f;
        for (i = 0; i < 3; i++) {
            if (w->done[i] == 1) {
                continue;
            }
            w->cur[i] += w->dir[i];
            if (w->down[i] == 0) {
                if (w->dir[i] > 0) {
                    if (w->cur[i] >= w->to[i]) {
                        w->down[i] = 1;
                        w->dir[i] = -1;
                        w->done[i] = 1;
                    }
                } else {
                    goto down;
                }
            } else if (w->dir[i] > 0) {
                if (w->cur[i] >= w->to[i]) {
                    w->down[i] = 1;
                    w->dir[i] = -1;
                    w->done[i] = 1;
                }
            } else {
            down:
                if (w->cur[i] <= w->from[i]) {
                    w->down[i] = 0;
                    w->dir[i] = 1;
                    w->done[i] = 1;
                }
            }
        }
        func_800234B8(w->light, w->cur[0], w->cur[1], w->cur[2]);
    }
    for (i = 0; i < 3; i++) {
        if (w->done[i] == 0) {
            break;
        }
    }
    if (i == 3) {
        w->cur[0] ^= 1; /* sic */
        w->unk27 = 0;
        w->timer = 0.0f;
    }
}

// register allocation (raw 49, masked 20); tried digit-subtract locals, coins %= steps (kept), declaration order (M1c)
#ifdef NON_MATCHING
void func_800F6EF4_DebugSequentialPlay(u16 arg0) {
    s16 coins;
    u16 spr;

    coins = GwPlayer[arg0].coins;
    spr = func_80019060(D_800F92D8_DebugSequentialPlay, 0, 1);
    func_80018E50(spr, coins / 100, 0);
    coins %= 100;
    SetBasicSpritePos(spr, D_800F8C10_DebugSequentialPlay[arg0] + 0x58, D_800F8C20_DebugSequentialPlay[arg0] + 0x20);
    spr = func_80019060(D_800F92D8_DebugSequentialPlay, 0, 1);
    func_80018E50(spr, coins / 10, 0);
    coins %= 10;
    SetBasicSpritePos(spr, D_800F8C10_DebugSequentialPlay[arg0] + 0x68, D_800F8C20_DebugSequentialPlay[arg0] + 0x20);
    spr = func_80019060(D_800F92D8_DebugSequentialPlay, 0, 1);
    func_80018E50(spr, coins, 0);
    SetBasicSpritePos(spr, D_800F8C10_DebugSequentialPlay[arg0] + 0x78, D_800F8C20_DebugSequentialPlay[arg0] + 0x20);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7E_DebugSequentialPlay/30F1B0", func_800F6EF4_DebugSequentialPlay);
#endif

/* func_800F70D0's team-letter templates (named so its INCLUDE_ASM build finds them) */
const u8 D_800F9284_DebugSequentialPlay[4] __attribute__((section(".rodata"))) = { 12, 0, 8, 13 };
const u8 D_800F9288_DebugSequentialPlay[4] __attribute__((section(".rodata"))) = { 18, 20, 1, 25 };

// scheduling of the sprite x (masked 2)
#ifdef NON_MATCHING
void func_800F70D0_DebugSequentialPlay(u16 arg0) {
    u16 sum = 0;
    u8 team0[4] = { 12, 0, 8, 13 };
    u8 team1[4] = { 18, 20, 1, 25 };
    s32 i;
    u8* text;

    for (i = 0; i < 4; i++) {
        sum += GwPlayer[i].group;
    }
    if (sum == 6) {
        for (i = 0; i < 4; i++) {
            func_80018C90(D_800F92E0_DebugSequentialPlay[arg0][i]);
        }
        return;
    }
    text = team1;
    if (GwPlayer[arg0].group == 0) {
        text = team0;
    }
    for (i = 0; i < 4; i++) {
        ShowBasicSprite(D_800F92E0_DebugSequentialPlay[arg0][i]);
        func_80018E50(D_800F92E0_DebugSequentialPlay[arg0][i], *text++, 0);
        func_80018E98(D_800F92E0_DebugSequentialPlay[arg0][i], 1);
        SetBasicSpritePos(D_800F92E0_DebugSequentialPlay[arg0][i], (i * 16 + 0x48) + D_800F8C10_DebugSequentialPlay[arg0], D_800F8C20_DebugSequentialPlay[arg0] + 8);
    }
    if (GwPlayer[arg0].group == 1) {
        func_80018C90(D_800F92E0_DebugSequentialPlay[arg0][3]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7E_DebugSequentialPlay/30F1B0", func_800F70D0_DebugSequentialPlay);
#endif

void func_800F72D0_DebugSequentialPlay(omObjData* arg0) {
    char buf[0x200]; /* unused */
    s32 i;

    func_800F75DC_DebugSequentialPlay();
    D_800F9308_DebugSequentialPlay = func_8006D010(0x48, 0x12, 0xB0, 0x14, 0, 0);
    D_800F930A_DebugSequentialPlay = func_8006D010(0x20, 0xA0, 0x100, 0x38, 0, 0);
    for (i = 0; i < 4; i++) {
        GwPlayer[i].coins += D_800F9510_DebugSequentialPlay[i];
        if (GwPlayer[i].coins >= 1000) {
            GwPlayer[i].coins = 999;
        }
        if (GwPlayer[i].coins < 0) {
            GwPlayer[i].coins = 0;
        }
    }
    func_800F78FC_DebugSequentialPlay();
    func_80060128(0x15);
    arg0->func_ptr = func_800F73EC_DebugSequentialPlay;
}

void func_800F73EC_DebugSequentialPlay(omObjData* arg0) {
    s32 i;
    s32 j;

    rand8();
    func_800F7D70_DebugSequentialPlay();
    i = 0;
    if (D_800F8C38_DebugSequentialPlay == 0) {
        if (func_80072718() != 0) {
            return;
        }
        D_800F8C38_DebugSequentialPlay = 1;
        if (D_800F8C3A_DebugSequentialPlay == 1) {
            GwSystem.unk_1E = (u8)(D_800F80D0_DebugSequentialPlay[D_800F9306_DebugSequentialPlay].info >> 16) - 1;
            omOvlCallEx(D_800F80D0_DebugSequentialPlay[D_800F9306_DebugSequentialPlay].ovl, 0, 0x94);
            return;
        }
        for (i = 0; i < D_800F3778; i++) {
            if ((ContBtn[i] & 0x20) && (ContBtn[i] & 0x10)) {
                D_800F8C40_DebugSequentialPlay = 1;
                return;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if ((ContBtnTrg[i] & 0x8000) || D_800F8C36_DebugSequentialPlay == 1) {
            func_800601D4(40);
            func_80070ED4();
            func_800726AC(2, 20);
            D_800F8C3A_DebugSequentialPlay = 1;
            D_800F8C38_DebugSequentialPlay = 0;
            return;
        }
        if (ContBtnTrg[i] & 0x4000) {
            func_800F75DC_DebugSequentialPlay();
            EndProcess(D_800F9518_DebugSequentialPlay);
            D_800F9518_DebugSequentialPlay = omAddPrcObj(func_800F782C_DebugSequentialPlay, 0x3FFF, 0, 0);
            for (j = 0; j < 4; j++) {
                func_800F70D0_DebugSequentialPlay(j);
            }
        }
    }
}

void func_800F75DC_DebugSequentialPlay(void) {
    while (1) {
        if ((u8)(D_800F80D0_DebugSequentialPlay[D_800C596E].info >> 24) == 0) {
            break;
        }
        if (++D_800C596E >= 70) {
            D_800C596E = 0;
        }
    }
    D_800F9306_DebugSequentialPlay = D_800C596E++;
    if (D_800C596E >= 70) {
        D_800C596E = 0;
    }
    func_800F7680_DebugSequentialPlay(D_800F9306_DebugSequentialPlay);
}

void func_800F7680_DebugSequentialPlay(u16 arg0) {
    u8 groups[4];
    u8* g;
    s32 i;
    DebugMgSetup* setup = &D_800F8670_DebugSequentialPlay[arg0];

    groups[0] = setup->group[0];
    groups[1] = setup->group[1];
    groups[2] = setup->group[2];
    groups[3] = setup->group[3];
    i = 0;
    do {
        g = &groups[rand8() & 3];
        if (*g != 0xFF) {
            GwPlayer[i].group = *g;
            *g = 0xFF;
            i++;
        }
    } while (i != 4);
}

void func_800F773C_DebugSequentialPlay(void) {
    if ((D_800F8C40_DebugSequentialPlay != 0) || (D_800F5144 != 0)) {
        func_800F80A8_DebugSequentialPlay(0x83);
        func_800601D4(0x28);
        func_80070ED4();
    }
}

void func_800F7788_DebugSequentialPlay(void) {
    char buf[0x200]; /* unused */

    func_8006E070(D_800F9308_DebugSequentialPlay, 0);
    LoadStringIntoWindow(D_800F9308_DebugSequentialPlay, "SEQUENTIAL PLAY", -1, -1);
    while (1) {
        if ((func_8006FCC0(D_800F9308_DebugSequentialPlay)) != 0) {
            HuPrcVSleep();
        } else {
            break;
        }
    }

    EndProcess(D_800F9518_DebugSequentialPlay);
    D_800F9518_DebugSequentialPlay = omAddPrcObj(func_800F782C_DebugSequentialPlay, 0x3FFF, 0, 0);

    while (1) {
        HuPrcVSleep();
    }
}

void func_800F782C_DebugSequentialPlay(void) {
    char buffer[0x200];

    func_8006EB40(D_800F930A_DebugSequentialPlay);
    func_8006EB80();
    func_8006DA5C(D_800F930A_DebugSequentialPlay, (void*)(s32)(D_800F80D0_DebugSequentialPlay[D_800F9306_DebugSequentialPlay].mes >> 16), 0);
    /* "<minigame name>" in SJIS brackets */
    sprintf(buffer, "\x82\xc2\x82\xab\x81\x4a\x82\xcd\x81\x75\x87\x40\x81\x76");
    func_8007149C(D_800F9310_DebugSequentialPlay, (u8*) buffer);
    LoadStringIntoWindow(D_800F930A_DebugSequentialPlay, D_800F9310_DebugSequentialPlay, -1, -1);
    while (1) {
        if (func_8006FCC0(D_800F930A_DebugSequentialPlay) != 0) {
            HuPrcVSleep();
        } else {
            break;
        }
    }

    EndProcess(D_800F9518_DebugSequentialPlay);

    while (1) {
        HuPrcVSleep();
    }
}

void func_800F78FC_DebugSequentialPlay(void) {
    Vtx* v;
    Vtx* src;
    Vtx* dst;
    s16 z;
    u16 i;
    u16 k;
    s32 x;
    s32 y;
    s32 row;

    D_800F95B4_DebugSequentialPlay = 2.5f;
    D_800F95B8_DebugSequentialPlay = 2.0f;
    D_800F95BC_DebugSequentialPlay = 50.0f;
    D_800F95C0_DebugSequentialPlay = 0.0f;
    for (i = 0; i < D_800F37DA; i++) {
        D_800F9590_DebugSequentialPlay[i] = func_80023684(15 * 15 * sizeof(Vtx), 0x7918);
        D_800F9570_DebugSequentialPlay[i] = func_80023684(0x800 * sizeof(Gfx), 0x7918);
    }
    v = D_800F9590_DebugSequentialPlay[D_800F37F0];
    for (y = 0; y < 15; y++) {
        x = 0;
        row = y * 15;
        z = y * 200.0f - 1400.0f;
        for (; x < 15; x++) {
            dst = &v[x + row];
            dst->v.ob[0] = x * 200.0f - 1400.0f;
            dst->v.ob[1] = 0;
            dst->v.ob[2] = z;
            dst->v.cn[0] = 0x20;
            dst->v.cn[1] = 0x40;
            dst->v.cn[2] = 0x20;
            dst->v.cn[3] = 0x80;
        }
    }
    for (i = 0; i < D_800F37DA; i++) {
        if (i != D_800F37F0) {
            src = v;
            dst = D_800F9590_DebugSequentialPlay[i];
            for (k = 0; k < 15 * 15; k++) {
                *dst++ = *src++;
            }
        }
    }
    func_800F7B5C_DebugSequentialPlay();
    D_800F95B0_DebugSequentialPlay = func_80024198(0xA81, D_800F9570_DebugSequentialPlay[D_800F37F0], 4);
}

void func_800F7B5C_DebugSequentialPlay(void) {
    Gfx* g;
    s32 i;
    s32 row;
    s32 t;

    for (i = 0; i < D_800F37DA; i++) {
        g = D_800F9570_DebugSequentialPlay[i];
        gDPPipeSync(g++);
        gSPSetOtherMode(g++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x552230);
        gSPSetGeometryMode(g++, G_LIGHTING);
        gSPTexture(g++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetColorDither(g++, G_CD_BAYER);
        gDPSetPrimColor(g++, 0, 0, 0x1E, 0x5E, 0xBC, 0xB0);
        gDPSetCombineMode(g++, G_CC_SHADE, G_CC_SHADE);
        gDPSetTextureLUT(g++, G_TT_NONE);
        for (row = 0; row < 14; row++) {
            gSPVertex(g++, D_800F9590_DebugSequentialPlay[i] + row * 15, 30, 0);
            for (t = 0; t < 14; t++) {
                gSP2Triangles(g++, t, t + 1, t + 15, 0, t + 1, t + 16, t + 15, 0);
            }
        }
        gDPPipeSync(g++);
        gSPEndDisplayList(g++);
    }
}

// register allocation: retail keeps &n in a saved register (masked ~5)
#ifdef NON_MATCHING
void func_800F7D70_DebugSequentialPlay(void) {
    f32 n[3];
    f32* np;
    Vtx* v;
    Vtx* p;
    f32 x;
    f32 z;
    s32 row;
    s32 col;
    s32 k;

    *D_800F2B7C[D_800F95B0_DebugSequentialPlay].unk_6C->unk_00 = D_800F9570_DebugSequentialPlay[D_800F37F0];
    v = D_800F9590_DebugSequentialPlay[D_800F37F0];
    for (row = 0; row < 14; row++) {
        for (col = 0; col < 14; col++) {
            p = &v[col + row * 15];
            x = p->v.ob[0];
            z = p->v.ob[2];
            p->v.ob[1] = func_800AEAC0((D_800F95C0_DebugSequentialPlay / D_800F95B8_DebugSequentialPlay -
                                        func_800B1750(x * x + z * z) / D_800F95B4_DebugSequentialPlay) *
                                       6.283185307179586) *
                         D_800F95BC_DebugSequentialPlay;
        }
    }
    D_800F95C0_DebugSequentialPlay += 1.0f;
    np = n;
    for (row = 0; row < 14; row++) {
        for (col = 0; col < 14; col++) {
            p = &v[col + row * 15];
            func_800295FC(p, &v[col + (row * 15 + 1)], &v[col + (row + 1) * 15], (Vec3f*)np);
            for (k = 0; k < 3; k++) {
                p->n.n[k] = np[k] * 127.0f;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7E_DebugSequentialPlay/30F1B0", func_800F7D70_DebugSequentialPlay);
#endif

void func_800F7FC0_DebugSequentialPlay(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    func_800178A0(1);
    CZoom = arg1;
    CRot.x = arg2;
    CRot.y = arg3;
    CRot.z = arg4;
    Center.x = arg5;
    Center.y = arg6;
    Center.z = arg7;
    D_800C3110->unk_40 = arg0;
}

void func_800F8070_DebugSequentialPlay(void) {
    s32 i;
    for (i = 0; i < D_800F3778; i++) {}
}

void func_800F80A8_DebugSequentialPlay(s32 arg0) {
    omOvlReturnEx(1);
}
