/** @addtogroup timer_file

@author @htmlonly &copy; @endhtmlonly 2022 Oskar Hieronymus Maier <ohma@posteo.de>
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

#include <libopencm3/stm32/timer.h>

/*---------------------------------------------------------------------------*/
/** @brief Set Master Mode

Select what triggers the timer's TRGO output that can be used for triggering
ADCs or DACs.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref
tim_reg_base
@param[in] mode Unsigned int32. Master Mode @ref tim_mastermode
*/

void timer_set_master_mode(uint32_t timer_peripheral, uint32_t mode)
{
	uint32_t reg32 = (mode << TIM_CR2_MMS_BIT3_SHIFT);
	reg32 |= (mode << TIM_CR2_MMS_SHIFT);
	reg32 &= TIM_CR2_MMS_MASK;
	reg32 |= TIM_CR2(timer_peripheral) & ~ TIM_CR2_MMS_MASK;
	TIM_CR2(timer_peripheral) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Master mode 2

Select what triggers the timer's TRGO2 output that can be used for triggering
ADCs or DACs.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] mode Unsigned int32. Master Mode 2 @ref tim_mastermode2
*/

void timer_set_master_mode_2(uint32_t timer_peripheral, uint32_t mode)
{
	uint32_t reg32 = mode << TIM_CR2_MMS2_SHIFT;
	reg32 &= TIM_CR2(timer_peripheral) & ~ TIM_CR2_MMS2_MASK;
	TIM_CR2(timer_peripheral) = reg32;
}
