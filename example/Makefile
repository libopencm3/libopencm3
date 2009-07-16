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

BINARY		= blink

# PREFIX	?= arm-none-eabi
PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
LD		= $(PREFIX)-ld
CFLAGS		= -Os -g -Wall -Wextra -I../include -fno-common \
		  -mcpu=cortex-m3 -mthumb
LDFLAGS		= -L../lib -T$(BINARY).ld -nostartfiles
OBJS		= $(BINARY).o

all: $(BINARY)

$(BINARY): $(OBJS) $(BINARY).ld
	$(LD) $(LDFLAGS) -o $(BINARY) $(OBJS) -lopenstm32

$(BINARY).o: $(BINARY).c
	$(CC) $(CFLAGS) -c $(BINARY).c

clean:
	rm -f *.o $(BINARY)

