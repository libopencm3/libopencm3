/** @defgroup pwr_file PWR peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32G4xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2020 Ben Brewer <ben.brewer@codethink.co.uk>
 *
 * @date 29 July 2020
 *
 * This library supports the power control system for the
 * STM32G4 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
 * Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 * Copyright (C) 2020 Ben Brewer <ben.brewer@codethink.co.uk>
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

	reg32 = PWR_CR1 & ~(PWR_CR1_VOS_MASK << PWR_CR1_VOS_SHIFT);
	reg32 |= (scale & PWR_CR1_VOS_MASK) << PWR_CR1_VOS_SHIFT;
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

/*---------------------------------------------------------------------------*/
/** @brief Select the low power mode used in deep sleep.
 * @param lpms low power mode @ref pwr_cr1_lpms
 */
void pwr_set_low_power_mode_selection(uint32_t lpms)
{
	uint32_t reg32;

	reg32 = PWR_CR1;
	reg32 &= ~(PWR_CR1_LPMS_MASK << PWR_CR1_LPMS_SHIFT);
	PWR_CR1 = (reg32 | (lpms << PWR_CR1_LPMS_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Power Voltage Detector.
 * @param[in] pvd_level Power Voltage Detector Falling Threshold voltage @ref pwr_pls.
*/
void pwr_enable_power_voltage_detect(uint32_t pvd_level)
{
	uint32_t reg32;

	reg32 = PWR_CR2;
	reg32 &= ~(PWR_CR2_PLS_MASK << PWR_CR2_PLS_SHIFT);
	PWR_CR2 = (reg32 | (pvd_level << PWR_CR2_PLS_SHIFT) | PWR_CR2_PVDE);
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Power Voltage Detector.
*/
void pwr_disable_power_voltage_detect(void)
{
	PWR_CR2 &= ~PWR_CR2_PVDE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Boost Mode.
*/
void pwr_enable_boost(void)
{
	PWR_CR5 &= ~PWR_CR5_R1MODE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Boost Mode.
*/
void pwr_disable_boost(void)
{
	PWR_CR5 |= PWR_CR5_R1MODE;
}

/**@}*/
