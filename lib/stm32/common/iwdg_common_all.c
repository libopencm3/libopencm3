/** @addtogroup iwdg_file IWDG peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies ksarkies@internode.on.net

This library supports the Independent Watchdog Timer System in the STM32F1xx
series of ARM Cortex Microcontrollers by ST Microelectronics.

The watchdog timer uses the LSI (low speed internal) clock which is low power
and continues to operate during stop and standby modes. Its frequency is
nominally 32kHz (40kHz for the STM32F1xx series) but can vary from as low
as 17kHz up to 60kHz (refer to datasheet electrical characteristics).

Note that the User Configuration option byte provides a means of automatically
enabling the IWDG timer at power on (with counter value 0xFFF). If the
relevant bit is not set, the IWDG timer must be enabled by software.

@note: Tested: CPU STM32F103RET6, Board ET-ARM Stamp STM32

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

#include <libopencm3/stm32/iwdg.h>

#define LSI_FREQUENCY 32000
#define COUNT_LENGTH 12
#define COUNT_MASK ((1 << COUNT_LENGTH)-1)

/*---------------------------------------------------------------------------*/
/** @brief IWDG Enable Watchdog Timer

The watchdog timer is started. The timeout period defaults to 512 milliseconds
unless it has been previously defined.

*/

void iwdg_start(void)
{
	IWDG_KR = IWDG_KR_START;
}

/*---------------------------------------------------------------------------*/
/** @brief IWDG Set Period in Milliseconds

The countdown period is converted into count and prescale values. The maximum
period is 32.76 seconds; values above this are truncated. Periods less than 1ms
are not supported by this library.

A delay of up to 5 clock cycles of the LSI clock (about 156 microseconds)
can occasionally occur if the prescale or preload registers are currently busy
loading a previous value.

@param[in] period uint32_t Period in milliseconds (< 32760) from a watchdog
reset until a system reset is issued.
*/
void iwdg_set_period_ms(uint32_t period)
{
	const int PRESCALER_MAX = 6;
	uint8_t prescale = 0;

	/* Set the count to represent ticks of 8kHz clock (the 32kHz LSI clock
	 * divided by 4 = lowest prescaler setting)
	 */
	uint32_t count = period << 3;

	/* Prevent underflow */
	if (count == 0) {
		count = 1;
	}

	/* Shift count while increasing prescaler as many times as needed to
	 * fit into IWDG_RLR
	 */
	while ((count - 1) >> COUNT_LENGTH) {
		count >>= 1;
		prescale++;
	}

	/* IWDG_RLR actually holds count - 1 */
	count--;

	/* Clamp to max possible period */
	if (prescale > PRESCALER_MAX) {
		count = COUNT_MASK;
		prescale = PRESCALER_MAX;
	}

	while (iwdg_prescaler_busy());
	IWDG_KR = IWDG_KR_UNLOCK;
	IWDG_PR = prescale;
	while (iwdg_reload_busy());
	IWDG_KR = IWDG_KR_UNLOCK;
	IWDG_RLR = count & COUNT_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief IWDG Get Reload Register Status

@returns boolean: TRUE if the reload register is busy and unavailable for
loading a new count value.
*/

bool iwdg_reload_busy(void)
{
	return IWDG_SR & IWDG_SR_RVU;
}

/*---------------------------------------------------------------------------*/
/** @brief IWDG Get Prescaler Register Status

@returns boolean: TRUE if the prescaler register is busy and unavailable for
loading a new period value.
*/

bool iwdg_prescaler_busy(void)
{
	return IWDG_SR & IWDG_SR_PVU;
}

/*---------------------------------------------------------------------------*/
/** @brief IWDG reset Watchdog Timer

The watchdog timer is reset. The counter restarts from the value in the reload
register.
*/

void iwdg_reset(void)
{
	IWDG_KR = IWDG_KR_RESET;
}
/**@}*/

