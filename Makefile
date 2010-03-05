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
	@printf "  BUILD   lib\n"
	$(Q)$(MAKE) -C lib all

examples: lib
	@printf "  BUILD   examples\n"
	$(Q)$(MAKE) -C examples all

install: build
	@printf "  INSTALL headers\n"
	$(Q)$(INSTALL) -d $(INCDIR)/libopenstm32
	$(Q)$(INSTALL) -d $(LIBDIR)
	$(Q)$(INSTALL) -m 0644 include/libopenstm32.h $(INCDIR)
	$(Q)$(INSTALL) -m 0644 include/libopenstm32/*.h $(INCDIR)/libopenstm32
	@printf "  INSTALL lib\n"
	$(Q)$(INSTALL) -m 0644 lib/*.a $(LIBDIR)
	@printf "  INSTALL ldscript\n"
	$(Q)$(INSTALL) -m 0644 lib/*.ld $(LIBDIR)

clean:
	$(Q)$(MAKE) -C examples clean
	$(Q)$(MAKE) -C lib clean

.PHONY: build lib examples install clean

