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

LDSCRIPT	= $(DEVICE).ld

family		:=$(shell awk -v PAT="$(DEVICE)" -v MODE="FAMILY" -f $(OPENCM3_DIR)/scripts/genlink.awk $(OPENCM3_DIR)/ld/devices.data 2>/dev/null)
cpu		:=$(shell awk -v PAT="$(DEVICE)" -v MODE="CPU" -f $(OPENCM3_DIR)/scripts/genlink.awk $(OPENCM3_DIR)/ld/devices.data 2>/dev/null)
fpu		:=$(shell awk -v PAT="$(DEVICE)" -v MODE="FPU" -f $(OPENCM3_DIR)/scripts/genlink.awk $(OPENCM3_DIR)/ld/devices.data 2>/dev/null)

CPPFLAGS	+= $(shell echo "-D$(family)" | tr [:lower:] [:upper:] 2>/dev/null)

ARCH_FLAGS	:=-mcpu=$(cpu)
ifeq ($(cpu),$(filter $(cpu),cortex-m0 cortex-m0plus cortex-m3 cortex-m4 cortex-m7))
ARCH_FLAGS    +=-mthumb
endif

ifeq ($(fpu),soft)
ARCH_FLAGS	+= -msoft-float
else ifeq ($(fpu),hard-fpv4-sp-d16)
ARCH_FLAGS	+= -mfloat-abi=hard -mfpu=fpv4-sp-d16
else ifeq ($(fpu),hard-fpv5-sp-d16)
ARCH_FLAGS      += -mfloat-abi=hard -mfpu=fpv5-sp-d16
else
$(warning No match for the FPU flags)
endif


ifeq ($(family),)
$(warning the device data file has no information about the library name matching your device)
endif

# only append to LDFLAGS if the library file exists to not break builds
# where those are provided by different means
ifneq (,$(wildcard $(OPENCM3_DIR)/lib/libopencm3_$(family).a))
LDLIBS += -lopencm3_$(family)
else
$(warning $(OPENCM3_DIR)/lib/libopencm3_$(family).a library variant for the selected device does not exist.)
endif

# only append to LDLIBS if the directory exists
ifneq (,$(wildcard $(OPENCM3_DIR)/lib))
LDFLAGS += -L$(OPENCM3_DIR)/lib
else
$(warning $(OPENCM3_DIR)/lib as given be OPENCM3_DIR does not exist.)
endif

# only append include path to CPPFLAGS if the directory exists
ifneq (,$(wildcard $(OPENCM3_DIR)/include))
CPPFLAGS += -I$(OPENCM3_DIR)/lib
else
$(warning $(OPENCM3_DIR)/include as given be OPENCM3_DIR does not exist.)
endif
