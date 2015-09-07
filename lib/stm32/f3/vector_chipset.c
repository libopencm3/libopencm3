/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#include <libopencm3/cm3/scb.h>

extern unsigned _ccm_data_loadaddr, _ccm_data, _ccm_edata, _ccm_ebss;

static void pre_main(void)
{
	volatile unsigned *src, *dest;

	/* Enable access to Floating-Point coprocessor. */
	SCB_CPACR |= SCB_CPACR_FULL * (SCB_CPACR_CP10 | SCB_CPACR_CP11);

	/* copy initialized code and data to CCM RAM */
	for (src = &_ccm_data_loadaddr, dest = &_ccm_data;
		dest < &_ccm_edata;
		src++, dest++) {
		*dest = *src;
	}

	/* clear zero-initialized data on CCM RAM */
	while (dest < &_ccm_ebss) {
		*dest++ = 0;
	}
}
