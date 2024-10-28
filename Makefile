### Build Options ###

VERSION      ?= us
BASEROM      := baserom.$(VERSION).z64
TARGET       := dukenukemzerohour
COMPARE      ?= 1
NON_MATCHING ?= 0
CHECK        ?= 1
VERBOSE      ?= 0
BUILD_DIR    ?= build/$(VERSION)
EXTERN       ?= 1
MODERN       ?= 0
AVOID_UB     ?= 0

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
override AVOID_UB=1
endif

# MODERN=1 implies COMPARE=0
ifeq ($(MODERN),1)
override COMPARE=0
override CHECK=0
override AVOID_UB=1
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

LIBULTRA_DIR := libs/libultra
LIBKMC_DIR   := libs/libkmc
LIBMUS_DIR   := libs/libmus
VERSION_DIR  := versions/$(VERSION)
LINKER_DIR   := linker_scripts/$(VERSION)
ROM          := $(BUILD_DIR)/$(TARGET).z64
ELF          := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT    := $(TARGET).ld
LD_MAP       := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON     := python3
N64CKSUM   := $(PYTHON) tools/scripts/n64cksum.py
SPLAT_YAML := $(VERSION_DIR)/$(TARGET).yaml
SPLAT      := splat split $(SPLAT_YAML)
DIFF       := diff
EXTRACT	   := $(PYTHON) tools/scripts/extract_assets.py

CROSS    := mips-linux-gnu-
AS       := tools/gcc_2.7.2/$(DETECTED_OS)/as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip
CPP      := $(CROSS)cpp

CC       := export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && tools/gcc_2.7.2/$(DETECTED_OS)/gcc
CC_HOST  := gcc

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

OPTFLAGS       := -O2 -g2
ASFLAGS        := -G0 -mips3 -I include
CFLAGS         := -G0 -mips3 -mgp32 -mfp32 -funsigned-char #-save-temps #-Wa,--vr4300mul-off
CPPFLAGS       := -I include -I gen/$(VERSION) -I $(LIBULTRA_DIR)/include/2.0I -D_LANGUAGE_C -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -D_FINALROM -DTARGET_N64
LDFLAGS        := -T $(VERSION_DIR)/undefined_syms.txt -T $(VERSION_DIR)/undefined_funcs.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections
CHECK_WARNINGS := -Wall -Wextra -Wno-missing-braces -Wno-format-security -Wno-unused-parameter -Wno-unused-variable -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-unused-function
CFLAGS_CHECK   := -m32 -fsyntax-only -funsigned-char -nostdinc -fno-builtin -std=gnu90
CFLAGS_MODERN  := -mabi=32 -march=vr4300 -mfix4300 -mno-abicalls -fno-pic -fno-exceptions -fno-stack-protector -fno-zero-initialized-in-bss -fno-builtin -mno-gpopt -fno-toplevel-reorder -DMODERN

ifeq ($(EXTERN),1)
CPPFLAGS += -DEXTERN_DATA=extern -DEXTERN_BSS=extern -DSTATIC=
else
CPPFLAGS += -DEXTERN_DATA= -DEXTERN_BSS= -D__CTX__ -DSTATIC=
endif

ifeq ($(NON_MATCHING),1)
CPPFLAGS += -DNON_MATCHING
endif

ifeq ($(AVOID_UB),1)
CPPFLAGS += -DAVOID_UB
endif

ifeq ($(VERSION),us)
    CPPFLAGS += -DVERSION_US=1
else ifeq ($(VERSION),fr)
    CPPFLAGS += -DVERSION_FR=1
else ifeq ($(VERSION),eu)
    CPPFLAGS += -DVERSION_EU=1
else ifeq ($(VERSION),proto)
    CPPFLAGS += -DVERSION_PROTO=1
else
$(error Invalid VERSION variable detected. Please use either 'us', 'fr', 'eu' or 'proto')
endif

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'BUILD_PATH.+\.o' $(LINKER_DIR)/$(LD_SCRIPT) -o)
OBJECTS := $(OBJECTS:BUILD_PATH/%=$(BUILD_DIR)/%)
DEPENDS := $(OBJECTS:=.d)

### Targets ###

ifeq ($(MODERN),1)
$(BUILD_DIR)/%.o: override OPTFLAGS := -O0 -g
CFLAGS += $(CFLAGS_MODERN) $(CHECK_WARNINGS)
CC := $(CROSS)gcc
endif

ifneq ($(NON_MATCHING),1)
ifneq ($(MODERN),1)
$(BUILD_DIR)/src/%.o: CPPFLAGS += -DNDEBUG
endif
endif

$(BUILD_DIR)/src/%.o: CPPFLAGS += -I $(LIBKMC_DIR)/include -I $(LIBMUS_DIR)/include

$(BUILD_DIR)/$(LIBULTRA_DIR)/src/%.o: OPTFLAGS := -O3 -g0
$(BUILD_DIR)/$(LIBULTRA_DIR)/src/%.o: CPPFLAGS += -I $(LIBULTRA_DIR)/src -I $(LIBULTRA_DIR)/include/2.0I/PR -I $(LIBULTRA_DIR)/include/2.0I/libc

$(BUILD_DIR)/$(LIBKMC_DIR)/src/%.o: OPTFLAGS := -O1 -g1
$(BUILD_DIR)/$(LIBKMC_DIR)/src/%.o: CFLAGS := $(filter-out -funsigned-char,$(CFLAGS))
$(BUILD_DIR)/$(LIBKMC_DIR)/src/%.o: CPPFLAGS += -I $(LIBKMC_DIR)/src -I $(LIBKMC_DIR)/include
$(BUILD_DIR)/$(LIBKMC_DIR)/src/%.o: ASFLAGS += -I $(LIBKMC_DIR)/src

$(BUILD_DIR)/$(LIBMUS_DIR)/src/%.o: OPTFLAGS := -O3 -g0
$(BUILD_DIR)/$(LIBMUS_DIR)/src/%.o: CPPFLAGS += -I $(LIBULTRA_DIR)/include/2.0I/PR -I $(LIBMUS_DIR)/include -D_OLD_AUDIO_LIBRARY

all: $(ROM)

objects: $(OBJECTS)

-include $(DEPENDS)

clean:
	$(V)rm -rf $(BUILD_DIR)

distclean: clean
	$(V)rm -rf assets/$(VERSION)
	$(V)rm -rf $(LINKER_DIR)
	$(V)rm -rf gen/$(VERSION)
	$(V)rm -rf asm/$(VERSION)
	$(V)rm -rf tmp/
	$(V)rm -f *ctx.c
	$(V)rm -f data.c*
	$(V)rm -f *.til

setup: distclean split

split:
	$(V)$(SPLAT)

extract:
	make -C tools/libEDL
	$(V)$(EXTRACT)
	
compare:
	$(V)$(PYTHON) tools/scripts/first_diff.py -v $(VERSION)

# Compile .c files with kmc gcc but preprocessed by modern gnu cpp
$(BUILD_DIR)/%.c.o: %.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
ifeq ($(CHECK),1)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CHECK_WARNINGS) $(CPPFLAGS) $<
endif
	$(V)$(CPP) $(CFLAGS) $(CPPFLAGS) -ffreestanding -U__mips -D__FILE__=\"$(notdir $<)\" -Wno-builtin-macro-redefined -MMD -MP -MT $@ -MF $@.d $< -o $@.i
	$(V)$(CC) $(OPTFLAGS) $(CFLAGS) -c -o $@ $@.i

# Compile .s files with kmc as but preprocessed by modern gnu cpp
$(BUILD_DIR)/%.s.o: %.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(CPP) $(CPPFLAGS) -U_LANGUAGE_C $< -o $@.i
	$(V)$(AS) $(ASFLAGS) -o $@ $@.i

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@$(PRINT)$(GREEN)objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/$(LD_SCRIPT): $(LINKER_DIR)/$(LD_SCRIPT)
	@$(PRINT)$(GREEN)Preprocessing linker script: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	$(V)$(CPP) -P -DBUILD_PATH=$(BUILD_DIR) $< -o $@

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final rom
$(ROM): $(BUILD_DIR)/$(TARGET).elf
	@$(PRINT)$(GREEN)Creating z64: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
	$(V)$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x2000000 $< $@
#	@$(PRINT)$(PURPLE)objcopy gap fill 0xFF to 0x2000000$(PURPLE)$(ENDPURPLE)$(ENDLINE)
	$(V)$(N64CKSUM) $@
ifeq ($(COMPARE),1)
	@$(DIFF) $(BASEROM) $(ROM) && printf "OK\n" || (echo 'The build succeeded, but did not match the base ROM. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif

### Make Settings ###

.PHONY: all clean distclean setup split compare extract

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
