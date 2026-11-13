/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the GD32F1x0 ADC</b>
 *
 * @ingroup GD32F1x0_defines
 *
 * @version 1.0.0
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

/* GD32F1x0 ADC uses the *STM32F1-style v1 layout* (RSQ0/RSQ1/RSQ2 sequence
 * registers, SAMPT0/SAMPT1 per-channel sample times, two-step
 * RSTCLB+CLB calibration). It does NOT match libopencm3's stm32/f0 ADC
 * (the v2 layout with CHSELR/SMPR). See decisions/v0.2/ADC.md.
 *
 * Forwarding to stm32/f1/adc.h, which provides the v1 family-specific
 * defines (ADC_JOFR*, ADC_HTR/LTR, ADC_SQR1-3) plus pulls in
 * adc_common_v1.h for the shared functions (adc_set_regular_sequence,
 * adc_set_sample_time, adc_calibrate, etc.).
 *
 * NOTE: no header guard here on purpose. stm32/f1/adc.h has its own
 * LIBOPENCM3_ADC_H guard, and a duplicate on this side would no-op the
 * include.
 */
#include <libopencm3/stm32/f1/adc.h>
