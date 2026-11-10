#define MB_1D3040 /* func_800FCAD4 reads its slot as u16 (callers pass an s16) */
#include "1CCCF0.h"

u32 D_800FD190_MarioBandstand = 0;

void func_800FC930_MarioBandstand(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
    D_800FD6C0_MarioBandstand = zoom;
}

/* Park-Miller minimal standard generator (Schrage's method), seeded from rand8 and the count. */
u32 func_800FC9D8_MarioBandstand(u32 seed) {
    u32 hi;
    u32 lo;

    if (seed == 0) {
        seed = rand8();
        seed ^= osGetCount();
        seed ^= 0xD826BC89;
    }
    hi = seed / 127773;
    lo = seed - hi * 127773;
    seed = hi * 2836;
    return seed - lo * 16807;
}

u32 func_800FCAAC_MarioBandstand(void) {
    return D_800FD190_MarioBandstand = func_800FC9D8_MarioBandstand(D_800FD190_MarioBandstand);
}

// NON_MATCHING: register allocation, arg2/arg3 in s3/s1 (raw 8, masked 4); tried u16 slot prototype, inlining model, s16 idx (M1c)
#ifdef NON_MATCHING
s16 func_800FCAD4_MarioBandstand(omObjData* obj, s32 file, s32 arg2, s32 arg3, u16 slot, s16 idx) {
    s16* cache = &D_800FD6E0_MarioBandstand[idx];
    void* data;
    s16 id;
    s16 model;

    if (*cache < 0) {
        data = DataRead(file);
        id = func_8001E00C(data, arg2 & 0xFFFF, arg3 & 0xFF);
        HuMemDirectFree(data);
        *cache = id;
    } else {
        id = func_8001E1D0(D_800FD6E0_MarioBandstand[idx], arg3 & 0xFF);
    }
    model = D_800ECDE0[id].unk_00;
    obj->model[(s16)slot] = model;
    func_80025930(model, 0x70000000, 0x70000000);
    return id;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1D3040", func_800FCAD4_MarioBandstand);
#endif
