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

all: miniblink fancyblink usart usb_cdcacm usb_hid button exti_both

miniblink:
	@printf "  BUILD   examples/stm32/stm32-h103/miniblink\n"
	$(Q)$(MAKE) -C miniblink

fancyblink:
	@printf "  BUILD   examples/stm32/stm32-h103/fancyblink\n"
	$(Q)$(MAKE) -C fancyblink

usart:
	@printf "  BUILD   examples/stm32/stm32-h103/usart\n"
	$(Q)$(MAKE) -C usart

spi:
	@printf "  BUILD   examples/stm32/stm32-h103/spi\n"
	$(Q)$(MAKE) -C spi

usb_cdcacm:
	@printf "  BUILD   examples/stm32/stm32-h103/usb_cdcacm\n"
	$(Q)$(MAKE) -C usb_cdcacm

usb_hid:
	@printf "  BUILD   examples/stm32/stm32-h103/usb_hid\n"
	$(Q)$(MAKE) -C usb_hid

button:
	@printf "  BUILD   examples/stm32/stm32-h103/button\n"
	$(Q)$(MAKE) -C button

exti_both:
	@printf "  BUILD   examples/stm32/stm32-h103/exti_both\n"
	$(Q)$(MAKE) -C exti_both

clean:
	@printf "  CLEAN   examples/stm32/stm32-h103/miniblink\n"
	$(Q)$(MAKE) -C miniblink clean
	@printf "  CLEAN   examples/stm32/stm32-h103/fancyblink\n"
	$(Q)$(MAKE) -C fancyblink clean
	@printf "  CLEAN   examples/stm32/stm32-h103/usart\n"
	$(Q)$(MAKE) -C usart clean
	@printf "  CLEAN   examples/stm32/stm32-h103/spi\n"
	$(Q)$(MAKE) -C spi clean
	@printf "  CLEAN   examples/stm32/stm32-h103/usb_cdcacm\n"
	$(Q)$(MAKE) -C usb_cdcacm clean
	@printf "  CLEAN   examples/stm32/stm32-h103/usb_hid\n"
	$(Q)$(MAKE) -C usb_hid clean
	@printf "  CLEAN   examples/stm32/stm32-h103/button\n"
	$(Q)$(MAKE) -C button clean
	@printf "  CLEAN   examples/stm32/stm32-h103/exti_both\n"
	$(Q)$(MAKE) -C exti_both clean

.PHONY: miniblink fancyblink usart spi usb_cdcacm usb_hid button exti_both clean

