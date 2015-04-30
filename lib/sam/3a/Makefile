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

LIBNAME		= libopencm3_sam3a
SRCLIBDIR	?= ../..

PREFIX		?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
CFLAGS		= -Os -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m3 -mthumb $(FP_FLAGS) -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSAM3A
CFLAGS          += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs
OBJS		= gpio_common_all.o gpio_common_3a3u3x.o pmc.o usart.o

VPATH += ../../usb:../../cm3:../common

include ../../Makefile.include

