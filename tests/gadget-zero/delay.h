/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Karl Palsson <karlp@tweak.net.au>
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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * Initialize the timers used for delays.
	 */
	void delay_setup(void);

	/**
	 * busy wait for a number of usecs.
	 * @param us number of usecs to delay.
	 */
	void delay_us(uint16_t us);

#ifdef __cplusplus
}
#endif