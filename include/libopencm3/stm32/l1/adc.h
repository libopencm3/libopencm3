/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32L1xx Analog to
Digital Converters</b>

@ingroup STM32L1xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013 Karl Palsson <karlp@remake.is>

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Karl Palsson <karlp@remake.is>
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

#include <libopencm3/stm32/common/adc_common_v1.h>

#define ADC_MAX_REGULAR_SEQUENCE	28
/* 26 in L/M, but 32 in two banks for M+/H density */
#define ADC_MAX_CHANNELS		32

/* ADC sample time register 3 (ADC_SMPR3) */
#define ADC_SMPR3(block)		MMIO32(block + 0x14)
#define ADC1_SMPR3			ADC_SMPR3(ADC1)

/* ADC injected channel data offset register x (ADC_JOFRx) (x=1..4) */
#define ADC_JOFR1(block)		MMIO32(block + 0x18)
#define ADC_JOFR2(block)		MMIO32(block + 0x1c)
#define ADC_JOFR3(block)		MMIO32(block + 0x20)
#define ADC_JOFR4(block)		MMIO32(block + 0x24)

/* ADC watchdog high threshold register (ADC_HTR) */
#define ADC_HTR(block)			MMIO32(block + 0x28)

/* ADC watchdog low threshold register (ADC_LTR) */
#define ADC_LTR(block)			MMIO32(block + 0x2c)

/* ADC regular sequence register 1 (ADC_SQR1) */
#define ADC_SQR1(block)			MMIO32(block + 0x30)

/* ADC regular sequence register 2 (ADC_SQR2) */
#define ADC_SQR2(block)			MMIO32(block + 0x34)

/* ADC regular sequence register 3 (ADC_SQR3) */
#define ADC_SQR3(block)			MMIO32(block + 0x38)

/* ADC regular sequence register 4 (ADC_SQR4) */
#define ADC_SQR4(block)			MMIO32(block + 0x3c)
#define ADC1_SQR4			ADC_SQR4(ADC1)

/* ADC regular sequence register 5 (ADC_SQR5) */
#define ADC_SQR5(block)			MMIO32(block + 0x40)
#define ADC1_SQR5			ADC_SQR5(ADC1)

/* ADC injected sequence register (ADC_JSQR) */
#define ADC_JSQR(block)			MMIO32(block + 0x44)

/* ADC injected data register x (ADC_JDRx) (x=1..4) */
#define ADC_JDR1(block)			MMIO32(block + 0x48)
#define ADC_JDR2(block)			MMIO32(block + 0x4c)
#define ADC_JDR3(block)			MMIO32(block + 0x50)
#define ADC_JDR4(block)			MMIO32(block + 0x54)

/* ADC regular data register (ADC_DR) */
#define ADC_DR(block)			MMIO32(block + 0x58)

/* ADC sample time register 0 (ADC_SMPR0) (high/med+ only) */
#define ADC_SMPR0(block)		MMIO32(block + 0x5c)
#define ADC1_SMPR0			ADC_SMPR0(ADC1)

#define ADC_CSR				MMIO32(ADC1 + 0x300)
#define ADC_CCR				MMIO32(ADC1 + 0x304)


/* These are _not_ consistent unfortunately! */
#define ADC_CHANNEL_TEMP        ADC_CHANNEL16
#define ADC_CHANNEL_VREFINT     ADC_CHANNEL17
#define ADC_CHANNEL_VBAT        ADC_CHANNEL18

/* --- ADC_SR values ------------------------------------------------------- */
#define ADC_SR_JCNR			(1 << 9)
#define ADC_SR_RCNR			(1 << 8)
#define ADC_SR_ADONS			(1 << 6)
#define ADC_SR_OVR			(1 << 5)

/* --- ADC_CR1 values ------------------------------------------------------- */
#define ADC_CR1_OVRIE			(1 << 28)
/****************************************************************************/
/** @defgroup adc_cr1_res ADC Resolution.
@ingroup adc_defines
@{*/
#define ADC_CR1_RES_12_BIT		0
#define ADC_CR1_RES_10_BIT		1
#define ADC_CR1_RES_8_BIT		2
#define ADC_CR1_RES_6_BIT		3
/**@}*/
#define ADC_CR1_RES_MASK		(0x3)
#define ADC_CR1_RES_SHIFT		24
#define ADC_CR1_PDI			(1 << 17)
#define ADC_CR1_PDD			(1 << 16)

#define ADC_CR1_AWDCH_MAX		26

/* --- ADC_CR2 values ------------------------------------------------------- */
/* SWSTART: */ /** Start conversion of regular channels. */
#define ADC_CR2_SWSTART			(1 << 30)

/* EXTEN[1:0]: External trigger enable for regular channels. */
/****************************************************************************/
#define ADC_CR2_EXTEN_SHIFT		28
#define ADC_CR2_EXTEN_MASK		(0x3 << ADC_CR2_EXTEN_SHIFT)
/** @defgroup adc_trigger_polarity_regular ADC Trigger Polarity
@ingroup adc_defines
@{*/
#define ADC_CR2_EXTEN_DISABLED		(0x0 << ADC_CR2_EXTEN_SHIFT)
#define ADC_CR2_EXTEN_RISING_EDGE	(0x1 << ADC_CR2_EXTEN_SHIFT)
#define ADC_CR2_EXTEN_FALLING_EDGE	(0x2 << ADC_CR2_EXTEN_SHIFT)
#define ADC_CR2_EXTEN_BOTH_EDGES	(0x3 << ADC_CR2_EXTEN_SHIFT)
/**@}*/

/* EXTSEL[3:0]: External event selection for regular group. */
/****************************************************************************/
#define ADC_CR2_EXTSEL_SHIFT		24
#define ADC_CR2_EXTSEL_MASK		(0xf << ADC_CR2_EXTSEL_SHIFT)
/** @defgroup adc_trigger_regular ADC Trigger Identifier for Regular group
@ingroup adc_defines

@{*/
#define ADC_CR2_EXTSEL_TIM9_CC2		(0 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM9_TRGO	(1 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM2_CC3		(2 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM2_CC2		(3 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM3_TRGO	(4 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM4_CC4		(5 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM2_TRGO	(6 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM3_CC1		(7 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM3_CC3		(8 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM4_TRGO	(9 << ADC_CR2_EXTSEL_SHIFT)
#define ADC_CR2_EXTSEL_TIM6_TRGO	(10 << ADC_CR2_EXTSEL_SHIFT)
/* reserved.... */
#define ADC_CR2_EXTSEL_EXTI11		(15 << ADC_CR2_EXTSEL_SHIFT)
/**@}*/

#define ADC_CR2_JSWSTART		(1 << 22)

/* JEXTEN[1:0]: External trigger enable for injected channels. */
/****************************************************************************/
#define ADC_CR2_JEXTEN_SHIFT		20
#define ADC_CR2_JEXTEN_MASK		(0x3 << ADC_CR2_JEXTEN_SHIFT)
/** @defgroup adc_trigger_polarity_injected ADC Injected Trigger Polarity
@ingroup adc_defines
@{*/
#define ADC_CR2_JEXTEN_DISABLED		(0x0 << ADC_CR2_JEXTEN_SHIFT)
#define ADC_CR2_JEXTEN_RISING_EDGE	(0x1 << ADC_CR2_JEXTEN_SHIFT)
#define ADC_CR2_JEXTEN_FALLING_EDGE	(0x2 << ADC_CR2_JEXTEN_SHIFT)
#define ADC_CR2_JEXTEN_BOTH_EDGES	(0x3 << ADC_CR2_JEXTEN_SHIFT)
/**@}*/

/* FIXME - add the values here */
#define ADC_CR2_JEXTSEL_SHIFT		16
#define ADC_CR2_JEXTSEL_MASK		(0xf << ADC_CR2_JEXTSEL_SHIFT)

#define ADC_CR2_EOCS			(1 << 10)
#define ADC_CR2_DDS			(1 << 9)
/* FIXME- add the values here */
#define ADC_CR2_DELS_SHIFT		4
#define ADC_CR2_DELS_MASK		0x7

#define ADC_CR2_ADC_CFG			(1 << 2)




/* --- ADC_SMPRx generic values -------------------------------------------- */
/****************************************************************************/
/* ADC_SMPRG ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_4CYC		0x0
#define ADC_SMPR_SMP_9CYC		0x1
#define ADC_SMPR_SMP_16CYC		0x2
#define ADC_SMPR_SMP_24CYC		0x3
#define ADC_SMPR_SMP_48CYC		0x4
#define ADC_SMPR_SMP_96CYC		0x5
#define ADC_SMPR_SMP_192CYC		0x6
#define ADC_SMPR_SMP_384CYC		0x7
/**@}*/

#define ADC_SQR_MASK			0x1f
#define ADC_SQR_MAX_CHANNELS_REGULAR	28 /* m+/h only, otherwise 27 */

#define ADC_CCR_TSVREFE			(1 << 23)

BEGIN_DECLS
	/* L1 specific, or not fully unified adc routines */
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity);

END_DECLS

#endif
