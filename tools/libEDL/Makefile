### Build Options ###
TARGET       := libEDL.so
VERBOSE      ?= 0
BUILD_DIR    ?= build
ROOTDIR      := ../..
SRCDIR       := $(ROOTDIR)
LIBULTRADIR  := $(ROOTDIR)/libs/libultra

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

### Tools ###
CROSS    :=
LD       := $(CROSS)gcc
CC       := $(CROSS)gcc

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
OPTFLAGS       := -O2
CFLAGS         := -fPIC
CPPFLAGS       := -I$(SRCDIR)/include -I $(LIBULTRADIR)/include/2.0I -D_LANGUAGE_C -DLIBEDL
LDFLAGS        := -shared
CHECK_WARNINGS := -Wall -Wextra

### Sources ###
SOURCE = $(SRCDIR)/src/code0/edl.c

# Object files
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(BUILD_DIR)/%.o, $(filter $(SRCDIR)/%.c, $(SOURCE)))
DEPENDS := $(OBJECTS:=.d)

### Targets ###
all: $(BUILD_DIR)/$(TARGET)

-include $(DEPENDS)

clean:
	$(V)rm -rf $(BUILD_DIR)

# Compile .c files
$(BUILD_DIR)/%.o: $(SRCDIR)/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# Link the .o files
$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	@$(PRINT)$(GREEN)Linking file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) $^ -o $@

### Make Settings ###

.PHONY: all clean

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
