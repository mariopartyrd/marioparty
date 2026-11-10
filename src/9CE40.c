#include "common.h"

/* HuVecDotProduct */
f32 func_8009C240(f32 aX, f32 aY, f32 aZ, f32 bX, f32 bY, f32 bZ) {
    return (aX * bX) + (aY * bY) + (aZ * bZ);
}

// register allocation: retail copies each result through $f2 before storing (masked 18).
// Hudson's copy of guLookAtF: eye - at in single precision (the SDK uses at - eye and -1.0).
#ifdef NON_MATCHING
void HuGuLookAtF(Matrix4f matrix, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp) {
    f32 xLook;
    f32 yLook;
    f32 zLook;
    f32 xRight;
    f32 yRight;
    f32 zRight;
    f32 len;

    xLook = xEye - xAt;
    yLook = yEye - yAt;
    zLook = zEye - zAt;
    len = 1.0f / func_800B1750(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;
    matrix[0][2] = xLook;
    matrix[1][2] = yLook;
    matrix[2][2] = zLook;
    matrix[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);
    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0f / func_800B1750(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;
    matrix[0][0] = xRight;
    matrix[1][0] = yRight;
    matrix[2][0] = zRight;
    matrix[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);
    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0f / func_800B1750(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;
    matrix[0][1] = xUp;
    matrix[1][1] = yUp;
    matrix[2][1] = zUp;
    matrix[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);
    matrix[2][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[3][3] = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/9CE40", HuGuLookAtF);
#endif