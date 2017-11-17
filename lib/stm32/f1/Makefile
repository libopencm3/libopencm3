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
SRCLIBDIR	?= ../..

PREFIX		?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m3 $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F1
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS		= adc.o adc_common_v1.o can.o desig.o flash.o gpio.o \
                  rcc.o rtc.o timer.o
OBJS		+= mac.o mac_stm32fxx7.o phy.o phy_ksz8051mll.o

OBJS            += crc_common_all.o dac_common_all.o dma_common_l1f013.o \
                   gpio_common_all.o i2c_common_v1.o iwdg_common_all.o \
                   pwr_common_v1.o spi_common_all.o spi_common_l1f124.o \
                   timer_common_all.o usart_common_all.o usart_common_f124.o \
                   rcc_common_all.o exti_common_all.o \
                   flash_common_f01.o

OBJS            += usb.o usb_control.o usb_standard.o usb_msc.o
OBJS		+= usb_fx07_common.o usb_f107.o
OBJS		+= st_usbfs_core.o st_usbfs_v1.o

VPATH += ../../usb:../:../../cm3:../common:../../ethernet

include ../../Makefile.include

