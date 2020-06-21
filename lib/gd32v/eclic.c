/*
 * This file is part of the libopencm3 project.
 *
 * Copyright 2020 Lubomir Rintel <lkundrak@v3.sk>
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

#include <libopencm3/gd32v/eclic.h>

#define ECLIC_IRQ_OFFSET	19

void eclic_init(uint32_t num_irqs)
{
	uint32_t irq;

	ECLIC_CFG = 0;
	ECLIC_MTH = 0;

	for (irq = 0; irq < ECLIC_IRQ_OFFSET + num_irqs; irq++) {
		ECLIC_INTIP(irq) = 0x00;
		ECLIC_INTIE(irq) = 0x00;
		ECLIC_INTATTR(irq) = 0x01; /* Vectored more. */
		ECLIC_INTCFG(irq) = 0x00;
	}
}

void eclic_enable_irq(uint32_t irq)
{
	ECLIC_INTIE(ECLIC_IRQ_OFFSET + irq) = 0x01;
}

void eclic_disable_irq(uint32_t irq)
{
	ECLIC_INTIE(ECLIC_IRQ_OFFSET + irq) = 0x00;
}
