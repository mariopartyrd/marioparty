#include "SlotMachine.h"
#include "engine/pad.h"

u8 D_800FE130_SlotMachine[76][38] = {
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCB, 0xBA, 0x96, 0x54, 0x44, 0x44, 0x44, 0x44, 0x45, 0x69, 0xAB, 0xBC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xC9, 0x65, 0x44, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x44, 0x56, 0x9C, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xB9, 0x63, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x36, 0x9B, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0x96, 0x53, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x35, 0x69, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xA6, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x6A, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xC9, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x9C, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x63, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x36, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xC6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x6C, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFD, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xDF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xEA, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0xAE, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xC6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x6C, 0xFF, 0xFF },
    { 0xFF, 0xFE, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xEF, 0xFF },
    { 0xFF, 0xFC, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xCF, 0xFF },
    { 0xFF, 0xFB, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xBF, 0xFF },
    { 0xFF, 0xE9, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9E, 0xFF },
    { 0xFF, 0xC6, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6C, 0xFF },
    { 0xFE, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xEF },
    { 0xFC, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xCF },
    { 0xFB, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xBF },
    { 0xFB, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xBF },
    { 0xFA, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xAF },
    { 0xE9, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9E },
    { 0xB6, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6B },
    { 0xA5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A },
    { 0xA5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A },
    { 0xB6, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6B },
    { 0xE9, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9E },
    { 0xFA, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xAF },
    { 0xFB, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xBF },
    { 0xFB, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xBF },
    { 0xFC, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xCF },
    { 0xFE, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xEF },
    { 0xFF, 0xC6, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6C, 0xFF },
    { 0xFF, 0xE9, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9E, 0xFF },
    { 0xFF, 0xFB, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xBF, 0xFF },
    { 0xFF, 0xFC, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xCF, 0xFF },
    { 0xFF, 0xFE, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xEF, 0xFF },
    { 0xFF, 0xFF, 0xC6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x6C, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xEA, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0xAE, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFD, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xDF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xC6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x6C, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x5A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x63, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x36, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xC9, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x9C, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xA6, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x6A, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0x96, 0x53, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x35, 0x69, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xB9, 0x63, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x36, 0x9B, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xC9, 0x65, 0x44, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x44, 0x56, 0x9C, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCB, 0xBA, 0x96, 0x54, 0x44, 0x44, 0x44, 0x44, 0x45, 0x69, 0xAB, 0xBC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEB, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xBE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};
s16 D_800FEC78_SlotMachine = 0;
s32 D_800FEC7C_SlotMachine = 0;
s32 D_800FEC80_SlotMachine = -1;
s32 D_800FEC84_SlotMachine = 1;
s32 D_800FEC88_SlotMachine = 0;
s32 D_800FEC8C_SlotMachine = 0;
s32 D_800FEC90_SlotMachine = 0;
s32 D_800FEC94_SlotMachine = 0;
s32 D_800FEC98_SlotMachine = 0;
s32 D_800FEC9C_SlotMachine = 0;
s32 D_800FECA0_SlotMachine = 0;
s32 D_800FECA4_SlotMachine = 0;
u8 D_800FECA8_SlotMachine = 1;
s16 D_800FECAC_SlotMachine[3] = { 0x16, 0x17, 0x18 };
f32 D_800FECB4_SlotMachine = 0.0f;
s32 D_800FECB8_SlotMachine = 1;
f32 D_800FECBC_SlotMachine = 1.0f;
f32 D_800FECC0_SlotMachine = 0.0f;
s32 D_800FECC4_SlotMachine = 1;
f32 D_800FECC8_SlotMachine = 0.0f;
u32 D_800FECCC_SlotMachine = 0x41C64E6D;

void func_800F76E0_SlotMachine(void) {
    CZoom = 1200.0f;
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 400.0f;
    Center.z = -100.0f;
}
SlotWork* func_800F7734_SlotMachine(omObjData* unused, omObjData* obj) {
    return func_800FBFEC_SlotMachine(obj);
}
/* Retail called these sprite and image helpers without a prototype (implicit int: the caller
   extends or masks the result), so on the N64 they are called as returning s32. */
#define SLOT_UNPROTO(f) ((s32 (*)())(f))
#define SLOT_8001E1D0(a, b) ((s32 (*)(s16, s32))func_8001E1D0)(a, b)

// register allocation: the image index and func_800FC050 % 480 sit in other registers (masked 33,
// mostly branch offsets after one missing move)
#ifdef NON_MATCHING
void func_800F7750_SlotMachine(omObjData* obj) {
    omObjData* player;
    SlotWork* coin;
    void* file;
    s32 i;
    s32 sprite;
    s32 grp;
    s32 result;
    s32 img;
    u16 idx;

    img = 0;
    D_800FFA24_SlotMachine = (D_800FFA24_SlotMachine + 1) % 3;
    player = D_800F3FB0[0];
    switch (D_800FEC80_SlotMachine) {
        case 0:
            if (D_800FEC98_SlotMachine == 0) {
                func_800FC018_SlotMachine();
                file = DataRead(0x2A);
                sprite = (s16)SLOT_UNPROTO(func_800678A4)(file);
                DataClose(file);
                grp = (s16)SLOT_UNPROTO(func_80064EF4)(20, 0);
                for (i = 0; i < 20; i++) {
                    coin = &D_800FF250_SlotMachine[i];
                    if (i == 0) {
                        func_8001DE70(0x20);
                        idx = img = (u16)SLOT_UNPROTO(ReadImgPackand)(0x21, 0x284, 8);
                    } else {
                        idx = (u16)SLOT_8001E1D0(img, 8);
                    }
                    func_80025930(coin->unk_40 = (D_800ECDE0 + idx)->unk_00, 0x70000000, 0x70000000);
                    func_80025830(coin->unk_40, 2.5f, 2.5f, 2.5f);
                    coin->unk_42 = grp;
                    func_80067208(grp, i, sprite, 0);
                    func_800674BC(grp, i, 0x900C);
                    func_800672B0(grp, i, 0);
                    func_800674F4(grp, (s16)i, 0xFF, 0xFF, 0xBE);
                    func_80067354(grp, i, 1.6f, 1.6f);
                    coin->unk_10 = 0.0f;
                    coin->unk_14 = 0.0f;
                    coin->unk_18 = -300.0f;
                    coin->unk_00 = 1;
                    coin->unk_02 = 0;
                    coin->unk_08 = 0;
                    coin->unk_46 = 0;
                    coin->unk_44 = 0;
                }
                D_800FEC98_SlotMachine = 1;
            }
            break;
        case 13:
        case 14:
        case 15:
        case 16:
            if (D_800FE100_SlotMachine != 0) {
                if (D_800FEC94_SlotMachine == 0) {
                    GwPlayer[D_800FFCB8_SlotMachine].coins_mg += (u16)D_800FEC90_SlotMachine;
                    func_800674BC((s16)D_800FFCE4_SlotMachine, 0, 0x8000);
                    func_800674BC((s16)D_800FFCE4_SlotMachine, 1, 0x8000);
                    GMesCreate(2);
                } else if (D_800FEC94_SlotMachine >= 60) {
                    D_800FEC80_SlotMachine = 0x11;
                }
            } else {
                if (D_800FEC94_SlotMachine == 0) {
                    GwPlayer[D_800FFCB8_SlotMachine].coins_mg += (u16)D_800FEC90_SlotMachine;
                    func_800674BC((s16)D_800FFCE4_SlotMachine, 0, 0x8000);
                    func_800674BC((s16)D_800FFCE4_SlotMachine, 1, 0x8000);
                    if (D_800FEC90_SlotMachine != 0) {
                        GMesCreate(2);
                    } else {
                        GMesCreate(14);
                    }
                } else if (D_800FEC94_SlotMachine > 0 && D_800FECA0_SlotMachine == 0) {
                    if (D_800FEC90_SlotMachine == 0) {
                        if (D_800FEC94_SlotMachine == 30) {
                            func_80060128(0x34);
                            func_800184BC(player, 14);
                            D_800FECA0_SlotMachine = D_800FEC94_SlotMachine;
                        }
                    } else if (GMesStatAllGet() & 2) {
                        s32 se = 0x3B;
                        if (D_800FEC90_SlotMachine == 20) {
                            se = 0x37;
                        }
                        func_80060128(se);
                        D_800FECA0_SlotMachine = D_800FEC94_SlotMachine;
                    }
                } else {
                    switch (D_800FEC90_SlotMachine) {
                        case 0:
                            if (D_800FEC94_SlotMachine == D_800FECA0_SlotMachine + 18) {
                                func_80010ED4(GwPlayer[D_800FFCB8_SlotMachine].character + 0x44A, 0);
                            } else if (D_800FEC94_SlotMachine >= D_800FECA0_SlotMachine + 95) {
                                D_800FEC80_SlotMachine = 0x11;
                            }
                            break;
                        case 20:
                            if (D_800FEC94_SlotMachine == D_800FECA0_SlotMachine + 2) {
                                func_800184BC(player, 13);
                            } else if (D_800FEC94_SlotMachine == D_800FECA0_SlotMachine + 38) {
                                func_80010ED4(GwPlayer[D_800FFCB8_SlotMachine].character + 0x451, 0);
                            } else if (D_800FEC94_SlotMachine >= D_800FECA0_SlotMachine + 95) {
                                D_800FEC80_SlotMachine = 0x11;
                            }
                            break;
                        default:
                            if (D_800FEC94_SlotMachine == D_800FECA0_SlotMachine + 16) {
                                func_800184BC(player, 13);
                            } else if (D_800FEC94_SlotMachine == D_800FECA0_SlotMachine + 36) {
                                if (D_800FEC90_SlotMachine >= 10) {
                                    func_80010ED4(GwPlayer[D_800FFCB8_SlotMachine].character + 0x451, 0);
                                }
                            } else if (D_800FEC94_SlotMachine >= D_800FECA0_SlotMachine + 91) {
                                D_800FEC80_SlotMachine = 0x11;
                            }
                            break;
                    }
                }
                if (ContBtnTrg[GwPlayer[D_800FFCB8_SlotMachine].port] & 0x9000) {
                    D_800FECA4_SlotMachine = 1;
                }
                if (D_800FECA4_SlotMachine != 0 && D_800FEC94_SlotMachine >= D_800FECA0_SlotMachine + 60) {
                    func_80011A30(90);
                    D_800FEC80_SlotMachine = 0x11;
                }
            }
            D_800FEC94_SlotMachine++;
            break;
        case 0x11:
            D_800FFCDC_SlotMachine = -1;
            break;
        default:
            D_800FFA28_SlotMachine = func_800FC2CC_SlotMachine();
            if (D_800FEC7C_SlotMachine <= 0 && D_800FEC80_SlotMachine == 8 && D_800FFA28_SlotMachine == 0) {
                if (D_800FEC84_SlotMachine > 0) {
                    func_800FC3F4_SlotMachine();
                    D_800FEC7C_SlotMachine = 300;
                    D_800FEC84_SlotMachine--;
                    func_800671DC((s16)D_800FFCE4_SlotMachine, 0, D_800FEC84_SlotMachine % 10);
                    func_800671DC((s16)D_800FFCE4_SlotMachine, 1, D_800FEC84_SlotMachine / 10);
                } else {
                    if (D_800FEC90_SlotMachine == 0) {
                        D_800FEC80_SlotMachine = 12;
                    }
                    func_800601D4(90);
                }
            }
            if ((D_800FFA28_SlotMachine == 2 || D_800FFA28_SlotMachine == 3) && D_800FEC7C_SlotMachine <= 0) {
                D_800FEC7C_SlotMachine += 30;
                func_800FC5C4_SlotMachine();
            }
            if (D_800FFA28_SlotMachine == 4) {
                result = (s16)SLOT_UNPROTO(func_800FC664_SlotMachine)();
                if (result >= 0) {
                    D_800FEC80_SlotMachine = 10;
                    switch (result) {
                        case 1:
                            D_800FEC90_SlotMachine += 3;
                            break;
                        case 2:
                            D_800FEC90_SlotMachine += 8;
                            break;
                        case 3:
                            D_800FEC90_SlotMachine += 5;
                            break;
                        case 0:
                        case 4:
                            D_800FEC90_SlotMachine += 6;
                            break;
                        case 5:
                            D_800FEC90_SlotMachine += 1;
                            break;
                        case 6:
                            D_800FEC90_SlotMachine += 10;
                            D_800FEC80_SlotMachine = 10;
                            break;
                        case 7:
                            D_800FEC90_SlotMachine += 20;
                            D_800FEC80_SlotMachine = 11;
                            break;
                    }
                    if (result == 7) {
                        PlaySound(0x1D9);
                    } else {
                        PlaySound(0x1D7);
                    }
                }
                D_800FEC7C_SlotMachine = 30;
            }
            D_800FEC7C_SlotMachine--;
            break;
    }
    func_800F89E8_SlotMachine();
    if (D_800FEC90_SlotMachine != 0) {
        for (i = 0; i < D_800FEC90_SlotMachine; i++) {
            coin = &D_800FF250_SlotMachine[i];
            if (coin->unk_00 != 0) {
                switch (coin->unk_02) {
                    case 0:
                        if (++coin->unk_44 >= i * 4) {
                            coin->unk_28 = func_800FC050_SlotMachine() % 480 - 240;
                            coin->unk_2C = coin->unk_30 = 0.0f;
                            coin->unk_1C = coin->unk_10;
                            coin->unk_20 = coin->unk_14;
                            coin->unk_24 = coin->unk_18;
                            coin->unk_02++;
                            coin->unk_44 = 0;
                            func_800258EC(coin->unk_40, 4, 0);
                        }
                        break;
                    case 1:
                        coin->unk_44++;
                        coin->unk_10 = coin->unk_44 * coin->unk_28 / 16.0f;
                        coin->unk_14 = 0.0f;
                        coin->unk_18 = (16 - coin->unk_44) * coin->unk_24 / 16.0f;
                        if (coin->unk_44 >= 16) {
                            coin->unk_1C = coin->unk_10;
                            coin->unk_20 = coin->unk_14;
                            coin->unk_24 = coin->unk_18;
                            coin->unk_44 = 0;
                            coin->unk_02++;
                        }
                        break;
                    case 2:
                        if (++coin->unk_44 >= 240) {
                            coin->unk_44 = 0;
                            coin->unk_02++;
                        }
                        break;
                    case 3:
                        coin->unk_44++;
                        if (coin->unk_44 & 1) {
                            func_800258EC(coin->unk_40, 4, 4);
                        } else {
                            func_800258EC(coin->unk_40, 4, 0);
                        }
                        if (coin->unk_44 >= 60) {
                            func_800258EC(coin->unk_40, 4, 4);
                            coin->unk_44 = 0;
                            coin->unk_02++;
                            D_800FEC9C_SlotMachine++;
                        }
                        break;
                }
                func_80025798(coin->unk_40, coin->unk_10, coin->unk_14, coin->unk_18);
                if ((s32)sqrtf((coin->unk_10 - player->trans.x) * (coin->unk_10 - player->trans.x) +
                               (coin->unk_14 - player->trans.y) * (coin->unk_14 - player->trans.y) +
                               (coin->unk_18 - player->trans.z) * (coin->unk_18 - player->trans.z)) <= 70.0 &&
                    coin->unk_02 != 4) {
                    coin->unk_00 = 0;
                    coin->unk_02 = 0;
                    func_800258EC(coin->unk_40, 4, 4);
                    D_800FEC9C_SlotMachine++;
                    func_80067480(coin->unk_42, i, 0x8000);
                    func_800672B0(coin->unk_42, i, 1);
                    func_80067284(coin->unk_42, i, 2.0f);
                    func_800672DC(coin->unk_42, i, 0, 0);
                    func_80066DF4(coin->unk_42, i, 0, coin->unk_10, coin->unk_14, coin->unk_18);
                    PlaySound(0xFC);
                }
            } else if (coin->unk_02 == 0 && (func_80067328(coin->unk_42, i) & 4)) {
                func_800674BC(coin->unk_42, i, 0x8000);
                coin->unk_02++;
            }
        }
        if (D_800FEC9C_SlotMachine == D_800FEC90_SlotMachine && D_800FEC80_SlotMachine == 8) {
            D_800FEC80_SlotMachine = 12;
        }
    }
    if (D_800F5144 == 1 && D_800FEC80_SlotMachine != -1) {
        func_800FBD60_SlotMachine();
        omOvlReturnEx(1);
        func_80060198();
        return;
    }
    if (D_800FFCDC_SlotMachine < 0) {
        if (D_800FE100_SlotMachine != 0) {
            func_80060398(40);
        }
        func_800726AC(0, 20);
        obj->func_ptr = func_800F8554_SlotMachine;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E13F0", func_800F7750_SlotMachine);
#endif
void func_800F8554_SlotMachine(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F699C_SlotMachine();
    }
}
void func_800F8580_SlotMachine(void) {
    s32 ids[3];
    void* file;
    s32 i;

    file = DataRead(0x14001A);
    D_800FFA38_SlotMachine = func_800678A4(file);
    DataClose(file);
    D_800FFA30_SlotMachine = func_80064EF4(1, 0);
    func_80067208((s16)D_800FFA30_SlotMachine, 0, (s16)D_800FFA38_SlotMachine, 0);
    func_800674BC((s16)D_800FFA30_SlotMachine, 0, 0x980C);
    func_800672B0((s16)D_800FFA30_SlotMachine, 0, 0);
    func_8006752C((s16)D_800FFA30_SlotMachine, 0, 0xA0);
    func_80066DC4((s16)D_800FFA30_SlotMachine, 0, 160, 120);
    for (i = 0; i < 3; i++) {
        D_800FFA54_SlotMachine[i] = HuMemDirectMalloc(0x9600);
    }
    file = DataRead(0x140019);
    ids[0] = func_800678A4(file);
    DataClose(file);
    D_800FFA34_SlotMachine = func_80064EF4(2, 0);
    for (i = 0; i < 2; i++) {
        func_80067208((s16)D_800FFA34_SlotMachine, i, (s16)ids[0], 0);
        func_800674BC((s16)D_800FFA34_SlotMachine, i, 0x28980C);
        func_800672B0((s16)D_800FFA34_SlotMachine, i, 0);
        func_80067354((s16)D_800FFA34_SlotMachine, i, 1.2f, 1.2f);
        func_8006752C((s16)D_800FFA34_SlotMachine, i, 0x48);
        func_8006768C((s16)D_800FFA34_SlotMachine, i, 5, 5);
        func_8006765C((s16)D_800FFA34_SlotMachine, i, 2.0f, 2.0f);
        func_80066DC4((s16)D_800FFA34_SlotMachine, i, 140, 74);
    }
    for (i = 0; i < 3; i++) {
        file = DataRead(D_800FECAC_SlotMachine[i] | 0x140000);
        ids[i] = func_800678A4(file);
        DataClose(file);
    }
    D_800FFA1C_SlotMachine = func_80064EF4(2, 0);
    D_800FFA2C_SlotMachine = func_80064EF4(2, 0);
    for (i = 0; i < 2; i++) {
        func_80067208((s16)D_800FFA1C_SlotMachine, i, (s16)ids[i], 0);
        func_80067208((s16)D_800FFA2C_SlotMachine, i, (s16)ids[2], 0);
        func_800674BC((s16)D_800FFA1C_SlotMachine, i, 0x9828);
        func_800674BC((s16)D_800FFA2C_SlotMachine, i, 0x980C);
        func_800672B0((s16)D_800FFA1C_SlotMachine, i, 0);
        func_800672B0((s16)D_800FFA2C_SlotMachine, i, 0);
        func_80067354((s16)D_800FFA1C_SlotMachine, i, 0.001f, 1.0f);
        func_80067354((s16)D_800FFA2C_SlotMachine, i, 122.0f, 1.0f);
        func_80066DC4((s16)D_800FFA1C_SlotMachine, i, 81, 120);
        func_8006752C((s16)D_800FFA2C_SlotMachine, i, 0xA0);
        func_80067384((s16)D_800FFA1C_SlotMachine, i, 0xFFFF);
        func_80067384((s16)D_800FFA2C_SlotMachine, i, 0xFFFF);
    }
    func_80067558((s16)D_800FFA1C_SlotMachine, 0, 0xFF, 0xFF, 0x66, 0x76);
    func_8006752C((s16)D_800FFA1C_SlotMachine, 1, 0xA0);
    func_80066DC4((s16)D_800FFA2C_SlotMachine, 0, 203, 120);
    func_80066DC4((s16)D_800FFA2C_SlotMachine, 1, -41, 120);
}
void func_800F89E8_SlotMachine(void) {
    f32 sx;
    f32 sy;
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 i;

    switch (D_800FEC80_SlotMachine) {
        case 1:
            if (D_800FECB4_SlotMachine >= 680.0f) {
                if ((D_800FECBC_SlotMachine -= 0.05) <= 0.0f) {
                    D_800FECBC_SlotMachine = 0.001f;
                }
                func_80067354((s16)D_800FFA34_SlotMachine, 0, D_800FECBC_SlotMachine, D_800FECBC_SlotMachine);
                func_80067354((s16)D_800FFA34_SlotMachine, 1, D_800FECBC_SlotMachine, D_800FECBC_SlotMachine);
            }
        case 0:
            if (D_800FECB4_SlotMachine >= 440.0f) {
                D_800FEC80_SlotMachine = 1;
            }
            sx = func_800AEAC0(D_800FECB4_SlotMachine * 0.5) * 100.0f;
            sy = func_800AEAC0(D_800FECB4_SlotMachine) * 60.0f;
            func_80066DC4((s16)D_800FFA34_SlotMachine, 0, x0 = sx + 160.0f, y0 = sy + 100.0f);
            func_80066DC4((s16)D_800FFA34_SlotMachine, 1, x1 = 160.0f - sx, y1 = 100.0f - sy);
            func_800F9534_SlotMachine(D_800FFA30_SlotMachine, 38, x0, y0, x1, y1,
                                      D_800FECBC_SlotMachine - (1.0f - D_800FECBC_SlotMachine) * 0.4);
            D_800FECB4_SlotMachine += 8.0f;
            break;
        case 2:
            if (D_800FECB8_SlotMachine != 0) {
                D_800FECB4_SlotMachine = 0.0f;
                D_800FECB8_SlotMachine = 0;
                for (i = 0; i < 3; i++) {
                    HuMemDirectFree(D_800FFA54_SlotMachine[i]);
                }
            }
            D_800FECB4_SlotMachine += 0.025;
            func_80067354((s16)D_800FFA1C_SlotMachine, 0, D_800FECB4_SlotMachine, 1.0f);
            func_80067354((s16)D_800FFA1C_SlotMachine, 1, D_800FECB4_SlotMachine, 1.0f);
            func_80066DC4((s16)D_800FFA2C_SlotMachine, 0, D_800FECB4_SlotMachine * 38.666 + 202.0, 120);
            func_80066DC4((s16)D_800FFA2C_SlotMachine, 1, -42.0 - D_800FECB4_SlotMachine * 37.9, 120);
            if (D_800FECB4_SlotMachine >= 1.0f) {
                func_80067354((s16)D_800FFA1C_SlotMachine, 0, 1.0f, 1.0f);
                func_80067354((s16)D_800FFA1C_SlotMachine, 1, 1.0f, 1.0f);
                D_800FEC80_SlotMachine = 3;
                D_800FECB8_SlotMachine = 1;
            }
            break;
        case 13:
            if (D_800FECB8_SlotMachine != 0) {
                D_800FECB4_SlotMachine = 0.0f;
                D_800FECB8_SlotMachine = 0;
                func_80067480((s16)D_800FFA1C_SlotMachine, 1, 0x8000);
                func_80067480((s16)D_800FFA2C_SlotMachine, 0, 0x8000);
                func_80067480((s16)D_800FFA2C_SlotMachine, 1, 0x8000);
            }
            D_800FECB4_SlotMachine += 4.5;
            func_8006752C((s16)D_800FFA1C_SlotMachine, 1, D_800FECB4_SlotMachine);
            func_8006752C((s16)D_800FFA2C_SlotMachine, 0, D_800FECB4_SlotMachine);
            func_8006752C((s16)D_800FFA2C_SlotMachine, 1, D_800FECB4_SlotMachine);
            if (D_800FECB4_SlotMachine >= 160.0f) {
                D_800FECB4_SlotMachine = 1.0f;
                D_800FEC80_SlotMachine = 0x10;
            }
            break;
        case 14:
            func_80067354((s16)D_800FFA1C_SlotMachine, 0, D_800FECB4_SlotMachine, 1.0f);
            func_80067354((s16)D_800FFA1C_SlotMachine, 1, D_800FECB4_SlotMachine, 1.0f);
            func_80066DC4((s16)D_800FFA2C_SlotMachine, 0,
                          D_800FECB4_SlotMachine * 38.666 + 281.0 + (s32)D_800FECB4_SlotMachine, 120);
            func_80066DC4((s16)D_800FFA2C_SlotMachine, 1, 160.0f - (D_800FECB4_SlotMachine * 38.0f + 122.0f), 120);
            if ((D_800FECB4_SlotMachine -= 0.05) <= 0.0f) {
                D_800FECA8_SlotMachine = 0;
                func_800674BC((s16)D_800FFA1C_SlotMachine, 0, 0x8000);
                func_800674BC((s16)D_800FFA1C_SlotMachine, 1, 0x8000);
                func_800674BC((s16)D_800FFA2C_SlotMachine, 1, 0x8000);
                func_80066DC4((s16)D_800FFA2C_SlotMachine, 0, 160, 120);
                func_80067354((s16)D_800FFA2C_SlotMachine, 0, 160.0f, 1.0f);
            }
            break;
    }
}
void func_800F91C4_SlotMachine(s32 arg0, s32 arg1, s32 x, s32 y, s32 z) {
    unk65770Obj* spr;
    f32 px;
    s32 i;

    if (arg0 != 0) {
        if (D_800FEC80_SlotMachine < 13) {
            func_80066DF4((s16)D_800FFA1C_SlotMachine, 0, 0, x, y, z);
            func_800675F4((s16)D_800FFA1C_SlotMachine, 0)->unk42 = 120;
        }
    } else if (D_800FEC80_SlotMachine >= 3) {
        if (arg1 == 5) {
            D_800FECC0_SlotMachine += 4.5;
            func_8006752C((s16)D_800FFA1C_SlotMachine, 1, 160.0f - D_800FECC0_SlotMachine);
            func_8006752C((s16)D_800FFA2C_SlotMachine, 0, 160.0f - D_800FECC0_SlotMachine);
            func_8006752C((s16)D_800FFA2C_SlotMachine, 1, 160.0f - D_800FECC0_SlotMachine);
        }
        for (i = 0; i < 2; i++) {
            func_80066DF4((s16)D_800FFA1C_SlotMachine, i, 0, x, y, z);
            spr = func_800675F4((s16)D_800FFA1C_SlotMachine, i);
            spr->unk42 = 120;
        }
        px = spr->unk40;
        func_80066DC4((s16)D_800FFA2C_SlotMachine, 0, px + 122.0f + 38.0f, 120);
        func_80066DC4((s16)D_800FFA2C_SlotMachine, 1, px - 122.0f - 38.0f, 120);
    }
}
void func_800F9534_SlotMachine(s32 grp, s32 size, s32 x0, s32 y0, s32 x1, s32 y1, f32 scale) {
    s32 size2;
    s32 i;
    s32 k;
    s32 c;
    s32 j;
    unk65770AnimC* frame;
    unk65770Obj* spr;
    f32 inv;
    f32 half;
    s32 sz;
    s32 sz2;
    s32 src;
    s32 srow;
    s32 row0;
    s32 row1;

    spr = func_800675F4(grp, 0);
    frame = &spr->unk4C->unk0[spr->unk52];
    size2 = size * 2;
    if (D_800FECC4_SlotMachine != 0) {
        for (i = 0; i < 3; i++) {
            k = 0;
            for (j = 0; j < frame->unk6; j++) {
                for (c = 0; c < frame->unk4; c += 2) {
                    D_800FFA54_SlotMachine[i][k++] = 0xFF;
                }
            }
            D_800FF9D0_SlotMachine[i] = x0;
            D_800FF9DC_SlotMachine[i] = y0;
            D_800FF9E8_SlotMachine[i] = x1;
            D_800FF9F4_SlotMachine[i] = y1;
        }
        D_800FFA18_SlotMachine = frame->unk0;
        D_800FECC4_SlotMachine = 0;
    } else {
        for (j = 0; j < size2; j++) {
            row0 = (j + D_800FF9DC_SlotMachine[D_800FFA24_SlotMachine] - size) * frame->unk4;
            row1 = (j + D_800FF9F4_SlotMachine[D_800FFA24_SlotMachine] - size) * frame->unk4;
            for (c = 0; c < size2; c += 2) {
                k = (row0 + (c + D_800FF9D0_SlotMachine[D_800FFA24_SlotMachine] - size)) * 0.5;
                D_800FFA54_SlotMachine[D_800FFA24_SlotMachine][k] = 0xFF;
                k = (row1 + (c + D_800FF9E8_SlotMachine[D_800FFA24_SlotMachine] - size)) * 0.5;
                D_800FFA54_SlotMachine[D_800FFA24_SlotMachine][k] = 0xFF;
            }
        }
    }
    frame->unk0 = D_800FFA54_SlotMachine[D_800FFA24_SlotMachine];
    inv = 1.0f / scale;
    half = inv * 0.5;
    sz = size * scale;
    sz2 = size2 * scale;
    for (j = 0; j < sz2; j++) {
        row0 = (y0 + j - sz) * frame->unk4;
        row1 = (y1 + j - sz) * frame->unk4;
        srow = (s32)(j * inv) * size;
        for (c = 0; c < sz2; c += 2) {
            src = srow + c * half;
            k = (row0 + (x0 + c - sz)) * 0.5;
            D_800FFA54_SlotMachine[D_800FFA24_SlotMachine][k] &= ((u8*)D_800FE130_SlotMachine)[src];
            k = (row1 + (x1 + c - sz)) * 0.5;
            D_800FFA54_SlotMachine[D_800FFA24_SlotMachine][k] &= ((u8*)D_800FE130_SlotMachine)[src];
        }
    }
    D_800FF9D0_SlotMachine[D_800FFA24_SlotMachine] = x0;
    D_800FF9DC_SlotMachine[D_800FFA24_SlotMachine] = y0;
    D_800FF9E8_SlotMachine[D_800FFA24_SlotMachine] = x1;
    D_800FF9F4_SlotMachine[D_800FFA24_SlotMachine] = y1;
}
void func_800F99E0_SlotMachine(omObjData* obj) {
    SlotWork* w;
    s32 i;
    unk65770Obj* spr;
    unk65770AnimC* frame;
    u16* fb;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 b;
    f32 c;

    w = func_800FBFEC_SlotMachine(obj);
    switch (D_800FEC80_SlotMachine) {
        case -1:
            switch (w->unk_40) {
                case 0:
                    D_800FFA10_SlotMachine = HuMemDirectMalloc(0x25800);
                    for (i = 0; i < 20; i++) {
                        func_800258EC(obj->model[i], 4, 4);
                    }
                    func_800258EC(obj->model[0], 4, 0);
                    w->unk_40++;
                    w->unk_42 = 0;
                    break;
                case 1:
                    if (++w->unk_42 >= 12) {
                        w->unk_40++;
                        D_800F3854 = 0;
                        func_800726AC(0, 1);
                    } else if (w->unk_42 == 4) {
                        SetFadeInTypeAndTime(0, 1);
                    }
                    break;
                case 2:
                    if (++w->unk_42 >= 3) {
                        w->unk_40++;
                    }
                    break;
                case 3:
                    fb = D_80360000;
                    for (i = 0; i < 320 * 240; i++) {
                        D_800FFA10_SlotMachine[i] = fb[i];
                    }
                    spr = func_800675F4((s16)D_800FFCC0_SlotMachine, 0);
                    frame = &spr->unk4C->unk0[spr->unk52];
                    D_800FFA14_SlotMachine = frame->unk0;
                    spr->unk4C->unk18 = 16;
                    spr->unk4C->unk1A = 255;
                    frame->unk0 = (u8*)D_800FFA10_SlotMachine;
                    frame->unk4 = 320;
                    frame->unk6 = 240;
                    frame->unk8 = 160;
                    frame->unkA = 120;
                    func_80067354((s16)D_800FFCC0_SlotMachine, 0, 1.0f, 1.0f);
                    w->unk_40++;
                    w->unk_42 = 0;
                    break;
                case 4:
                    D_800F3854 = 1;
                    for (i = 0; i < 9; i++) {
                        func_800258EC(obj->model[i], 4, 0);
                    }
                    func_800258EC(obj->model[0], 4, 4);
                    func_800258EC(obj->model[6], 4, 4);
                    func_800258EC(obj->model[7], 4, 4);
                    func_800258EC(obj->model[12], 4, 0);
                    func_800258EC(obj->model[13], 4, 0);
                    func_800258EC(obj->model[14], 4, 0);
                    func_800258EC(obj->model[16], 4, 0);
                    for (i = 0; i < 2; i++) {
                        func_80067480((s16)D_800FFA34_SlotMachine, i, 0x8000);
                    }
                    func_80067480((s16)D_800FFA30_SlotMachine, 0, 0x8000);
                    w->unk_40++;
                    w->unk_42 = 0;
                    break;
                case 5:
                    w->unk_42++;
                    func_80026174(obj->model[14], obj->model[15], 0.0f);
                    func_80026174(obj->model[16], obj->model[17], 0.0f);
                    if (w->unk_42 >= 3) {
                        osViBlack(0);
                        w->unk_40 = 0;
                        w->unk_42 = 0;
                        D_800FEC80_SlotMachine = 0;
                        D_800FECC8_SlotMachine = 0.0f;
                        PlaySound(0x1AF);
                        SetFadeInTypeAndTime(0, 16);
                    }
                    break;
            }
            break;
        case 1:
            if (D_800FECC8_SlotMachine <= 1.0) {
                func_80026174(obj->model[14], obj->model[15], D_800FECC8_SlotMachine);
                func_80026174(obj->model[16], obj->model[17], D_800FECC8_SlotMachine);
            } else {
                func_80026174(obj->model[14], obj->model[15], 1.0f);
                func_80026174(obj->model[16], obj->model[17], 1.0f);
            }
            if ((func_8005FD5C() + D_800F64F8) == 0) {
                D_800FECC8_SlotMachine += 0.025;
            }
            if (D_800FECC8_SlotMachine >= 1.5) {
                for (i = 0; i < 2; i++) {
                    func_80067480((s16)D_800FFA2C_SlotMachine, i, 0x8000);
                    func_80067480((s16)D_800FFA1C_SlotMachine, i, 0x8000);
                    func_800674BC((s16)D_800FFA34_SlotMachine, i, 0x8000);
                }
                func_800674BC((s16)D_800FFA30_SlotMachine, 0, 0x8000);
                D_800FEC80_SlotMachine = 2;
                D_800FECC8_SlotMachine = 1.0f;
            }
            break;
        case 3:
            if (D_800FEC8C_SlotMachine > 0.0) {
                D_800FFA00_SlotMachine = x = D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][0];
                D_800FFA04_SlotMachine = y = D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][1];
                D_800FFA08_SlotMachine = z = D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][2];
                D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][0] = 0.0f;
                D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][1] = 0.0f;
                D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][2] = 0.0f;
                func_80025798(obj->model[4], x * 20.0f * 0.05, y * 20.0f * 0.05, z * 20.0f * 0.05);
                D_800FEC80_SlotMachine = 4;
                func_80060128(30);
            }
            break;
        case 4:
            func_800257E4(obj->model[4], D_800FEC8C_SlotMachine, 0.0f, 0.0f);
            if ((s32)(D_800FEC8C_SlotMachine / 3.6) == 1) {
                PlaySound(0x1D2);
            }
            if (D_800FEC8C_SlotMachine >= 80.0) {
                func_800FC3F4_SlotMachine();
                D_800FEC84_SlotMachine--;
                func_800671DC((s16)D_800FFCE4_SlotMachine, 0, D_800FEC84_SlotMachine % 10);
                func_800671DC((s16)D_800FFCE4_SlotMachine, 1, D_800FEC84_SlotMachine / 10);
                D_800FEC7C_SlotMachine = 600;
                D_800FEC80_SlotMachine = 5;
            }
            break;
        case 5:
            if ((func_8005FD5C() + D_800F64F8) == 0) {
                D_800FEC8C_SlotMachine -= 10;
            }
            func_800257E4(obj->model[4], D_800FEC8C_SlotMachine, 0.0f, 0.0f);
            if (D_800FEC8C_SlotMachine <= 0.0) {
                w->unk_42 = 30;
                w->unk_44 = 0;
                D_800FEC80_SlotMachine = 6;
            }
            break;
        case 6:
            if ((func_8005FD5C() + D_800F64F8) == 0) {
                w->unk_42--;
                w->unk_44 = (w->unk_44 + 30) % 360;
            }
            c = -w->unk_42 * func_800AEAC0(w->unk_44);
            func_800257E4(obj->model[4], c, 0.0f, 0.0f);
            if (w->unk_42 <= 0) {
                w->unk_42 = 0;
                w->unk_44 = 0;
                D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][0] = D_800FFA00_SlotMachine;
                D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][1] = D_800FFA04_SlotMachine;
                D_800F2B7C[obj->model[4]].unk_6C->unk_A0->unk_64[3][2] = D_800FFA08_SlotMachine;
                func_80025798(obj->model[4], 0.0f, 0.0f, 0.0f);
                D_800FEC80_SlotMachine = 7;
            }
            break;
        case 11:
            obj->rot.z = func_800AEAC0((w->unk_42 + 1) * 11.25) * 10.0f;
            func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
            func_800257E4(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
        case 10:
            obj->scale.x = (f32)(func_800AEAC0((w->unk_42 + 1) * 22.5) * 0.1) + 1.0;
            obj->scale.y = (f32)(-func_800AEAC0((w->unk_42 + 1) * 22.5) * 0.1) + 1.0;
            func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
            func_80025830(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
        case 9:
            if (w->unk_42 < 61) {
                if (w->unk_42 == 0) {
                    func_800258EC(obj->model[13], 4, 4);
                    func_800258EC(obj->model[18], 4, 0);
                    func_800258EC(obj->model[19], 4, 0);
                    func_80060F04((s16)D_800FFCB8_SlotMachine, 2, 2, 20);
                }
                a = func_800AEAC0(w->unk_42 * 9) * 12.0f * 20.0f;
                b = func_800AEAC0(w->unk_42 * 18) * 8.0f * 20.0f;
                func_800FAC10_SlotMachine(obj->model[18], a, -b, 0);
                func_800FAC10_SlotMachine(obj->model[19], -a, b, 0);
            } else {
                b = (80 - w->unk_42) * 0.05;
                func_800FAC10_SlotMachine(obj->model[18], b, b, 1);
                func_800FAC10_SlotMachine(obj->model[19], b, b, 1);
            }
            if ((func_8005FD5C() + D_800F64F8) == 0) {
                if (!(++w->unk_42 & 1)) {
                    func_800258EC(obj->model[w->unk_44 + 9], 4, 4);
                    w->unk_44 = (w->unk_44 + 1) % 3;
                    func_800258EC(obj->model[w->unk_44 + 9], 4, 0);
                    if (!(w->unk_42 & 3)) {
                        func_800258EC(obj->model[w->unk_46 + 6], 4, 4);
                        w->unk_46 ^= 1;
                        func_800258EC(obj->model[w->unk_46 + 6], 4, 0);
                        if (w->unk_42 >= 80) {
                            w->unk_42 = 0;
                            func_800258EC(obj->model[18], 4, 4);
                            func_800258EC(obj->model[19], 4, 4);
                            func_800258EC(obj->model[6], 4, 4);
                            func_800258EC(obj->model[7], 4, 4);
                            func_800258EC(obj->model[13], 4, 0);
                            func_800258EC(obj->model[8], 4, 0);
                            func_800258EC(obj->model[9], 4, 4);
                            func_800258EC(obj->model[10], 4, 4);
                            func_800258EC(obj->model[11], 4, 4);
                            if (D_800FEC80_SlotMachine == 10 || D_800FEC80_SlotMachine == 11) {
                                obj->scale.x = obj->scale.y = 1.0f;
                                obj->rot.z = 0.0f;
                                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                                func_800257E4(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
                                func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
                                func_80025830(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
                            }
                            D_800FEC80_SlotMachine = 8;
                        }
                    }
                }
            }
            break;
        case 14:
        case 15:
            if (D_800FECC8_SlotMachine == 1.0) {
                func_800601D4(90);
            }
            if (D_800FECC8_SlotMachine > 0.0) {
                func_80026174(obj->model[14], obj->model[15], D_800FECC8_SlotMachine);
                func_80026174(obj->model[16], obj->model[17], D_800FECC8_SlotMachine);
            } else {
                func_80026174(obj->model[14], obj->model[15], 0.0f);
                func_80026174(obj->model[16], obj->model[17], 0.0f);
            }
            if ((func_8005FD5C() + D_800F64F8) == 0) {
                D_800FECC8_SlotMachine -= 0.02;
            }
            if (D_800FECC8_SlotMachine <= 0.65) {
                D_800FEC80_SlotMachine = 14;
            }
            if (D_800FECC8_SlotMachine <= -0.5) {
                D_800FEC80_SlotMachine = 16;
                D_800FECC8_SlotMachine = 0.0f;
            }
            break;
    }
    if (D_800FEC88_SlotMachine != 0) {
        if ((func_8005FD5C() + D_800F64F8) == 0) {
            if (w->unk_40 == 0 && (D_800FFA28_SlotMachine == 2 || D_800FFA28_SlotMachine == 3)) {
                func_800FC5C4_SlotMachine();
                D_800FEC7C_SlotMachine = 300;
            }
            w->unk_40 += 18;
        }
        func_80025798(obj->model[3], 0.0f, (func_800AEFD0(w->unk_40) * 2.0f + 14.0) * 20.0, -70.0f);
        func_80025830(obj->model[5], 0.35 - func_800AEFD0(w->unk_40) * 0.1, 1.0f, 0.35 - func_800AEFD0(w->unk_40) * 0.1);
        if (w->unk_40 >= 90) {
            w->unk_40 = 0;
            func_80025830(obj->model[5], 0.35f, 1.0f, 0.35f);
            D_800FEC88_SlotMachine = 0;
        }
    }
}
void func_800FAC10_SlotMachine(s16 model, f32 x, f32 y, s32 mode) {
    unk2C0C0StructC0* c0;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 n;
    s16 i;

    c0 = D_800F2B7C[model].unk_6C;
    src = c0->unk_04;
    dst = c0->unk_08[D_800F37F0];
    n = c0->unk_72;
    if (mode == 0) {
        for (i = 0; i < n; i++) {
            *dst = *src;
            if (i != 1) {
                dst->unk_00 = src->unk_00 + x * 0.5;
                dst->unk_04 = src->unk_04 + y * 0.5;
            }
            src++;
            dst++;
        }
    } else if (mode == 1) {
        for (i = 0; i < n; i++) {
            *dst = *src;
            if (i != 1) {
                dst->unk_00 = src->unk_00 * x;
                dst->unk_04 = src->unk_04 * y;
            }
            src++;
            dst++;
        }
    }
}
void func_800FAE34_SlotMachine(omObjData* obj) {
    SlotPlayerWork* p;
    SlotWork* w;
    u8 port;
    s32 stat;
    f32 s;
    f32 sc;
    s16 r;

    sc = 0.0f;
    p = SLOT_PLAYER(obj);
    w = func_800FBFEC_SlotMachine(obj);
    if (w->unk_00 >= 0) {
        w->unk_00 |= 0x80C0;
        w->unk_02 = 1;
        w->unk_04 = w->unk_06 = 4;
        w->unk_10 = D_800F2B7C[*obj->model].unk_24;
        w->unk_14 = D_800F2B7C[*obj->model].unk_28;
        w->unk_18 = D_800F2B7C[*obj->model].unk_2C;
        w->unk_40 = w->unk_48 = 0;
        w->unk_42 = 0x30;
        p->unk_38 = sc;
        func_800184BC(obj, 1);
        D_800FFA0C_SlotMachine = GwPlayer[p->unk_58].cpu_difficulty;
        return;
    }
    port = p->unk_56;
    stat = func_80017A60(obj);
    switch (w->unk_08) {
        case 0:
            w->unk_1C = w->unk_10;
            w->unk_20 = w->unk_14;
            switch (w->unk_40) {
                case 0:
                    obj->rot.x = w->unk_5E;
                    obj->rot.y = 180.0f;
                    obj->rot.z = 0.0f;
                    p->unk_3C = 0.0f;
                    func_80025EB4(obj->model[0], 1, 1);
                    func_800258EC(obj->model[1], 4, 4);
                    if (D_800FEC80_SlotMachine == 3) {
                        func_800258EC(obj->model[1], 4, 0);
                        func_800184BC(obj, 0x23);
                        w->unk_40 = 1;
                    }
                    break;
                case 1:
                    func_80025CA8(obj->model[0], 8.0f);
                    func_80025EB4(obj->model[0], 1, 1);
                    if ((w->unk_14 += -28.8) <= 350.0) {
                        D_800FEC8C_SlotMachine = 0;
                        w->unk_40 = 2;
                    }
                    break;
                case 2:
                    D_800FEC8C_SlotMachine += 3.6;
                    w->unk_14 = (func_800AEFD0(D_800FEC8C_SlotMachine) * 15.0f + 2.5) * 20.0;
                    w->unk_18 = (func_800AEAC0(D_800FEC8C_SlotMachine) * 15.0f - 17.5) * 20.0;
                    if (D_800FEC8C_SlotMachine >= 80.0) {
                        D_800FEC8C_SlotMachine = 80;
                        obj->rot.x = 0.0f;
                        obj->rot.y = 45.0f;
                        obj->rot.z = 0.0f;
                        w->unk_14 = 0.0f;
                        p->unk_3C = 135.0f;
                        func_80025EB4(obj->model[0], 1, 0);
                        func_800184BC(obj, 6);
                        w->unk_40 = 3;
                        w->unk_44 = 0;
                    }
                    break;
                case 3:
                    w->unk_44 += 3;
                    w->unk_10 = (func_800AEAC0(w->unk_44) * 15.0f + -20.0f) * 20.0f;
                    w->unk_14 = (func_800AEAC0(w->unk_44 * 2) * 30.0f + 2.5 - func_800AEAC0(w->unk_44) * 2.5) * 20.0;
                    w->unk_18 = (func_800AEAC0(w->unk_44) * 2.5 + -2.5) * 20.0;
                    if (w->unk_44 == 45) {
                        func_800184BC(obj, 9);
                    }
                    if (w->unk_44 >= 90) {
                        func_80010ED4(GwPlayer[p->unk_58].character + 0x12E, 0);
                        w->unk_40 = 4;
                        w->unk_44 = 0;
                    }
                    break;
                case 4:
                    w->unk_44 += 6;
                    w->unk_10 = (func_800AEAC0(w->unk_44) * 5.0f + -5.0f) * 20.0f;
                    w->unk_14 = func_800AEAC0(w->unk_44 * 2) * 5.0f * 20.0f;
                    if (w->unk_44 >= 90) {
                        func_80010ED4(GwPlayer[p->unk_58].character + 0x12E, 0);
                        func_800184BC(obj, 0xB);
                        w->unk_40 = 5;
                        w->unk_44 = 0;
                    }
                    break;
                case 5:
                    p->unk_3C += 1.0f;
                    if ((obj->rot.y -= 1.0f) == 10.0) {
                        func_800674BC((s16)D_800FFA1C_SlotMachine, 1, 0x8000);
                        func_800674BC((s16)D_800FFA2C_SlotMachine, 0, 0x8000);
                        func_800674BC((s16)D_800FFA2C_SlotMachine, 1, 0x8000);
                    }
                    if (obj->rot.y <= 0.0) {
                        func_800184BC(obj, 0);
                        w->unk_08 = 1;
                        w->unk_40 = 0;
                        w->unk_44 = 0;
                        func_800258EC(D_800FFA22_SlotMachine, 4, 0);
                        D_800FEC7C_SlotMachine = 300;
                        D_800FEC80_SlotMachine = 8;
                        omSysPauseEnableFlag = 0;
                        p->unk_3C = 0.0f;
                    }
                    break;
            }
            break;
        case 1:
            w->unk_1C = obj->trans.x;
            w->unk_20 = obj->trans.y;
            if (GwPlayer[p->unk_58].flags & 1) {
                ContStkY[(s8)port] = 0;
                ContStkX[(s8)port] = 0;
                ContBtnTrg[(s8)port] = 0;
                ContBtn[(s8)port] = 0;
                if (stat & 2) {
                    switch (w->unk_40) {
                        case 0:
                            if (w->unk_42 == 0) {
                                ContBtn[(s8)port] = ContBtnTrg[(s8)port] |= 0x8000;
                                w->unk_40++;
                            } else if (D_800FFA28_SlotMachine == 2 && !(func_800FC050_SlotMachine() & 0x1F)) {
                                ContBtn[(s8)port] = ContBtnTrg[(s8)port] |= 0x8000;
                                w->unk_40++;
                            } else {
                                w->unk_42--;
                            }
                            break;
                        case 1:
                            w->unk_42 = func_800FC684_SlotMachine();
                            if (w->unk_42 != 0) {
                                w->unk_40++;
                                r = rand8() % (12 - D_800FFA0C_SlotMachine * 2) - 6;
                                w->unk_42 += r + (s16)D_800FFA0C_SlotMachine;
                            }
                            break;
                        case 2:
                            if (w->unk_42 < 7) {
                                ContBtn[(s8)port] = ContBtnTrg[(s8)port] |= 0x8000;
                                w->unk_40++;
                                w->unk_42 = 0;
                            } else {
                                w->unk_42--;
                            }
                            break;
                        case 3:
                            w->unk_42 = func_800FC684_SlotMachine();
                            if (w->unk_42 != 0) {
                                w->unk_40++;
                                r = rand8() % (24 - D_800FFA0C_SlotMachine * 2) - 12;
                                w->unk_42 += r + (s16)D_800FFA0C_SlotMachine;
                            }
                            break;
                        case 4:
                            if (w->unk_42 < 7) {
                                ContBtn[(s8)port] = ContBtnTrg[(s8)port] |= 0x8000;
                                w->unk_40++;
                                w->unk_42 = 20;
                            } else {
                                w->unk_42--;
                            }
                            break;
                        case 5:
                            if (w->unk_42 == 0) {
                                w->unk_40++;
                            }
                            w->unk_42--;
                            break;
                        case 6:
                            if (D_800FEC80_SlotMachine != 12) {
                                ContStkX[(s8)port] = -60;
                                if (obj->trans.x <= -230.0) {
                                    w->unk_40++;
                                }
                            }
                            break;
                    }
                } else {
                    switch (w->unk_40) {
                        case 6:
                            if (D_800FEC80_SlotMachine != 12) {
                                ContStkX[(s8)port] = -60;
                                if (obj->trans.x <= -230.0) {
                                    w->unk_40++;
                                }
                            }
                            break;
                        case 7:
                            if (D_800FEC80_SlotMachine != 12) {
                                ContStkX[(s8)port] = 60;
                                if (obj->trans.x >= 230.0) {
                                    w->unk_40--;
                                }
                            }
                            break;
                    }
                }
            }
            if (D_800FEC80_SlotMachine == 12) {
                ContBtn[(s8)port] &= 0x7FFF;
                ContBtnTrg[(s8)port] &= 0x7FFF;
            }
            func_80005A28(obj);
            obj->trans.z = 0.0f;
            if (fabs(obj->trans.x) > 245.0) {
                obj->trans.x = w->unk_1C;
            }
            w->unk_10 = obj->trans.x;
            w->unk_14 = obj->trans.y;
            w->unk_18 = obj->trans.z;
            if (stat & 0x120) {
                if (fabs(w->unk_10) < 60.0 && fabs(w->unk_18) < 60.0) {
                    if (w->unk_14 + p->unk_34 >= 280.0 && w->unk_14 + p->unk_34 <= 340.0 && p->unk_38 < 0.0) {
                        D_800FEC88_SlotMachine = 1;
                        p->unk_38 = 0.0f;
                        func_80060540(0x194, 0);
                    } else if (w->unk_14 + p->unk_34 >= 290.0) {
                        w->unk_10 = w->unk_1C;
                    }
                }
            } else if (obj->trans.y <= 10.0 && D_800FEC80_SlotMachine == 12) {
                func_8009ECB0(D_800F2B7C[*obj->model].unk7C, 0.0f, 0.0f, 0.0f);
                obj->trans.y = 0.0f;
                w->unk_08 = 2;
            }
            break;
        case 2:
            w->unk_1C = w->unk_10;
            w->unk_20 = w->unk_14;
            func_800184BC(obj, 1);
            if (w->unk_10 >= 0.0f) {
                w->unk_10 -= 8.0;
                p->unk_3C = 90.0f;
                obj->rot.x = 0.0f;
                obj->rot.y = 270.0f;
                obj->rot.z = 0.0f;
            } else {
                w->unk_10 += 8.0;
                p->unk_3C = -90.0f;
                obj->rot.x = 0.0f;
                obj->rot.y = 90.0f;
                obj->rot.z = 0.0f;
            }
            if (w->unk_1C * w->unk_10 <= 0.0f) {
                func_800184BC(obj, 0);
                w->unk_10 = 0.0f;
                D_800FEC80_SlotMachine = 13;
                p->unk_3C = 0.0f;
                obj->rot.x = 0.0f;
                obj->rot.y = 0.0f;
                obj->rot.z = 0.0f;
                w->unk_08++;
            }
            break;
    }
    obj->trans.x = w->unk_10;
    obj->trans.y = w->unk_14;
    obj->trans.z = w->unk_18;
    s = w->unk_14 / 20.0f;
    if (s > 0.0) {
        sc = 1.0 - s * 0.025;
    } else {
        sc = 1.0f;
    }
    func_80025830(obj->model[1], sc, 1.0f, sc);
    func_80025798(obj->model[1], obj->trans.x, 4.0f, obj->trans.z);
    func_800F91C4_SlotMachine(w->unk_08, w->unk_40, w->unk_10, w->unk_14, w->unk_18);
    if (w->unk_08 != 1) {
        func_80017DB0(obj);
    }
}
// load scheduling: the frame table's base is loaded before the index product, twice (masked 4)
#ifdef NON_MATCHING
void func_800FBD60_SlotMachine(void) {
    s32 i;
    unk65770Obj* spr;
    unk65770Obj* spr2;
    unk65770Anim* anim;

    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_800FFA3C_SlotMachine[i]);
        HuMemDirectFree(D_800FFA48_SlotMachine[i]);
        if (D_800FEC80_SlotMachine < 3) {
            HuMemDirectFree(D_800FFA54_SlotMachine[i]);
        }
    }
    HuMemDirectFree(D_800FFA10_SlotMachine);
    spr = func_800675F4((s16)D_800FFCC0_SlotMachine, 0);
    anim = spr->unk4C;
    anim->unk0[spr->unk52].unk0 = D_800FFA14_SlotMachine;
    spr2 = func_800675F4((s16)D_800FFA30_SlotMachine, 0);
    anim = spr2->unk4C;
    anim->unk0[spr2->unk52].unk0 = D_800FFA18_SlotMachine;
    func_800FBF6C_SlotMachine();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E13F0", func_800FBD60_SlotMachine);
#endif
SlotWork* func_800FBE84_SlotMachine(omObjData* obj) {
    SlotWork* w;

    w = HuMemDirectMalloc(sizeof(SlotWork));
    D_800FFCC8_SlotMachine[D_800FEC78_SlotMachine++] = w;
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
    w->unk_00 = 0;
    w->unk_02 = 0;
    w->unk_08 = 0;
    w->unk_0C = obj;
    w->unk_10 = w->unk_14 = w->unk_18 = 0.0f;
    w->unk_1C = w->unk_20 = w->unk_24 = 0.0f;
    w->unk_28 = w->unk_2C = w->unk_30 = 0.0f;
    w->unk_40 = w->unk_42 = w->unk_44 = w->unk_46 = 0;
    w->unk_48 = w->unk_4A = w->unk_4C = w->unk_4E = 0;
    w->unk_50 = w->unk_52 = w->unk_54 = w->unk_56 = 0;
    w->unk_58 = w->unk_5A = w->unk_5C = w->unk_5E = 0;
    return w;
}
void func_800FBF6C_SlotMachine(void) {
    s16 i;

    for (i = 0; i < D_800FEC78_SlotMachine; i++) {
        if (D_800FFCC8_SlotMachine[i] != NULL) {
            HuMemDirectFree(D_800FFCC8_SlotMachine[i]);
        }
    }
}
SlotWork* func_800FBFEC_SlotMachine(omObjData* obj) {
    return (SlotWork*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}
void func_800FC018_SlotMachine(void) {
    D_800FECCC_SlotMachine *= rand8();
}
s32 func_800FC050_SlotMachine(void) {
    D_800FECCC_SlotMachine = D_800FECCC_SlotMachine * 0x41C64E6D + 0x3039;
    return (D_800FECCC_SlotMachine >> 16) + ((D_800FECCC_SlotMachine << 16) >> 31);
}