##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2012 chrysn <chrysn@fsfe.org>
## Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

LIBNAME		= libopencm3_ezr32wg
SRCLIBDIR	?= ../..
FAMILY		= EZR32WG

FP_FLAGS        ?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m4 $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -D$(FAMILY)
TGT_CFLAGS      += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS += acmp_common.o
OBJS += adc_common.o
OBJS += burtc_common.o
OBJS += cmu_common.o
OBJS += dac_common.o
OBJS += dma_common.o
OBJS += emu_common.o
OBJS += gpio_common.o
OBJS += i2c_common.o
OBJS += letimer_common.o
OBJS += msc_common.o
OBJS += prs_common.o
OBJS += rmu_common.o
OBJS += rtc_common.o
OBJS += timer_common.o
OBJS += usart_common.o
OBJS += wdog_common.o

OBJS += usb.o usb_control.o usb_standard.o usb_msc.o
OBJS += usb_hid.o
OBJS += usb_audio.o usb_cdc.o usb_midi.o
OBJS += usb_efm32.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include
