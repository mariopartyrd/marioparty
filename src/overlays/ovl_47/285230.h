#include "common.h"

void func_800F6D1C_name_47(void);
void func_800F6E14_name_47(void);
void func_800F6924_name_47(void);
void func_800F6CBC_name_47(omObjData* obj);
void func_800F6DE8_name_47(void);
void func_800F6EB4_name_47(void);
void func_800F6C40_name_47(omObjData* obj);
s32 func_800F66D0_name_47(s32, u8*);
void func_80071788(s32, s16);
void func_8004DBD4(s32, s32);
extern Vec3f D_800F6EE4_name_47;
extern Vec3f D_800F6EF0_name_47;
extern Vec3f D_800F6EFC_name_47;
extern s32 D_800F6F08_name_47[]; /* MBModelCreate motion list: words */
extern Object* D_800F6F24_name_47;
extern Object* D_800F6F28_name_47;
/* the choice result as a word; retail also reads its low half (big-endian +2) as s16 */
extern s32 D_800F6EE0_name_47;
extern s16 D_800F6EE2_name_47;


/* Retail calls func_8006FCF0 unprototyped here: the window id and cursor are passed as s16 values
   promoted to int (sll/sra 16), not narrowed to the prototype's s8. The host calls it normally. */
#define func_8006FCF0_unproto(win, cur, arg) ((s32 (*)())func_8006FCF0)(win, cur, arg)
