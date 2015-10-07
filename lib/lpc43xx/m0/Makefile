##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
## Copyright (C) 2012/2013 Benjamin Vernoux <titanmkd@gmail.com>
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

LIBNAME		= libopencm3_lpc43xx_m0
SRCLIBDIR	?= ../..

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -O2 -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m0 -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DLPC43XX -DLPC43XX_M0
TGT_CFLAGS      += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

# LPC43xx common files for M4 / M0
OBJ_LPC43XX     = gpio.o scu.o i2c.o ssp.o uart.o timer.o

#LPC43xx M0 specific file + Generic LPC43xx M4/M0 files
OBJS		= $(OBJ_LPC43XX)

VPATH += ../:../../cm3

include ../../Makefile.include
