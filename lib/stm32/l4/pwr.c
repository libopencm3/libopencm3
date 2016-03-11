/** @defgroup pwr_file PWR
 *
 * @ingroup STM32L4xx
 *
 * @brief <b>libopencm3 STM32L4xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2011 Stephen Caudle <scaudle@doceme.com>
 * @author @htmlonly &copy; @endhtmlonly 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
 *
 * @date 4 March 2013
 *
 * This library supports the power control system for the
 * STM32L4 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
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
#include <libopencm3/stm32/pwr.h>

void pwr_set_vos_range(enum pwr_vos_scale scale)
{
	uint32_t reg32;

	reg32 = PWR_CR1;
	reg32 &= ~(PWR_CR1_VOS_MASK << PWR_CR1_VOS_SHIFT);
	if (scale == PWR_SCALE1) {
		reg32 |= (PWR_CR1_VOS_RANGE_1 << PWR_CR1_VOS_SHIFT);
	} else if (scale == PWR_SCALE1) {
		reg32 |= (PWR_CR1_VOS_RANGE_2 << PWR_CR1_VOS_SHIFT);
	}
	PWR_CR1 = reg32;
}
/*---------------------------------------------------------------------------*/
/** @brief Disable Backup Domain Write Protection.

This allows backup domain registers to be changed. These registers are write
protected after a reset.
*/

void pwr_disable_backup_domain_write_protect(void)
{
	PWR_CR1 |= PWR_CR1_DBP;
}

/*---------------------------------------------------------------------------*/
/** @brief Re-enable Backup Domain Write Protection.

This protects backup domain registers from inadvertent change.
*/

void pwr_enable_backup_domain_write_protect(void)
{
	PWR_CR1 &= ~PWR_CR1_DBP;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Power Voltage Detector.

This provides voltage level threshold detection. The result of detection is
provided in the power voltage detector output flag (see @ref pwr_voltage_high)
or by setting the EXTI16 interrupt (see datasheet for configuration details).

@param[in] pvd_level uint32_t. Taken from @ref pwr_pls.
*/

void pwr_enable_power_voltage_detect(uint32_t pvd_level)
{
	PWR_CR2 &= ~(PWR_CR2_PLS_MASK << PWR_CR2_PLS_SHIFT);
	PWR_CR2 |= (PWR_CR2_PVDE | (pvd_level << PWR_CR2_PLS_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Power Voltage Detector.

*/

void pwr_disable_power_voltage_detect(void)
{
	PWR_CR2 &= ~PWR_CR2_PVDE;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Standby Flag.

This is set when the processor returns from a standby mode.
*/

void pwr_clear_standby_flag(void)
{
	PWR_SCR |= PWR_SCR_CSBF;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Wakeup Flag.

This is set when the processor receives a wakeup signal.
*/

void pwr_clear_wakeup_flag(void)
{
	PWR_SCR |= PWR_SCR_CWUF1 | PWR_SCR_CWUF2 | PWR_SCR_CWUF3 | PWR_SCR_CWUF4 | PWR_SCR_CWUF5;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Wakeup Pin.

The wakeup pin is used for waking the processor from standby mode.
*/

void pwr_enable_wakeup_pin(void)
{
	PWR_CR3 |= PWR_CR3_EWUP1 | PWR_CR3_EWUP2 | PWR_CR3_EWUP3 | PWR_CR3_EWUP4 | PWR_CR3_EWUP5;
}

/*---------------------------------------------------------------------------*/
/** @brief Release Wakeup Pin.

The wakeup pin is used for general purpose I/O.
*/

void pwr_disable_wakeup_pin(void)
{
	PWR_CR3 &= ~PWR_CR3_EWUP1 & ~PWR_CR3_EWUP2 & ~PWR_CR3_EWUP3 & ~PWR_CR3_EWUP4 & ~PWR_CR3_EWUP5;
}

/*---------------------------------------------------------------------------*/
/** @brief Get Voltage Detector Output.

The voltage detector threshold must be set when the power voltage detector is
enabled, see @ref pwr_enable_power_voltage_detect.

@returns boolean: TRUE if the power voltage is above the preset voltage
threshold.
*/

bool pwr_voltage_high(void)
{
	return PWR_SR2 & PWR_SR2_PVDO;
}

/*---------------------------------------------------------------------------*/
/** @brief Get Standby Flag.

The standby flag is set when the processor returns from a standby state. It is
cleared by software (see @ref pwr_clear_standby_flag).

@returns boolean: TRUE if the processor was in standby state.
*/

bool pwr_get_standby_flag(void)
{
	return PWR_SR1 & PWR_SR1_SBF;
}

/*---------------------------------------------------------------------------*/
/** @brief Get Wakeup Flag.

The wakeup flag is set when a wakeup event has been received. It is
cleared by software (see @ref pwr_clear_wakeup_flag).

@returns boolean: TRUE if a wakeup event was received.
*/

bool pwr_get_wakeup_flag(void)
{
	return PWR_SR1 & (PWR_SR1_WUF1 | PWR_SR1_WUF2 | PWR_SR1_WUF3 | PWR_SR1_WUF4 | PWR_SR1_WUF5);
}
/**@}*/
