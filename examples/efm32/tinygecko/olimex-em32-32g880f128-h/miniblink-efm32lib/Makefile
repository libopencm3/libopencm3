##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
## along with this library. If not, see <http://www.gnu.org/licenses/>.
##

BINARY = miniblink

OBJS += efm32_gpio.o efm32_cmu.o
CFLAGS += -I/tmp/EFM32_CMSIS_2.4.1/efm32lib/inc/ -I /tmp/EFM32_CMSIS_2.4.1/CMSIS/CM3/DeviceSupport/EnergyMicro/EFM32/ -DEFM32G880F128 -I.

include ../Makefile.include
