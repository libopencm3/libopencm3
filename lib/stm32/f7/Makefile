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

PREFIX		?= arm-none-eabi

CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar

# STM32F7 only supports single precision FPU
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv5-sp-d16

CFLAGS		= -Os -g \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m7 -mthumb $(FP_FLAGS) \
		  -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F7

ARFLAGS		= rcs

OBJS		= gpio.o gpio_common_all.o gpio_common_f0234.o

VPATH += ../../usb:../:../../cm3:../common
VPATH += ../../ethernet

###############################################################################
# Checking CPU support in the toolchain
###############################################################################
# TODO: This check and silent skip of build should be removed, when it will be
# sure that first compatible toolchain (g-a-e 4.8 2014q3) will be sufficiently
# penetrated in majority of user stations.
define MISSING_CPU
Your toolchain doesn't support -mcpu=cortex-m7.
Please use gcc-arm-embedded 4.8 2014q3 or newer. Skipping this sub-library.
endef

ifneq ($(shell $(CC) -fsyntax-only -mcpu=cortex-m7 -mthumb -xc /dev/null 2>&1; echo $$?),0)
  $(warning $(MISSING_CPU))

all clean:
	@true

$(SRCLIBDIR)/$(LIBNAME).a:
	@true

else
  include ../../Makefile.include
endif
