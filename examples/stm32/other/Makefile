##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

all: i2c_stts75_sensor adc_temperature_sensor dma_mem2mem timer_interrupt systick dogm128 rtc usb_cdcacm usb_dfu usb_hid

i2c_stts75_sensor:
	@printf "  BUILD   examples/stm32/other/i2c_stts75_sensor\n"
	$(Q)$(MAKE) -C i2c_stts75_sensor

adc_temperature_sensor:
	@printf "  BUILD   examples/stm32/other/adc_temperature_sensor\n"
	$(Q)$(MAKE) -C adc_temperature_sensor

dma_mem2mem:
	@printf "  BUILD   examples/stm32/other/dma_mem2mem\n"
	$(Q)$(MAKE) -C dma_mem2mem

timer_interrupt:
	@printf "  BUILD   examples/stm32/other/timer_interrupt\n"
	$(Q)$(MAKE) -C timer_interrupt

systick:
	@printf "  BUILD   examples/stm32/other/systick\n"
	$(Q)$(MAKE) -C systick

dogm128:
	@printf "  BUILD   examples/stm32/other/dogm128\n"
	$(Q)$(MAKE) -C dogm128

rtc:
	@printf "  BUILD   examples/stm32/other/rtc\n"
	$(Q)$(MAKE) -C rtc

usb_cdcacm:
	@printf "  BUILD   examples/stm32/other/usb_cdcacm\n"
	$(Q)$(MAKE) -C usb_cdcacm

usb_dfu:
	@printf "  BUILD   examples/stm32/other/usb_dfu\n"
	$(Q)$(MAKE) -C usb_dfu

usb_hid:
	@printf "  BUILD   examples/stm32/other/usb_hid\n"
	$(Q)$(MAKE) -C usb_hid

clean:
	@printf "  CLEAN   examples/stm32/other/i2c_stts75_sensor\n"
	$(Q)$(MAKE) -C i2c_stts75_sensor clean
	@printf "  CLEAN   examples/stm32/other/adc_temperature_sensor\n"
	$(Q)$(MAKE) -C adc_temperature_sensor clean
	@printf "  CLEAN   examples/stm32/other/dma_mem2mem\n"
	$(Q)$(MAKE) -C dma_mem2mem clean
	@printf "  CLEAN   examples/stm32/other/timer_interrupt\n"
	$(Q)$(MAKE) -C timer_interrupt clean
	@printf "  CLEAN   examples/stm32/other/systick\n"
	$(Q)$(MAKE) -C systick clean
	@printf "  CLEAN   examples/stm32/other/dogm128\n"
	$(Q)$(MAKE) -C dogm128 clean
	@printf "  CLEAN   examples/stm32/other/rtc\n"
	$(Q)$(MAKE) -C rtc clean
	@printf "  CLEAN   examples/stm32/other/usb_cdcacm\n"
	$(Q)$(MAKE) -C usb_cdcacm clean
	@printf "  CLEAN   examples/stm32/other/usb_dfu\n"
	$(Q)$(MAKE) -C usb_dfu clean
	@printf "  CLEAN   examples/stm32/other/usb_hid\n"
	$(Q)$(MAKE) -C usb_hid clean

.PHONY: i2c_stts75_sensor adc_temperature_sensor dma_mem2mem timer_interrupt systick dogm128 rtc clean usb_cdcacm usb_dfu usb_hid

