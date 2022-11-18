### Build Options ###

BASEROM      := baserom.us.z64
TARGET       := dukenukemzerohour
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

BUILD_DIR    := build
LIBULTRA_DIR := libs/libultra
LIBKMC_DIR   := libs/libkmc
LIBMUS_DIR   := libs/libmus
ROM          := $(BUILD_DIR)/$(TARGET).z64
ELF          := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT    := $(TARGET).ld
LD_MAP       := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON     := python3
N64CKSUM   := $(PYTHON) tools/scripts/n64cksum.py
SPLAT_YAML := dukenukemzerohour.yaml
SPLAT      := $(PYTHON) tools/splat/split.py $(SPLAT_YAML)
EMULATOR   := mupen64plus
DIFF       := diff

CROSS    := mips-linux-gnu-
AS       := tools/gcc_2.7.2/$(DETECTED_OS)/as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip
CPP      := $(CROSS)cpp

CC       := tools/gcc_2.7.2/$(DETECTED_OS)/gcc
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
CFLAGS         := -G0 -mips3 -mgp32 -mfp32 #-save-temps #-Wa,--vr4300mul-off
CPPFLAGS       := -I include -I $(LIBULTRA_DIR)/include/2.0I -I $(LIBMUS_DIR)/include -D_LANGUAGE_C -DF3DEX_GBI_2 -DF3DEX_GBI_2x -D_MIPS_SZLONG=32 -D_FINALROM
LDFLAGS        := -T undefined_syms.txt -T undefined_funcs.txt -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections
CHECK_WARNINGS := -Wall -Wextra -Wno-missing-braces -Wno-format-security -Wno-unused-parameter -Wno-unused-variable -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -m32
CFLAGS_CHECK   := -fsyntax-only -fsigned-char -nostdinc -fno-builtin -D CC_CHECK -std=gnu90 $(CHECK_WARNINGS)

ifneq ($(CHECK),1)
CFLAGS_CHECK += -w
endif

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'build.+\.o' dukenukemzerohour.ld -o)
DEPENDS := $(OBJECTS:=.d) 

### Targets ###
build/$(LIBULTRA_DIR)/src/%.o: OPTFLAGS := -O3 -g0
build/$(LIBULTRA_DIR)/src/%.o: CFLAGS += -funsigned-char
build/$(LIBULTRA_DIR)/src/%.o: CPPFLAGS += -I $(LIBULTRA_DIR)/src -I $(LIBULTRA_DIR)/include/2.0I/PR

build/$(LIBKMC_DIR)/src/%.o: OPTFLAGS := -O1 -g1
build/$(LIBKMC_DIR)/src/%.o: CPPFLAGS += -I $(LIBKMC_DIR)/src -I $(LIBKMC_DIR)/include/
build/$(LIBKMC_DIR)/src/%.o: ASFLAGS += -I $(LIBKMC_DIR)/src

build/$(LIBMUS_DIR)/src/%.o: OPTFLAGS := -O3 -g0
build/$(LIBMUS_DIR)/src/%.o: CFLAGS += -D_OLD_AUDIO_LIBRARY
build/$(LIBMUS_DIR)/src/%.o: CPPFLAGS += -I $(LIBULTRA_DIR)/include/2.0I/PR

all: $(ROM)

-include $(DEPENDS)

clean:
	$(V)rm -rf build

distclean: clean
	$(V)rm -rf assets/
	$(V)rm -f *auto.txt
	$(V)rm -f dukenukemzerohour.ld
	$(V)rm -f include/ld_addrs.h
	$(V)rm -rf nonmatchings/
	$(V)rm -rf gen/
	$(V)rm -rf data/
	$(V)rm -f ctx.c

setup: distclean split

split:
	$(V)$(SPLAT)

test: $(ROM)
	$(V)$(EMULATOR) $<

context:
	@$(PRINT)$(GREEN)Creating context file...$(ENDLINE)
	$(V)rm -f ctx.c ctx_includes.c
	$(V)find include/ src/ -type f -name "*.h" | sed -e 's/.*/#include "\0"/' > ctx_includes.c
	$(V)$(PYTHON) tools/scripts/m2ctx.py ctx_includes.c
	$(V)rm -f ctx_includes.c

compare:
	$(V)$(PYTHON) tools/scripts/first_diff.py

# Compile .c files with kmc gcc but preprocessed by modern gnu cpp
$(BUILD_DIR)/%.c.o: %.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)$(CPP) $(CFLAGS) $(CPPFLAGS) -U__mips -D__FILE__=\"$(notdir $<)\" -Wno-builtin-macro-redefined $< -o $@.i
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) -c -o $@ $@.i

# Compile .s files with kmc as but preprocessed by modern gnu cpp
$(BUILD_DIR)/%.s.o: %.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(CPP) $(ASFLAGS) $(CPPFLAGS) -U_LANGUAGE_C $< -o $@.i
	$(V)$(AS) $(ASFLAGS) -o $@ $@.i

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
#	$(V)$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x2000000 $< $@
#	@$(PRINT)$(PURPLE)objcopy gap fill 0xFF to 0x2000000$(PURPLE)$(ENDPURPLE)$(ENDLINE)
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
