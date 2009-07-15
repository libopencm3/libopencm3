##
## This file is part of the libopenstm32 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
##

# PREFIX	?= arm-none-eabi
PREFIX		?= arm-elf
DESTDIR		?= /usr/local
INCLUDEDIR	= $(DESTDIR)/$(PREFIX)/include
LIBDIR		= $(DESTDIR)/$(PREFIX)/lib
INSTALL		= install

all: build

build:
	$(MAKE) -C lib all

install: build
	$(INSTALL) -d $(INCLUDEDIR)/libopenstm32
	$(INSTALL) -d $(LIBDIR)
	$(INSTALL) -m 0644 include/libopenstm32.h $(INCLUDEDIR)
	$(INSTALL) -m 0644 include/libopenstm32/*.h $(INCLUDEDIR)/libopenstm32
	$(INSTALL) -m 0644 lib/*.a $(LIBDIR)

clean:
	$(MAKE) -C lib clean

