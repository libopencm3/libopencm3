/** @defgroup dac_defines DAC Defines

@brief <b>Defined Constants and Types for the STM32F4xx DAC</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@date 5 December 2012

LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_DAC_H
#define LIBOPENCM3_DAC_H

#include <libopencm3/stm32/common/dac_common_all.h>


/** DAC status register (DAC_SR).
 * not available on STM32F4x1/STM32F4x2 */
#define DAC_SR				MMIO32(DAC_BASE + 0x34)

/* --- DAC_SR values ------------------------------------------------------- */

/** DMAUDR2: DAC channel 1 DMA underrun flag */
#define DAC_SR_DMAUDR1		(1 << 13)


/** DMAUDR2: DAC channel 2 DMA underrun flag.
 * not available on STM32F4x1/STM32F4x2 and STM32F410*/
#define DAC_SR_DMAUDR2		(1 << 29)


#endif

