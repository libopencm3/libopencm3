##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
DESTDIR		?= /usr/local
INCDIR		= $(DESTDIR)/$(PREFIX)/include
LIBDIR		= $(DESTDIR)/$(PREFIX)/lib
SHAREDIR	= $(DESTDIR)/$(PREFIX)/share/libopencm3/scripts
INSTALL		= install

TARGETS = stm32/f1 stm32/f2 stm32/f4 lpc13xx lpc17xx lm3s 

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
# Do not print "Entering directory ...".
MAKEFLAGS += --no-print-directory
endif

all: build

build: lib examples

lib:
	$(Q)for i in $(addprefix $@/,$(TARGETS)); do \
		if [ -d $$i ]; then \
			printf "  BUILD   $$i\n"; \
			$(MAKE) -C $$i || exit $?; \
		fi; \
	done

examples: lib
	$(Q)for i in $(addsuffix /*/*,$(addprefix $@/,$(TARGETS))); do \
		if [ -d $$i ]; then \
			printf "  BUILD   $$i\n"; \
			$(MAKE) -C $$i || exit $?; \
		fi; \
	done

install: lib
	@printf "  INSTALL headers\n"
	$(Q)$(INSTALL) -d $(INCDIR)/libopencm3
	$(Q)$(INSTALL) -d $(LIBDIR)
	$(Q)$(INSTALL) -d $(SHAREDIR)
	$(Q)cp -r include/libopencm3/* $(INCDIR)/libopencm3
	@printf "  INSTALL libs\n"
	$(Q)$(INSTALL) -m 0644 lib/*/*/*.a $(LIBDIR)
	@printf "  INSTALL ldscripts\n"
	$(Q)$(INSTALL) -m 0644 lib/*/*/*.ld $(LIBDIR)
	@printf "  INSTALL scripts\n"
	$(Q)$(INSTALL) -m 0644 scripts/* $(SHAREDIR)

doxy:
	doxygen Doxyfile

clean:
	$(Q)for i in $(addprefix lib/,$(TARGETS)) \
		     $(addsuffix /*/*,$(addprefix examples/,$(TARGETS))); do \
		if [ -d $$i ]; then \
			printf "  CLEAN   $$i\n"; \
			$(MAKE) -C $$i clean || exit $?; \
		fi; \
	done
	@printf "  CLEAN   doxygen\n"
	$(Q)rm -rf doxygen

.PHONY: build lib examples install doxy clean

