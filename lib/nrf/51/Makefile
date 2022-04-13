##
## This file is part of the libopencm3 project.
## Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
## Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

LIBNAME		= libopencm3_nrf51
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar

FP_FLAGS ?= -msoft-float

TGT_CFLAGS	= -Os -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m0 -mthumb $(FP_FLAGS) \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DNRF51

TGT_CFLAGS += $(DEBUG_FLAGS)
TGT_CFLAGS += $(STANDARD_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS += clock_common.o clock.o
OBJS += gpio.o
OBJS += i2c_common.o
OBJS += ppi.o
OBJS += rtc.o
OBJS += radio_common.o ./radio.o
OBJS += timer.o
OBJS += uart.o

VPATH += ../../cm3:../common

include ../../Makefile.include

