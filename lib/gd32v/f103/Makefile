##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2020 Lubomir Rintel <lkundrak@v3.sk>
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

LIBNAME		= libopencm3_gd32vf103
SRCLIBDIR	?= ../..
ARCH		= riscv

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -march=rv32imac -mabi=ilp32 -mcmodel=medlow \
		  $(FP_FLAGS) -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DGD32VF103
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
ARFLAGS		= rcs

OBJS += adc.o adc_common_v1.o
OBJS += can.o
OBJS += crc_common_all.o
OBJS += dac_common_all.o
OBJS += desig_common_all.o desig_common_v1.o
OBJS += dma_common_l1f013.o
OBJS += exti_common_all.o
OBJS += flash.o flash_common_all.o flash_common_f.o flash_common_f01.o
OBJS += gpio.o gpio_common_all.o
OBJS += i2c_common_v1.o
OBJS += iwdg_common_all.o
OBJS += pwr_common_v1.o
OBJS += rcc.o rcc_common_f1.o rcc_common_all.o
OBJS += rtc.o
OBJS += spi_common_all.o spi_common_v1.o
OBJS += timer.o timer_common_all.o
OBJS += usart_common_all.o usart_common_f124.o

OBJS += usb.o usb_control.o usb_standard.o usb_msc.o
OBJS += usb_hid.o
OBJS += usb_dwc_common.o usb_f107.o

vpath %.c ../
vpath %.c ../common
vpath %.c ../../usb
vpath %.c ../../stm32/f1
vpath %.c ../../stm32/common
vpath %.c ../../stm32

include ../../Makefile.include
