/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019
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

#include <libopencm3/cm3/tpiu.h>

/*---------------------------------------------------------------------------*/
/** @brief TPIU Set the clock divisor for the baud rate of the Serial Wire
 * Output (SWO)
 *
 * The TPIU output will be divided by the specified divisor value.
 *
 * Writing to the register automatically updates the prescale counter,
 * immediately affecting the baud rate of the serial data output. If a debugger
 * changes the register value while the TPIU is transmitting data, the effect on
 * the output stream is UNPREDICTABLE and the required recovery process is
 * IMPLEMENTATION DEFINED.
 *
 * @return void
 */
void tpiu_set_output_clock_divider(uint16_t div) {
  // The TPIU internally adds one to the prescaler, so remove it here.
  const uint16_t scale = div - 1;
  // Prescaler is bits [12:0]
  const uint16_t prescaler_mask = 0x1FFF;
  TPIU_ACPR = (TPIU_ACPR & ~prescaler_mask) | (scale & prescaler_mask);
}

/*---------------------------------------------------------------------------*/
/** @brief TPIU Set the output clock speed of the TPIU to the specified value
 *
 * Sets the output clock rate of the TPIU to be as close as possible to the
 * specified value. Note that not all output clock rates can be accurately
 * selected for any given processor core clock.
 *
 * @return void
 */
void tpiu_set_output_clock_speed(uint32_t core_clock_hz, uint32_t output_hz) {
  // Calculated desired divisor as core clock speed over baudrate.
  const uint32_t scaler = (core_clock_hz / output_hz) - 1;
  tpiu_set_output_clock_divider(scaler);
}

/*---------------------------------------------------------------------------*/
/** @brief TPIU Configure TPIU trace port output format
 *
 * Specifies the protocol for the trace output from the TPIU.
 * Permitted values are:
 *     TPIU_SPPR_SYNC			(0x0)
 *     TPIU_SPPR_ASYNC_MANCHESTER	(0x1)
 *     TPIU_SPPR_ASYNC_NRZ		(0x2)
 *
 * @return void
 */
void tpiu_set_trace_output_mode(uint16_t mode) {
  // TX Mode configuration is bits [1:0]
  const uint16_t txmode_mask = 0x03;
  TPIU_SPPR = (TPIU_SPPR & ~txmode_mask) | (mode & txmode_mask);
}

/*---------------------------------------------------------------------------*/
/** @brief TPIU Enable or disable continuous formatting
 *
 * If the formatter is disabled, only the ITM and DWT trace source passes
 * through. The TPIU accepts and discards data from the ETM. This function can
 * be used to connect a device containing an ETM to a trace capture device that
 * is only able to capture SWO data. Enabling or disabling the formatter causes
 * momentary data corruption.
 *
 * @return void
 */
void tpiu_set_continuous_formatting_enabled(bool enable) {
  if (enable) {
    TPIU_FFCR |= TPIU_FFCR_ENFCONT;
  } else {
    TPIU_FFCR &= ~TPIU_FFCR_ENFCONT;
  }
}
