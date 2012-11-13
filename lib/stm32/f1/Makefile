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

LIBNAME		= libopencm3_stm32f1

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
CFLAGS		= -Os -g -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m3 -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F1
# ARFLAGS	= rcsv
ARFLAGS		= rcs
OBJS		= rcc.o gpio.o usart.o adc.o spi.o flash.o \
		  rtc.o i2c.o dma.o exti.o ethernet.o \
		  usb_f103.o usb.o usb_control.o usb_standard.o can.o \
		  timer.o usb_f107.o desig.o crc.o dac.o iwdg.o pwr.o \
		  usb_fx07_common.o \
		  gpio_common_all.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include

