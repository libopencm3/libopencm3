##
## This file is part of the libopenstm32 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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
MAKEFLAGS += --no-print-directory

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
endif

all: miniblink fancyblink usart

miniblink:
	@printf "  BUILD   miniblink\n"
	$(Q)$(MAKE) -C miniblink

fancyblink:
	@printf "  BUILD   fancyblink\n"
	$(Q)$(MAKE) -C fancyblink

usart:
	@printf "  BUILD   usart\n"
	$(Q)$(MAKE) -C usart

clean:
	@printf "  CLEAN   miniblink\n"
	$(Q)$(MAKE) -C miniblink clean
	@printf "  CLEAN   fancyblink\n"
	$(Q)$(MAKE) -C fancyblink clean
	@printf "  CLEAN   usart\n"
	$(Q)$(MAKE) -C usart clean

.PHONY: miniblink fancyblink usart clean

