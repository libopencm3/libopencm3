/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Owen Kirby <oskirby@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/sam/pmc.h>

void pmc_pllb_config(uint8_t mul, uint8_t div)
{
	CKGR_PLLBR = ((mul - 1) << 16) | CKGR_PLLBR_PLLBCOUNT_MASK | div;
	while (!(PMC_SR & PMC_SR_LOCKB));
}

void pmc_usb_set_source(enum usbck_src src)
{
	PMC_USB = (PMC_USB & ~PMC_USB_USBDIV_MASK) | src;
	PMC_SCER = PMC_SCER_UDP;
}


