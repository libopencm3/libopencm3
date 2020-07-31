##
## This file is part of the libopencm3 project.
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

LIBNAME		= libopencm3_stm32h7
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar

# STM32H7 supports double precision FPU
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv5-d16

TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m7 -mthumb $(FP_FLAGS) \
		  -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32H7
TGT_CFLAGS	+= $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)

ARFLAGS		= rcs

OBJS += dac_common_all.o
OBJS += exti_common_all.o
OBJS += flash_common_all.o flash_common_f.o flash_common_f24.o
OBJS += fmc_common_f47.o
OBJS += gpio_common_all.o gpio_common_f0234.o
OBJS += pwr.o rcc.o
OBJS += rcc_common_all.o
OBJS += spi_common_all.o spi_common_v2.o
OBJS += timer_common_all.o
OBJS += usart_common_v2.o usart_common_fifos.o

VPATH += ../../usb:../:../../cm3:../common

include ../../Makefile.include
