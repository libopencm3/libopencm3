##
## This file is part of the libopencm3 project.
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

# PREFIX	?= arm-none-eabi
PREFIX		?= arm-elf
DESTDIR		?= /usr/local
INCDIR		= $(DESTDIR)/$(PREFIX)/include
LIBDIR		= $(DESTDIR)/$(PREFIX)/lib
INSTALL		= install

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
# Do not print "Entering directory ...".
MAKEFLAGS += --no-print-directory
endif

all: build

build: lib examples

lib:
	@printf "  BUILD   lib/stm32\n"
	$(Q)$(MAKE) -C lib/stm32 all
	@printf "  BUILD   lib/lpc13xx\n"
	$(Q)$(MAKE) -C lib/lpc13xx all

examples: lib
	@printf "  BUILD   examples/stm32\n"
	$(Q)$(MAKE) -C examples/stm32 all
	@printf "  BUILD   examples/lpc13xx\n"
	$(Q)$(MAKE) -C examples/lpc13xx all

install: build
	@printf "  INSTALL headers\n"
	$(Q)$(INSTALL) -d $(INCDIR)/libopencm3
	$(Q)$(INSTALL) -d $(LIBDIR)/libopencm3
	$(Q)cp -r include/* $(INCDIR)/libopencm3
	@printf "  INSTALL libs\n"
	$(Q)$(INSTALL) -m 0644 lib/*/*.a $(LIBDIR)/libopencm3
	@printf "  INSTALL ldscripts\n"
	$(Q)$(INSTALL) -m 0644 lib/*/*.ld $(LIBDIR)/libopencm3

clean:
	$(Q)$(MAKE) -C examples/stm32 clean
	$(Q)$(MAKE) -C lib/stm32 clean
	$(Q)$(MAKE) -C examples/lpc13xx clean
	$(Q)$(MAKE) -C lib/lpc13xx clean

.PHONY: build lib examples install clean

