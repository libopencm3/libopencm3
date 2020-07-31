/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32F7xx Analog to Digital
Converters</b>

@ingroup STM32F7xx_defines

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

/* ADC injected channel data offset register x (ADC_JOFRx) (x=1..4) */
#define ADC_JOFR1(block)		MMIO32((block) + 0x14)
#define ADC_JOFR2(block)		MMIO32((block) + 0x18)
#define ADC_JOFR3(block)		MMIO32((block) + 0x1c)
#define ADC_JOFR4(block)		MMIO32((block) + 0x20)

/* ADC watchdog high threshold register (ADC_HTR) */
#define ADC_HTR(block)			MMIO32((block) + 0x24)

/* ADC watchdog low threshold register (ADC_LTR) */
#define ADC_LTR(block)			MMIO32((block) + 0x28)

/* ADC regular sequence register 1 (ADC_SQR1) */
#define ADC_SQR1(block)			MMIO32((block) + 0x2c)

/* ADC regular sequence register 2 (ADC_SQR2) */
#define ADC_SQR2(block)			MMIO32((block) + 0x30)

/* ADC regular sequence register 3 (ADC_SQR3) */
#define ADC_SQR3(block)			MMIO32((block) + 0x34)

/* ADC injected sequence register (ADC_JSQR) */
#define ADC_JSQR(block)			MMIO32((block) + 0x38)

/* ADC injected data register x (ADC_JDRx) (x=1..4) */
#define ADC_JDR1(block)			MMIO32((block) + 0x3c)
#define ADC_JDR2(block)			MMIO32((block) + 0x40)
#define ADC_JDR3(block)			MMIO32((block) + 0x44)
#define ADC_JDR4(block)			MMIO32((block) + 0x48)

/* ADC regular data register (ADC_DR) */
#define ADC_DR(block)			MMIO32((block) + 0x4c)

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *@{*/
#define ADC_CHANNEL_TEMP	18
#define ADC_CHANNEL_VREF	17
#define ADC_CHANNEL_VBAT	18
/**@}*/


/* --- ADC_CR1 values (note some of these are defined elsewhere) ----------- */
#define ADC_CR1_AWDCH_MAX		18

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

/* ADC_SMPRG ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_3CYC		0x0
#define ADC_SMPR_SMP_15CYC		0x1
#define ADC_SMPR_SMP_28CYC		0x2
#define ADC_SMPR_SMP_56CYC		0x3
#define ADC_SMPR_SMP_84CYC		0x4
#define ADC_SMPR_SMP_112CYC		0x5
#define ADC_SMPR_SMP_144CYC		0x6
#define ADC_SMPR_SMP_480CYC		0x7
/**@}*/

/* --- ADC_SQR1 values ----------------------------------------------------- */
#define ADC_SQR1_L_MSK			(0xf << ADC_SQR1_L_LSB)

#define ADC_SQR_MAX_CHANNELS_REGULAR	16

/* ADCPRE: ADC prescaler. */
/****************************************************************************/
/** @defgroup adc_ccr_adcpre ADC Prescale
@ingroup adc_defines

@{*/
#define ADC_CCR_ADCPRE_BY2		(0x0 << 16)
#define ADC_CCR_ADCPRE_BY4		(0x1 << 16)
#define ADC_CCR_ADCPRE_BY6		(0x2 << 16)
#define ADC_CCR_ADCPRE_BY8		(0x3 << 16)
/**@}*/
#define ADC_CCR_ADCPRE_MASK		(0x3 << 16)
#define ADC_CCR_ADCPRE_SHIFT		16

BEGIN_DECLS

void adc_set_multi_mode(uint32_t mode);
void adc_enable_vbat_sensor(void);
void adc_disable_vbat_sensor(void);

END_DECLS

#endif
