/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32F4xx Analog to Digital
Converters</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2019
Matthew Lai <m@matthewlai.ca>
@author @htmlonly &copy; @endhtmlonly 2009
Edward Cheeseman <evbuilder@users.sourceforge.net>

@date 31 August 2012

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Matthew Lai <m@matthewlai.ca>
 * Copyright (C) 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
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

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/stm32/common/adc_common_v1_multi.h>

/* --- Convenience macros -------------------------------------------------- */
/* EXTSEL[3:0]: External event selection for regular group. */
/****************************************************************************/
/** @defgroup adc_trigger_regular ADC Trigger Identifier for Regular group
@ingroup adc_defines

@{*/
/** Timer 1 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM1_CC1		(0x0 << 24)
/** Timer 1 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM1_CC2		(0x1 << 24)
/** Timer 1 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM1_CC3		(0x2 << 24)
/** Timer 2 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM2_CC2		(0x3 << 24)
/** Timer 5 TRGO Event */
#define ADC_CR2_EXTSEL_TIM5_TRGO	(0x4 << 24)
/** Timer 4 Compare Output 4 */
#define ADC_CR2_EXTSEL_TIM4_CC4		(0x5 << 24)
/** Timer 3 Compare Output 4 */
#define ADC_CR2_EXTSEL_TIM3_CC4		(0x6 << 24)
/** Timer 8 TRGO Event */
#define ADC_CR2_EXTSEL_TIM8_TRGO	(0x7 << 24)
/** Timer 8 TRGO2 Event */
#define ADC_CR2_EXTSEL_TIM8_TRGO2	(0x8 << 24)
/** Timer 1 TRGO Event */
#define ADC_CR2_EXTSEL_TIM1_TRGO	(0x9 << 24)
/** Timer 1 TRGO2 Event */
#define ADC_CR2_EXTSEL_TIM1_TRGO2	(0xA << 24)
/** Timer 2 TRGO Event */
#define ADC_CR2_EXTSEL_TIM2_TRGO	(0xB << 24)
/** Timer 4 TRGO Event */
#define ADC_CR2_EXTSEL_TIM4_TRGO	(0xC << 24)
/** Timer 6 TRGO Event */
#define ADC_CR2_EXTSEL_TIM6_TRGO	(0xD << 24)
/** EXTI Line 11 Event */
#define ADC_CR2_EXTSEL_EXTI_LINE_11	(0xF << 24)
/**@}*/

/* JEXTSEL[3:0]: External event selection for injected group. */
/****************************************************************************/
/** @defgroup adc_trigger_injected ADC Trigger Identifier for Injected group
@ingroup adc_defines

@{*/
#define ADC_CR2_JEXTSEL_TIM1_TRGO	(0x0 << 16)
#define ADC_CR2_JEXTSEL_TIM1_CC4	(0x1 << 16)
#define ADC_CR2_JEXTSEL_TIM2_TRGO	(0x2 << 16)
#define ADC_CR2_JEXTSEL_TIM2_CC1	(0x3 << 16)
#define ADC_CR2_JEXTSEL_TIM3_CC4	(0x4 << 16)
#define ADC_CR2_JEXTSEL_TIM4_TRGO	(0x5 << 16)
/* 0x6 undefined */
#define ADC_CR2_JEXTSEL_TIM8_CC4	(0x7 << 16)
#define ADC_CR2_JEXTSEL_TIM1_TRGO2	(0x8 << 16)
#define ADC_CR2_JEXTSEL_TIM8_TRGO	(0x9 << 16)
#define ADC_CR2_JEXTSEL_TIM8_TRGO2	(0xA << 16)
#define ADC_CR2_JEXTSEL_TIM3_cc3	(0xB << 16)
#define ADC_CR2_JEXTSEL_TIM5_TRGO	(0xC << 16)
#define ADC_CR2_JEXTSEL_TIM3_CC1	(0xD << 16)
#define ADC_CR2_JEXTSEL_TIM6_TRGO	(0xE << 16)
/* 0xf undefined */
/**@}*/

#endif
