##
## This file is part of the unicore-mx project.
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

LIBNAME		= libopencm3_nrf52fp
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar

#FP_FLAGS ?= -msoft-float
FP_FLAGS ?= -mfloat-abi=hard -mfpu=fpv4-sp-d16

TGT_CFLAGS	= -Os -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m4 -mthumb $(FP_FLAGS) \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DNRF52
TGT_CFLAGS += $(DEBUG_FLAGS)
TGT_CFLAGS += $(STANDARD_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs
 
OBJS += clock_common.o
OBJS += gpio.o
OBJS += i2c.o
OBJS += ppi.o
OBJS += radio_common.o
OBJS += rtc.o
OBJS += timer.o
OBJS += uart.o

VPATH += ../../cm3:../common

include ../../Makefile.include

