##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

LIBNAME		= libopencm3_nrf52
SRCLIBDIR	?= ../..

FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
PREFIX	        ?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m4 -mthumb $(FP_FLAGS) \
		  -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DNRF52
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS		= gpio.o uart.o uarte.o timer.o clock.o spim.o radio.o saadc.o \
              ppi.o pwm.o temp.o rng.o power.o

OBJS            += gpio_common.o uart_common.o uarte_common.o timer_common.o \
				   clock_common.o spim_common.o radio_common.o saadc_common.o \
				   ppi_common.o pwm_common.o temp_common.o rng_common.o \
				   power.o

VPATH += ../../usb:../:../../cm3:../common
VPATH += ../../ethernet

include ../../Makefile.include
