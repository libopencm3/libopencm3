/** @defgroup pwr_file PWR peripheral API
 * @ingroup peripheral_apis
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @brief <b>libopencm3 STM32G0xx Power Control</b>
 *
 * @version 1.0.0
 *
 * This library supports the power control system for the
 * STM32G0 series of ARM Cortex Microcontrollers by ST Microelectronics.
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
#include <libopencm3/stm32/pwr.h>

/*---------------------------------------------------------------------------*/
/** @brief Setup voltage scaling range. 
 */
void pwr_set_vos_scale(enum pwr_vos_scale scale)
{
	uint32_t reg32;

	reg32 = PWR_CR1 & ~(PWR_CR1_VOS_MASK << PWR_CR1_VOS_SHIFT);
	reg32 |= (scale & PWR_CR1_VOS_MASK) << PWR_CR1_VOS_SHIFT;
	PWR_CR1 = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable RTC domain write protect. 
 */
void pwr_disable_backup_domain_write_protect(void)
{
	PWR_CR1 |= PWR_CR1_DBP;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable RTC domain write protect. 
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
 * @param[in] pvdr_level Power Voltage Detector Rising Threshold voltage @ref pwr_cr2_pvdrt.
 * @param[in] pvdf_level Power Voltage Detector Falling Threshold voltage @ref pwr_cr2_pvdft.
*/
void pwr_enable_power_voltage_detect(uint32_t pvdr_level, uint32_t pvdf_level)
{
	uint32_t reg32;

	reg32 = PWR_CR2;
	reg32 &= ~(PWR_CR2_PVDRT_MASK << PWR_CR2_PVDRT_SHIFT);
	reg32 &= ~(PWR_CR2_PVDFT_MASK << PWR_CR2_PVDFT_SHIFT);
	PWR_CR2 = (reg32 | (pvdf_level << PWR_CR2_PVDFT_SHIFT) | (pvdr_level << PWR_CR2_PVDRT_SHIFT) | PWR_CR2_PVDE);
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Power Voltage Detector.
*/
void pwr_disable_power_voltage_detect(void)
{
	PWR_CR2 &= ~PWR_CR2_PVDE;
}

/**@}*/
