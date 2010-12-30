##
## This file is part of the libopencm3 project.
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

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
# Do not print "Entering directory ...".
MAKEFLAGS += --no-print-directory
endif

# TODO: Add usb_dfu later, doesn't build at the moment.
all: usb_hid

usb_hid:
	@printf "  BUILD   examples/stm32/lisa-m/usb_hid\n"
	$(Q)$(MAKE) -C usb_hid

clean:
	@printf "  CLEAN   examples/stm32/lisa-m/usb_hid\n"
	$(Q)$(MAKE) -C usb_hid clean

.PHONY: usb_hid clean

