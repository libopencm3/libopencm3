/** @addtogroup opamp_file OPAMP peripheral API
 * @ingroup peripheral_apis
 */

/*
 * This file is part of the libopencm3 project.
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

/**@{*/

#include <libopencm3/stm32/opamp.h>

bool opamp_read_calout(uint32_t base)
{
	return (OPAMP_CSR(base) >> OPAMP_CSR_CALOUT_SHIFT) &
			OPAMP_CSR_CALOUT_MASK;
}

void opamp_high_speed_mode_enable(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_OPAHSM;
}

void opamp_high_speed_mode_disable(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_OPAHSM;
}

void opamp_output_set_internal(uint32_t base)
{
	OPAMP_CSR(base) |= OPAMP_CSR_OPAINTOEN;
}

void opamp_output_set_external(uint32_t base)
{
	OPAMP_CSR(base) &= ~OPAMP_CSR_OPAINTOEN;
}

/**@}*/
