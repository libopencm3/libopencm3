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

LIBNAME		= libopencm3_stm32f7
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar

# STM32F7 only supports single precision FPU
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv5-sp-d16

TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m7 -mthumb $(FP_FLAGS) \
		  -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F7
TGT_CFLAGS	+= $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)

ARFLAGS		= rcs

OBJS += adc_common_v1.o adc_common_v1_multi.o adc_common_f47.o
OBJS += can.o
OBJS += crc_common_all.o crc_v2.o
OBJS += dac_common_all.o dac_common_v1.o
OBJS += dcmi_common_f47.o
OBJS += desig_common_all.o desig.o
OBJS += dma_common_f24.o
OBJS += dma2d_common_f47.o
OBJS += dsi_common_f47.o
OBJS += exti_common_all.o
OBJS += flash_common_all.o flash_common_f.o flash_common_f24.o flash.o
OBJS += fmc_common_f47.o
OBJS += gpio_common_all.o gpio_common_f0234.o
OBJS += i2c_common_v2.o
OBJS += iwdg_common_all.o
OBJS += lptimer_common_all.o
OBJS += ltdc_common_f47.o
OBJS += pwr.o rcc.o
OBJS += rcc_common_all.o
OBJS += rng_common_v1.o
OBJS += spi_common_all.o spi_common_v2.o
OBJS += timer_common_all.o
OBJS += usart_common_all.o usart_common_v2.o

# Ethernet
OBJS += mac.o phy.o mac_stm32fxx7.o phy_ksz80x1.o

OBJS += usb.o usb_standard.o usb_control.o
OBJS += usb_audio.o
OBJS += usb_cdc.o
OBJS += usb_hid.o
OBJS += usb_midi.o
OBJS += usb_msc.o
OBJS += usb_dwc_common.o usb_f107.o usb_f207.o

VPATH += ../../usb:../:../../cm3:../common
VPATH += ../../ethernet

include ../../Makefile.include
