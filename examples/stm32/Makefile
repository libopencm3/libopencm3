##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
# Do not print "Entering directory ...".
MAKEFLAGS += --no-print-directory
endif

all: stm32-h103 stm32-h107 mb525 lisa-m obldc other

stm32-h103:
	@printf "  BUILD   examples/stm32/stm32-h103\n"
	$(Q)$(MAKE) -C stm32-h103

stm32-h107:
	@printf "  BUILD   examples/stm32/stm32-h107\n"
	$(Q)$(MAKE) -C stm32-h107

mb525:
	@printf "  BUILD   examples/stm32/mb525\n"
	$(Q)$(MAKE) -C mb525

lisa-m:
	@printf "  BUILD   examples/stm32/lisa-m\n"
	$(Q)$(MAKE) -C lisa-m

other:
	@printf "  BUILD   examples/stm32/other\n"
	$(Q)$(MAKE) -C other

obldc:
	@printf "  BUILD   examples/stm32/obldc\n"
	$(Q)$(MAKE) -C obldc

clean:
	@printf "  CLEAN   examples/stm32/stm32-h103\n"
	$(Q)$(MAKE) -C stm32-h103 clean
	@printf "  CLEAN   examples/stm32/stm32-h107\n"
	$(Q)$(MAKE) -C stm32-h107 clean
	@printf "  CLEAN   examples/stm32/mb525\n"
	$(Q)$(MAKE) -C mb525 clean
	@printf "  CLEAN   examples/stm32/lisa-m\n"
	$(Q)$(MAKE) -C lisa-m clean
	@printf "  CLEAN   examples/stm32/other\n"
	$(Q)$(MAKE) -C other clean
	@printf "  CLEAN   examples/stm32/obldc\n"
	$(Q)$(MAKE) -C obldc clean

.PHONY: stm32-h103 stm32-h107 mb525 lisa-m other obldc clean

