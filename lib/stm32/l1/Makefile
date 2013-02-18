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

LIBNAME		= libopencm3_stm32l1

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
CFLAGS		= -Os -g -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m3 -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32L1
# ARFLAGS	= rcsv
ARFLAGS		= rcs
OBJS		= rcc.o desig.o crc.o usart.o exti2.o flash.o timer.o
OBJS +=     gpio_common_all.o gpio_common_f24.o spi_common_all.o crc_common_all.o
OBJS +=     dac_common_all.o usart_common_all.o iwdg_common_all.o i2c_common_all.o
OBJS +=     pwr_common_all.o pwr.o
OBJS +=     rtc_common_bcd.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include

