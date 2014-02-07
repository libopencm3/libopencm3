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
$(error no DEVICE specified for linker script generator)
endif

LDSCRIPT	= $(DEVICE).ld

GENLINK_DEFS	:=$(shell awk -v PAT="$(DEVICE)" -v MODE="DEFS" -f $(OPENCM3_DIR)/scripts/genlink.awk $(OPENCM3_DIR)/ld/devices.data 2>/dev/null)
GENLINK_ARCH	:=$(shell awk -v PAT="$(DEVICE)" -v MODE="ARCH" -f $(OPENCM3_DIR)/scripts/genlink.awk $(OPENCM3_DIR)/ld/devices.data 2>/dev/null)
GENLINK_LIB	:=$(shell awk -v PAT="$(DEVICE)" -v MODE="LIB" -f $(OPENCM3_DIR)/scripts/genlink.awk $(OPENCM3_DIR)/ld/devices.data 2>/dev/null)

DEFS		+= $(GENLINK_DEFS)
ARCH_FLAGS	:= $(GENLINK_ARCH)
OPENCM3_LIBNAME	:= $(strip $(subst -l,,$(GENLINK_LIB)))

GENFILES	+= $(LDSCRIPT)
