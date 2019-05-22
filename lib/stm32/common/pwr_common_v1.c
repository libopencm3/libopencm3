/** @addtogroup pwr_file PWR peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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
/** @brief Disable Backup Domain Write Protection.

This allows backup domain registers to be changed. These registers are write
protected after a reset.
*/

void pwr_disable_backup_domain_write_protect(void)
{
	PWR_CR |= PWR_CR_DBP;
}

/*---------------------------------------------------------------------------*/
/** @brief Re-enable Backup Domain Write Protection.

This protects backup domain registers from inadvertent change.
*/

void pwr_enable_backup_domain_write_protect(void)
{
	PWR_CR &= ~PWR_CR_DBP;
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
	PWR_CR &= ~PWR_CR_PLS_MASK;
	PWR_CR |= (PWR_CR_PVDE | pvd_level);
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Power Voltage Detector.

*/

void pwr_disable_power_voltage_detect(void)
{
	PWR_CR &= ~PWR_CR_PVDE;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Standby Flag.

This is set when the processor returns from a standby mode.
*/

void pwr_clear_standby_flag(void)
{
	PWR_CR |= PWR_CR_CSBF;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Wakeup Flag.

This is set when the processor receives a wakeup signal.
*/

void pwr_clear_wakeup_flag(void)
{
	PWR_CR |= PWR_CR_CWUF;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Standby Mode in Deep Sleep.

*/

void pwr_set_standby_mode(void)
{
	PWR_CR |= PWR_CR_PDDS;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Stop Mode in Deep Sleep.

*/

void pwr_set_stop_mode(void)
{
	PWR_CR &= ~PWR_CR_PDDS;
}

/*---------------------------------------------------------------------------*/
/** @brief Voltage Regulator On in Stop Mode.

*/

void pwr_voltage_regulator_on_in_stop(void)
{
	PWR_CR &= ~PWR_CR_LPDS;
}

/*---------------------------------------------------------------------------*/
/** @brief Voltage Regulator Low Power in Stop Mode.

*/

void pwr_voltage_regulator_low_power_in_stop(void)
{
	PWR_CR |= PWR_CR_LPDS;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Wakeup Pin.

The wakeup pin is used for waking the processor from standby mode.
*/

void pwr_enable_wakeup_pin(void)
{
	PWR_CSR |= PWR_CSR_EWUP;
}

/*---------------------------------------------------------------------------*/
/** @brief Release Wakeup Pin.

The wakeup pin is used for general purpose I/O.
*/

void pwr_disable_wakeup_pin(void)
{
	PWR_CSR &= ~PWR_CSR_EWUP;
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
	return !(PWR_CSR & PWR_CSR_PVDO);
}

/*---------------------------------------------------------------------------*/
/** @brief Get Standby Flag.

The standby flag is set when the processor returns from a standby state. It is
cleared by software (see @ref pwr_clear_standby_flag).

@returns boolean: TRUE if the processor was in standby state.
*/

bool pwr_get_standby_flag(void)
{
	return PWR_CSR & PWR_CSR_SBF;
}

/*---------------------------------------------------------------------------*/
/** @brief Get Wakeup Flag.

The wakeup flag is set when a wakeup event has been received. It is
cleared by software (see @ref pwr_clear_wakeup_flag).

@returns boolean: TRUE if a wakeup event was received.
*/

bool pwr_get_wakeup_flag(void)
{
	return PWR_CSR & PWR_CSR_WUF;
}
/**@}*/
