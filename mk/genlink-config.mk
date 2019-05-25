##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2014 Frantisek Burian <BuFran@seznam.cz>
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

ifeq ($(DEVICE),)
$(warning no DEVICE specified for linker script generator)
endif

LDSCRIPT	= generated.$(DEVICE).ld
DEVICES_DATA = $(OPENCM3_DIR)/ld/devices.data

genlink_family		:=$(shell $(OPENCM3_DIR)/scripts/genlink.py $(DEVICES_DATA) $(DEVICE) FAMILY)
genlink_subfamily	:=$(shell $(OPENCM3_DIR)/scripts/genlink.py $(DEVICES_DATA) $(DEVICE) SUBFAMILY)
genlink_cpu		:=$(shell $(OPENCM3_DIR)/scripts/genlink.py $(DEVICES_DATA) $(DEVICE) CPU)
genlink_fpu		:=$(shell $(OPENCM3_DIR)/scripts/genlink.py $(DEVICES_DATA) $(DEVICE) FPU)
genlink_cppflags	:=$(shell $(OPENCM3_DIR)/scripts/genlink.py $(DEVICES_DATA) $(DEVICE) CPPFLAGS)

CPPFLAGS	+= $(genlink_cppflags)

ARCH_FLAGS	:=-mcpu=$(genlink_cpu)
ifeq ($(genlink_cpu),$(filter $(genlink_cpu),cortex-m0 cortex-m0plus cortex-m3 cortex-m4 cortex-m7))
ARCH_FLAGS    +=-mthumb
endif

ifeq ($(genlink_fpu),soft)
ARCH_FLAGS	+= -msoft-float
else ifeq ($(genlink_fpu),hard-fpv4-sp-d16)
ARCH_FLAGS	+= -mfloat-abi=hard -mfpu=fpv4-sp-d16
else ifeq ($(genlink_fpu),hard-fpv5-sp-d16)
ARCH_FLAGS      += -mfloat-abi=hard -mfpu=fpv5-sp-d16
else
$(warning No match for the FPU flags)
endif


ifeq ($(genlink_family),)
$(warning $(DEVICE) not found in $(DEVICES_DATA))
endif

# only append to LDFLAGS if the library file exists to not break builds
# where those are provided by different means
ifneq (,$(wildcard $(OPENCM3_DIR)/lib/libopencm3_$(genlink_family).a))
LIBNAME = opencm3_$(genlink_family)
else
ifneq (,$(wildcard $(OPENCM3_DIR)/lib/libopencm3_$(genlink_subfamily).a))
LIBNAME = opencm3_$(genlink_subfamily)
else
$(warning $(OPENCM3_DIR)/lib/libopencm3_$(genlink_family).a library variant for the selected device does not exist.)
endif
endif

LDLIBS += -l$(LIBNAME)
LIBDEPS += $(OPENCM3_DIR)/lib/lib$(LIBNAME).a

# only append to LDLIBS if the directory exists
ifneq (,$(wildcard $(OPENCM3_DIR)/lib))
LDFLAGS += -L$(OPENCM3_DIR)/lib
else
$(warning $(OPENCM3_DIR)/lib as given be OPENCM3_DIR does not exist.)
endif

# only append include path to CPPFLAGS if the directory exists
ifneq (,$(wildcard $(OPENCM3_DIR)/include))
CPPFLAGS += -I$(OPENCM3_DIR)/include
else
$(warning $(OPENCM3_DIR)/include as given be OPENCM3_DIR does not exist.)
endif
