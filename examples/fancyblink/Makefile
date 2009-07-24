##
## This file is part of the libopenstm32 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

BINARY		= fancyblink

# PREFIX	?= arm-none-eabi
PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
LD		= $(PREFIX)-ld
OBJCOPY		= $(PREFIX)-objcopy
OBJDUMP		= $(PREFIX)-objdump
# Uncomment this line if you want to use the installed (not local) library.
# TOOLCHAIN_DIR = `dirname \`which $(CC)\``/../$(PREFIX)
TOOLCHAIN_DIR   = ../..
CFLAGS		= -O0 -g -Wall -Wextra -I$(TOOLCHAIN_DIR)/include -fno-common \
		  -mcpu=cortex-m3 -mthumb
LDFLAGS		= -T$(BINARY).ld -nostartfiles -L$(TOOLCHAIN_DIR)/lib
OBJS		= $(BINARY).o
OPENOCD		= openocd

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
NULL := 2>/dev/null
endif

all: images

images: $(BINARY)
	@printf "  OBJCOPY $(BINARY).bin\n"
	$(Q)$(OBJCOPY) -Obinary $(BINARY) $(BINARY).bin
	@printf "  OBJCOPY $(BINARY).hex\n"
	$(Q)$(OBJCOPY) -Oihex $(BINARY) $(BINARY).hex
	@printf "  OBJCOPY $(BINARY).srec\n"
	$(Q)$(OBJCOPY) -Osrec $(BINARY) $(BINARY).srec
	@printf "  OBJDUMP $(BINARY).list\n"
	$(Q)$(OBJDUMP) -S $(BINARY) > $(BINARY).list

$(BINARY): $(OBJS) $(BINARY).ld
	@printf "  LD      $(subst $(shell pwd)/,,$(@))\n"
	$(Q)$(LD) $(LDFLAGS) -o $(BINARY) $(OBJS) -lopenstm32

%.o: %.c Makefile
	@printf "  CC      $(subst $(shell pwd)/,,$(@))\n"
	$(Q)$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@printf "  CLEAN   $(subst $(shell pwd)/,,$(OBJS))\n"
	$(Q)rm -f *.o
	@printf "  CLEAN   $(BINARY)\n"
	$(Q)rm -f $(BINARY)
	@printf "  CLEAN   $(BINARY).bin\n"
	$(Q)rm -f $(BINARY).bin
	@printf "  CLEAN   $(BINARY).hex\n"
	$(Q)rm -f $(BINARY).hex
	@printf "  CLEAN   $(BINARY).srec\n"
	$(Q)rm -f $(BINARY).srec
	@printf "  CLEAN   $(BINARY).list\n"
	$(Q)rm -f $(BINARY).list

flash: images
	@printf "  FLASH   $(BINARY).bin\n"
	@# IMPORTANT: Don't use "resume", only "reset" will work correctly!
	$(Q)$(OPENOCD) -f interface/jtagkey-tiny.cfg \
		       -f board/olimex_stm32_h103.cfg \
		       -c "init" -c "reset halt" \
		       -c "flash write_image erase $(BINARY).bin 0x08000000" \
		       -c "reset" \
		       -c "shutdown" $(NULL)

.PHONY: images clean

