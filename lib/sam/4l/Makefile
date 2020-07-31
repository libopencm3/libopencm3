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

LIBNAME		= libopencm3_sam4l
SRCLIBDIR	?= ../..

FP_FLAGS ?= -msoft-float
CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os -Wall -Wextra -I../../../include -fno-common \
		  -mcpu=cortex-m4 -mthumb $(FP_FLAGS) -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSAM4L
TGT_CFLAGS      += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs

OBJS += adcife.o
OBJS += gpio.o
OBJS += pm.o
OBJS += scif.o
OBJS += usart_common_all.o usart.o

VPATH += ../../usb:../../cm3:../common

include ../../Makefile.include

