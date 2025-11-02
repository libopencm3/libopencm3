##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

LIBNAME		= libopencm3_stm32u5
SRCLIBDIR	?= ../..
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv5-sp-d16

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m33 $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32U5
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)

ARFLAGS		= rcs

OBJS += timer_common_all.o
OBJS += exti_common_all.o
OBJS += iwdg_common_all.o
OBJS += i2c_common_v2.o
OBJS += usart_common_all.o usart_common_v2.o
OBJS += gpio_common_all.o gpio_common_f0234.o
OBJS += rcc.o rcc_common_all.o crs_common_all.o
OBJS += pwr.o

OBJS += usb.o usb_standard.o usb_control.o usb_msc.o
OBJS += usb_hid.o usb_bos.o usb_microsoft.o
OBJS += usb_audio.o usb_cdc.o usb_midi.o
OBJS += usb_dwc_common.o usb_f107.o usb_f207.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include

