/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <libopencm3/sam3x/pmc.h>

void pmc_plla_config(u8 mul, u8 div)
{
	CKGR_PLLAR = CKGR_PLLAR_ONE | (mul << 16) |
			CKGR_PLLAR_PLLACOUNT_MASK | div;
	while (!(PMC_SR & PMC_SR_LOCKA));
}

void pmc_peripheral_clock_enable(u8 pid)
{
	if (pid < 32)
		PMC_PCER0 = 1 << pid;
	else
		PMC_PCER1 = 1 << (pid & 31);
}

void pmc_peripheral_clock_disable(u8 pid)
{
	if (pid < 32)
		PMC_PCDR0 = 1 << pid;
	else
		PMC_PCDR1 = 1 << (pid & 31);
}

