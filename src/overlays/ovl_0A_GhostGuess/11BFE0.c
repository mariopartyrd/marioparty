#include "GhostGuess.h"

void func_800FB3B0_GhostGuess(void) {
    D_800FC32A_GhostGuess = 0;
    D_800FC328_GhostGuess = 0;
    CZoom = 300.0f;
    CRot.x = -10.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 100.0f;
    Center.z = 0.0f;
    D_800FC320_GhostGuess = 300.0f;
    D_800FC308_GhostGuess.x = -10.0f;
    D_800FC308_GhostGuess.y = 0.0f;
    D_800FC308_GhostGuess.z = 0.0f;
    D_800FC2F0_GhostGuess.x = D_800FC2F0_GhostGuess.z = CRot.y;
    D_800FC2F0_GhostGuess.y = 100.0f;
}
void func_800FB448_GhostGuess(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u16 arg7) {
    D_800FC324_GhostGuess = arg0;
    D_800FC2FC_GhostGuess.x = arg1;
    D_800FC2FC_GhostGuess.y = arg2;
    D_800FC2FC_GhostGuess.z = arg3;
    D_800FC314_GhostGuess.x = arg4;
    D_800FC314_GhostGuess.y = arg5;
    D_800FC314_GhostGuess.z = arg6;
    if (D_800FC328_GhostGuess == 0) {
        D_800FC32A_GhostGuess = arg7;
        D_800FC328_GhostGuess = arg7;
    }
}

void func_800FB4B0_GhostGuess(void) {
    D_800FC320_GhostGuess = D_800FC324_GhostGuess;
    D_800FC308_GhostGuess.x = D_800FC314_GhostGuess.x;
    D_800FC308_GhostGuess.y = D_800FC314_GhostGuess.y;
    D_800FC308_GhostGuess.z = D_800FC314_GhostGuess.z;
    D_800FC2F0_GhostGuess.x = D_800FC2FC_GhostGuess.x;
    D_800FC2F0_GhostGuess.y = D_800FC2FC_GhostGuess.y;
    D_800FC2F0_GhostGuess.z = D_800FC2FC_GhostGuess.z;
}

void func_800FB514_GhostGuess(void) {
    f32 t;

    if (D_800FC328_GhostGuess != 0) {
        if (--D_800FC328_GhostGuess == 0) {
            func_800FB4B0_GhostGuess();
        }
        t = (f32)((s16)D_800FC32A_GhostGuess - D_800FC328_GhostGuess) / (s16)D_800FC32A_GhostGuess;
        CZoom = D_800FC320_GhostGuess + (D_800FC324_GhostGuess - D_800FC320_GhostGuess) * t;
        CRot.x = D_800FC308_GhostGuess.x + (D_800FC314_GhostGuess.x - D_800FC308_GhostGuess.x) * t;
        CRot.y = D_800FC308_GhostGuess.y + (D_800FC314_GhostGuess.y - D_800FC308_GhostGuess.y) * t;
        CRot.z = D_800FC308_GhostGuess.z + (D_800FC314_GhostGuess.z - D_800FC308_GhostGuess.z) * t;
        Center.x = D_800FC2F0_GhostGuess.x + (D_800FC2FC_GhostGuess.x - D_800FC2F0_GhostGuess.x) * t;
        Center.y = D_800FC2F0_GhostGuess.y + (D_800FC2FC_GhostGuess.y - D_800FC2F0_GhostGuess.y) * t;
        Center.z = D_800FC2F0_GhostGuess.z + (D_800FC2FC_GhostGuess.z - D_800FC2F0_GhostGuess.z) * t;
    }
}