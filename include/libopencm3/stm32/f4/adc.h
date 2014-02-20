/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32F4xx Analog to Digital
Converters</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012
Matthew Lai <m@matthewlai.ca>
@author @htmlonly &copy; @endhtmlonly 2009
Edward Cheeseman <evbuilder@users.sourceforge.net>

@date 31 August 2012

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Matthew Lai <m@matthewlai.ca>
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

#include <libopencm3/stm32/common/adc_common_v1.h>

/* --- Convenience macros -------------------------------------------------- */

/* ADC injected channel data offset register x (ADC_JOFRx) (x=1..4) */
#define ADC_JOFR1(block)		MMIO32(block + 0x14)
#define ADC_JOFR2(block)		MMIO32(block + 0x18)
#define ADC_JOFR3(block)		MMIO32(block + 0x1c)
#define ADC_JOFR4(block)		MMIO32(block + 0x20)

/* ADC watchdog high threshold register (ADC_HTR) */
#define ADC_HTR(block)			MMIO32(block + 0x24)

/* ADC watchdog low threshold register (ADC_LTR) */
#define ADC_LTR(block)			MMIO32(block + 0x28)

/* ADC regular sequence register 1 (ADC_SQR1) */
#define ADC_SQR1(block)			MMIO32(block + 0x2c)

/* ADC regular sequence register 2 (ADC_SQR2) */
#define ADC_SQR2(block)			MMIO32(block + 0x30)

/* ADC regular sequence register 3 (ADC_SQR3) */
#define ADC_SQR3(block)			MMIO32(block + 0x34)

/* ADC injected sequence register (ADC_JSQR) */
#define ADC_JSQR(block)			MMIO32(block + 0x38)

/* ADC injected data register x (ADC_JDRx) (x=1..4) */
#define ADC_JDR1(block)			MMIO32(block + 0x3c)
#define ADC_JDR2(block)			MMIO32(block + 0x40)
#define ADC_JDR3(block)			MMIO32(block + 0x44)
#define ADC_JDR4(block)			MMIO32(block + 0x48)

/* ADC regular data register (ADC_DR) */
#define ADC_DR(block)			MMIO32(block + 0x4c)

/* ADC common (shared) registers */
#define	ADC_COMMON_REGISTERS_BASE	(ADC1_BASE+0x300)
#define ADC_CSR				MMIO32(ADC_COMMON_REGISTERS_BASE + 0x0)
#define ADC_CCR				MMIO32(ADC_COMMON_REGISTERS_BASE + 0x4)
#define ADC_CDR				MMIO32(ADC_COMMON_REGISTERS_BASE + 0x8)

/* --- ADC Channels ------------------------------------------------------- */

/* Thanks ST! F40x and F41x are on 16, F42x and F43x are on 18! */
#define ADC_CHANNEL_TEMP_F40	ADC_CHANNEL16
#define ADC_CHANNEL_TEMP_F42	ADC_CHANNEL18
#define ADC_CHANNEL_VREFINT	ADC_CHANNEL17
#define ADC_CHANNEL_VBAT	ADC_CHANNEL18

/* --- ADC_SR values ------------------------------------------------------- */

#define ADC_SR_OVR			(1 << 5)

/* --- ADC_CR1 values specific to STM32F2,4--------------------------------- */

/* OVRIE: Overrun interrupt enable */
#define ADC_CR1_OVRIE			(1 << 26)

/* RES[1:0]: Resolution */
/****************************************************************************/
/** @defgroup adc_cr1_res ADC Resolution.
@ingroup adc_defines

@{*/
#define ADC_CR1_RES_12BIT		(0x0 << 24)
#define ADC_CR1_RES_10BIT		(0x1 << 24)
#define ADC_CR1_RES_8BIT		(0x2 << 24)
#define ADC_CR1_RES_6BIT		(0x3 << 24)
/**@}*/
#define ADC_CR1_RES_MASK		(0x3 << 24)
#define ADC_CR1_RES_SHIFT		24

/* Note: Bits [21:16] are reserved, and must be kept at reset value. */

/* --- ADC_CR1 values (note some of these are defined elsewhere) ----------- */
#define ADC_CR1_AWDCH_MAX		18


/* --- ADC_CR2 values ------------------------------------------------------ */

/* SWSTART: Start conversion of regular channels. */
#define ADC_CR2_SWSTART			(1 << 30)

/* EXTEN[1:0]: External trigger enable for regular channels. */
/****************************************************************************/
/** @defgroup adc_trigger_polarity_regular ADC Trigger Polarity
@ingroup adc_defines

@{*/
#define ADC_CR2_EXTEN_DISABLED		(0x0 << 28)
#define ADC_CR2_EXTEN_RISING_EDGE	(0x1 << 28)
#define ADC_CR2_EXTEN_FALLING_EDGE	(0x2 << 28)
#define ADC_CR2_EXTEN_BOTH_EDGES	(0x3 << 28)
/**@}*/
#define ADC_CR2_EXTEN_MASK			(0x3 << 28)
#define ADC_CR2_EXTEN_SHIFT			28

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
/** Timer 2 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM2_CC3		(0x4 << 24)
/** Timer 2 Compare Output 4 */
#define ADC_CR2_EXTSEL_TIM2_CC4		(0x5 << 24)
/** Timer 2 TRGO Event */
#define ADC_CR2_EXTSEL_TIM2_TRGO	(0x6 << 24)
/** Timer 3 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM3_CC1		(0x7 << 24)
/** Timer 3 TRGO Event */
#define ADC_CR2_EXTSEL_TIM3_TRGO	(0x8 << 24)
/** Timer 4 Compare Output 4 */
#define ADC_CR2_EXTSEL_TIM4_CC4		(0x9 << 24)
/** Timer 5 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM5_CC1		(0xA << 24)
/** Timer 5 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM5_CC2		(0xB << 24)
/** Timer 5 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM5_CC3		(0xC << 24)
/** Timer 8 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM8_CC1		(0xD << 24)
/** Timer 8 TRGO Event */
#define ADC_CR2_EXTSEL_TIM8_TRGO	(0xE << 24)
/** EXTI Line 11 Event */
#define ADC_CR2_EXTSEL_EXTI_LINE_11	(0xF << 24)
/**@}*/
#define ADC_CR2_EXTSEL_MASK			(0xF << 24)
#define ADC_CR2_EXTSEL_SHIFT		24

/* Bit 23 is reserved */

/* JSWSTART: Start conversion of injected channels. */
#define ADC_CR2_JSWSTART		(1 << 22)

/* JEXTEN[1:0]: External trigger enable for injected channels. */
/****************************************************************************/
/** @defgroup adc_trigger_polarity_injected ADC Injected Trigger Polarity
@ingroup adc_defines

@{*/
#define ADC_CR2_JEXTEN_DISABLED		(0x0 << 20)
#define ADC_CR2_JEXTEN_RISING_EDGE	(0x1 << 20)
#define ADC_CR2_JEXTEN_FALLING_EDGE	(0x2 << 20)
#define ADC_CR2_JEXTEN_BOTH_EDGES	(0x3 << 20)
/**@}*/
#define ADC_CR2_JEXTEN_MASK			(0x3 << 20)
#define ADC_CR2_JEXTEN_SHIFT		20

/* JEXTSEL[3:0]: External event selection for injected group. */
/****************************************************************************/
/** @defgroup adc_trigger_injected ADC Trigger Identifier for Injected group
@ingroup adc_defines

@{*/
#define ADC_CR2_JEXTSEL_TIM1_CC4	(0x0 << 16)
#define ADC_CR2_JEXTSEL_TIM1_TRGO	(0x1 << 16)
#define ADC_CR2_JEXTSEL_TIM2_CC1	(0x2 << 16)
#define ADC_CR2_JEXTSEL_TIM2_TRGO	(0x3 << 16)
#define ADC_CR2_JEXTSEL_TIM3_CC2	(0x4 << 16)
#define ADC_CR2_JEXTSEL_TIM3_CC4	(0x5 << 16)
#define ADC_CR2_JEXTSEL_TIM4_CC1	(0x6 << 16)
#define ADC_CR2_JEXTSEL_TIM4_CC2	(0x7 << 16)
#define ADC_CR2_JEXTSEL_TIM4_CC3	(0x8 << 16)
#define ADC_CR2_JEXTSEL_TIM4_TRGO	(0x9 << 16)
#define ADC_CR2_JEXTSEL_TIM5_CC4	(0xA << 16)
#define ADC_CR2_JEXTSEL_TIM5_TRGO	(0xB << 16)
#define ADC_CR2_JEXTSEL_TIM8_CC2	(0xC << 16)
#define ADC_CR2_JEXTSEL_TIM8_CC3	(0xD << 16)
#define ADC_CR2_JEXTSEL_TIM8_CC4	(0xE << 16)
#define ADC_CR2_JEXTSEL_EXTI_LINE_15	(0xF << 16)
/**@}*/
#define ADC_CR2_JEXTSEL_MASK		(0xF << 16)
#define ADC_CR2_JEXTSEL_SHIFT		16

/* ALIGN: Data alignement. */
#define ADC_CR2_ALIGN_RIGHT             (0 << 11)
#define ADC_CR2_ALIGN_LEFT              (1 << 11)
#define ADC_CR2_ALIGN			(1 << 11)

/* EOCS: End of conversion selection. */
#define ADC_CR2_EOCS			(1 << 10)

/* DDS: DMA disable selection */
#define ADC_CR2_DDS			(1 << 9)

/* DMA: Direct memory access mode. (ADC1 and ADC3 only!) */
#define ADC_CR2_DMA			(1 << 8)

/* Note: Bits [7:2] are reserved and must be kept at reset value. */

/* CONT: Continous conversion. */
#define ADC_CR2_CONT			(1 << 1)

/* ADON: A/D converter On/Off. */
/* Note: If any other bit in this register apart from ADON is changed at the
 * same time, then conversion is not triggered. This is to prevent triggering
 * an erroneous conversion.
 * Conclusion: Must be separately written.
 */
#define ADC_CR2_ADON			(1 << 0)

/* --- ADC_SMPR1 values ---------------------------------------------------- */

#define ADC_SMPR1_SMP17_LSB		21
#define ADC_SMPR1_SMP16_LSB		18
#define ADC_SMPR1_SMP15_LSB		15
#define ADC_SMPR1_SMP14_LSB		12
#define ADC_SMPR1_SMP13_LSB		9
#define ADC_SMPR1_SMP12_LSB		6
#define ADC_SMPR1_SMP11_LSB		3
#define ADC_SMPR1_SMP10_LSB		0
#define ADC_SMPR1_SMP17_MSK		(0x7 << ADC_SMP17_LSB)
#define ADC_SMPR1_SMP16_MSK		(0x7 << ADC_SMP16_LSB)
#define ADC_SMPR1_SMP15_MSK		(0x7 << ADC_SMP15_LSB)
#define ADC_SMPR1_SMP14_MSK		(0x7 << ADC_SMP14_LSB)
#define ADC_SMPR1_SMP13_MSK		(0x7 << ADC_SMP13_LSB)
#define ADC_SMPR1_SMP12_MSK		(0x7 << ADC_SMP12_LSB)
#define ADC_SMPR1_SMP11_MSK		(0x7 << ADC_SMP11_LSB)
#define ADC_SMPR1_SMP10_MSK		(0x7 << ADC_SMP10_LSB)

/* --- ADC_SMPR2 values ---------------------------------------------------- */

#define ADC_SMPR2_SMP9_LSB		27
#define ADC_SMPR2_SMP8_LSB		24
#define ADC_SMPR2_SMP7_LSB		21
#define ADC_SMPR2_SMP6_LSB		18
#define ADC_SMPR2_SMP5_LSB		15
#define ADC_SMPR2_SMP4_LSB		12
#define ADC_SMPR2_SMP3_LSB		9
#define ADC_SMPR2_SMP2_LSB		6
#define ADC_SMPR2_SMP1_LSB		3
#define ADC_SMPR2_SMP0_LSB		0
#define ADC_SMPR2_SMP9_MSK		(0x7 << ADC_SMP9_LSB)
#define ADC_SMPR2_SMP8_MSK		(0x7 << ADC_SMP8_LSB)
#define ADC_SMPR2_SMP7_MSK		(0x7 << ADC_SMP7_LSB)
#define ADC_SMPR2_SMP6_MSK		(0x7 << ADC_SMP6_LSB)
#define ADC_SMPR2_SMP5_MSK		(0x7 << ADC_SMP5_LSB)
#define ADC_SMPR2_SMP4_MSK		(0x7 << ADC_SMP4_LSB)
#define ADC_SMPR2_SMP3_MSK		(0x7 << ADC_SMP3_LSB)
#define ADC_SMPR2_SMP2_MSK		(0x7 << ADC_SMP2_LSB)
#define ADC_SMPR2_SMP1_MSK		(0x7 << ADC_SMP1_LSB)
#define ADC_SMPR2_SMP0_MSK		(0x7 << ADC_SMP0_LSB)

/* --- ADC_SMPRx values --------------------------------------------------- */
/****************************************************************************/
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

#define ADC_SQR_MAX_CHANNELS_REGULAR	16

#define ADC_SQR1_SQ16_LSB		15
#define ADC_SQR1_SQ15_LSB		10
#define ADC_SQR1_SQ14_LSB		5
#define ADC_SQR1_SQ13_LSB		0
#define ADC_SQR1_L_MSK			(0xf << ADC_SQR1_L_LSB)
#define ADC_SQR1_SQ16_MSK		(0x1f << ADC_SQR1_SQ16_LSB)
#define ADC_SQR1_SQ15_MSK		(0x1f << ADC_SQR1_SQ15_LSB)
#define ADC_SQR1_SQ14_MSK		(0x1f << ADC_SQR1_SQ14_LSB)
#define ADC_SQR1_SQ13_MSK		(0x1f << ADC_SQR1_SQ13_LSB)

/* --- ADC_SQR2 values ----------------------------------------------------- */

#define ADC_SQR2_SQ12_LSB		25
#define ADC_SQR2_SQ11_LSB		20
#define ADC_SQR2_SQ10_LSB		15
#define ADC_SQR2_SQ9_LSB		10
#define ADC_SQR2_SQ8_LSB		5
#define ADC_SQR2_SQ7_LSB		0
#define ADC_SQR2_SQ12_MSK		(0x1f << ADC_SQR2_SQ12_LSB)
#define ADC_SQR2_SQ11_MSK		(0x1f << ADC_SQR2_SQ11_LSB)
#define ADC_SQR2_SQ10_MSK		(0x1f << ADC_SQR2_SQ10_LSB)
#define ADC_SQR2_SQ9_MSK		(0x1f << ADC_SQR2_SQ9_LSB)
#define ADC_SQR2_SQ8_MSK		(0x1f << ADC_SQR2_SQ8_LSB)
#define ADC_SQR2_SQ7_MSK		(0x1f << ADC_SQR2_SQ7_LSB)

/* --- ADC_SQR3 values ----------------------------------------------------- */

#define ADC_SQR3_SQ6_LSB		25
#define ADC_SQR3_SQ5_LSB		20
#define ADC_SQR3_SQ4_LSB		15
#define ADC_SQR3_SQ3_LSB		10
#define ADC_SQR3_SQ2_LSB		5
#define ADC_SQR3_SQ1_LSB		0
#define ADC_SQR3_SQ6_MSK		(0x1f << ADC_SQR3_SQ6_LSB)
#define ADC_SQR3_SQ5_MSK		(0x1f << ADC_SQR3_SQ5_LSB)
#define ADC_SQR3_SQ4_MSK		(0x1f << ADC_SQR3_SQ4_LSB)
#define ADC_SQR3_SQ3_MSK		(0x1f << ADC_SQR3_SQ3_LSB)
#define ADC_SQR3_SQ2_MSK		(0x1f << ADC_SQR3_SQ2_LSB)
#define ADC_SQR3_SQ1_MSK		(0x1f << ADC_SQR3_SQ1_LSB)

/* --- ADC_JDRx, ADC_DR values --------------------------------------------- */

#define ADC_JDATA_LSB			0
#define ADC_DATA_LSB			0
#define ADC_JDATA_MSK			(0xffff << ADC_JDATA_LSB)
#define ADC_DATA_MSK			(0xffff << ADC_DA)

/* --- Common Registers ---------------------------------------------------- */

/* --- ADC_CSR values (read only images) ------------------------------------ */

/* OVR3: Overrun ADC3. */
#define ADC_CSR_OVR3				(1 << 21)

/* STRT3: Regular channel start ADC3. */
#define ADC_CSR_STRT3				(1 << 20)

/* JSTRT3: Injected channel start ADC3. */
#define ADC_CSR_JSTRT3				(1 << 19)

/* JEOC3: Injected channel end of conversion ADC3. */
#define ADC_CSR_JEOC3				(1 << 18)

/* EOC3: Regular channel end of conversion ADC3. */
#define ADC_CSR_EOC3				(1 << 17)

/* EOC3: Regular channel end of conversion ADC3. */
#define ADC_CSR_AWD3				(1 << 16)

/* Bits 15:14 Reserved, must be kept at reset value */

/* OVR2: Overrun ADC2. */
#define ADC_CSR_OVR2				(1 << 13)

/* STRT2: Regular channel start ADC2. */
#define ADC_CSR_STRT2				(1 << 12)

/* JSTRT2: Injected channel start ADC2. */
#define ADC_CSR_JSTRT2				(1 << 11)

/* JEOC2: Injected channel end of conversion ADC2. */
#define ADC_CSR_JEOC2				(1 << 10)

/* EOC2: Regular channel end of conversion ADC2. */
#define ADC_CSR_EOC2				(1 << 9)

/* EOC2: Regular channel end of conversion ADC2. */
#define ADC_CSR_AWD2				(1 << 8)

/* Bits 7:6 Reserved, must be kept at reset value */

/* OVR1: Overrun ADC1. */
#define ADC_CSR_OVR1				(1 << 5)

/* STRT1: Regular channel start ADC1. */
#define ADC_CSR_STRT1				(1 << 4)

/* JSTRT1: Injected channel start ADC1. */
#define ADC_CSR_JSTRT1				(1 << 3)

/* JEOC1: Injected channel end of conversion ADC1. */
#define ADC_CSR_JEOC1				(1 << 2)

/* EOC1: Regular channel end of conversion ADC1. */
#define ADC_CSR_EOC1				(1 << 1)

/* EOC1: Regular channel end of conversion ADC1. */
#define ADC_CSR_AWD1				(1 << 0)

/* --- ADC_CCR values ------------------------------------------------------ */

/* TSVREFE: Temperature sensor and Vrefint enable. */
#define ADC_CCR_TSVREFE				(1 << 23)

/* VBATE: VBat enable. */
#define ADC_CCR_VBATE				(1 << 22)

/* Bit 18:21 reserved, must be kept at reset value. */

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

/* DMA: Direct memory access mode for multi ADC mode. */
/****************************************************************************/
/** @defgroup adc_dma_mode ADC DMA mode for multi ADC mode
@ingroup adc_defines

@{*/
#define ADC_CCR_DMA_DISABLE		(0x0 << 14)
#define ADC_CCR_DMA_MODE_1		(0x1 << 14)
#define ADC_CCR_DMA_MODE_2		(0x2 << 14)
#define ADC_CCR_DMA_MODE_3		(0x3 << 14)
/**@}*/
#define ADC_CCR_DMA_MASK		(0x3 << 14)
#define ADC_CCR_DMA_SHIFT		14

/* DDS: DMA disable selection (for multi-ADC mode). */
#define ADC_CCR_DDS				(1 << 13)

/* Bit 12 reserved, must be kept at reset value */

/* DELAY: Delay between 2 sampling phases. */
/****************************************************************************/
/** @defgroup adc_delay ADC Delay between 2 sampling phases
@ingroup adc_defines

@{*/
#define ADC_CCR_DELAY_5ADCCLK		(0x0 << 8)
#define ADC_CCR_DELAY_6ADCCLK		(0x1 << 8)
#define ADC_CCR_DELAY_7ADCCLK		(0x2 << 8)
#define ADC_CCR_DELAY_8ADCCLK		(0x3 << 8)
#define ADC_CCR_DELAY_9ADCCLK		(0x4 << 8)
#define ADC_CCR_DELAY_10ADCCLK		(0x5 << 8)
#define ADC_CCR_DELAY_11ADCCLK		(0x6 << 8)
#define ADC_CCR_DELAY_12ADCCLK		(0x7 << 8)
#define ADC_CCR_DELAY_13ADCCLK		(0x8 << 8)
#define ADC_CCR_DELAY_14ADCCLK		(0x9 << 8)
#define ADC_CCR_DELAY_15ADCCLK		(0xa << 8)
#define ADC_CCR_DELAY_16ADCCLK		(0xb << 8)
#define ADC_CCR_DELAY_17ADCCLK		(0xc << 8)
#define ADC_CCR_DELAY_18ADCCLK		(0xd << 8)
#define ADC_CCR_DELAY_19ADCCLK		(0xe << 8)
#define ADC_CCR_DELAY_20ADCCLK		(0xf << 8)
/**@}*/
#define ADC_CCR_DELAY_MASK		(0xf << 8)
#define ADC_CCR_DELAY_SHIFT		8

/* Bit 7:5 reserved, must be kept at reset value */

/* MULTI: Multi ADC mode selection. */
/****************************************************************************/
/** @defgroup adc_multi_mode ADC Multi mode selection
@ingroup adc_defines

@{*/

/** All ADCs independent */
#define ADC_CCR_MULTI_INDEPENDENT	(0x00 << 0)

/* Dual modes (ADC1 + ADC2) */
/**
 * Dual modes (ADC1 + ADC2) Combined regular simultaneous +
 * injected simultaneous mode.
 */
#define ADC_CCR_MULTI_DUAL_REG_SIMUL_AND_INJECTED_SIMUL		(0x01 << 0)
/**
 * Dual modes (ADC1 + ADC2) Combined regular simultaneous +
 * alternate trigger mode.
 */
#define ADC_CCR_MULTI_DUAL_REG_SIMUL_AND_ALTERNATE_TRIG		(0x02 << 0)
/** Dual modes (ADC1 + ADC2) Injected simultaneous mode only. */
#define ADC_CCR_MULTI_DUAL_INJECTED_SIMUL			(0x05 << 0)
/** Dual modes (ADC1 + ADC2) Regular simultaneous mode only. */
#define ADC_CCR_MULTI_DUAL_REGULAR_SIMUL			(0x06 << 0)
/** Dual modes (ADC1 + ADC2) Interleaved mode only. */
#define ADC_CCR_MULTI_DUAL_INTERLEAVED				(0x07 << 0)
/** Dual modes (ADC1 + ADC2) Alternate trigger mode only. */
#define ADC_CCR_MULTI_DUAL_ALTERNATE_TRIG			(0x09 << 0)

/* Triple modes (ADC1 + ADC2 + ADC3) */
/**
 * Triple modes (ADC1 + ADC2 + ADC3) Combined regular simultaneous +
 * injected simultaneous mode.
 */
#define ADC_CCR_MULTI_TRIPLE_REG_SIMUL_AND_INJECTED_SIMUL	(0x11 << 0)
/**
 * Triple modes (ADC1 + ADC2 + ADC3) Combined regular simultaneous +
 * alternate trigger mode.
 */
#define ADC_CCR_MULTI_TRIPLE_REG_SIMUL_AND_ALTERNATE_TRIG	(0x12 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Injected simultaneous mode only. */
#define ADC_CCR_MULTI_TRIPLE_INJECTED_SIMUL			(0x15 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Regular simultaneous mode only. */
#define ADC_CCR_MULTI_TRIPLE_REGULAR_SIMUL			(0x16 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Interleaved mode only. */
#define ADC_CCR_MULTI_TRIPLE_INTERLEAVED			(0x17 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Alternate trigger mode only. */
#define ADC_CCR_MULTI_TRIPLE_ALTERNATE_TRIG			(0x19 << 0)
/**@}*/

#define ADC_CCR_MULTI_MASK		(0x1f << 0)
#define ADC_CCR_MULTI_SHIFT		0

/* --- ADC_CDR values ------------------------------------------------------ */

#define ADC_CDR_DATA2_MASK		(0xffff << 16)
#define ADC_CDR_DATA2_SHIFT		16

#define ADC_CDR_DATA1_MASK		(0xffff << 0)
#define ADC_CDR_DATA1_SHIFT		0

BEGIN_DECLS

void adc_set_clk_prescale(uint32_t prescaler);
void adc_set_multi_mode(uint32_t mode);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity);
void adc_set_resolution(uint32_t adc, uint32_t resolution);
void adc_enable_overrun_interrupt(uint32_t adc);
void adc_disable_overrun_interrupt(uint32_t adc);
bool adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);
bool adc_awd(uint32_t adc);
void adc_eoc_after_each(uint32_t adc);
void adc_eoc_after_group(uint32_t adc);
void adc_set_dma_continue(uint32_t adc);
void adc_set_dma_terminate(uint32_t adc);

void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);

END_DECLS

/**@}*/

#endif
