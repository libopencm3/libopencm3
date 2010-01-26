##
## This file is part of the libopenstm32 project.
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

# Do not print "Entering directory ...".
## MAKEFLAGS += --no-print-directory

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
endif

all: stm32-h103 mb525

stm32-h103:
	@printf "  BUILD   examples/stm32-h103\n"
	$(Q)$(MAKE) -C stm32-h103

mb525:
	@printf "  BUILD   examples/mb525\n"
	$(Q)$(MAKE) -C mb525

clean:
	@printf "  CLEAN   examples/stm32-h103\n"
	$(Q)$(MAKE) -C stm32-h103 clean
	@printf "  CLEAN   examples/mb525\n"
	$(Q)$(MAKE) -C mb525 clean

.PHONY: stm32-h103 mb525 clean

