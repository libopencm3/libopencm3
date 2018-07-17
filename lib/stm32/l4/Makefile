##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

LIBNAME		= libopencm3_stm32l4
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
		  -ffunction-sections -fdata-sections -MD -DSTM32L4
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
ARFLAGS		= rcs

# Specific objs
OBJS		= adc.o flash.o pwr.o rcc.o

# common/shared objs
OBJS            += rcc_common_all.o
OBJS            += gpio_common_all.o gpio_common_f0234.o
OBJS            += exti_common_all.o
OBJS            += adc_common_v2.o adc_common_v2_multi.o
OBJS            += crc_common_all.o crc_v2.o
OBJS            += crs_common_all.o
OBJS            += flash_common_all.o flash_common_f.o flash_common_idcache.o
OBJS            += rng_common_v1.o
OBJS            += timer_common_all.o
OBJS            += i2c_common_v2.o
OBJS            += usart_common_all.o usart_common_v2.o
OBJS            += dma_common_l1f013.o
OBJS            += iwdg_common_all.o
OBJS            += rtc_common_l1f024.o
OBJS            += spi_common_all.o spi_common_v2.o

OBJS            += usb.o usb_control.o usb_standard.o usb_msc.o
OBJS            += st_usbfs_core.o st_usbfs_v2.o

VPATH += ../../usb:../:../../cm3:../common
VPATH += ../../ethernet

include ../../Makefile.include
