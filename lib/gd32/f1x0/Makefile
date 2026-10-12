##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
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

LIBNAME		= libopencm3_gd32f1x0
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m3 $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DGD32F1X0
TGT_CFLAGS      += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS += flash.o flash_common_all.o flash_common_f.o flash_common_f01.o
OBJS += gpio_common_all.o gpio_common_f0234.o
OBJS += iwdg_common_all.o
OBJS += rcc.o rcc_common_all.o
OBJS += timer_common_all.o timer_common_f0234.o
OBJS += dma_common_l1f013.o
OBJS += usart_common_all.o usart_common_v2.o
OBJS += adc.o adc_common_v1.o
OBJS += i2c.o i2c_common_v1.o

# stm32/f1 contributes the v1-family family-specific adc.c + i2c.c
# (adc_reset_calibration / adc_calibration etc.) which adc_common_v1.c
# alone doesn't provide.
VPATH += ../:../../cm3:../common:../../stm32/common:../../stm32/f1

include ../../Makefile.include
