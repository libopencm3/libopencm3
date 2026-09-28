##
## This file is part of the libopencm3 project.
##
## Licensed under the GNU LGPL v3 or later.
##

LIBNAME		= libopencm3_py32f0
SRCLIBDIR	?= ../..

CC		= $(PREFIX)gcc
AR		= $(PREFIX)ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m0plus $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DPY32F0
TGT_CFLAGS	+= $(DEBUG_FLAGS)
TGT_CFLAGS	+= $(STANDARD_FLAGS)

ARFLAGS		= rcs

# Common Cortex-M objects.
OBJS += vector.o systick.o scb.o nvic.o assert.o sync.o dwt.o

# Family-specific objects.
OBJS += rcc.o gpio.o usart.o

VPATH += ../:../../cm3

include ../../Makefile.include
