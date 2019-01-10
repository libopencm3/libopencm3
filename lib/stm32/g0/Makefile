##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

LIBNAME		= libopencm3_stm32g0
SRCLIBDIR	?= ../..

PREFIX	        ?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m0plus -mthumb $(FP_FLAGS) \
		  -ffunction-sections -fdata-sections -MD -DSTM32G0
TGT_CFLAGS	+= $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)

ARFLAGS		= rcs

# specific objs
OBJS		= rcc.o
OBJS		+= flash.o

# common/shared objs
OBJS		+= rcc_common_all.o
OBJS		+= flash_common_all.o
OBJS		+= gpio_common_all.o gpio_common_f0234.o

VPATH +=../:../../cm3:../common

include ../../Makefile.include
