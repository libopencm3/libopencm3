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

LIBNAME		= libopencm3_stm32f2
SRCLIBDIR	?= ../..

PREFIX		?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m3 -mthumb $(FP_FLAGS) -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F2
TGT_CFLAGS      += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS		= gpio.o rcc.o desig.o

OBJS            += crc_common_all.o dac_common_all.o dma_common_f24.o \
                   gpio_common_all.o gpio_common_f0234.o i2c_common_all.o \
                   iwdg_common_all.o rtc_common_l1f024.o spi_common_all.o \
                   spi_common_l1f124.o timer_common_all.o timer_common_f234.o \
		   timer_common_f24.o usart_common_all.o usart_common_f124.o \
		   flash_common_f234.o flash_common_f24.o hash_common_f24.o \
		   crypto_common_f24.o exti_common_all.o rcc_common_all.o

OBJS            += usb.o usb_standard.o usb_control.o usb_fx07_common.o \
                   usb_f107.o usb_f207.o usb_msc.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include
