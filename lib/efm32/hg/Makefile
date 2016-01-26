##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2012 chrysn <chrysn@fsfe.org>
## Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
## Copyright (C) 2018 Seb Holzapfel <schnommus@gmail.com>
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
## along with this library. If not, see <http://www.gnu.org/licenses/>.
##

LIBNAME		= libopencm3_efm32hg
SRCLIBDIR	?= ../..
FAMILY		= EFM32HG

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m0plus $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -D$(FAMILY)
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)

ARFLAGS		= rcs

OBJS		= cmu.o gpio_common.o timer_common.o
OBJS		+= usb.o usb_control.o usb_standard.o usb_msc.o \
		   usb_dwc_common.o usb_efm32hg.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include
