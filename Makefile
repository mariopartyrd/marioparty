### Build Options ###

BASEROM      := baserom.us.z64
TARGET       := marioparty
COMPARE      ?= 1
NON_MATCHING ?= 0
CHECK        ?= 1
VERBOSE      ?= 0

# Patches
# PATCHES_ASFLAGS := --defsym MP_SAVETYPE_PATCH=1

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif

ifeq ($(VERBOSE),0)
V := @
endif

ifeq ($(OS),Windows_NT)
  DETECTED_OS=windows
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS=linux
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS=macos
    MAKE=gmake
    CPPFLAGS += -xc++
  endif
endif


### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET).z64
ELF       := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP    := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON     := venv/bin/python3  # Ensure we're using the Python from the virtual environment
N64CKSUM   := $(PYTHON) tools/n64cksum.py
SPLAT_YAML := marioparty.yaml
SPLAT      := $(PYTHON) -m splat split $(SPLAT_YAML)  # Use splat from the virtual environment
EMULATOR   := mupen64plus
DIFF       := diff

CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip

CC       := tools/gcc_2.7.2/$(DETECTED_OS)/gcc
CC_HOST  := gcc
CPP      := cpp -P

PRINT := printf '
 ENDCOLOR := \033[0m
 WHITE     := \033[0m
 ENDWHITE  := $(ENDCOLOR)
 GREEN     := \033[0;32m
 ENDGREEN  := $(ENDCOLOR)
 BLUE      := \033[0;34m
 ENDBLUE   := $(ENDCOLOR)
 YELLOW    := \033[0;33m
 ENDYELLOW := $(ENDCOLOR)
 PURPLE    := \033[0;35m
 ENDPURPLE := $(ENDCOLOR)
ENDLINE := \n'

### Compiler Options ###

ASFLAGS        := -G 0 -I include -mips3 -mabi=32
VR4300MULFlag := -Wa,--vr4300mul-off
CFLAGS         := -G0 -mips3 -mgp32 -mfp32 $(VR4300MULFlag) -D_LANGUAGE_C
CPPFLAGS     := -I include -I $(BUILD_DIR)/include -I src -DF3DEX_GBI_2 -D_LANGUAGE_C
LDFLAGS        := -T undefined_syms.txt -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections
CHECK_WARNINGS := -Wall -Wextra -Wunused-but-set-variable -Wno-format-security -Wno-unused-parameter -Wno-sign-compare -Wno-unused-variable -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -m32
CFLAGS_CHECK   := -fsyntax-only -fsigned-char -nostdinc -fno-builtin -D CC_CHECK -D _LANGUAGE_C -std=gnu90 $(CHECK_WARNINGS)

ifneq ($(CHECK),1)
CFLAGS_CHECK += -w
endif

OPTFLAGS := -O1

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'build.+\.o' marioparty.ld -o)
DEPENDS := $(OBJECTS:=.d) 

### Targets ###

#leave the mul fix on
# ovl_32 TugOWar: mul fix on (nop between mul.s in func_800FB7AC); own line
build/src/overlays/ovl_32_TugOWar/%.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_1F TightropeTreachery: mul fix on (nop between mul.s in func_800F8DA4); own line
build/src/overlays/ovl_1F_TightropeTreachery/%.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_04 F2800.c (Treasure Divers): nop between back-to-back mul.s (func_800FB79C)
build/src/overlays/ovl_04_TreasureDivers/F2800.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_04 F4420.c too: nop before a mult (func_800FCA70)
build/src/overlays/ovl_04_TreasureDivers/F4420.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_23_CraneGame/%.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_10 137050.c (Bash 'n' Cash): mul fix on (nop between mul.s in func_800FB940); own line
build/src/overlays/ovl_10_BashNCash/137050.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_05 F6AB0.c (Shell Game): mul fix on (nop between mul.s in func_800F7410); own line
build/src/overlays/ovl_05_ShellGame/F6AB0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_0B 11C810.c (Musical Mushroom): nop between back-to-back mul.s (func_800F7D1C)
build/src/overlays/ovl_0B_MusicalMushroom/11C810.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_2E 207040.c (Hot Rope Jump): mul fix on (nop between mul.s in func_800F8A14); own line
build/src/overlays/ovl_2E_HotRopeJump/207040.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_30 218510.c (Deep Sea Divers): mul fix on (nop between mul.d in func_800FD8C8); own line
build/src/overlays/ovl_30_DeepSeaDivers/218510.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_15 152BE0.c (Coin Block Bash): mul fix on (nop between mul.s in func_800F7148); own line
build/src/overlays/ovl_15_CoinBlockBash/152BE0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_15 15AC50.c (Coin Block Bash, blocks/billboards): mul fix on (nop between mul.d in func_800FEE90); own line
build/src/overlays/ovl_15_CoinBlockBash/15AC50.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_06 103D80.c: nop between mul.s (func_800FC29C)
build/src/overlays/ovl_06_UnusedMinigame0/103D80.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_1D 188410.c (Bobsled Run): mul fix on (nop between mul.s in func_800F6DB8); own line
build/src/overlays/ovl_1D_BobsledRun/188410.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_13 149E80.c (Balloon Burst) also has the mul fix on: nop between back-to-back mul.s (func_800F9368)
build/src/overlays/ovl_13_BalloonBurst/149E80.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_1C 184870.c: nop between back-to-back mul.s in func_800F97E8
build/src/overlays/ovl_1C_GrabBag/184870.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_1C 1837D0.c: nop between back-to-back mul.s in func_800F6E90
build/src/overlays/ovl_1C_GrabBag/1837D0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_25 SlotCarDerby too: nop between back-to-back mul.s (func_800F9B60)
build/src/overlays/ovl_25_SlotCarDerby/%.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_61 29B410.c (opening scene) also has the mul fix on: nop between back-to-back mul.s (func_800F86D0, func_800FB670)
build/src/overlays/ovl_61_OpeningScene/29B410.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_41 2721F0.c (story ending, Yoshi scene): nop between dependent mul.s (func_80109294)
build/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_0A 117210.c (Ghost Guess): mul fix on, nop between back-to-back mul.s (func_800F7FD8)
build/src/overlays/ovl_0A_GhostGuess/117210.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_20 19FEE0.c (KnockBlockTower): nop between back-to-back mul.s in func_800F7D0C
build/src/overlays/ovl_20_KnockBlockTower/19FEE0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 69010.c (sprite draw) was built with the assembler VR4300 mul fix on: a nop after each mul.s pair
build/src/69010.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 24740.c (model entries) also has the mul fix on: nop between dependent mul.s (func_80027100)
build/src/24740.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 34D80.c (model animation keyframes) also has the mul fix on: nop between back-to-back mul.s (func_80035824)
build/src/34D80.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 3DEB0.c (vector rotation) also has the mul fix on: nop between back-to-back mul.s (func_8003D64C)
build/src/3DEB0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 59E80.c (save data, menus, camera) also has the mul fix on: nop between back-to-back mul.s (func_80059EBC)
build/src/59E80.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_62 2A2500.c (board intro) also has the mul fix on: nop between cvt.d.s and mul.d (func_800F6854)
build/src/overlays/ovl_62_BoardIntro/2A2500.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_47 285230.c also has the mul fix on: nop before a mult at a loop head (func_800F6924)
build/src/overlays/ovl_47/285230.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 29C90.c (collision grid) also has the mul fix on: nop before a mult at a loop head (func_80029174)
build/src/29C90.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_6F 2DB2D0.c (minigame instructions) also has the mul fix on: nop between back-to-back mul.s (func_800F785C, func_800F94E8)
build/src/overlays/ovl_6F_MinigameInstructions/2DB2D0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_6F 2DF200.c and 2E8220.c also have the mul fix on: nop between back-to-back mul.s (func_800FADF4, func_801077C8)
build/src/overlays/ovl_6F_MinigameInstructions/2DF200.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_6F_MinigameInstructions/2E8220.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_2C 1F62C0.c (Key-pa-Way) also has the mul fix on: nop between dependent mul.s (func_800FDA7C)
build/src/overlays/ovl_2C_KeyPaWay/1F62C0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_02 E5DA0.c (slot machine reels/effects) also has the mul fix on: nop before a mult at a loop head (func_800FD590)
build/src/overlays/ovl_02_SlotMachine/E5DA0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_0F 131FA0.c (Whack-a-Plant) also has the mul fix on: nop between back-to-back mul.s (func_800FAF34)
build/src/overlays/ovl_0F_WhackAPlant/131FA0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_02 E13F0.c also has the mul fix on: nop between back-to-back mul.s (func_800FAE34)
build/src/overlays/ovl_02_SlotMachine/E13F0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 26E620.c (ovl_41, story ending) was built with the VR4300 mul fix on (nop between mul.s in func_8010725C)
build/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C

#build/src/libultra/os/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
#build/src/libultra/libc/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
#build/src/lib/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)

all: $(ROM)

-include $(DEPENDS)

clean:
	$(V)rm -rf build

distclean: clean
	$(V)rm -rf asm
	$(V)rm -rf assets
	$(V)rm -f *auto.txt
	$(V)rm -f marioparty.ld
	$(V)rm -f include/ld_addrs.h

setup: distclean split

split:
	$(V)$(SPLAT)

test: $(ROM)
	$(V)$(EMULATOR) $<

# Flags for individual files. TODO: move these to a common directory and make this a directory thing instead
build/src/lib/%.c.o: OPTFLAGS = -O3 -funsigned-char
build/src/lib/%.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
build/src/lib/%.c.o: CPPFLAGS = -I include -I include/PR -I include/gcc -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2

# Special flags since these functions have a mono sound patch.
build/src/lib/2.0I/audio/synsetpan.c.o: OPTFLAGS = -O0
build/src/lib/2.0I/audio/synstartvoiceparam.c.o: OPTFLAGS = -O0

# 64FD0.c is libultra's audio/sndplayer.c (alSndpNew and its static helpers): it includes the lib audio headers
build/src/64FD0.c.o: CPPFLAGS = -I include -I include/PR -I include/gcc -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2

# ovl_01 D51E0.c (Chance Time) also has the mul fix on: nop between back-to-back mul.s (func_800F8288)
build/src/overlays/ovl_01_ChanceTime/D51E0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_41 266C80.c (story ending scene) also has the mul fix on: nop between back-to-back mul.s (func_800FD60C)
build/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/engine/math.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_63 2A9CA0.c (staff credits) also has the mul fix on: nop between back-to-back mul.s (func_800F9F70)
build/src/overlays/ovl_63_StaffScene/2A9CA0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_0D 1250D0.c (Crazy Cutter): nop between back-to-back mul.s (func_800FAB0C), nop before mult
build/src/overlays/ovl_0D_CrazyCutter/1250D0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_09 113DC0.c (Pipe Maze) also has the mul fix on: nop between back-to-back mul.s (func_800F6DD8)
build/src/overlays/ovl_09_PipeMaze/113DC0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_1B 17E710.c (Hammer Drop): nop between back-to-back mul.s and before mult (func_800FA1AC, twin of func_800FAB0C)
build/src/overlays/ovl_1B_HammerDrop/17E710.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C

# mul nops included in the following *.c (Maybe only one func uses --vr4300mul-off)
build/src/3AC60.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/48D90.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/B980.c.o:  CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/6D4E0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/156F0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/1130.c.o:  CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/1A2A0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/6C470.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/23C40.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# 72D90.c (window/message code): mul fix on, nop between mul.s in func_80073560 and func_80078B6C
build/src/72D90.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/1B800.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/2C0C0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/99E0.c.o:  CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_7C_UnknownResultsScreen/308A50.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_7D 30C540.c (func_800F8898: nop before mult) has the mul fix on
build/src/overlays/ovl_7D_MinigameIslandMISS/30C540.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_14_CoinBlockBlitz/14E940.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_03 E8F60.c (nop before mult, func_800F7164) and EB0E0.c (func_800F8D1C, func_800FA90C) have the mul fix on
build/src/overlays/ovl_03_BuriedTreasure/E8F60.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_03_BuriedTreasure/EB0E0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_41 262590.c (func_800F8FE8: nop between back-to-back mul.s) has the mul fix on
build/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/262590.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_17_BoxMountainMayhem/166D50.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_17_BoxMountainMayhem/168CA0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_40 259EB0.c: nop before mult at func_800FA61C's roulette loop head
build/src/overlays/ovl_40_ResultsScene/259EB0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_64 2B1670.c: ovl_40 twin (same mul-fix nop)
build/src/overlays/ovl_64_ResultsEternalStar2/2B1670.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_31 225DF0.c: nop between mul.s in func_800FF35C (mul fix on)
build/src/overlays/ovl_31_PiranhasPursuit/225DF0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_70 2F40C0.c: nop between mul.s in func_800F846C (mul fix on)
build/src/overlays/ovl_70_TestingRoom/2F40C0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_06 105EA0.c: nop between back-to-back mul.d in func_800FFA64 (mul fix on)
build/src/overlays/ovl_06_UnusedMinigame0/105EA0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_00 CDA50.c: nop between mul.d in func_800F9178 (mul fix on)
build/src/overlays/ovl_00_MemoryMatch/CDA50.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_00 D27D0.c: nop between mul.s in func_800FD6A0 (mul fix on)
build/src/overlays/ovl_00_MemoryMatch/D27D0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_2D 1FF1E0.c: nop between mul.s in func_800F7A0C
build/src/overlays/ovl_2D_RunningOfTheBulb/1FF1E0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_22 1AA2A0.c: nop between mul.s in func_800FA4B4 (mul fix on; blank-line strip rule below too)
build/src/overlays/ovl_22_BombsAway/1AA2A0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_2A 1E9440.c: nop between back-to-back mul.s in func_800F85C0 (mul fix on; blank-line strip rule below too)
build/src/overlays/ovl_2A/1E9440.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_16 15EAF0.c: nop between mul.s in func_800F7758 (mul fix on; blank-line strip rule below too)
build/src/overlays/ovl_16_SkateBoardSkamper/15EAF0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_24 1BD640.c: nop between back-to-back mul.s in func_800FA2B0
build/src/overlays/ovl_24_FlowerShower/1BD640.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_41 26BA10.c and 2643A0.c: nop between mul.s in func_80102380, func_800FB1E4
build/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/26BA10.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/2643A0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_12 146B60.c: nop between mul.s in func_800F7560, func_800F7844
build/src/overlays/ovl_12_GroundPound/146B60.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_12 148840.c: nop between mul.s in func_800F9314, func_800F9A24
build/src/overlays/ovl_12_GroundPound/148840.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_19 176130.c: nop between mul.s in func_800F99F4
build/src/overlays/ovl_19_TeeteringTowers/176130.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_0E 12BC20.c: nop between mul.s in func_800F7444_FaceLift
build/src/overlays/ovl_0E_FaceLift/12BC20.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_28 1D9690.c: nop between mul.s in func_800F9F60 and func_800F7720 (mul fix on)
build/src/overlays/ovl_28_ShyGuySays/1D9690.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_11 13EFB0.c and 142EA0.c (Bowl Over): nop between mul.s (func_800F9DB4, func_800FAC94)
build/src/overlays/ovl_11_BowlOver/13EFB0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_11_BowlOver/142EA0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_6B 2CAA00.c: nop between mul.s in func_800F7274 (mul fix on)
# ovl_33 234F80.c: nop between back-to-back mul.s in func_800FAFEC_PaddleBattle (mul fix on)
build/src/overlays/ovl_33_PaddleBattle/234F80.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_6B_MinigameHouse/2CAA00.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_1E 191700.c: nop between mul.s in func_800F74E8 (mul fix on)
build/src/overlays/ovl_1E_BumperBalls/191700.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C

# -O3 static inlines
build/src/7CD60.c.o: OPTFLAGS = -O3

build/src/9CE40.c.o: OPTFLAGS = -O0
# SDK pass (sdk-hu1): Hudson -O0 gu/vector math
build/src/9CCA0.c.o: OPTFLAGS = -O0
build/src/9CD00.c.o: OPTFLAGS = -O0
build/src/9CD60.c.o: OPTFLAGS = -O0
build/src/9D2E0.c.o: OPTFLAGS = -O0
build/src/9D920.c.o: OPTFLAGS = -O0
build/src/9E440.c.o: OPTFLAGS = -O0
build/src/9E6D0.c.o: OPTFLAGS = -O0
build/src/9E910.c.o: OPTFLAGS = -O0
build/src/9EBF0.c.o: OPTFLAGS = -O0
build/src/A0E70.c.o: OPTFLAGS = -O0
build/src/9E520.c.o: OPTFLAGS = -O0
build/src/9E750.c.o: OPTFLAGS = -O0
build/src/9E990.c.o: OPTFLAGS = -O0
build/src/9D370.c.o: OPTFLAGS = -O0
build/src/9D9B0.c.o: OPTFLAGS = -O0
build/src/9F3E0.c.o: OPTFLAGS = -O0
build/src/9F4F0.c.o: OPTFLAGS = -O0
build/src/9FED0.c.o: OPTFLAGS = -O0
build/src/A0130.c.o: OPTFLAGS = -O0
build/src/A05B0.c.o: OPTFLAGS = -O0
build/src/A0940.c.o: OPTFLAGS = -O0
build/src/A0FB0.c.o: OPTFLAGS = -O0
build/src/9EF60.c.o: OPTFLAGS = -O0
build/src/9F750.c.o: OPTFLAGS = -O0
build/src/A1620.c.o: OPTFLAGS = -O0
build/src/A19A0.c.o: OPTFLAGS = -O0
build/src/A1A80.c.o: OPTFLAGS = -O0
build/src/A1B00.c.o: OPTFLAGS = -O0
build/src/A1E50.c.o: OPTFLAGS = -O0
build/src/A4CD0.c.o: OPTFLAGS = -O0
build/src/9EC60.c.o: OPTFLAGS = -O0
build/src/ABCD0.c.o: OPTFLAGS = -O0
build/src/ACA90.c.o: OPTFLAGS = -O0
build/src/ACCB0.c.o: OPTFLAGS = -O0
build/src/ACF80.c.o: OPTFLAGS = -O0
build/src/AD380.c.o: OPTFLAGS = -O0
build/src/AD740.c.o: OPTFLAGS = -O0
build/src/ADA70.c.o: OPTFLAGS = -O0
build/src/ADBD0.c.o: OPTFLAGS = -O0
build/src/ADF70.c.o: OPTFLAGS = -O0
build/src/AE150.c.o: OPTFLAGS = -O0
build/src/AE630.c.o: OPTFLAGS = -O0
build/src/AE820.c.o: OPTFLAGS = -O0
build/src/AED10.c.o: OPTFLAGS = -O0
build/src/AEF30.c.o: OPTFLAGS = -O0
build/src/AF450.c.o: OPTFLAGS = -O0
build/src/AF6C0.c.o: OPTFLAGS = -O0
build/src/AF960.c.o: OPTFLAGS = -O0
build/src/AFBD0.c.o: OPTFLAGS = -O0
build/src/AFE60.c.o: OPTFLAGS = -O0
build/src/AFF70.c.o: OPTFLAGS = -O0
build/src/B07B0.c.o: OPTFLAGS = -O0
build/src/B0BA0.c.o: OPTFLAGS = -O0
build/src/B0FC0.c.o: OPTFLAGS = -O0
build/src/B1930.c.o: OPTFLAGS = -O0
build/src/B1B60.c.o: OPTFLAGS = -O0
build/src/B1DC0.c.o: OPTFLAGS = -O0
build/src/B1FD0.c.o: OPTFLAGS = -O0
build/src/B22E0.c.o: OPTFLAGS = -O0
build/src/B2310.c.o: OPTFLAGS = -O0
build/src/89EA0.c.o: OPTFLAGS = -O0
build/src/A2080.c.o: OPTFLAGS = -O0
build/src/A21C0.c.o: OPTFLAGS = -O0
build/src/A3370.c.o: OPTFLAGS = -O0
# sdk-hu3 (Hudson -O0 matrix/vector math, A7380..AD210)
build/src/A7380.c.o: OPTFLAGS = -O0
build/src/A7C30.c.o: OPTFLAGS = -O0
build/src/A8190.c.o: OPTFLAGS = -O0
build/src/A8450.c.o: OPTFLAGS = -O0
build/src/A8D50.c.o: OPTFLAGS = -O0
build/src/A9C10.c.o: OPTFLAGS = -O0
build/src/AA510.c.o: OPTFLAGS = -O0
build/src/AA7F0.c.o: OPTFLAGS = -O0
build/src/AB3D0.c.o: OPTFLAGS = -O0
build/src/ABFB0.c.o: OPTFLAGS = -O0
build/src/ACA30.c.o: OPTFLAGS = -O0
build/src/ACC50.c.o: OPTFLAGS = -O0
build/src/ACF10.c.o: OPTFLAGS = -O0
build/src/AD210.c.o: OPTFLAGS = -O0
build/src/A27D0.c.o: OPTFLAGS = -O0
# sdk-hu2 (2026-10-15): Hudson -O0 math units A1330-A7090
build/src/A1330.c.o: OPTFLAGS = -O0
build/src/A1490.c.o: OPTFLAGS = -O0
build/src/A1500.c.o: OPTFLAGS = -O0
build/src/A1570.c.o: OPTFLAGS = -O0
build/src/A15D0.c.o: OPTFLAGS = -O0
build/src/A1C10.c.o: OPTFLAGS = -O0
build/src/A2260.c.o: OPTFLAGS = -O0
build/src/A23A0.c.o: OPTFLAGS = -O0
build/src/A24F0.c.o: OPTFLAGS = -O0
build/src/A29F0.c.o: OPTFLAGS = -O0
build/src/A2A40.c.o: OPTFLAGS = -O0
build/src/A2A90.c.o: OPTFLAGS = -O0
build/src/A2AF0.c.o: OPTFLAGS = -O0
build/src/A2E80.c.o: OPTFLAGS = -O0
build/src/A2EE0.c.o: OPTFLAGS = -O0
build/src/A30C0.c.o: OPTFLAGS = -O0
build/src/A3110.c.o: OPTFLAGS = -O0
build/src/A3320.c.o: OPTFLAGS = -O0
build/src/A3600.c.o: OPTFLAGS = -O0
build/src/A3650.c.o: OPTFLAGS = -O0
build/src/A3B10.c.o: OPTFLAGS = -O0
build/src/A3FB0.c.o: OPTFLAGS = -O0
build/src/A42C0.c.o: OPTFLAGS = -O0
build/src/A4770.c.o: OPTFLAGS = -O0
build/src/A4B40.c.o: OPTFLAGS = -O0
build/src/A50B0.c.o: OPTFLAGS = -O0
build/src/A5250.c.o: OPTFLAGS = -O0
build/src/A5370.c.o: OPTFLAGS = -O0
build/src/A5620.c.o: OPTFLAGS = -O0
build/src/A57B0.c.o: OPTFLAGS = -O0
build/src/A58C0.c.o: OPTFLAGS = -O0
build/src/A5A20.c.o: OPTFLAGS = -O0
build/src/A5B30.c.o: OPTFLAGS = -O0
build/src/A5CA0.c.o: OPTFLAGS = -O0
build/src/A5EC0.c.o: OPTFLAGS = -O0
build/src/A62D0.c.o: OPTFLAGS = -O0
build/src/A6930.c.o: OPTFLAGS = -O0
build/src/A6BD0.c.o: OPTFLAGS = -O0
build/src/A7090.c.o: OPTFLAGS = -O0
build/src/AD5D0.c.o: OPTFLAGS = -O0
build/src/AD940.c.o: OPTFLAGS = -O0
build/src/A1D90.c.o: OPTFLAGS = -O0
# ovl_21 1A4EB0.c: nop between back-to-back mul.s in func_800F8D2C, func_800F8FE0
build/src/overlays/ovl_21_TipsyTourney/1A4EB0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_18 PlatformPeril 170470.c, 16C6A0.c: nop between back-to-back mul.s (func_800FB680; func_800F7070, func_800F8220, func_800F979C)
build/src/overlays/ovl_18_PlatformPeril/170470.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/overlays/ovl_18_PlatformPeril/16C6A0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# ovl_27 1D6E30.c (DesertDash): nop between back-to-back mul.s in func_800FB750
build/src/overlays/ovl_27_DesertDash/1D6E30.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
build/src/A1E00.c.o: OPTFLAGS = -O0
build/src/95F40.c.o: OPTFLAGS = -O2 -funsigned-char

# sdk-lib: libultra units in the main region (0x95BF0-0x9AD00) build like src/lib (-O3, unsigned char, lib headers)
SDK_LIB_UNITS := build/src/95BF0.c.o build/src/95C00.c.o build/src/95CA0.c.o build/src/95CC0.c.o build/src/95CE0.c.o build/src/95E40.c.o build/src/95E50.c.o build/src/96AA0.c.o build/src/972D0.c.o build/src/98B20.c.o build/src/99680.c.o build/src/99880.c.o build/src/99AA0.c.o build/src/99B90.c.o build/src/99F50.c.o build/src/9A0C0.c.o build/src/9A230.c.o build/src/9AB60.c.o build/src/9ABB0.c.o build/src/9AC00.c.o build/src/9AC50.c.o build/src/9ACE0.c.o build/src/9AD00.c.o build/src/9AD20.c.o
$(SDK_LIB_UNITS): OPTFLAGS = -O3 -funsigned-char
$(SDK_LIB_UNITS): CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
$(SDK_LIB_UNITS): CPPFLAGS = -I include -I include/PR -I include/gcc -I $(BUILD_DIR)/include -I src -I src/lib/2.0I/audio -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2
# 95F40.c (xprintf) keeps its -O2 but takes the lib defines (size_t needs _MIPS_SZLONG)
build/src/95F40.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
build/src/95F40.c.o: CPPFLAGS = -I include -I include/PR -I include/gcc -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2
build/src/9AF70.c.o: OPTFLAGS = -O3 -funsigned-char
build/src/9B9F0.c.o: OPTFLAGS = -O3 -funsigned-char
# 9C190.c (KMC libm fmod): nop between the call's div.d delay slot and mul.d (mul fix on)
build/src/9C190.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C

# Compile .c files with kmc gcc (use strip to fix objects so that they can be linked with modern gnu ld) 
$(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_28 1D9690.c: blank-line strip as for 1130.c (func_800F9F60: mul.s right after func_800AEFD0's return).
$(BUILD_DIR)/src/overlays/ovl_28_ShyGuySays/1D9690.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# 1130.c is assembled with the KMC vr4300 mul fix on (no --vr4300mul-off, see CFLAGS above) from
# GCC's assembly with blank lines removed: KMC as adds a nop before a mul.s that follows a call when
# GCC's blank line separates it from the call's `.set reorder`, and the original object has none there.
# 34D80.c needs the same (func_80036B00: mul.s right after a call's return); 1B800.c too
# (func_8001C9F4: a nop before the mul.s after a branch-likely store).
# 34D80.c needs the same (func_80036B00: mul.s right after a call's return).
# 3DEB0.c too (func_8003D8CC: mul.s right after a call's return).
# 59E80.c too (func_80059EBC: mul.s right after a call's return).
# ovl_61 29B410.c too (func_800F7E50, func_800FB670: mul.s right after a call's return).
# ovl_62 2A2500.c too (func_800F6854: mul.s right after sinf's return).
# ovl_6F 2DB2D0.c too (func_800F92D4: mul.s right after sinf/cosf's return); 2DF200.c and 2E8220.c too (func_800FADF4, func_80104988).
# ovl_2C 1F62C0.c too (func_800F7840: mul.s right after func_800AEAC0's return).
# ovl_14 14E940.c too (func_800F7604: mul.s right after func_800AEFD0's return; the unit has the mul fix on for func_800F83A8).
# ovl_03 EB0E0.c too (func_800F8EF0: mul.s right after a branch-likely's delay slot).
# ovl_17 166D50.c and 168CA0.c too (func_800F8400, func_800FA058: mul fix on, mul.s right after func_800AEAC0's return).
# ovl_23 1B3E00.c, 1B9050.c and 1BAA60.c too (func_800F746C: mul fix on, mul.s right after func_800AEAC0's return).
# ovl_25 1C1EB0.c too (mul fix on; kept with its neighbours for mul.s after a call's return).
# ovl_22 1AA2A0.c too (func_800F723C: mul fix on, mul.s right after func_800AEFD0's return).
# ovl_41 262590.c too (mul fix on for func_800F8FE8; mul.s right after sinf/cosf's return elsewhere).
# 72D90.c too (mul fix on; without the strip func_8007420C and func_80079128 gain nops).
# ovl_33 234F80.c too (mul fix on; func_800FDE08_PaddleBattle: mul.s right after a branch-likely).
$(BUILD_DIR)/src/1130.c.o $(BUILD_DIR)/src/engine/math.c.o $(BUILD_DIR)/src/24740.c.o $(BUILD_DIR)/src/B980.c.o $(BUILD_DIR)/src/34D80.c.o $(BUILD_DIR)/src/1B800.c.o $(BUILD_DIR)/src/3DEB0.c.o $(BUILD_DIR)/src/59E80.c.o $(BUILD_DIR)/src/overlays/ovl_61_OpeningScene/29B410.c.o $(BUILD_DIR)/src/overlays/ovl_62_BoardIntro/2A2500.c.o $(BUILD_DIR)/src/overlays/ovl_6F_MinigameInstructions/2DB2D0.c.o $(BUILD_DIR)/src/overlays/ovl_6F_MinigameInstructions/2DF200.c.o $(BUILD_DIR)/src/overlays/ovl_6F_MinigameInstructions/2E8220.c.o $(BUILD_DIR)/src/overlays/ovl_2C_KeyPaWay/1F62C0.c.o $(BUILD_DIR)/src/overlays/ovl_14_CoinBlockBlitz/14E940.c.o $(BUILD_DIR)/src/overlays/ovl_03_BuriedTreasure/EB0E0.c.o $(BUILD_DIR)/src/overlays/ovl_17_BoxMountainMayhem/166D50.c.o $(BUILD_DIR)/src/overlays/ovl_17_BoxMountainMayhem/168CA0.c.o $(BUILD_DIR)/src/overlays/ovl_23_CraneGame/1B3E00.c.o $(BUILD_DIR)/src/overlays/ovl_23_CraneGame/1B9050.c.o $(BUILD_DIR)/src/overlays/ovl_23_CraneGame/1BAA60.c.o $(BUILD_DIR)/src/overlays/ovl_25_SlotCarDerby/1C1EB0.c.o $(BUILD_DIR)/src/overlays/ovl_2D_RunningOfTheBulb/1FF1E0.c.o $(BUILD_DIR)/src/overlays/ovl_22_BombsAway/1AA2A0.c.o $(BUILD_DIR)/src/overlays/ovl_16_SkateBoardSkamper/15EAF0.c.o $(BUILD_DIR)/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/262590.c.o $(BUILD_DIR)/src/overlays/ovl_13_BalloonBurst/149E80.c.o $(BUILD_DIR)/src/overlays/ovl_2A/1E9440.c.o $(BUILD_DIR)/src/72D90.c.o $(BUILD_DIR)/src/overlays/ovl_33_PaddleBattle/234F80.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_0A 117210.c (Ghost Guess): blank-line strip as for 1130.c (func_800F9400: mul.s right after func_800AEAC0's return).
# ovl_20 KnockBlockTower units: mul fix on, blank-line strip (mul.s right after a call's return); own rule.
# ovl_10 137050.c (Bash 'n' Cash) too (mul.s right after func_800AEAC0's return in func_800F8240).
$(BUILD_DIR)/src/overlays/ovl_0A_GhostGuess/117210.c.o $(BUILD_DIR)/src/overlays/ovl_20_KnockBlockTower/19FEE0.c.o $(BUILD_DIR)/src/overlays/ovl_10_BashNCash/137050.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_2E 207040.c (Hot Rope Jump): mul fix on, blank-line strip (mul.s right after sinf's return); own rule.
$(BUILD_DIR)/src/overlays/ovl_2E_HotRopeJump/207040.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_1D 188410.c (Bobsled Run): mul fix on, blank-line strip (mul.s right after a call's return); own rule.
$(BUILD_DIR)/src/overlays/ovl_1D_BobsledRun/188410.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_06 UnusedMinigame0 103D80.c: mul fix on, blank-line strip (mul.s right after a call's return); own rule.
$(BUILD_DIR)/src/overlays/ovl_06_UnusedMinigame0/103D80.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_15 152BE0.c (Coin Block Bash): mul fix on, blank-line strip (mul.s right after a call's return); own rule.
$(BUILD_DIR)/src/overlays/ovl_15_CoinBlockBash/152BE0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_70 2F40C0.c (Testing Room): mul fix on, blank-line strip (mul.s right after a call's return); own rule.
$(BUILD_DIR)/src/overlays/ovl_70_TestingRoom/2F40C0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_11 BowlOver units: mul fix on, blank-line strip (mul.s right after a call's return); own rule.
$(BUILD_DIR)/src/overlays/ovl_11_BowlOver/13EFB0.c.o $(BUILD_DIR)/src/overlays/ovl_11_BowlOver/142EA0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_1F 19ACC0.c: mul fix on (CFLAGS line above), blank lines stripped (mult right after
# guRandom's return in func_800F9FD8); own rule.
$(BUILD_DIR)/src/overlays/ovl_1F_TightropeTreachery/19ACC0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_41 2721F0.c too (func_8010B0E4: mul fix on, mul.s right after sinf/cosf's return); own rule
# so the five ovl_41 branches do not all edit the list above.
$(BUILD_DIR)/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name


# ovl_0B 11C810.c too (func_800F7D1C: mul fix on, mul.s right after func_800AEAC0's return); own rule.
# ovl_0E 12BC20.c: mul fix on, blank lines stripped (mul.s right after sinf/cosf's return in
# func_800F9EE4_FaceLift); own rule so parallel branches do not edit a shared list.
$(BUILD_DIR)/src/overlays/ovl_0B_MusicalMushroom/11C810.c.o $(BUILD_DIR)/src/overlays/ovl_0E_FaceLift/12BC20.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_18 16C6A0.c, 170470.c: mul fix on, blank lines stripped (mul.s right after func_800AEAC0/func_800AEFD0 returns); own rule.
$(BUILD_DIR)/src/overlays/ovl_18_PlatformPeril/16C6A0.c.o $(BUILD_DIR)/src/overlays/ovl_18_PlatformPeril/170470.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_24 1BD640.c: keep the mul-fix nop between adjacent mul.s, but strip blank lines so the
# assembler does not add extra hazard nops after calls.
# ovl_1C 184870.c: mul fix on, with blank lines stripped so mul.s immediately after trig calls
# does not gain an extra nop. Kept separate from the shared target list for branch merges.
$(BUILD_DIR)/src/overlays/ovl_24_FlowerShower/1BD640.c.o $(BUILD_DIR)/src/overlays/ovl_1C_GrabBag/184870.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_00 CDA50.c: mul fix on (CFLAGS line above) with blank lines stripped: mul.s right after
# func_800AEAC0's return in func_800FA400. A separate rule so the shared target list is not edited.
$(BUILD_DIR)/src/overlays/ovl_00_MemoryMatch/CDA50.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_21 1A4EB0.c: the same blank-line-stripped assembly (mul fix on; mul.s right after
# func_800B1750's return in func_800F9C48). A separate rule so the shared target list is not edited.
$(BUILD_DIR)/src/overlays/ovl_21_TipsyTourney/1A4EB0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_1E 191700.c: the same blank-line-stripped assembly (mul fix on; mul.s right after
# func_800B1750's return in func_800FA3A0). A separate rule so the shared target list is not edited.
$(BUILD_DIR)/src/overlays/ovl_1E_BumperBalls/191700.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_6B 2CAA00.c: the same blank-line-stripped assembly (mul fix on; mult right after a call's
# return in func_800F6AD0 has no nop). A separate rule so the shared target list is not edited.
$(BUILD_DIR)/src/overlays/ovl_6B_MinigameHouse/2CAA00.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_63 2A9CA0.c: the same blank-line-stripped assembly (mul fix on; mul.s right after
# func_800AEAC0's return in func_800F758C). A separate rule so the shared target list is not edited.
$(BUILD_DIR)/src/overlays/ovl_63_StaffScene/2A9CA0.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_12 146B60.c: the same blank-line-stripped assembly (mul fix on; mul.s right after
# func_800AEAC0's return in func_800F7180, func_800F796C). A separate rule so the shared list is not edited.
$(BUILD_DIR)/src/overlays/ovl_12_GroundPound/146B60.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_41 26E620.c: the same blank-line-stripped assembly (mul fix on; mul.s right after sinf's return
# in func_80107660). A separate rule so the shared target list above is not edited.
$(BUILD_DIR)/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/26E620.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# ovl_41 266C80.c (func_800FD60C), 2643A0.c (func_800FAD64), 26BA10.c (func_80102380): mul fix on, mul.s
# right after a call's return.
$(BUILD_DIR)/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80.c.o $(BUILD_DIR)/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/2643A0.c.o $(BUILD_DIR)/src/overlays/ovl_41_YoshisTropicalIslandEndingScene/26BA10.c.o: $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name

# Assemble .s files with modern gnu as
$(BUILD_DIR)/asm/%.s.o: asm/%.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@$(PRINT)$(GREEN)objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	@$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final rom
$(ROM): $(BUILD_DIR)/$(TARGET).elf
	@$(PRINT)$(GREEN)Creating z64: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
	$(V)$(N64CKSUM) $@
ifeq ($(COMPARE),1)
	@$(DIFF) $(BASEROM) $(ROM) && printf "OK\n" || (echo 'The build succeeded, but did not match the base ROM. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif

### Make Settings ###

.PHONY: all clean distclean test setup split

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
