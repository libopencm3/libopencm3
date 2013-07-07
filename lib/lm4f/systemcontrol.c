/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#include <libopencm3/lm4f/systemcontrol.h>

/**
 * \brief Enable the clock source for the peripheral
 *
 * @param[in] periph peripheral and clock type to enable @see lm4f_clken
 */
void periph_clock_enable(enum lm4f_clken periph)
{
	MMIO32(SYSCTL_BASE + (periph >> 5)) |= 1 << (periph & 0x1f);
}

/**
 * \brief Disable the clock source for the peripheral
 *
 * @param[in] periph peripheral and clock type to enable @see lm4f_clken
 */
void periph_clock_disable(enum lm4f_clken periph)
{
	MMIO32(SYSCTL_BASE + (periph >> 5)) &= ~(1 << (periph & 0x1f));
}
