/** @addtogroup exti_file EXTI peripheral API
 * @ingroup peripheral_apis
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @date 10 January 2019
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

#include <libopencm3/stm32/exti.h>

/* @brief Get the rising edge interrupt requestf flag of a given EXTI interrupt.
 *
 * @param[in] exti unsigned int32 Exti line.
 *
 * */
uint32_t exti_get_rising_flag_status(uint32_t exti)
{
	return (EXTI_RPR1 & exti);
}

/* @brief Get the rising edge interrupt request flag of a given EXTI interrupt.
 *
 * @param[in] exti unsigned int32 Exti line.
 *
 * */
uint32_t exti_get_falling_flag_status(uint32_t exti)
{
	return (EXTI_FPR1 & exti);
}

/* @brief Resets the rising edge interrupt request pending flag of a given EXTI interrupt.
 *
 * @param[in] exti unsigned int32 Exti line.
 *
 * */
void exti_reset_rising_request(uint32_t extis)
{
	EXTI_RPR1 = extis;
}

/* @brief Resets the falling edge interrupt request pending flag of a given EXTI interrupt.
 *
 * @param[in] exti unsigned int32 Exti line.
 *
 * */
void exti_reset_falling_request(uint32_t extis)
{
	EXTI_FPR1 = extis;
}

/**@}*/
