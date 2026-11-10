#include "engine/process.h"
#include "dkJungleAdventure.h"

/* event-list functions (defined below) */
void func_800F7A1C_DKsJungleAdventure(void);
void func_800F7C34_DKsJungleAdventure(void);
void func_800F7C6C_DKsJungleAdventure(void);
void func_800F7E88_DKsJungleAdventure(void);
void func_800F7EC0_DKsJungleAdventure(void);
void func_800F80DC_DKsJungleAdventure(void);
void func_800F8248_DKsJungleAdventure(void);
void func_800F8A00_DKsJungleAdventure(void);
void func_800F8FC4_DKsJungleAdventure(void);
void func_800F91B4_DKsJungleAdventure(void);
void func_800F9398_DKsJungleAdventure(void);
void func_800F93BC_DKsJungleAdventure(void);
void func_800F93E0_DKsJungleAdventure(void);
void func_800F9404_DKsJungleAdventure(void);
void func_800F9428_DKsJungleAdventure(void);
void func_800F944C_DKsJungleAdventure(void);
void func_800F9674_DKsJungleAdventure(void);
void func_800F96A8_DKsJungleAdventure(void);
void func_800F970C_DKsJungleAdventure(void);
void func_800F9798_DKsJungleAdventure(void);
void func_800F9804_DKsJungleAdventure(void);

/* .data (0x800F98C0..0x800FA240) */
Vec4f D_800F98C0_DKsJungleAdventure = { 0.0f, 0.0f, 320.0f, 240.0f };
s16 D_800F98D0_DKsJungleAdventure[] = { 3, 5, 6, 0, 1, 2, 4, 0 };
s16 D_800F98E0_DKsJungleAdventure[] = { 0, 0, 0, 1, 1, 1, 3, 0 };
s16 D_800F98F0_DKsJungleAdventure[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0 };
s16 D_800F9900_DKsJungleAdventure[] = { 0x77, 0x80, 0x7F, 0x84, 0x83, 0x75, 0x76, 0 };
s16 D_800F9910_DKsJungleAdventure[] = { 0x61, 0x6E, 0x6D, 0x72, 0x71, 0x5F, 0x60, 0 };
s32 D_800F9920_DKsJungleAdventure[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
s16 D_800F9928_DKsJungleAdventure[] = { 0x61, 0x6E, 0x6D, 0x72, 0x71, 0x5F, 0x60, 0 };
s16 D_800F9938_DKsJungleAdventure[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0 };
/* splat's D_800F994A is the .two half of entry 0 onwards */
struct D_800F9948_tuple D_800F9948_DKsJungleAdventure[] = {
    { 6, 0 }, { 0, -3 }, { 0, -8 }, { -3, 0 }, { -2, 0 }, { -2, 0 }, { -3, 0 },
};
s16 D_800F9964_DKsJungleAdventure[] = { 0, 1, 2, 0 };
s16 D_800F996C_DKsJungleAdventure[] = { 0x68, 0x66, 0x67, 0 };
s16 D_800F9974_DKsJungleAdventure[] = { 0x65, 0x6C, 0x5E, 0 };
s16 D_800F997C_DKsJungleAdventure[] = { 0x74, 0x7E, 0x85, 0 };
s32 D_800F9984_DKsJungleAdventure[] = { 1, 0x68 }; /* MBModelCreate motion list: words */
s16 D_800F998C_DKsJungleAdventure[] = { 0x6F, 0x62 };
s16 D_800F9990_DKsJungleAdventure[] = { 0x64, 0x63 };
s16 D_800F9994_DKsJungleAdventure[] = { 0x7A, 0x7B };
DecisionTreeNonLeafNode D_800F9998_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x3F }, { 0x1503C } },
    { 0x0, { (void*)0x0 }, { 0x11E32 } },
};
DecisionTreeNonLeafNode D_800F99B0_DKsJungleAdventure[5] = {
    { 0x01000000, { (void*)0x28 }, { 0x16450 } },
    { 0x01000000, { (void*)0x1E }, { 0x15F46 } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9998_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x3F }, { 0x14632 } },
    { 0x0, { (void*)0x0 }, { 0x11E28 } },
};
DecisionTreeNonLeafNode D_800F99EC_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x1F }, { 0x1503C } },
    { 0x0, { (void*)0x0 }, { 0x12832 } },
};
DecisionTreeNonLeafNode D_800F9A04_DKsJungleAdventure[5] = {
    { 0x01000000, { (void*)0x28 }, { 0x1645A } },
    { 0x01000000, { (void*)0x1E }, { 0x15F50 } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F99EC_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x1F }, { 0x14632 } },
    { 0x0, { (void*)0x0 }, { 0x11E32 } },
};
DecisionTreeNonLeafNode D_800F9A40_DKsJungleAdventure[5] = {
    { 0x02000000, { (void*)0x1 }, { 0x6450 } },
    { 0x02000000, { (void*)0x2 }, { (u32)D_800F99B0_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F9A04_DKsJungleAdventure } },
    { 0x01000000, { (void*)0x14 }, { 0x15F46 } },
    { 0x0, { (void*)0x0 }, { 0x1503C } },
};
DecisionTreeNonLeafNode D_800F9A7C_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0xF }, { 0x5F50 } },
    { 0x0, { (void*)0x0 }, { 0x3C3C } },
};
DecisionTreeNonLeafNode D_800F9A94_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0xF }, { 0x4646 } },
    { 0x0, { (void*)0x0 }, { 0x1428 } },
};
DecisionTreeNonLeafNode D_800F9AAC_DKsJungleAdventure[4] = {
    { 0x02000000, { (void*)0x7E }, { 0x1645A } },
    { 0x01000000, { (void*)0x1E }, { 0x5F50 } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9A7C_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { (u32)D_800F9A94_DKsJungleAdventure } },
};
DecisionTreeNonLeafNode D_800F9ADC_DKsJungleAdventure[2] = {
    { 0x04000000, { (void*)0x10000 }, { (u32)D_800F9A40_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { (u32)D_800F9AAC_DKsJungleAdventure } },
};
DecisionTreeNonLeafNode D_800F9AF4_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x18 }, { 0x1141E } },
    { 0x0, { (void*)0x0 }, { 0x16450 } },
};
DecisionTreeNonLeafNode D_800F9B0C_DKsJungleAdventure[3] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F9AF4_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x7 }, { 0x15F50 } },
    { 0x0, { (void*)0x0 }, { 0x11E28 } },
};
DecisionTreeNonLeafNode D_800F9B30_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x118 }, { 0x13232 } },
    { 0x0, { (void*)0x0 }, { 0x10028 } },
};
DecisionTreeNonLeafNode D_800F9B48_DKsJungleAdventure[5] = {
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F9B0C_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x2 }, { 0x6450 } },
    { 0x02000000, { (void*)0x1 }, { (u32)D_800F9B30_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x200 }, { 0x1463C } },
    { 0x0, { (void*)0x0 }, { 0x10028 } },
};
DecisionTreeNonLeafNode D_800F9B84_DKsJungleAdventure[3] = {
    { 0x03000000, { (void*)0x7 }, { 0x16450 } },
    { 0x03000000, { (void*)0x7 }, { 0x11432 } },
    { 0x0, { (void*)0x0 }, { 0x16450 } },
};
DecisionTreeNonLeafNode D_800F9BA8_DKsJungleAdventure[4] = {
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9B84_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x7 }, { 0x16450 } },
    { 0x03000000, { (void*)0x7 }, { 0x11432 } },
    { 0x0, { (void*)0x0 }, { 0x12846 } },
};
DecisionTreeNonLeafNode D_800F9BD8_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0xF }, { 0x6446 } },
    { 0x0, { (void*)0x0 }, { 0x283C } },
};
DecisionTreeNonLeafNode D_800F9BF0_DKsJungleAdventure[4] = {
    { 0x01000000, { (void*)0x1E }, { 0x6450 } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9BD8_DKsJungleAdventure } },
    { 0x03000000, { (void*)0xF }, { 0x5A46 } },
    { 0x0, { (void*)0x0 }, { 0x1E32 } },
};
DecisionTreeNonLeafNode D_800F9C20_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x1FF }, { 0x514 } },
    { 0x0, { (void*)0x0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_800F9C38_DKsJungleAdventure[5] = {
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F9BA8_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x2 }, { (u32)D_800F9BF0_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x1 }, { (u32)D_800F9C20_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x118 }, { 0x5046 } },
    { 0x0, { (void*)0x0 }, { 0x514 } },
};
DecisionTreeNonLeafNode D_800F9C74_DKsJungleAdventure[2] = {
    { 0x04000000, { (void*)0x110000 }, { (u32)D_800F9B48_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { (u32)D_800F9C38_DKsJungleAdventure } },
};
DecisionTreeNonLeafNode D_800F9C8C_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x7F }, { 0x16450 } },
    { 0x0, { (void*)0x0 }, { 0x11E32 } },
};
DecisionTreeNonLeafNode D_800F9CA4_DKsJungleAdventure[4] = {
    { 0x01000000, { (void*)0x1E }, { 0x16450 } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9C8C_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x7F }, { 0x16450 } },
    { 0x0, { (void*)0x0 }, { 0x11428 } },
};
DecisionTreeNonLeafNode D_800F9CD4_DKsJungleAdventure[5] = {
    { 0x02000000, { (void*)0x20 }, { 0x5F50 } },
    { 0x02000000, { (void*)0x40 }, { (u32)D_800F9CA4_DKsJungleAdventure } },
    { 0x01000000, { (void*)0x37 }, { 0x1463C } },
    { 0x01000000, { (void*)0x1E }, { 0x13228 } },
    { 0x0, { (void*)0x0 }, { 0x1141E } },
};
DecisionTreeNonLeafNode D_800F9D10_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x3 }, { 0x6450 } },
    { 0x0, { (void*)0x0 }, { 0x1428 } },
};
DecisionTreeNonLeafNode D_800F9D28_DKsJungleAdventure[4] = {
    { 0x01000000, { (void*)0x1E }, { 0x6450 } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9D10_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x3 }, { 0x5F50 } },
    { 0x0, { (void*)0x0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_800F9D58_DKsJungleAdventure[3] = {
    { 0x02000000, { (void*)0x20 }, { (u32)D_800F9D28_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x40 }, { 0x15F50 } },
    { 0x0, { (void*)0x0 }, { 0x1428 } },
};
DecisionTreeNonLeafNode D_800F9D7C_DKsJungleAdventure[2] = {
    { 0x04000000, { (void*)0x200000 }, { (u32)D_800F9CD4_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { (u32)D_800F9D58_DKsJungleAdventure } },
};
DecisionTreeNonLeafNode D_800F9D94_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x4 }, { 0x2832 } },
    { 0x0, { (void*)0x0 }, { 0x5A46 } },
};
DecisionTreeNonLeafNode D_800F9DAC_DKsJungleAdventure[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x5032 } },
    { 0x05000000, { (void*)0x6 }, { 0x3232 } },
    { 0x0, { (void*)0x0 }, { 0x1E28 } },
};
DecisionTreeNonLeafNode D_800F9DD0_DKsJungleAdventure[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x1E28 } },
    { 0x05000000, { (void*)0x6 }, { 0x463C } },
    { 0x0, { (void*)0x0 }, { 0x5046 } },
};
DecisionTreeNonLeafNode D_800F9DF4_DKsJungleAdventure[5] = {
    { 0x03000000, { (void*)0x10 }, { (u32)D_800F9DAC_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x80 }, { (u32)D_800F9DD0_DKsJungleAdventure } },
    { 0x05000000, { (void*)0x1 }, { 0x1E28 } },
    { 0x05000000, { (void*)0x6 }, { 0x3C32 } },
    { 0x0, { (void*)0x0 }, { 0x5A46 } },
};
DecisionTreeNonLeafNode D_800F9E30_DKsJungleAdventure[3] = {
    { 0x02000000, { (void*)0x16 }, { (u32)D_800F9D94_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x68 }, { (u32)D_800F9DF4_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { 0x6450 } },
};
DecisionTreeNonLeafNode D_800F9E54_DKsJungleAdventure[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x3C32 } },
    { 0x05000000, { (void*)0x6 }, { 0x1428 } },
    { 0x0, { (void*)0x0 }, { 0x514 } },
};
DecisionTreeNonLeafNode D_800F9E78_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x30 }, { (u32)D_800F9E54_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { 0x6450 } },
};
DecisionTreeNonLeafNode D_800F9E90_DKsJungleAdventure[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x2832 } },
    { 0x05000000, { (void*)0x6 }, { 0x1428 } },
    { 0x0, { (void*)0x0 }, { 0x514 } },
};
DecisionTreeNonLeafNode D_800F9EB4_DKsJungleAdventure[6] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F9E78_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x4F }, { 0x5A46 } },
    { 0x03000000, { (void*)0x30 }, { (u32)D_800F9E90_DKsJungleAdventure } },
    { 0x05000000, { (void*)0x1 }, { 0x1E32 } },
    { 0x05000000, { (void*)0x6 }, { 0xA1E } },
    { 0x0, { (void*)0x0 }, { 0x14 } },
};
DecisionTreeNonLeafNode D_800F9EFC_DKsJungleAdventure[2] = {
    { 0x03000000, { (void*)0x3F0 }, { 0x1E32 } },
    { 0x0, { (void*)0x0 }, { 0x1428 } },
};
DecisionTreeNonLeafNode D_800F9F14_DKsJungleAdventure[3] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F9EFC_DKsJungleAdventure } },
    { 0x03000000, { (void*)0x3F0 }, { 0x1428 } },
    { 0x0, { (void*)0x0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_800F9F38_DKsJungleAdventure[3] = {
    { 0x02000000, { (void*)0x10 }, { (u32)D_800F9EB4_DKsJungleAdventure } },
    { 0x02000000, { (void*)0x7 }, { (u32)D_800F9F14_DKsJungleAdventure } },
    { 0x0, { (void*)0x0 }, { 0x14 } },
};
s16 D_800F9F5C_DKsJungleAdventure[] = { 0x48, 0x45, -1, 0x0 };
EventListEntry D_800F9F64_DKsJungleAdventure[] = {
    { 1, 2, func_800F7A1C_DKsJungleAdventure },
    { 2, 1, func_800F7C34_DKsJungleAdventure },
    { 0, 0, NULL },
};
s16 D_800F9F7C_DKsJungleAdventure[] = { 0x42, 0x38, -1, 0x0 };
EventListEntry D_800F9F84_DKsJungleAdventure[] = {
    { 1, 2, func_800F7C6C_DKsJungleAdventure },
    { 2, 1, func_800F7E88_DKsJungleAdventure },
    { 0, 0, NULL },
};
s16 D_800F9F9C_DKsJungleAdventure[] = { 0x1A, 0x25, -1, 0x0 };
EventListEntry D_800F9FA4_DKsJungleAdventure[] = {
    { 1, 2, func_800F7EC0_DKsJungleAdventure },
    { 2, 1, func_800F80DC_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800F9FBC_DKsJungleAdventure[] = {
    { 1, 2, func_800F8248_DKsJungleAdventure },
    { 0, 0, NULL },
};
/* boulder path, -1 terminated; splat's D_800F9FCE is element 1 */
s16 D_800F9FCC_DKsJungleAdventure[] = { 1, 2, 3, 4, 5, 6, 7, -1 };
EventListEntry D_800F9FDC_DKsJungleAdventure[] = {
    { 3, 2, func_800F8A00_DKsJungleAdventure },
    { 0, 0, NULL },
};
s16 D_800F9FEC_DKsJungleAdventure[] = { 0x4D, 0x57, -1, 0x0 };
EventListEntry D_800F9FF4_DKsJungleAdventure[] = {
    { 1, 2, func_800F8FC4_DKsJungleAdventure },
    { 0, 0, NULL },
};
s16 D_800FA004_DKsJungleAdventure[] = { 0x2A, 0x2E, -1, 0x0 };
EventListEntry D_800FA00C_DKsJungleAdventure[] = {
    { 1, 2, func_800F91B4_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA01C_DKsJungleAdventure[] = {
    { 1, 1, func_800F9398_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA02C_DKsJungleAdventure[] = {
    { 1, 1, func_800F93BC_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA03C_DKsJungleAdventure[] = {
    { 1, 1, func_800F93E0_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA04C_DKsJungleAdventure[] = {
    { 1, 1, func_800F9404_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA05C_DKsJungleAdventure[] = {
    { 1, 1, func_800F9428_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA06C_DKsJungleAdventure[] = {
    { 1, 1, func_800F944C_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA07C_DKsJungleAdventure[] = {
    { 1, 1, func_800F944C_DKsJungleAdventure },
    { 1, 2, func_800F9674_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA094_DKsJungleAdventure[] = {
    { 1, 1, func_800F96A8_DKsJungleAdventure },
    { 3, 1, func_800F970C_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA0AC_DKsJungleAdventure[] = {
    { 1, 1, func_800F9798_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventListEntry D_800FA0BC_DKsJungleAdventure[] = {
    { 1, 1, func_800F9804_DKsJungleAdventure },
    { 0, 0, NULL },
};
EventTableEntry D_800FA0CC_DKsJungleAdventure[] = {
    { 0x77, D_800FA094_DKsJungleAdventure },
    { 0x80, D_800FA094_DKsJungleAdventure },
    { 0x7F, D_800FA094_DKsJungleAdventure },
    { 0x84, D_800FA094_DKsJungleAdventure },
    { 0x83, D_800FA094_DKsJungleAdventure },
    { 0x75, D_800FA094_DKsJungleAdventure },
    { 0x76, D_800FA094_DKsJungleAdventure },
    { 0x74, D_800F9F64_DKsJungleAdventure },
    { 0x45, D_800F9FBC_DKsJungleAdventure },
    { 0x48, D_800F9FBC_DKsJungleAdventure },
    { 0x38, D_800F9FBC_DKsJungleAdventure },
    { 0x42, D_800F9FBC_DKsJungleAdventure },
    { 0x1A, D_800F9FBC_DKsJungleAdventure },
    { 0x25, D_800F9FBC_DKsJungleAdventure },
    { 0x7E, D_800F9F84_DKsJungleAdventure },
    { 0x85, D_800F9FA4_DKsJungleAdventure },
    { 0x7A, D_800F9FF4_DKsJungleAdventure },
    { 0x7B, D_800FA00C_DKsJungleAdventure },
    { 0x2F, D_800F9FDC_DKsJungleAdventure },
    { 0x33, D_800F9FDC_DKsJungleAdventure },
    { 0x35, D_800F9FDC_DKsJungleAdventure },
    { 0x22, D_800F9FDC_DKsJungleAdventure },
    { 0x21, D_800F9FDC_DKsJungleAdventure },
    { 0x59, D_800F9FDC_DKsJungleAdventure },
    { 0x16, D_800F9FDC_DKsJungleAdventure },
    { 0xD, D_800F9FDC_DKsJungleAdventure },
    { 0xC, D_800F9FDC_DKsJungleAdventure },
    { 0x79, D_800FA06C_DKsJungleAdventure },
    { 0x56, D_800FA02C_DKsJungleAdventure },
    { 0x5B, D_800FA01C_DKsJungleAdventure },
    { 0x34, D_800FA02C_DKsJungleAdventure },
    { 0x3A, D_800FA03C_DKsJungleAdventure },
    { 0x30, D_800FA03C_DKsJungleAdventure },
    { 0x9, D_800FA05C_DKsJungleAdventure },
    { 0x15, D_800FA05C_DKsJungleAdventure },
    { 0x54, D_800FA04C_DKsJungleAdventure },
    { 0x1C, D_800FA04C_DKsJungleAdventure },
    { -1, NULL },
};
EventTableEntry D_800FA1FC_DKsJungleAdventure[] = {
    { 0x79, D_800FA07C_DKsJungleAdventure },
    { -1, NULL },
};
EventTableEntry D_800FA20C_DKsJungleAdventure[] = {
    { 0x81, D_800FA0AC_DKsJungleAdventure },
    { 0xA, D_800FA0AC_DKsJungleAdventure },
    { -1, NULL },
};
EventTableEntry D_800FA224_DKsJungleAdventure[] = {
    { 0x82, D_800FA0BC_DKsJungleAdventure },
    { -1, NULL },
};


// bss
extern struct Object *D_800FA300_DKsJungleAdventure;
extern struct Object *D_800FA304_DKsJungleAdventure;
// struct mpSource_object *bss_toad_model;
// struct mpSource_object *bss_toad_instances[DK_STAR_COUNT];
// struct mpSource_object *bss_thwomp_model;
// struct mpSource_object *thwomp_instances[DK_THWOMP_COUNT];
// struct mpSource_object *boo_model;
// struct mpSource_object *boo_instances[DK_BOO_COUNT];
// struct mpSource_object *coin_gate_model;
// // Seems awkward this isn't an array like the others,
// // but memory alignment issues occur with an array.
// struct mpSource_object *coin_gate_right;
// struct mpSource_object *coin_gate_left;
// void *arrow_unk_1;
// void *arrow_unk_2;
// void *arrow_unk_3;
// void *arrow_unk_4;
// f32 ov054_unk_boulder_float_1;
// f32 ov054_unk_boulder_float_2;
// s16 boulder_active;
// struct mpSource_object *boulder_obj_model;

s16 func_800F6610_DKsJungleAdventure(void) {
    return D_800F9910_DKsJungleAdventure[GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex]];
}

void func_800F663C_DKsJungleAdventure(void) { //ov054_func_800F663C
    s32 s1;
    s32 rand1;
    s32 rand2;
    s32 swap1;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;
    for (s1 = 0; s1 < 30; s1++) {
        rand1 = rand8() % 7;
        rand2 = rand8() % 7;
        if (rand1 == rand2) {
            continue;
        }

        if (rand1 < D_800F98E0_DKsJungleAdventure[rand2]) {
            continue;
        }

        if (rand2 < D_800F98E0_DKsJungleAdventure[rand1]) {
            continue;
        }

        swap1 = D_800F98D0_DKsJungleAdventure[rand1];
        D_800F98D0_DKsJungleAdventure[rand1] = D_800F98D0_DKsJungleAdventure[rand2];
        D_800F98D0_DKsJungleAdventure[rand2] = swap1;

        swap1 = D_800F98E0_DKsJungleAdventure[rand1];
        D_800F98E0_DKsJungleAdventure[rand1] = D_800F98E0_DKsJungleAdventure[rand2];
        D_800F98E0_DKsJungleAdventure[rand2] = swap1;
    }

    for (s1 = 0; s1 < DK_STAR_COUNT; s1++) {
        ed5c0->starSpaces[s1] = D_800F98D0_DKsJungleAdventure[s1];
    }
}

void func_800F67A4_DKsJungleAdventure(void) {
    s32 starSpaceTemp;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;

    if (++ed5c0->chosenStarSpaceIndex < DK_STAR_COUNT) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[6];
    ed5c0->chosenStarSpaceIndex = 0;

    SetBoardFeatureFlag(0x44);
    func_800F663C_DKsJungleAdventure();

    if (starSpaceTemp != ed5c0->starSpaces[0]) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[0];
    ed5c0->starSpaces[0] = ed5c0->starSpaces[6];
    ed5c0->starSpaces[6] = starSpaceTemp;
}

void func_800F6830_DKsJungleAdventure(void) { //ov054_func_800F6830
    s32 s0, s1;
    GW_SYSTEM* ed5c0 = &GwSystem;

    for (s1 = 0; s1 < DK_STAR_COUNT; s1++) {
        BoardSpaceTypeSet(D_800F9900_DKsJungleAdventure[s1], 1);
        SetBoardFeatureFlag(D_800F98F0_DKsJungleAdventure[s1]);
    }

    if (_CheckFlag(0x44)) {
        s0 = DK_STAR_COUNT;
    } else {
        s0 = ed5c0->chosenStarSpaceIndex;
    }

    for (s1 = 0; s1 < s0; s1++) {
        BoardSpaceTypeSet(D_800F9900_DKsJungleAdventure[ed5c0->starSpaces[s1]], 6);
    }

    BoardSpaceTypeSet(D_800F9900_DKsJungleAdventure[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]], 5);

    ClearBoardFeatureFlag(D_800F98F0_DKsJungleAdventure[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
}

s16 func_800F6958_DKsJungleAdventure(s32 current_space_index) {
    s32 i;
    s32 j;
    s16* ov054_star_space_indicesptr;
    GW_SYSTEM* ed5c0 = &GwSystem;

    i = 0;

    ov054_star_space_indicesptr = D_800F9900_DKsJungleAdventure;

    // This feels a bit odd, but the match was difficult.
    current_space_index = (s16)current_space_index;

    for (; i < DK_STAR_COUNT; i++) {
        if (current_space_index == ov054_star_space_indicesptr[i]) {
            if (i == ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]) {
                ed5c0->unk_1A = D_800F98F0_DKsJungleAdventure[i];
                return 1;
            }

            if (_CheckFlag(68)) {
                current_space_index = DK_STAR_COUNT;
            }
            else {
                current_space_index = ed5c0->chosenStarSpaceIndex;
            }

            for (j = 0; j < current_space_index; j++) {
                if (i == ed5c0->starSpaces[j]) {
                  return 2;
                }
            }

            return 0;
        }        
    }
    return 0;
}

void func_800F6A38_DKsJungleAdventure(void) {
    BoardSpace* space_data;
    Object* ptr;
    void *ret;
    s32 s0;
    f32 ftemp;
    f32 ftt;
    f32 const20;

    space_data = (HuPrcCurrentGet())->user_data;

    PlaySound(109);
    ptr = MBModelCreate(64, NULL);
    ptr->unk_0A |= 4;
    func_8004CDCC(ptr);
    func_800A0D50(&ptr->coords, &space_data->coords);

    ptr->unk_30 = 500.0f;

    ret = func_80042728(ptr, 0);

    ftemp = 0.0f;
    for (s0 = 0; s0 < 6; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp += 0.4f;
        HuPrcVSleep();
    }

    for (s0 = 0; s0 < 3; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp -= 0.4f;
        HuPrcVSleep();
    }

    HuPrcSleep(30);
    PlaySound(68);

    ftt = 0.0f;
    const20 = 20.0f;
    while (TRUE) {
        func_800A40D0(D_800F2B7C[*ptr->unk_3C->unk_40].unk7C, ftt); /* the typed field: a raw 0x7C view is wrong on the host */
        ftemp -= 0.02f;

        ftt += const20;
        if (ftemp < 0) {
            break;
        }

        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ptr->unk_30 -= 6.0f;
        HuPrcVSleep();
    }

    func_800427D4(ret);
    HuPrcSleep(30);
    MBModelKill(ptr);
    EndProcess(NULL);
}

void func_800F6C48_DKsJungleAdventure(mystery_struct_ret_func_80048224* a0) { //ov054_ShowNextStarSpotInner
    Object* unk0ptr;

    unk0ptr = a0->unk0;
    unk0ptr->unk_34 = 20.0f;
    unk0ptr->unk_38 = -3.0f;

    MBMotionSet(a0->unk0, 0, 0);
    HuPrcSleep(3);

    while (MBMotionCheck(a0->unk0) == 0) {
        HuPrcVSleep();
    }

    MBMotionSet(a0->unk0, -1, 2);
}

void func_800F6CD8_DKsJungleAdventure(void) {
    GW_SYSTEM* ed5c0;
    mystery_struct_ret_func_80048224 *str;
    BoardSpace* spacedata;
    Process* proc_struct;
    s32 string_id;

    ed5c0 = &GwSystem;

    func_80060128(43);
    str = func_80048224(D_800F9920_DKsJungleAdventure);
    SetFadeInTypeAndTime(2, 16);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }

    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6C48_DKsJungleAdventure(str);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1256;
    } else {
        string_id = 1258;
    }

    LoadStringIntoWindow(str->unk8, (void*)(s32)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(1125);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);

    spacedata = BoardSpaceGet(D_800F9910_DKsJungleAdventure[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
    func_8004B5DC(&spacedata->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);

    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }

    HuPrcSleep(5);

    proc_struct = omAddPrcObj(&func_800F6A38_DKsJungleAdventure, 18432, 0, 0);
    proc_struct->user_data = spacedata;

    HuPrcSleep(30);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1257;
    } else {
        string_id = 1259;
    }

    LoadStringIntoWindow(str->unk8, (void*)(s32)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_800601D4(90);
    HuPrcSleep(30);
    func_800726AC(2, 16);
    HuPrcSleep(17);
    func_8004847C(str);
    func_80056AF4();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_800F6F0C_DKsJungleAdventure(void) {  //ov054_Entrypoint0
    GW_SYSTEM* gameStatus = &GwSystem;

    gameStatus->curBoardIndex = 0;
    omInitObjMan(10, 0); // InitObjectSystem
    omOvlGotoEx(53, 0, 146);
}

void func_800F6F44_DKsJungleAdventure(void) { //ov054_Entrypoint1
    GW_SYSTEM* ed5c0;
    ed5c0 = &GwSystem;

    omInitObjMan(10, 0); // InitObjectSystem

    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);

    switch (ed5c0->unk_00) {
        case 0:
            SetBoardFeatureFlag(0x46);
            SetBoardFeatureFlag(0x47);
            SetBoardFeatureFlag(0x49);
            SetBoardFeatureFlag(0x4B);
            break;

        case 1:
            SetBoardFeatureFlag(0x47);
            SetBoardFeatureFlag(0x49);
            break;
    }

    SetBoardFeatureFlag(0x43);

    func_800F663C_DKsJungleAdventure();

    GwCommon.boardWork[0] = 0;
    GwCommon.boardWork[1] = 0;
    GwCommon.boardWork[2] = 0;

    omOvlReturnEx(1);
}

void func_800F7024_DKsJungleAdventure(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0, 0x45, 4, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }

    if (_CheckFlag(0x4E) != 0) {
        ClearBoardFeatureFlag(0x4E);
        func_800F67A4_DKsJungleAdventure();
    }

    func_800F6830_DKsJungleAdventure();
    func_800F748C_DKsJungleAdventure();
    func_800F766C_DKsJungleAdventure();
    func_800F78DC_DKsJungleAdventure();

    if (_CheckFlag(0xE) == 0) {
        func_800F7368_DKsJungleAdventure();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F77B8_DKsJungleAdventure();
    }
    if (_CheckFlag(0xD) == 0) {
        func_800F72CC_DKsJungleAdventure();
    }
}

void func_800F7190_DKsJungleAdventure(void) {
    func_80060128(8);
    InitCameras(2);
    func_800F7024_DKsJungleAdventure();
    EventTableHydrate(D_800FA0CC_DKsJungleAdventure);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800FA1FC_DKsJungleAdventure);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800FA20C_DKsJungleAdventure);
    }
    if (_CheckFlag(0xD) == 0) {
        EventTableHydrate(D_800FA224_DKsJungleAdventure);
    }
    func_800584F0(0);
}

void func_800F7224_DKsJungleAdventure(void) { //ov054_Entrypoint3
    InitCameras(1);
    func_800F7024_DKsJungleAdventure();
    func_800584F0(1);
}

void func_800F7250_DKsJungleAdventure(void) { //ov054_DrawBowserInner
    Object *ptr;

    if (D_800FA300_DKsJungleAdventure != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3B, NULL);
    func_8003E174(ptr);
    D_800FA300_DKsJungleAdventure = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x70)->coords);
    func_8003C314(7, ptr, -2, 0);
}

void func_800F72CC_DKsJungleAdventure(void) { //ov054_DrawBowserOuter
    D_800FA300_DKsJungleAdventure = 0;
    func_800F7250_DKsJungleAdventure();
}

void func_800F72EC_DKsJungleAdventure(void) { //ov054_DrawKoopaInner
    Object *ptr;

    if (D_800FA304_DKsJungleAdventure != NULL) {
        return;
    }

    ptr = MBModelCreate(0x39, NULL);
    func_8003E174(ptr);
    D_800FA304_DKsJungleAdventure = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x5D)->coords);
    func_8003C314(9, ptr, -1, -3);
}

void func_800F7368_DKsJungleAdventure(void) {
    D_800FA304_DKsJungleAdventure = NULL;
    func_800F72EC_DKsJungleAdventure();
}
void func_800F7388_DKsJungleAdventure(s16 arg0) {
    Object* obj;

    if (D_800FA310_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA308_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0x3A, NULL);
            func_8003E174(obj);
            D_800FA308_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA308_DKsJungleAdventure);
        }
        D_800FA310_DKsJungleAdventure[arg0] = obj;
        obj->unk_0A |= 2;
        func_8004CDCC(obj);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9928_DKsJungleAdventure[arg0])->coords);
        func_8003C314(6, obj, D_800F9948_DKsJungleAdventure[arg0].one, D_800F9948_DKsJungleAdventure[arg0].two);
    }
}
void func_800F748C_DKsJungleAdventure(void) {
    s32 i;

    D_800FA308_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_STAR_COUNT; i++) {
        D_800FA310_DKsJungleAdventure[i] = NULL;
        if (_CheckFlag(D_800F9938_DKsJungleAdventure[i]) == 0) {
            func_800F7388_DKsJungleAdventure(i);
        }
    }
}
void func_800F7514_DKsJungleAdventure(s16 arg0) {
    Object* obj;
    BoardSpace* space;
    Vec3f* pos;

    if (D_800FA330_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA32C_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0xA, D_800F9984_DKsJungleAdventure);
            func_8003E174(obj);
            D_800FA32C_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA32C_DKsJungleAdventure);
        }
        D_800FA330_DKsJungleAdventure[arg0] = obj;
        func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
        obj->unk_0A |= 2;
        if (GwCommon.boardWork[D_800F9964_DKsJungleAdventure[arg0]] == 0) {
            space = BoardSpaceGet(D_800F996C_DKsJungleAdventure[arg0]);
        } else {
            space = BoardSpaceGet(D_800F9974_DKsJungleAdventure[arg0]);
        }
        pos = &obj->coords;
        func_800A0D50(pos, &space->coords);
        func_800A0E80(&obj->unk_18, &BoardSpaceGet(D_800F997C_DKsJungleAdventure[arg0])->coords, pos);
    }
}
void func_800F766C_DKsJungleAdventure(void) {
    s32 i;

    D_800FA32C_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_THWOMP_COUNT; i++) {
        func_800F7514_DKsJungleAdventure(i);
    }
}
void func_800F76B0_DKsJungleAdventure(s16 arg0) {
    Object* obj;

    if (D_800FA340_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA33C_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0x6A, NULL);
            func_8003E174(obj);
            D_800FA33C_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA33C_DKsJungleAdventure);
        }
        D_800FA340_DKsJungleAdventure[arg0] = obj;
        obj->unk_0A |= 2;
        func_800A0D00(&obj->xScale, 0.6f, 0.6f, 0.6f);
        obj->unk_30 = 100.0f;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F998C_DKsJungleAdventure[arg0])->coords);
        func_8003C314(8, obj, 0, 0);
    }
}
void func_800F77B8_DKsJungleAdventure(void) {
    s32 i;

    D_800FA33C_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_BOO_COUNT; i++) {
        func_800F76B0_DKsJungleAdventure(i);
    }
}
void func_800F77FC_DKsJungleAdventure(s16 arg0) {
    Object* obj;

    if (D_800FA34C_DKsJungleAdventure[arg0] == NULL) {
        if (D_800FA348_DKsJungleAdventure == NULL) {
            obj = MBModelCreate(0x29, NULL);
            func_8003E174(obj);
            D_800FA348_DKsJungleAdventure = obj;
        } else {
            obj = MBModelParamCreate(D_800FA348_DKsJungleAdventure);
        }
        obj->unk_0A |= 2;
        D_800FA34C_DKsJungleAdventure[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9990_DKsJungleAdventure[arg0])->coords);
        func_8004CD48(obj, D_800F9994_DKsJungleAdventure[arg0]);
    }
}
void func_800F78DC_DKsJungleAdventure(void) {
    s32 i;

    D_800FA348_DKsJungleAdventure = NULL;
    for (i = 0; i < DK_COIN_GATE_COUNT; i++) {
        func_800F77FC_DKsJungleAdventure(i);
    }
}
void func_800F7920_DKsJungleAdventure(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800FA354_DKsJungleAdventure = func_80045D84(0, 0x92, 1);
    D_800FA358_DKsJungleAdventure = func_80045D84(1, 0xA0, 1);
    D_800FA35C_DKsJungleAdventure = func_80045D84(3, 0xAE, 1);
    D_800FA360_DKsJungleAdventure = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}
void func_800F79D0_DKsJungleAdventure(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800FA354_DKsJungleAdventure);
    func_80045E6C(D_800FA358_DKsJungleAdventure);
    func_80045E6C(D_800FA35C_DKsJungleAdventure);
    func_80045E6C(D_800FA360_DKsJungleAdventure);
}
void func_800F7A1C_DKsJungleAdventure(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    if (PlayerHasCoins(-1, 10) != 0) {
        func_800F7920_DKsJungleAdventure();
        prompt = func_8003C218(-1, D_800F9F5C_DKsJungleAdventure);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(D_800F9ADC_DKsJungleAdventure);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F79D0_DKsJungleAdventure();
        if ((GwCommon.boardWork[0] == 0) & (dir != 0)) {
            SetNextChainAndSpace(-1, 3, 0);
        } else if ((GwCommon.boardWork[0] != 0) & (dir == 0)) {
            SetNextChainAndSpace(-1, 1, 0);
        } else {
            GwCommon.boardWork[15] = 0;
            func_800587EC(0x47, 0, 1);
            SetEventReturnFlag(1);
        }
    } else {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x32, 0x3C, 0xC, 2);
        LoadStringIntoWindow(win, (void*)0x18B, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x8F);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        if (GwCommon.boardWork[0] == 0) {
            SetNextChainAndSpace(-1, 3, 0);
        } else {
            SetNextChainAndSpace(-1, 1, 0);
        }
    }
    EndProcess(NULL);
}

void func_800F7C34_DKsJungleAdventure(void) {
    if (GwCommon.boardWork[0] != 0) {
        SetNextChainAndSpace(-1, 1, 0);
    } else {
        SetNextChainAndSpace(-1, 3, 0);
    }
}

void func_800F7C6C_DKsJungleAdventure(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    if (PlayerHasCoins(-1, 10) != 0) {
        func_800F7920_DKsJungleAdventure();
        prompt = func_8003C218(-1, D_800F9F7C_DKsJungleAdventure);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(D_800F9C74_DKsJungleAdventure);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F79D0_DKsJungleAdventure();
        if ((GwCommon.boardWork[1] == 0) & (dir != 0)) {
            SetNextChainAndSpace(-1, 15, 0);
        } else if ((GwCommon.boardWork[1] != 0) & (dir == 0)) {
            SetNextChainAndSpace(-1, 14, 0);
        } else {
            GwCommon.boardWork[15] = 1;
            func_800587EC(0x47, 0, 1);
            SetEventReturnFlag(1);
        }
    } else {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x32, 0x3C, 0xC, 2);
        LoadStringIntoWindow(win, (void*)0x18B, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x8F);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        if (GwCommon.boardWork[1] == 0) {
            SetNextChainAndSpace(-1, 15, 0);
        } else {
            SetNextChainAndSpace(-1, 14, 0);
        }
    }
    EndProcess(NULL);
}
void func_800F7E88_DKsJungleAdventure(void) {
    if (GwCommon.boardWork[1] != 0) {
        SetNextChainAndSpace(-1, 14, 0);
    } else {
        SetNextChainAndSpace(-1, 15, 0);
    }
}
void func_800F7EC0_DKsJungleAdventure(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    if (PlayerHasCoins(-1, 10) != 0) {
        func_800F7920_DKsJungleAdventure();
        prompt = func_8003C218(-1, D_800F9F9C_DKsJungleAdventure);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(D_800F9D7C_DKsJungleAdventure);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F79D0_DKsJungleAdventure();
        if ((GwCommon.boardWork[2] == 0) & (dir == 0)) {
            SetNextChainAndSpace(-1, 6, 0);
        } else if ((GwCommon.boardWork[2] != 0) & (dir != 0)) {
            SetNextChainAndSpace(-1, 5, 0);
        } else {
            GwCommon.boardWork[15] = 2;
            func_800587EC(0x47, 0, 1);
            SetEventReturnFlag(1);
        }
    } else {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x32, 0x3C, 0xC, 2);
        LoadStringIntoWindow(win, (void*)0x18B, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x8F);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        if (GwCommon.boardWork[2] == 0) {
            SetNextChainAndSpace(-1, 6, 0);
        } else {
            SetNextChainAndSpace(-1, 5, 0);
        }
    }
    EndProcess(NULL);
}
void func_800F80DC_DKsJungleAdventure(void) {
    if (GwCommon.boardWork[2] != 0) {
        SetNextChainAndSpace(-1, 5, 0);
    } else {
        SetNextChainAndSpace(-1, 6, 0);
    }
}
void func_800F8114_DKsJungleAdventure(void) {
    Vec3f sp10;
    Process* proc;
    DKThwompMove* work;
    Object* obj;
    BoardSpace* dest;
    Vec3f* destPos;
    Vec3f* pos;
    Vec3f* rot;

    proc = HuPrcCurrentGet();
    work = proc->user_data;
    obj = work->obj;
    dest = work->dest;
    MBMotionSet(obj, 0, 2);
    destPos = &dest->coords;
    pos = &obj->coords;
    func_800A0E80(&sp10, destPos, pos);
    rot = &obj->unk_18;
    HuPrcChildLink(proc, func_8004D1EC(rot, &sp10, rot, 10));
    HuPrcChildWatch();
    func_800A0D50(&sp10, pos);
    HuPrcChildLink(proc, func_8004D3F4(&sp10, destPos, pos, 25));
    HuPrcChildWatch();
    dest = work->facing;
    func_800A0E80(&sp10, &dest->coords, pos);
    HuPrcChildLink(proc, func_8004D1EC(rot, &sp10, rot, 10));
    HuPrcChildWatch();
    MBMotionSet(obj, -1, 2);
    EndProcess(NULL);
}

// decomp-permuter
void func_800F8248_DKsJungleAdventure(void)
{
  Process *proc;
  DKThwompMove *work;
  s16 space;
  s32 dest;
  s32 idx;
  s16 cur;
  cur = GetCurrentSpaceIndex();
  space = -1;
  idx = 0;
  switch (cur)
  {
    case 0x45:
      space = 0x65;
      GwCommon.boardWork[0] = 1;
      idx = 0;
      break;

    case 0x48:
      space = 0x68;
      GwCommon.boardWork[0] = 0;
      idx = 0;
      break;

    case 0x38:
      idx = 1;
      GwCommon.boardWork[1] = idx;
      space = 0x6C;
      break;

    case 0x42:
      space = 0x66;
      GwCommon.boardWork[1] = 0;
      idx = 1;
      break;

    case 0x1A:
      space = 0x5E;
      GwCommon.boardWork[2] = 1;
      idx = 2;
      break;

    case 0x25:
      space = 0x67;
      idx = 2;
      GwCommon.boardWork[2] = 0;
      break;

  }

  dest = space;
  if (dest != 0)
  {
    proc = omAddPrcObj(func_800F8114_DKsJungleAdventure, 0x4800, 0, 0x40);
    space = idx;
    work = HuMemMemoryAlloc(proc->heap, sizeof(DKThwompMove));
    proc->user_data = work;
    work->obj = D_800FA330_DKsJungleAdventure[space];
    work->dest = BoardSpaceGet(dest);
    work->facing = BoardSpaceGet(D_800F997C_DKsJungleAdventure[space]);
  }
  EndProcess(0);
}

void func_800F83B0_DKsJungleAdventure(void) {
    if (_CheckFlag(0xD) == 0) {
        func_800A0D50(&D_800FA300_DKsJungleAdventure->coords, &BoardSpaceGet(0x6A)->coords);
    }
    if (_CheckFlag(0x48) == 0) {
        func_800A0D50(&D_800FA310_DKsJungleAdventure[2]->coords, &BoardSpaceGet(0x69)->coords);
    }
    if (_CheckFlag(0x4A) == 0) {
        func_800A0D50(&D_800FA310_DKsJungleAdventure[4]->coords, &BoardSpaceGet(0x6B)->coords);
    }
}
void func_800F8448_DKsJungleAdventure(void) {
    if (_CheckFlag(0xD) == 0) {
        func_800A0D50(&D_800FA300_DKsJungleAdventure->coords, &BoardSpaceGet(0x70)->coords);
    }
    if (_CheckFlag(0x48) == 0) {
        func_800A0D50(&D_800FA310_DKsJungleAdventure[2]->coords, &BoardSpaceGet(0x6D)->coords);
    }
    if (_CheckFlag(0x4A) == 0) {
        func_800A0D50(&D_800FA310_DKsJungleAdventure[4]->coords, &BoardSpaceGet(0x71)->coords);
    }
}
void func_800F84E0_DKsJungleAdventure(void) {
    func_800726AC(4, 16);
    HuPrcSleep(16);
    func_800F83B0_DKsJungleAdventure();
    func_8004A7DC();
    func_8004A7A4();
    D_800FA364_DKsJungleAdventure = func_8004B844();
    func_8004B838(-1.0f);
    D_800FA368_DKsJungleAdventure = func_8004B5D0();
    func_8004B5C4(1.0f);
    func_8004A510();
    func_8004B5DC(&BoardSpaceGet(0)->coords);
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(D_800FA368_DKsJungleAdventure);
    func_8004B838(D_800FA364_DKsJungleAdventure);
    func_800421E0();
    SetFadeInTypeAndTime(4, 16);
    HuPrcSleep(16);
}
void func_800F85BC_DKsJungleAdventure(void) {
    func_800726AC(4, 16);
    HuPrcSleep(16);
    func_800F8448_DKsJungleAdventure();
    func_8004A7DC();
    func_8004A7A4();
    D_800FA364_DKsJungleAdventure = func_8004B844();
    func_8004B838(-1.0f);
    D_800FA368_DKsJungleAdventure = func_8004B5D0();
    func_8004B5C4(1.0f);
    func_8004A510();
    func_8004B5DC(&GetPlayerStruct(-1)->player_obj->coords);
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(D_800FA368_DKsJungleAdventure);
    func_8004B838(D_800FA364_DKsJungleAdventure);
    func_8004220C();
    SetFadeInTypeAndTime(4, 16);
    HuPrcSleep(16);
}
void func_800F869C_DKsJungleAdventure(void) {
    Vec3f sp10;
    void* rumble;
    Process* proc;
    GW_PLAYER* player;
    Object* obj;
    Object* boulder;
    s16 space;
    s16 remaining;

    space = 0;
    player = HuPrcCurrentGet()->user_data;
    obj = player->player_obj;
    boulder = D_800FA370_DKsJungleAdventure;
    proc = HuPrcCurrentGet();
    rumble = func_80058A4C(player->player_index, 0, 10);
    while (!(func_800A13C0(&BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space))->coords,
                           &boulder->coords) < 310.0f)) {
        func_8004CCD0(&obj->coords, &boulder->coords, &obj->unk_18);
        HuPrcVSleep();
    }
    func_80060618(0x45F, player->player_index);
    remaining = BoardGetChainLength(player->cur_chain) - player->cur_space;
    SetPlayerAnimation(player->player_index, 1, 2);
    for (; remaining > 0; remaining--) {
        if (remaining == 1) {
            SetNextChainAndSpace(player->player_index, 9, 1);
        }
        if (space == 0x7C) {
            obj->unk_34 = 40.0f;
            obj->unk_38 = -5.0f;
            SetPlayerAnimation(player->player_index, 2, 0);
        }
        if (space == 0x24) {
            SetPlayerAnimation(player->player_index, -1, 2);
            func_800A0E80(&sp10, &boulder->coords, &obj->coords);
            func_8004D1EC(&obj->unk_18, &sp10, &obj->unk_18, 8);
            HuPrcSleep(30);
            SetPlayerAnimation(player->player_index, 1, 2);
        }
        if (((BoardPlayerObj*)player->player_obj)->unk_38 == 0.0f && ((BoardPlayerObj*)player->player_obj)->unk_46 != 1) {
            SetPlayerAnimation(player->player_index, 1, 2);
        }
        space = GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain, player->next_space);
        func_8004CB70(player->player_index, space, &sp10);
        func_8004CCD0(&obj->coords, &sp10, &obj->unk_18);
        HuPrcChildLink(proc, func_8004D648(&obj->coords, &sp10, &obj->coords, 20.0f));
        HuPrcChildWatch();
        SetPlayerOntoChain(player->player_index, player->next_chain, player->next_space);
    }
    SetPlayerAnimation(player->player_index, -1, 2);
    func_80058AD0(rumble);
    EndProcess(NULL);
}
void func_800F8978_DKsJungleAdventure(void) {
    s16 saved;

    saved = func_80056E3C();
    func_80056E30(0);
    func_800F84E0_DKsJungleAdventure();
    while (D_800FA370_DKsJungleAdventure != NULL) {
        func_8004B5DC(&D_800FA370_DKsJungleAdventure->coords);
        HuPrcVSleep();
    }
    func_800F85BC_DKsJungleAdventure();
    func_80056E30(saved);
    EndProcess(NULL);
}
void func_800F8A00_DKsJungleAdventure(void) {
    Vec3f sp10;
    Process* proc;
    GW_PLAYER* player;
    Object* obj;
    Vec3f* target;
    s16 win;
    s16 chainSpace;
    s32 i;
    s32 count;
    s32 sfx;

    i = 0;
    proc = HuPrcCurrentGet();
    count = 0;
    for (; i < 4; i++) {
        player = GetPlayerStruct(i);
        chainSpace = GetChainSpaceIndexFromAbsSpaceIndex(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space), 17);
        if (chainSpace >= 0) {
            player->cur_chain = 17;
            player->cur_space = chainSpace;
            player->next_chain = 17;
            player->next_space = chainSpace + 1;
            omAddPrcObj(func_800F869C_DKsJungleAdventure, 0x4800, 0, 0)->user_data = player;
            count++;
        }
    }
    if (count == 0) {
        obj = GetPlayerStruct(-1)->player_obj;
        func_8004CD84(&sp10);
        func_8003D514(&sp10, 0.0f);
        HuPrcChildLink(proc, func_8004D1EC(&obj->unk_18, &sp10, &obj->unk_18, 6));
        HuPrcChildWatch();
        win = CreateTextWindow(0x4B, 0x40, 0xE, 1);
        LoadStringIntoWindow(win, (void*)0x194, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        EndProcess(NULL);
    }
    D_800FA36C_DKsJungleAdventure = 0;
    D_800FA370_DKsJungleAdventure = NULL;
    omAddPrcObj(func_800F8978_DKsJungleAdventure, 0x1003, 0, 0);
    obj = MBModelCreate(0x26, NULL);
    D_800FA370_DKsJungleAdventure = obj;
    func_800A0D50(&obj->coords, &BoardSpaceGet(0)->coords);
    func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
    HuPrcSleep(30);
    sfx = PlaySound(0x8B);
    for (i = 0; D_800F9FCC_DKsJungleAdventure[i] >= 0; i++) {
        target = &BoardSpaceGet(D_800F9FCC_DKsJungleAdventure[i])->coords;
        func_8004CCD0(&obj->coords, target, &obj->unk_18);
        HuPrcChildLink(proc, func_8004D648(&obj->coords, target, &obj->coords, 20.0f));
        HuPrcChildWatch();
        if (D_800F9FCC_DKsJungleAdventure[i] == 6) {
            func_800A0E80(&sp10, &BoardSpaceGet(D_800F9FCC_DKsJungleAdventure[i + 1])->coords, &obj->coords);
            func_8004D1EC(&obj->unk_18, &sp10, &obj->unk_18, 20);
            obj->unk_34 = 38.0f;
            obj->unk_38 = -2.0f;
            PlaySound(0x8D);
            func_80060758(0x8B);
            while (obj->unk_38 != 0.0) {
                HuPrcVSleep();
            }
            PlaySound(0x8D);
            sfx = PlaySound(0x8B);
        }
    }
    func_80060BC8(sfx, 30);
    MBModelKill(obj);
    D_800FA370_DKsJungleAdventure = NULL;
    HuPrcSleep(30);
    D_800FA36C_DKsJungleAdventure = 1;
    EndProcess(NULL);
}
void func_800F8DC8_DKsJungleAdventure(void) {
    Object* obj;

    obj = HuPrcCurrentGet()->user_data;
    HuPrcSleep(5);
    PlaySound(0x92);
    while (obj->yScale < 1.0f) {
        HuPrcVSleep();
        obj->yScale += 0.05f;
    }
    obj->yScale = 1.0f;
    PlaySound(0x93);
    EndProcess(NULL);
}
Process* func_800F8E80_DKsJungleAdventure(Object* arg0) {
    Process* proc;

    proc = omAddPrcObj(func_800F8DC8_DKsJungleAdventure, 0x4800, 0, 0);
    proc->user_data = arg0;
    return proc;
}
void func_800F8EBC_DKsJungleAdventure(void) {
    Object* obj;
    void* rumble;

    obj = HuPrcCurrentGet()->user_data;
    HuPrcSleep(5);
    rumble = func_80058A4C(-1, 0, 10);
    PlaySound(0x92);
    while (obj->yScale > 0.0f) {
        HuPrcVSleep();
        obj->yScale -= 0.05f;
    }
    obj->yScale = 0.0f;
    PlaySound(0x93);
    func_80058AD0(rumble);
    EndProcess(NULL);
}
Process* func_800F8F88_DKsJungleAdventure(Object* arg0) {
    Process* proc;

    proc = omAddPrcObj(func_800F8EBC_DKsJungleAdventure, 0x4800, 0, 0);
    proc->user_data = arg0;
    return proc;
}
void func_800F8FC4_DKsJungleAdventure(void) {
    GW_PLAYER* player;
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    player = GetPlayerStruct(-1);
    SetPlayerAnimation(-1, -1, 2);
    if (player->coins < 20) {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x3C, 0x3C, 0x11, 2);
        LoadStringIntoWindow(win, (void*)0x186, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, player->player_index);
        HideTextWindow(win);
        SetNextChainAndSpace(player->player_index, 10, 0);
    } else {
        HuPrcChildLink(HuPrcCurrentGet(), func_800F8F88_DKsJungleAdventure(D_800FA34C_DKsJungleAdventure[0]));
        HuPrcChildWatch();
        func_800F7920_DKsJungleAdventure();
        prompt = func_8003C218(-1, D_800F9FEC_DKsJungleAdventure);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(D_800F9E30_DKsJungleAdventure);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F79D0_DKsJungleAdventure();
        if (dir == 0) {
            SetNextChainAndSpace(player->player_index, 11, 0);
        } else {
            SetNextChainAndSpace(player->player_index, 10, 0);
        }
        func_800F8E80_DKsJungleAdventure(D_800FA34C_DKsJungleAdventure[0]);
    }
    EndProcess(NULL);
}
void func_800F91B4_DKsJungleAdventure(void) {
    GW_PLAYER* player;
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    player = GetPlayerStruct(-1);
    SetPlayerAnimation(-1, -1, 2);
    if (player->coins < 20) {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x3C, 0x3C, 0x11, 2);
        LoadStringIntoWindow(win, (void*)0x186, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, player->player_index);
        HideTextWindow(win);
        SetNextChainAndSpace(-1, 16, 0);
    } else {
        HuPrcChildLink(HuPrcCurrentGet(), func_800F8F88_DKsJungleAdventure(D_800FA34C_DKsJungleAdventure[1]));
        HuPrcChildWatch();
        func_800F7920_DKsJungleAdventure();
        prompt = func_8003C218(-1, D_800FA004_DKsJungleAdventure);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(D_800F9F38_DKsJungleAdventure);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F79D0_DKsJungleAdventure();
        if (dir == 0) {
            SetNextChainAndSpace(-1, 8, 0);
        } else {
            SetNextChainAndSpace(-1, 16, 0);
        }
        func_800F8E80_DKsJungleAdventure(D_800FA34C_DKsJungleAdventure[1]);
    }
    EndProcess(NULL);
}
void func_800F9398_DKsJungleAdventure(void) {
    SetNextChainAndSpace(-1, 9, 1);
}
void func_800F93BC_DKsJungleAdventure(void) {
    SetNextChainAndSpace(-1, 2, 0);
}
void func_800F93E0_DKsJungleAdventure(void) {
    SetNextChainAndSpace(-1, 4, 0);
}
void func_800F9404_DKsJungleAdventure(void) {
    SetNextChainAndSpace(-1, 9, 0);
}
void func_800F9428_DKsJungleAdventure(void) {
    SetNextChainAndSpace(-1, 7, 0);
}
void func_800F944C_DKsJungleAdventure(void) {
    SetNextChainAndSpace(-1, 0, 1);
}
// decomp-permuter
void func_800F9470_DKsJungleAdventure(void)
{
  s16 player;
  s16 win;
  short coins;
  int new_var;
  player = GetCurrentPlayerIndex();
  func_800405DC(player);
  SetPlayerAnimation(-1, -1, 2);
  if (_CheckFlag(0x42) == 0)
  {
    win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
    LoadStringIntoWindow(win, (void *) 0x239, -1, -1);
    coins = 10;
  }
  else
  {
    new_var = 0x41;
    win = CreateTextWindow(new_var, 0x3C, 0x11, 3);
    LoadStringIntoWindow(win, (void *) 0x23A, -1, -1);
    coins = 20;
  }
  func_8006E070(win, 0);
  ShowTextWindow(win);
  PlaySound(0x432);
  func_8004DBD4(win, player);
  HideTextWindow(win);
  func_80055960(player, coins);
  ShowPlayerCoinChange(player, coins);
  HuPrcSleep(30);
  func_8003FEFC(player);
}

void func_800F95A4_DKsJungleAdventure(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F9470_DKsJungleAdventure();
}
void func_800F9674_DKsJungleAdventure(void) {
    func_8004D2A4(-1, 8, 0x5D);
    func_800F95A4_DKsJungleAdventure();
    EndProcess(NULL);
}
void func_800F96A8_DKsJungleAdventure(void) {
    if (func_800F6958_DKsJungleAdventure(GetCurrentSpaceIndex()) == 1) {
        func_800587EC(0x44, 0, 2);
        func_8004D2A4(-1, 8, func_800F6610_DKsJungleAdventure());
    }
}
void func_800F970C_DKsJungleAdventure(void) {
    GW_PLAYER* player;
    s32 i;

    if (func_800F6958_DKsJungleAdventure(GetCurrentSpaceIndex()) == 2) {
        for (i = 0; i < 4; i++) {
            player = GetPlayerStruct(i);
            player->group = i != GetCurrentPlayerIndex();
        }
        func_800587BC(1, 0, 5, 1);
    }
}
void func_800F9798_DKsJungleAdventure(void) {
    switch (GetCurrentSpaceIndex()) {
    case 0x81:
        func_8004D2A4(-1, 8, 0x6F);
        break;
    case 0xA:
        func_8004D2A4(-1, 8, 0x62);
        break;
    }
    func_800587EC(0x65, 0, 1);
}
void func_800F9804_DKsJungleAdventure(void) {
    func_8004D2A4(-1, 8, 0x70);
    func_800587BC(0x48, 0, 3, 1);
}
void func_800F983C_DKsJungleAdventure(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F98C0_DKsJungleAdventure);
    func_800F7024_DKsJungleAdventure();
    func_800584F0(2);
    omAddPrcObj(func_800F6CD8_DKsJungleAdventure, 0x1005, 0, 0);
}