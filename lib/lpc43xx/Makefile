##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
## Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

LIBNAME		= libopencm3_lpc43xx

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
CFLAGS		= -O2 -g3 -Wall -Wextra -I../../include -fno-common \
		  -mcpu=cortex-m4 -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD \
		  -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DLPC43XX
# ARFLAGS	= rcsv
ARFLAGS		= rcs
OBJS		= gpio.o scu.o i2c.o ssp.o

VPATH += ../cm3

include ../Makefile.include
