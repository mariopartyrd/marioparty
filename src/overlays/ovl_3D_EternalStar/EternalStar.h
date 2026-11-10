#include "common.h"
#include "engine/process.h"
#include "spaces.h"
//start of rodata 800F8B80
//bss 800F9160 - 800F91B0


s16 func_800F753C_EternalStar(void);
s16 func_800F7564_EternalStar(void);
s16 func_800F758C_EternalStar(void);
s16 func_800F75B4_EternalStar(void);
s16 func_800F75DC_EternalStar(void);
s16 func_800F7608_EternalStar(void);
s16 func_800F7630_EternalStar(void);
s16 func_800F7658_EternalStar(void);
s16 func_800F7684_EternalStar(void);
s16 func_800F76B0_EternalStar(void);
s16 func_800F76D8_EternalStar(void);
s16 func_800F7704_EternalStar(void);
s16 func_800F7730_EternalStar(void);

void func_800F7B6C_EternalStar(void);
void func_800F7BA0_EternalStar(void);
void func_800F7BD4_EternalStar(void);
void func_800F7C08_EternalStar(void);
void func_800F7C3C_EternalStar(void);
void func_800F8130_EternalStar(void);
void func_800F8240_EternalStar(void);
void func_800F8298_EternalStar(void);
void func_800F8514_EternalStar(void);
void func_800F8588_EternalStar(void);
void func_800F88EC_EternalStar(void);
void func_800F8914_EternalStar(void);
void func_800F893C_EternalStar(void);
void func_800F8964_EternalStar(void);
void func_800F898C_EternalStar(void);
void func_800F89B4_EternalStar(void);
void func_800F89D8_EternalStar(void);
void func_800F89FC_EternalStar(void);
void func_800F8A30_EternalStar(void);
void func_800F8A94_EternalStar(void);


typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
} my_struct; // size 0x4

typedef struct EventTableUnkStruct {
    s16* spaceIDs;
    DecisionTreeNonLeafNode* decisionTree;
    s16 unk_08;
    s16 unk_0A;
} EventTableUnkStruct;

// extern my_struct D_800F8C18_EternalStar[]; // tbd how big it is :)

// extern s16* D_800F8ED8_EternalStar[];
extern s16 D_800F8F08_EternalStar[];
extern s16 D_800ED156;
extern s16 D_800ED158[];

// extern s32 D_800F8CA0_EternalStar[]; //ai decision struct
// extern s32 D_800F8D30_EternalStar[]; //ai decision struct
// extern s32 D_800F8D00_EternalStar[]; //ai decision struct
// extern s32 D_800F8CD0_EternalStar[]; //ai decision struct
// extern s32 D_800F8CA0_EternalStar[]; //ai decision struct
// extern s32 D_800F8C40_EternalStar[]; //ai decision struct
// extern s32 D_800F8C70_EternalStar[]; //ai decision struct
// extern s32 D_800F8D60_EternalStar[]; //ai decision struct
extern s16 D_800ED172;
// extern s32 D_800F8BF0_EternalStar[];
// extern s16 D_800F8BC0_EternalStar[]; //more spaceIDs
// extern s16 D_800F8BD0_EternalStar[]; //spaceIDs
// extern s16 D_800F8BE0_EternalStar[];
extern Vec3f D_800F9180_EternalStar;
extern Vec3f D_800F918C_EternalStar;
extern Vec3f D_800F9198_EternalStar;
extern Vec3f D_800F91A4_EternalStar;
extern Vec3f D_800F91B0_EternalStar;
extern f32 D_800F91B4_EternalStar;
extern s16 D_800F8BF8_EternalStar[];
extern Object* D_800F91BC_EternalStar;
extern Object* D_800F91C0_EternalStar[];
// extern s16 D_800F8C08_EternalStar[];
// extern s16 D_800F8C34_EternalStar[];
extern Object* D_800F91DC_EternalStar;
extern Object* D_800F91E0_EternalStar[];
// extern s16 D_800F8C38_EternalStar[];
extern Object* D_800F91E4_EternalStar;
// extern s16 D_800EE320;
extern s32 D_800F91E8_EternalStar; /* label windows (func_80045D84): pointers on the host */
extern s32 D_800F91EC_EternalStar;
extern s32 D_800F91F0_EternalStar;
extern s32 D_800F91F4_EternalStar;
extern s16 D_800EE320;
// extern s32 D_800F91E8_EternalStar;
// extern s32 D_800F91EC_EternalStar;
// extern s32 D_800F91F0_EternalStar;
// extern s32 D_800F91F4_EternalStar;
// extern ProcessHeader D_800F8F68_EternalStar;
// extern ProcessHeader D_800F8F8C_EternalStar;
// extern ProcessHeader D_800F8FB0_EternalStar;
// extern ProcessHeader D_800F8FD4_EternalStar;
// extern ProcessHeader D_800F8FF8_EternalStar;
// //extern s32 D_800F8BB0_EternalStar;
// extern void (*D_800F8D6C_EternalStar[16])();

void func_800F6D30_EternalStar(void);
void InitBoard(void);
void func_800F6F68_EternalStar(void);
void func_800F7070_EternalStar(void);
void func_800F8B20_EternalStar(void);

Object* func_800F7D6C_EternalStar(s16);
void func_800F7E5C_EternalStar(Object*);
s32 func_800F775C_EternalStar(void);
s32 func_800F7794_EternalStar(void);
void func_800F7B30_EternalStar(s32, s32);
void func_800F6BD8_EternalStar(void);
void func_800F6E34_EternalStar(void);
s16 func_800F6610_EternalStar(void);
s16 func_800F67AC_EternalStar(s16);
void func_800F87E4_EternalStar(EventTableUnkStruct*);
void func_800F7C70_EternalStar(void);
void func_800F7D20_EternalStar(void);
void func_800F7F7C_EternalStar(void);
Object* func_800F7D6C_EternalStar(s16);
void func_800F7E5C_EternalStar(Object*);
void func_800F7E78_EternalStar(Object*);
void func_800F7EE0_EternalStar(Object*);
s32 func_800F7A60_EternalStar(void);
s32 func_800F7AE8_EternalStar(void);
s32 func_800F79BC_EternalStar(void);
s32 func_800F7A2C_EternalStar(void);
s32 func_800F78CC_EternalStar(void);
s32 func_800F7934_EternalStar(void);
s32 func_800F77CC_EternalStar(void);
s32 func_800F784C_EternalStar(void);
void func_800F7B30_EternalStar(s32, s32);
void func_800F7224_EternalStar(s16);
void func_800F709C_EternalStar(s16);
void func_800F6E34_EternalStar(void);
ProcessHeader* func_800F68E4_EternalStar(s32*);
void func_800F6AA0_EternalStar(ProcessHeader*);
void func_800F6B58_EternalStar(ProcessHeader*);
void func_800F667C_EternalStar(void);
void func_800F66C8_EternalStar(void);
void func_800F671C_EternalStar(void);
void func_800F719C_EternalStar(void);
void func_800F732C_EternalStar(void);
void func_800F74D4_EternalStar(void);
void func_800F667C_EternalStar(void);
void func_800F7F4C_EternalStar(void);
void func_800F6850_EternalStar(void);
void func_800F6850_EternalStar(void);
void func_800F68B8_EternalStar(void);
