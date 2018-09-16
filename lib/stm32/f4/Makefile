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

LIBNAME		= libopencm3_stm32f4
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
		  -ffunction-sections -fdata-sections -MD -DSTM32F4
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS		= adc.o adc_common_v1.o can.o desig.o gpio.o pwr.o rcc.o \
		  rtc.o crypto.o

OBJS            += crc_common_all.o dac_common_all.o dma_common_f24.o \
                   gpio_common_all.o gpio_common_f0234.o i2c_common_v1.o \
                   iwdg_common_all.o pwr_common_v1.o rtc_common_l1f024.o \
                   timer_common_all.o \
                   timer_common_f0234.o timer_common_f24.o usart_common_all.o \
		   usart_common_f124.o \
		   hash_common_f24.o crypto_common_f24.o exti_common_all.o \
		   rcc_common_all.o
OBJS		+= flash.o flash_common_all.o flash_common_f.o flash_common_f24.o
OBJS		+= flash_common_idcache.o
OBJS		+= rng_common_v1.o
OBJS		+= spi_common_all.o spi_common_v1.o spi_common_v1_frf.o

OBJS            += usb.o usb_standard.o usb_control.o usb_dwc_common.o \
		   usb_f107.o usb_f207.o usb_msc.o

OBJS		+= mac.o phy.o mac_stm32fxx7.o phy_ksz80x1.o fmc.o

OBJS		+= ltdc.o 

VPATH += ../../usb:../:../../cm3:../common
VPATH += ../../ethernet

include ../../Makefile.include
