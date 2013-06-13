/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Tomaz Solc <tomaz.solc@tablix.org>
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

#include <libopencm3/cm3/assert.h>

void __attribute__((weak)) cm3_assert_failed(void)
{
	while (1);
}

void __attribute__((weak)) cm3_assert_failed_verbose(
		const char *file __attribute__((unused)),
		int line __attribute__((unused)),
		const char *func __attribute__((unused)),
		const char *assert_expr __attribute__((unused)))
{
	cm3_assert_failed();
}
