/** @defgroup dac_defines DAC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Digital to Analog
 * Converter</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define DAC				DAC_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define DAC_CR				MMIO32(DAC_BASE + 0x00)
#define DAC_SWTRIGR			MMIO32(DAC_BASE + 0x04)
#define DAC_DHR12R1			MMIO32(DAC_BASE + 0x08)
#define DAC_DHR12L1			MMIO32(DAC_BASE + 0x0C)
#define DAC_DHR8R1			MMIO32(DAC_BASE + 0x10)
#define DAC_DOR1			MMIO32(DAC_BASE + 0x2C)
#define DAC_SR				MMIO32(DAC_BASE + 0x34)


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* DAC_CR Values ------------------------------------------------------------*/

#define DAC_CR_DMAUDRIE1		(1 << 13)
#define DAC_CR_DMAEN1			(1 << 12)

#define DAC_CR_TSEL1_SHIFT		3
#define DAC_CR_TSEL1			(7 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_TIM6_TRGO		(0 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_TIM8_TRGO		(1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_TIM7_TRGO		(2 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_TIM5_TRGO		(3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_TIM2_TRGO		(4 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_TIM4_TRGO		(5 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_EXT_9		(6 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_SWTRG		(7 << DAC_CR_TSEL1_SHIFT)

#define DAC_CR_TEN1			(1 << 2)
#define DAC_CR_BOFF1			(1 << 1)
#define DAC_CR_EN1			(1 << 0)

/* DAC_SWTRIGR Values -------------------------------------------------------*/

#define DAC_SWTRIGR_SWTRIG1		(1 << 0)

/* DAC_DHR12R1 Values -------------------------------------------------------*/

#define DAC_DHR12R1_DACC1DHR		0xFFF

/* DAC_DHR12L1 Values -------------------------------------------------------*/

#define DAC_DHR12L1_DACC1DHR		(0xFFF << 4)

/* DAC_DHR8R1 Values --------------------------------------------------------*/

#define DAC_DHR8R1_DACC1DHR		0xFF

/* DAC_DOR1 Values ----------------------------------------------------------*/

#define DAC_DOR1_DACC1DOR		0xFFF

/* DAC_SR Values ------------------------------------------------------------*/

#define DAC_SR_DMAUDR1			(1 << 13)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif
