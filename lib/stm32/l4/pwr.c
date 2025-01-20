/** @defgroup pwr_file PWR peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32L4xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
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
 * Copyright (C) 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
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

void pwr_set_vos_scale(enum pwr_vos_scale scale)
{
	uint32_t reg32;

	reg32 = PWR_CR1;
	reg32 &= ~(PWR_CR1_VOS_MASK << PWR_CR1_VOS_SHIFT);
	switch (scale) {
	case PWR_SCALE1:
		reg32 |= (PWR_CR1_VOS_RANGE_1 << PWR_CR1_VOS_SHIFT);
		break;
	case PWR_SCALE2:
		reg32 |= (PWR_CR1_VOS_RANGE_2 << PWR_CR1_VOS_SHIFT);
		break;
	}
	PWR_CR1 = reg32;
}

/** Disable Backup Domain Write Protection
 *
 * This allows backup domain registers to be changed. These registers are write
 * protected after a reset.
 */
void pwr_disable_backup_domain_write_protect(void)
{
	PWR_CR1 |= PWR_CR1_DBP;
}

/** Re-enable Backup Domain Write Protection
 *
 * This protects backup domain registers from inadvertent change.
 */
void pwr_enable_backup_domain_write_protect(void)
{
	PWR_CR1 &= ~PWR_CR1_DBP;
}

/** Enable Low Power Run
 * 
 * This enables low power run mode. The clock frequency is limited to 2 MHz in this mode 
 * and must be set before entering low power run mode.
 */
void pwr_enable_low_power_run(void)
{
	PWR_CR1 |= PWR_CR1_LPR;
}

/** Disable Low Power Run
 * 
 * This disables low power run mode
 */
void pwr_disable_low_power_run(void)
{
	PWR_CR1 &= ~PWR_CR1_LPR;
}

/** @brief Select the low power mode used in deep sleep.
 * 
 * Set which power mode is entered when the processor enters deep sleep.
 * 
 * @param[in] lpms low power mode @ref pwr_cr1_lpms
 */
void pwr_set_low_power_mode_selection(uint32_t lpms)
{
	uint32_t reg32;

	reg32 = PWR_CR1;
	reg32 &= ~(PWR_CR1_LPMS_MASK << PWR_CR1_LPMS_SHIFT);
	PWR_CR1 = (reg32 | (lpms << PWR_CR1_LPMS_SHIFT));
}

/**@}*/
