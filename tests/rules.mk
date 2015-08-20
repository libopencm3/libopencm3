##
## This file is part of the libopencm3 project.
##
## This library is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library.  If not, see <http://www.gnu.org/licenses/>.
##

# This version of rules.mk expects the following to be defined before
# inclusion..
### REQUIRED ###
# OPENCM3_DIR - duh
# OPENCM3_LIB - the basename, eg: opencm3_stm32f4
# OPENCM3_DEFS - the target define eg: -DSTM32F4
# ARCH_FLAGS - eg, -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
#    (ie, the full set of cpu arch flags, _none_ are defined in this file)
# PROJECT - will be the basename of the output elf, eg usb-gadget0-stm32f4disco
# CFILES - basenames only, eg main.c blah.c
# LDSCRIPT - full path, eg ../../examples/stm32/f4/stm32f4-discovery/stm32f4-discovery.ld
#
### OPTIONAL ###
# INCLUDES - fully formed -I paths, if you want extra, eg -I../shared
# BUILD_DIR - defaults to bin, should set this if you are building multiarch
# OPT - full -O flag, defaults to -Os
# CSTD - defaults -std=c99
# CXXSTD - no default.
# OOCD_INTERFACE - eg stlink-v2
# OOCD_TARGET - eg stm32f4x
#    both only used if you use the "make flash" target.
# OOCD_FILE - eg my.openocd.cfg
#    This overrides interface/target above, and is used as just -f FILE
### TODO/FIXME/notes ###
# No support for stylecheck.
# No support for BMP/texane/random flash methods, no plans either
# No support for magically finding the library.
# C++ hasn't been actually tested with this..... sorry bout that. ;)
# Second expansion/secondary not set, add this if you need them.

BUILD_DIR ?= bin
OPT ?= -Os
CSTD ?= -std=c99

# Be silent per default, but 'make V=1' will show all compiler calls.
# If you're insane, V=99 will print out all sorts of things.
V?=0
ifeq ($(V),0)
Q	:= @
NULL	:= 2>/dev/null
endif

# Tool paths.
PREFIX	?= arm-none-eabi-
CC	= $(PREFIX)gcc
LD	= $(PREFIX)gcc
OBJCOPY	= $(PREFIX)objcopy
OBJDUMP	= $(PREFIX)objdump
OOCD	?= openocd

OPENCM3_INC = $(OPENCM3_DIR)/include

# Inclusion of library header files
INCLUDES += $(patsubst %,-I%, . $(OPENCM3_INC) )

OBJS = $(CFILES:%.c=$(BUILD_DIR)/%.o)

CPPFLAGS += -MD
CPPFLAGS += -Wall -Wundef $(INCLUDES)
CPPFLAGS += $(INCLUDES) $(OPENCM3_DEFS)

CFLAGS += $(OPT) $(CSTD) -ggdb3
CFLAGS += $(ARCH_FLAGS)
CFLAGS += -fno-common
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Wextra -Wshadow -Wno-unused-variable -Wimplicit-function-declaration
CFLAGS += -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes

CXXFLAGS += $(OPT) $(CXXSTD) -ggdb3
CXXFLAGS += $(ARCH_FLAGS)
CXXFLAGS += -fno-common
CXXFLAGS += -ffunction-sections -fdata-sections
CXXFLAGS += -Wextra -Wshadow -Wredundant-decls  -Weffc++

LDFLAGS += -T$(LDSCRIPT) -L$(OPENCM3_DIR)/lib -nostartfiles
LDFLAGS += $(ARCH_FLAGS)
LDFLAGS += -specs=nano.specs
LDFLAGS += -Wl,--gc-sections
# OPTIONAL
#LDFLAGS += -Wl,-Map=$(PROJECT).map
ifeq ($(V),99)
LDFLAGS += -Wl,--print-gc-sections
endif

LDLIBS += -l$(OPENCM3_LIB)
# nosys is only in newer gcc-arm-embedded...
#LDLIBS += -specs=nosys.specs
LDLIBS += -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

all: $(PROJECT).elf $(PROJECT).bin
flash: $(PROJECT).flash

$(LDSCRIPT):
ifeq (,$(wildcard $(LDSCRIPT)))
    $(error Unable to find specified linker script: $(LDSCRIPT))
endif

# Need a special rule to have a bin dir
$(BUILD_DIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cxx
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

$(PROJECT).elf: $(OBJS) $(LDSCRIPT)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

%.bin: %.elf
	@printf "  OBJCOPY\t$@\n"
	$(Q)$(OBJCOPY) -O binary  $< $@

%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

%.list: %.elf
	$(OBJDUMP) -S $< > $@

%.flash: %.elf
	@printf "  FLASH\t$<\n"
ifeq (,$(OOCD_FILE))
	$(Q)$(OOCD) -f interface/$(OOCD_INTERFACE).cfg \
		-f target/$(OOCD_TARGET).cfg \
		-c "program $(*).elf verify reset exit" \
		$(NULL)
else
	$(Q)$(OOCD) -f $(OOCD_FILE) \
		-c "program $(*).elf verify reset exit" \
		$(NULL)
endif

clean:
	rm -rf $(BUILD_DIR) $(PROJECT).{elf,bin} $(PROJECT).{list,lss,map}

.PHONY: all clean flash
-include $(OBJS:.o=.d)

