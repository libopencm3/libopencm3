/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#include <libopencm3/cm3/common.h>

extern unsigned _etext_ram, _text_ram, _etext_rom;

#define CREG_M4MEMMAP   MMIO32((0x40043000U + 0x100))

static void pre_main(void)
{
	volatile unsigned *src, *dest;

	/* Copy the code from ROM to Real RAM (if enabled) */
	if ((&_etext_ram-&_text_ram) > 0) {
		src = &_etext_rom-(&_etext_ram-&_text_ram);
		/* Change Shadow memory to ROM (for Debug Purpose in case Boot
		 * has not set correctly the M4MEMMAP because of debug)
		 */
		CREG_M4MEMMAP = (unsigned long)src;

		for (dest = &_text_ram; dest < &_etext_ram; ) {
			*dest++ = *src++;
		}

		/* Change Shadow memory to Real RAM */
		CREG_M4MEMMAP = (unsigned long)&_text_ram;

		/* Continue Execution in RAM */
	}
}
