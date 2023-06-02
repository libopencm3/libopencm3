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

LIBNAME		= libopencm3_at32f42x
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m4 $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DAT32F42X
TGT_CFLAGS      += $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)
ARFLAGS		= rcs

OBJS		+= adc_common_v1.o
OBJS		+= crs.o
OBJS		+= desig_common_all.o desig_common_v1.o
OBJS		+= dma.o dma_common_at32.o dma_common_l1f013.o
OBJS		+= exti_common_all.o
OBJS		+= flash_common_all.o
OBJS		+= gpio_common_all.o gpio_common_f0234.o gpio_common_at32.o
OBJS		+= i2c_common_v2.o
OBJS		+= iwdg_common_all.o
OBJS		+= pwr_common_v1.o
OBJS		+= rcc.o rcc_common_at32.o rcc_common_all.o
OBJS		+= rtc_common_l1f024.o
OBJS		+= spi_common_all.o spi_common_v1.o spi_common_v1_frf.o
OBJS		+= timer_common_at32.o timer_common_all.o
OBJS		+= usart_common_all.o usart_common_f124.o

gpio_common_f0234.o:	TGT_CFLAGS	+= -DGPIO_SET_OUTPUT_OPTIONS

vpath %.c	../../stm32/common:../../stm32
VPATH		+= ../common:../../usb:../../cm3

include ../../Makefile.include
