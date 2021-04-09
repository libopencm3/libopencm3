##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2020 Karl Palsson <karlp@tweak.net.au>
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

LIBNAME		= libopencm3_stm32g4
SRCLIBDIR	?= ../..

FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m4 -mthumb $(FP_FLAGS) \
		  -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32G4
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
ARFLAGS		= rcs

OBJS += adc.o adc_common_v2.o adc_common_v2_multi.o
OBJS += crs_common_all.o
OBJS += dac_common_all.o dac_common_v2.o
OBJS += dma_common_l1f013.o
OBJS += dmamux.o
OBJS += fdcan.o fdcan_common.o
OBJS += flash.o flash_common_all.o flash_common_f.o flash_common_idcache.o
OBJS += gpio_common_all.o gpio_common_f0234.o
OBJS += opamp_common_all.o opamp_common_v2.o
OBJS += pwr.o
OBJS += rcc.o rcc_common_all.o
OBJS += spi_common_all.o spi_common_v2.o
OBJS += timer_common_all.o timer_common_f0234.o
OBJS += quadspi_common_v1.o

OBJS += usb.o usb_control.o usb_standard.o
OBJS += usb_audio.o
OBJS += usb_cdc.o
OBJS += usb_hid.o
OBJS += usb_midi.o
OBJS += usb_msc.o
OBJS += st_usbfs_core.o st_usbfs_v2.o

VPATH += ../../usb:../:../../cm3:../common
VPATH += ../../ethernet

include ../../Makefile.include
