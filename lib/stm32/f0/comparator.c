/** @defgroup comp_file COMP
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx COMP</b>
 *
 * @version 1.0.0
 *
 * @date 10 July 2013
 *
 * LGPL License Terms @ref lgpl_license
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

#include <libopencm3/stm32/comparator.h>

void comp_enable(uint8_t id)
{
	COMP_CSR(id) |= COMP_CSR_EN;
}

void comp_disable(uint8_t id)
{
	COMP_CSR(id) &= ~COMP_CSR_EN;
}

void comp_select_input(uint8_t id, uint32_t input)
{
	COMP_CSR(id) = (COMP_CSR(id) & ~COMP_CSR_INSEL) | input;
}

void comp_select_output(uint8_t id, uint32_t output)
{
	COMP_CSR(id) = (COMP_CSR(id) & ~COMP_CSR_OUTSEL) | output;
}

void comp_select_hyst(uint8_t id, uint32_t hyst)
{
	COMP_CSR(id) = (COMP_CSR(id) & ~COMP_CSR_HYST) | hyst;
}

void comp_select_speed(uint8_t id, uint32_t speed)
{
	COMP_CSR(id) = (COMP_CSR(id) & ~COMP_CSR_SPEED) | speed;
}
/**@}*/

