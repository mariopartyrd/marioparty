#ifndef _FUNCTIONS_
#define _FUNCTIONS_

#include "types.h"
#include "common_structs.h"

void func_8001D934(s32, s32, f32*);
void func_80079078(s16);
void func_8005D718(s32);
s32 func_8005021C(f32); //getRandInRange
void func_800A0D00(void*, f32, f32, f32);
void func_80025CA8(s16, s32);
void func_80026040(s16);
void func_80039C48(s32*, s16*);
void func_80009340(Object*, s32, s32, s32, s32);
void func_8001E2F8(u8, u8);
void func_8001E360(u8, u8, u8, u8);
void func_80021240(s16);
void func_80025798(s16, f32, f32, f32);
void func_800257E4(s16, f32, f32, f32);
void func_80025830(s16, f32, f32, f32);
void func_80025EB4(s16, s32, s32);
void func_80009438(void);
void func_8000942C(void);
void func_8003E694(unk_Struct03*);
void* func_8003DBE0(u8, void*);
void func_8004CCD0(f32*, f32*, f32*);
s32 func_80052F04(u8);
void func_8004F284(void);
void func_8004F28C(s32, s16);
void func_800546B4(s32, u8);
void func_8005E3A8(void);
void func_800635B4(void);
void func_800568A4(void);
void ClearBoardFeatureFlag(s32 flag);
void SetBoardFeatureFlag(s32 flag);
void func_800567D4(void);
void func_8005E044(s32, s32, s32);
void func_8005E36C(s32, s32, s32, s32);
void ExecBoardScene( void(*function), s32);
void func_8006B870(void);
s32 func_8006B8A4(s32, s32, s32, s32, s32);
f64 fabs(f64 f);
u8 GetRandomByte(void);
void func_80017660(u8, f32, f32, f32, f32);
void func_800176C4(u8, f32, f32, f32, f32, f32, f32);
void func_800178A0(s32);
s16 func_800178E8(void);
void func_8001D494(s16, f32, f32, f32);
void func_8001DE70(s32);
void func_80023448(s32);
void func_800234B8(u8, u8, u8, u8);
void func_80023504(s32, f32, f32, f32);
void func_80029090(s32);
void func_8005CF30 (s32 maxObjects, s32 maxProcesses);
Object* func_8005D384(s32, s32, s32, s32, void*);
void func_8005D8B8(Object*, s32);
void func_80060088(void);
void func_800602AC(s32);
void func_8007B168(s32*, s32);
void func_80086F08(f32*, void*);
f32 func_800AEAC0(f32);
f32 func_800AEFD0(f32);
u32 func_8005EB1C(void);
s32 IsBoardFeatureFlagSet(s32);
s16 func_8000C544(void);
s32 func_80075FE0(void);
s32 func_80072718(void);
void func_80009730(void);
void func_800601D4(s32);
void func_800790C0(void);
void func_8005DFB8(s32);
void func_80060198(void);
void func_8008B6A0(s32);
void func_80060398(s32);
void func_800726AC(s32, s32);
void func_80075CCC(s32, ...);
s16 ReadImgPackand(s32);
void func_80025930(s16, s32, s32);
s32 func_80076174(void);
f32 func_800B0CD8(void);
void* ReadMainFS(s32);
void FreeMainFS(void*);
s16 LoadFormFile(s32, s32);
s16 func_800678A4(void*);
s16 func_80023FC8(s16);
void func_80049F0C(void);
void func_8004A140(void);
s32 func_80054654(void);
void func_80070ED4(void);
void func_8004F1D0(void);
void func_80049E70(Addr*);
void func_80049F4C(s32);
void func_8003DAA8(void);
void func_8004F140(s16);
void func_80049F0C(void);
void func_8004A140(void);
void func_800544E4(void);
void func_80054834(s32, s32);
void func_8005DC28(void*, s32, s32, s32);
void func_80060128(s32);
void func_8006CEA0(void);
void func_80072644(s32, s32);
void func_80066DC4(s16, s16, s16, s16);
void func_800671DC(s16, s16, s16);
void func_800672B0(s16, s16, s16);
void func_80067354(s16, s32, f32, f32);
void func_80060128(s32);
void func_80025C20(s16, s16, s32, s32, s32);
s16 func_80025E48(s16);
void func_8005D95C(Object*, f32, f32, f32);
void func_80009458(void);
void func_80009624(unkGlobalStruct_00*, s32);
void func_80017DB0(Object*);
void func_800184BC(Object*, s32);
void func_8006071C(s16);
void func_80008FB8(Object*, f32);
void func_80008FC4(Object*, f32);
u16 func_800174C0(s32, s32);
unkGlobalStruct_00* func_80023684(s32, s32);
void func_8009B770(unkGlobalStruct_00*, s32, s32);
void func_80009500(void);
void func_800090B8(u16);
f32 sqrtf(f32);
void* MallocPerm(s32 size);
s16 func_80060288(void);
void func_80018C90(u16);
u16 func_80019060(s16, s16, s16);
void func_80067480(s16, s32, s32); //could also be  void func_80067480(s16, s32, u16); (as required by functions in face lift)
void func_800672DC(s16, u16, u16, s32);
void func_800674BC(s16, s16, u16);
s16 func_80064EF4(s32, s32);
void func_80067208(s16, s32, s16, s32);
void func_80009000(Object*, s32, f32);

void FreePerm(void*);
s16 InitSprite(s32);
void func_8002578C(s32);
void func_8002890C(s32, s32, s32);
void func_8002ADF0(s32*, s32);
s16 func_80039084(void*);
void func_8005D98C(s32, s32);
Object** func_8005DB44(s32);
void func_80009468(void);

#endif