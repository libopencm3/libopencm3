/** @defgroup STM32F4xx_adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32F4xx Analog to Digital Converters</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Matthew Lai <m@matthewlai.ca>
@author @htmlonly &copy; @endhtmlonly 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>

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

#include <libopencm3/stm32/f4/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* ADC port base addresses (for convenience) */
/****************************************************************************/
/** @defgroup adc_reg_base ADC register base addresses
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC1				ADC1_BASE
#define ADC2				ADC2_BASE
#define ADC3				ADC3_BASE
/**@}*/

/* --- ADC registers ------------------------------------------------------- */

/* ADC status register (ADC_SR) */
#define ADC_SR(block)			MMIO32(block + 0x00)
#define ADC1_SR				ADC_SR(ADC1)
#define ADC2_SR				ADC_SR(ADC2)
#define ADC3_SR				ADC_SR(ADC3)

/* ADC control register 1 (ADC_CR1) */
#define ADC_CR1(block)			MMIO32(block + 0x04)
#define ADC1_CR1			ADC_CR1(ADC1)
#define ADC2_CR1			ADC_CR1(ADC2)
#define ADC3_CR1			ADC_CR1(ADC3)

/* ADC control register 2 (ADC_CR2) */
#define ADC_CR2(block)			MMIO32(block + 0x08)
#define ADC1_CR2			ADC_CR2(ADC1)
#define ADC2_CR2			ADC_CR2(ADC2)
#define ADC3_CR2			ADC_CR2(ADC3)

/* ADC sample time register 1 (ADC_SMPR1) */
#define ADC_SMPR1(block)		MMIO32(block + 0x0c)
#define ADC1_SMPR1			ADC_SMPR1(ADC1)
#define ADC2_SMPR1			ADC_SMPR1(ADC2)
#define ADC3_SMPR1			ADC_SMPR1(ADC3)

/* ADC sample time register 2 (ADC_SMPR2) */
#define ADC_SMPR2(block)		MMIO32(block + 0x10)
#define ADC1_SMPR2			ADC_SMPR2(ADC1)
#define ADC2_SMPR2			ADC_SMPR2(ADC2)
#define ADC3_SMPR2			ADC_SMPR2(ADC3)

/* ADC injected channel data offset register x (ADC_JOFRx) (x=1..4) */
#define ADC_JOFR1(block)		MMIO32(block + 0x14)
#define ADC_JOFR2(block)		MMIO32(block + 0x18)
#define ADC_JOFR3(block)		MMIO32(block + 0x1c)
#define ADC_JOFR4(block)		MMIO32(block + 0x20)
#define ADC1_JOFR1			ADC_JOFR1(ADC1)
#define ADC2_JOFR1			ADC_JOFR1(ADC2)
#define ADC3_JOFR1			ADC_JOFR1(ADC3)
#define ADC1_JOFR2			ADC_JOFR2(ADC1)
#define ADC2_JOFR2			ADC_JOFR2(ADC2)
#define ADC3_JOFR2			ADC_JOFR2(ADC3)
#define ADC1_JOFR3			ADC_JOFR3(ADC1)
#define ADC2_JOFR3			ADC_JOFR3(ADC2)
#define ADC3_JOFR3			ADC_JOFR3(ADC3)
#define ADC1_JOFR4			ADC_JOFR4(ADC1)
#define ADC2_JOFR4			ADC_JOFR4(ADC2)
#define ADC3_JOFR4			ADC_JOFR4(ADC3)

/* ADC watchdog high threshold register (ADC_HTR) */
#define ADC_HTR(block)			MMIO32(block + 0x24)
#define ADC1_HTR			ADC_HTR(ADC1)
#define ADC2_HTR			ADC_HTR(ADC2)
#define ADC3_HTR			ADC_HTR(ADC3)

/* ADC watchdog low threshold register (ADC_LTR) */
#define ADC_LTR(block)			MMIO32(block + 0x28)
#define ADC1_LTR			ADC_LTR(ADC1_BASE)
#define ADC2_LTR			ADC_LTR(ADC2_BASE)
#define ADC3_LTR			ADC_LTR(ADC3_BASE)

/* ADC regular sequence register 1 (ADC_SQR1) */
#define ADC_SQR1(block)			MMIO32(block + 0x2c)
#define ADC1_SQR1			ADC_SQR1(ADC1)
#define ADC2_SQR1			ADC_SQR1(ADC2)
#define ADC3_SQR1			ADC_SQR1(ADC3)

/* ADC regular sequence register 2 (ADC_SQR2) */
#define ADC_SQR2(block)			MMIO32(block + 0x30)
#define ADC1_SQR2			ADC_SQR2(ADC1)
#define ADC2_SQR2			ADC_SQR2(ADC2)
#define ADC3_SQR2			ADC_SQR2(ADC3)

/* ADC regular sequence register 3 (ADC_SQR3) */
#define ADC_SQR3(block)			MMIO32(block + 0x34)
#define ADC1_SQR3			ADC_SQR3(ADC1)
#define ADC2_SQR3			ADC_SQR3(ADC2)
#define ADC3_SQR3			ADC_SQR3(ADC3)

/* ADC injected sequence register (ADC_JSQR) */
#define ADC_JSQR(block)			MMIO32(block + 0x38)
#define ADC1_JSQR			ADC_JSQR(ADC1_BASE)
#define ADC2_JSQR			ADC_JSQR(ADC2_BASE)
#define ADC3_JSQR			ADC_JSQR(ADC3_BASE)

/* ADC injected data register x (ADC_JDRx) (x=1..4) */
#define ADC_JDR1(block)			MMIO32(block + 0x3c)
#define ADC_JDR2(block)			MMIO32(block + 0x40)
#define ADC_JDR3(block)			MMIO32(block + 0x44)
#define ADC_JDR4(block)			MMIO32(block + 0x48)
#define ADC1_JDR1			ADC_JDR1(ADC1)
#define ADC2_JDR1			ADC_JDR1(ADC2)
#define ADC3_JDR1			ADC_JDR1(ADC3)
#define ADC1_JDR2			ADC_JDR2(ADC1)
#define ADC2_JDR2			ADC_JDR2(ADC2)
#define ADC3_JDR2			ADC_JDR2(ADC3)
#define ADC1_JDR3			ADC_JDR3(ADC1)
#define ADC2_JDR3			ADC_JDR3(ADC2)
#define ADC3_JDR3			ADC_JDR3(ADC3)
#define ADC1_JDR4			ADC_JDR4(ADC1)
#define ADC2_JDR4			ADC_JDR4(ADC2)
#define ADC3_JDR4			ADC_JDR4(ADC3)

/* ADC regular data register (ADC_DR) */
#define ADC_DR(block)			MMIO32(block + 0x4c)
#define ADC1_DR				ADC_DR(ADC1)
#define ADC2_DR				ADC_DR(ADC2)
#define ADC3_DR				ADC_DR(ADC3)

/* ADC common (shared) registers */
#define	ADC_COMMON_REGISTERS_BASE	(ADC1_BASE+0x300)
#define ADC_CSR						MMIO32(ADC_COMMON_REGISTERS_BASE + 0x0)
#define ADC_CCR						MMIO32(ADC_COMMON_REGISTERS_BASE + 0x4)
#define ADC_CDR						MMIO32(ADC_COMMON_REGISTERS_BASE + 0x8)

/* --- ADC Channels ------------------------------------------------------- */

/****************************************************************************/
/** @defgroup adc_channel ADC Channel Numbers
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_CHANNEL0		0x00
#define ADC_CHANNEL1		0x01
#define ADC_CHANNEL2		0x02
#define ADC_CHANNEL3		0x03
#define ADC_CHANNEL4		0x04
#define ADC_CHANNEL5		0x05
#define ADC_CHANNEL6		0x06
#define ADC_CHANNEL7		0x07
#define ADC_CHANNEL8		0x08
#define ADC_CHANNEL9		0x09
#define ADC_CHANNEL10		0x0A
#define ADC_CHANNEL11		0x0B
#define ADC_CHANNEL12		0x0C
#define ADC_CHANNEL13		0x0D
#define ADC_CHANNEL14		0x0E
#define ADC_CHANNEL15		0x0F
#define ADC_CHANNEL16		0x10
#define ADC_CHANNEL17		0x11
#define ADC_CHANNEL18		0x12
/**@}*/
#define ADC_MASK		    0x1F
#define ADC_SHIFT		    0

/* --- ADC_SR values ------------------------------------------------------- */

#define ADC_SR_OVR			(1 << 5)
#define ADC_SR_STRT			(1 << 4)
#define ADC_SR_JSTRT			(1 << 3)
#define ADC_SR_JEOC			(1 << 2)
#define ADC_SR_EOC			(1 << 1)
#define ADC_SR_AWD			(1 << 0)

/* --- ADC_CR1 values specific to STM32F2,4------------------------------------ */

/* OVRIE: Overrun interrupt enable */
#define ADC_CR1_OVRIE			(1 << 26)

/* RES[1:0]: Resolution */
/****************************************************************************/
/** @defgroup adc_cr1_res ADC Resolution.
@ingroup STM32F4xx_adc_defines

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

/* AWDEN: Analog watchdog enable on regular channels */
#define ADC_CR1_AWDEN			(1 << 23)

/* JAWDEN: Analog watchdog enable on injected channels */
#define ADC_CR1_JAWDEN			(1 << 22)

/* DISCNUM[2:0]: Discontinuous mode channel count. */
/****************************************************************************/
/** @defgroup adc_cr1_discnum ADC Number of channels in discontinuous mode.
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_CR1_DISCNUM_1CHANNELS       (0x0 << 13)
#define ADC_CR1_DISCNUM_2CHANNELS       (0x1 << 13)
#define ADC_CR1_DISCNUM_3CHANNELS       (0x2 << 13)
#define ADC_CR1_DISCNUM_4CHANNELS       (0x3 << 13)
#define ADC_CR1_DISCNUM_5CHANNELS       (0x4 << 13)
#define ADC_CR1_DISCNUM_6CHANNELS       (0x5 << 13)
#define ADC_CR1_DISCNUM_7CHANNELS       (0x6 << 13)
#define ADC_CR1_DISCNUM_8CHANNELS       (0x7 << 13)
/**@}*/
#define ADC_CR1_DISCNUM_MASK		(0x7 << 13)
#define ADC_CR1_DISCNUM_SHIFT		13

/* JDISCEN: */ /** Discontinuous mode on injected channels. */
#define ADC_CR1_JDISCEN			(1 << 12)

/* DISCEN: */ /** Discontinuous mode on regular channels. */
#define ADC_CR1_DISCEN			(1 << 11)

/* JAUTO: */ /** Automatic Injection Group conversion. */
#define ADC_CR1_JAUTO			(1 << 10)

/* AWDSGL: */ /** Enable the watchdog on a single channel in scan mode. */
#define ADC_CR1_AWDSGL			(1 << 9)

/* SCAN: */ /** Scan mode. */
#define ADC_CR1_SCAN			(1 << 8)

/* JEOCIE: */ /** Interrupt enable for injected channels. */
#define ADC_CR1_JEOCIE			(1 << 7)

/* AWDIE: */ /** Analog watchdog interrupt enable. */
#define ADC_CR1_AWDIE			(1 << 6)

/* EOCIE: */ /** Interrupt enable EOC. */
#define ADC_CR1_EOCIE			(1 << 5)

/* AWDCH[4:0]: Analog watchdog channel bits. (Up to 17 other values reserved) */
/* Notes:
 * ADC1: Analog channel 16 and 17 are internally connected to the temperature
 * sensor and V_REFINT, respectively.
 * ADC2: Analog channel 16 and 17 are internally connected to V_SS.
 * ADC3: Analog channel 9, 14, 15, 16 and 17 are internally connected to V_SS.
 */
/****************************************************************************/
/* ADC_CR1 AWDCH[4:0] ADC watchdog channel */
/** @defgroup adc_watchdog_channel ADC watchdog channel
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_CR1_AWDCH_CHANNEL0		(0x00 << 0)
#define ADC_CR1_AWDCH_CHANNEL1		(0x01 << 0)
#define ADC_CR1_AWDCH_CHANNEL2		(0x02 << 0)
#define ADC_CR1_AWDCH_CHANNEL3		(0x03 << 0)
#define ADC_CR1_AWDCH_CHANNEL4		(0x04 << 0)
#define ADC_CR1_AWDCH_CHANNEL5		(0x05 << 0)
#define ADC_CR1_AWDCH_CHANNEL6		(0x06 << 0)
#define ADC_CR1_AWDCH_CHANNEL7		(0x07 << 0)
#define ADC_CR1_AWDCH_CHANNEL8		(0x08 << 0)
#define ADC_CR1_AWDCH_CHANNEL9		(0x09 << 0)
#define ADC_CR1_AWDCH_CHANNEL10		(0x0A << 0)
#define ADC_CR1_AWDCH_CHANNEL11		(0x0B << 0)
#define ADC_CR1_AWDCH_CHANNEL12		(0x0C << 0)
#define ADC_CR1_AWDCH_CHANNEL13		(0x0D << 0)
#define ADC_CR1_AWDCH_CHANNEL14		(0x0E << 0)
#define ADC_CR1_AWDCH_CHANNEL15		(0x0F << 0)
#define ADC_CR1_AWDCH_CHANNEL16		(0x10 << 0)
#define ADC_CR1_AWDCH_CHANNEL17		(0x11 << 0)
/**@}*/
#define ADC_CR1_AWDCH_MASK		(0x1F << 0)
#define ADC_CR1_AWDCH_SHIFT		0

/* --- ADC_CR2 values ------------------------------------------------------ */

/* SWSTART: Start conversion of regular channels. */
#define ADC_CR2_SWSTART			(1 << 30)

/* EXTEN[1:0]: External trigger enable for regular channels. */
/****************************************************************************/
/** @defgroup adc_trigger_polarity_regular ADC Trigger Polarity
@ingroup STM32F4xx_adc_defines

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
@ingroup STM32F4xx_adc_defines

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
@ingroup STM32F4xx_adc_defines

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
@ingroup STM32F4xx_adc_defines

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
/****************************************************************************/
/* ADC_SMPR1 ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_r1 ADC Sample Time Selection for ADC1
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_SMPR1_SMP_1DOT5CYC		0x0
#define ADC_SMPR1_SMP_7DOT5CYC		0x1
#define ADC_SMPR1_SMP_13DOT5CYC		0x2
#define ADC_SMPR1_SMP_28DOT5CYC		0x3
#define ADC_SMPR1_SMP_41DOT5CYC		0x4
#define ADC_SMPR1_SMP_55DOT5CYC		0x5
#define ADC_SMPR1_SMP_71DOT5CYC		0x6
#define ADC_SMPR1_SMP_239DOT5CYC	0x7
/**@}*/

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
/****************************************************************************/
/* ADC_SMPR2 ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_r2 ADC Sample Time Selection for ADC2
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_SMPR2_SMP_1DOT5CYC		0x0
#define ADC_SMPR2_SMP_7DOT5CYC		0x1
#define ADC_SMPR2_SMP_13DOT5CYC		0x2
#define ADC_SMPR2_SMP_28DOT5CYC		0x3
#define ADC_SMPR2_SMP_41DOT5CYC		0x4
#define ADC_SMPR2_SMP_55DOT5CYC		0x5
#define ADC_SMPR2_SMP_71DOT5CYC		0x6
#define ADC_SMPR2_SMP_239DOT5CYC	0x7
/**@}*/

/* --- ADC_SMPRx generic values -------------------------------------------- */
/****************************************************************************/
/* ADC_SMPRG ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_SMPR_SMP_1DOT5CYC		0x0
#define ADC_SMPR_SMP_7DOT5CYC		0x1
#define ADC_SMPR_SMP_13DOT5CYC		0x2
#define ADC_SMPR_SMP_28DOT5CYC		0x3
#define ADC_SMPR_SMP_41DOT5CYC		0x4
#define ADC_SMPR_SMP_55DOT5CYC		0x5
#define ADC_SMPR_SMP_71DOT5CYC		0x6
#define ADC_SMPR_SMP_239DOT5CYC		0x7
/**@}*/

/* --- ADC_JOFRx, ADC_HTR, ADC_LTR values ---------------------------------- */

#define ADC_JOFFSET_LSB			0
#define ADC_JOFFSET_MSK			(0x7ff << 0)
#define ADC_HT_LSB			0
#define ADC_HT_MSK			(0x7ff << 0)
#define ADC_LT_LSB			0
#define ADC_LT_MSK			(0x7ff << 0)

/* --- ADC_SQR1 values ----------------------------------------------------- */

#define ADC_SQR1_L_LSB			20
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

/* --- ADC_JSQR values ----------------------------------------------------- */

#define ADC_JSQR_JL_LSB			20
#define ADC_JSQR_JSQ4_LSB		15
#define ADC_JSQR_JSQ3_LSB		10
#define ADC_JSQR_JSQ2_LSB		5
#define ADC_JSQR_JSQ1_LSB		0

/* JL[2:0]: Discontinous mode channel count injected channels. */
/****************************************************************************/
/** @defgroup adc_jsqr_jl ADC Number of channels in discontinuous mode fro injected channels.
@ingroup STM32F4xx_adc_defines

@{*/
#define ADC_JSQR_JL_1CHANNELS       (0x0 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_2CHANNELS       (0x1 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_3CHANNELS       (0x2 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_4CHANNELS       (0x3 << ADC_JSQR_JL_LSB)
/**@}*/
#define ADC_JSQR_JL_SHIFT		13
#define ADC_JSQR_JL_MSK			(0x2 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JSQ4_MSK		(0x1f << ADC_JSQR_JSQ4_LSB)
#define ADC_JSQR_JSQ3_MSK		(0x1f << ADC_JSQR_JSQ3_LSB)
#define ADC_JSQR_JSQ2_MSK		(0x1f << ADC_JSQR_JSQ2_LSB)
#define ADC_JSQR_JSQ1_MSK		(0x1f << ADC_JSQR_JSQ1_LSB)

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
@ingroup STM32F4xx_adc_defines

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
@ingroup STM32F4xx_adc_defines

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
@ingroup STM32F4xx_adc_defines

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
@ingroup STM32F4xx_adc_defines

@{*/

/** All ADCs independent */
#define ADC_CCR_MULTI_INDEPENDENT	(0x00 << 0)

/* dual modes (ADC1 + ADC2) */
/** Dual modes (ADC1 + ADC2) Combined regular simultaneous + injected simultaneous mode */
#define ADC_CCR_MULTI_DUAL_REG_SIMUL_AND_INJECTED_SIMUL		(0x01 << 0)
/** Dual modes (ADC1 + ADC2) Combined regular simultaneous + alternate trigger mode. */
#define ADC_CCR_MULTI_DUAL_REG_SIMUL_AND_ALTERNATE_TRIG		(0x02 << 0)
/** Dual modes (ADC1 + ADC2) Injected simultaneous mode only. */
#define ADC_CCR_MULTI_DUAL_INJECTED_SIMUL					(0x05 << 0)
/** Dual modes (ADC1 + ADC2) Regular simultaneous mode only. */
#define ADC_CCR_MULTI_DUAL_REGULAR_SIMUL					(0x06 << 0)
/** Dual modes (ADC1 + ADC2) Interleaved mode only. */
#define ADC_CCR_MULTI_DUAL_INTERLEAVED						(0x07 << 0)
/** Dual modes (ADC1 + ADC2) Alternate trigger mode only. */
#define ADC_CCR_MULTI_DUAL_ALTERNATE_TRIG					(0x09 << 0)

/* Triple modes (ADC1 + ADC2 + ADC3) */
/** Triple modes (ADC1 + ADC2 + ADC3) Combined regular simultaneous + injected simultaneous mode */
#define ADC_CCR_MULTI_TRIPLE_REG_SIMUL_AND_INJECTED_SIMUL		(0x11 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Combined regular simultaneous + alternate trigger mode. */
#define ADC_CCR_MULTI_TRIPLE_REG_SIMUL_AND_ALTERNATE_TRIG		(0x12 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Injected simultaneous mode only. */
#define ADC_CCR_MULTI_TRIPLE_INJECTED_SIMUL						(0x15 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Regular simultaneous mode only. */
#define ADC_CCR_MULTI_TRIPLE_REGULAR_SIMUL						(0x16 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Interleaved mode only. */
#define ADC_CCR_MULTI_TRIPLE_INTERLEAVED						(0x17 << 0)
/** Triple modes (ADC1 + ADC2 + ADC3) Alternate trigger mode only. */
#define ADC_CCR_MULTI_TRIPLE_ALTERNATE_TRIG						(0x19 << 0)
/**@}*/

#define ADC_CCR_MULTI_MASK		(0x1f << 0)
#define ADC_CCR_MULTI_SHIFT		0

/* --- ADC_CDR values ------------------------------------------------------ */

#define ADC_CDR_DATA2_MASK		(0xffff << 16)
#define ADC_CDR_DATA2_SHIFT		16

#define ADC_CDR_DATA1_MASK		(0xffff << 0)
#define ADC_CDR_DATA1_SHIFT		0

BEGIN_DECLS

void adc_power_on(u32 adc);
void adc_off(u32 adc);
void adc_enable_analog_watchdog_regular(u32 adc);
void adc_disable_analog_watchdog_regular(u32 adc);
void adc_enable_analog_watchdog_injected(u32 adc);
void adc_disable_analog_watchdog_injected(u32 adc);
void adc_enable_discontinuous_mode_regular(u32 adc, u8 length);
void adc_disable_discontinuous_mode_regular(u32 adc);
void adc_enable_discontinuous_mode_injected(u32 adc);
void adc_disable_discontinuous_mode_injected(u32 adc);
void adc_enable_automatic_injected_group_conversion(u32 adc);
void adc_disable_automatic_injected_group_conversion(u32 adc);
void adc_enable_analog_watchdog_on_all_channels(u32 adc);
void adc_enable_analog_watchdog_on_selected_channel(u32 adc, u8 channel);
void adc_enable_scan_mode(u32 adc);
void adc_disable_scan_mode(u32 adc);
void adc_enable_eoc_interrupt_injected(u32 adc);
void adc_disable_eoc_interrupt_injected(u32 adc);
void adc_enable_awd_interrupt(u32 adc);
void adc_disable_awd_interrupt(u32 adc);
void adc_enable_eoc_interrupt(u32 adc);
void adc_disable_eoc_interrupt(u32 adc);
void adc_start_conversion_regular(u32 adc);
void adc_start_conversion_injected(u32 adc);
void adc_disable_external_trigger_regular(u32 adc);
void adc_disable_external_trigger_injected(u32 adc);
void adc_set_left_aligned(u32 adc);
void adc_set_right_aligned(u32 adc);
void adc_enable_dma(u32 adc);
void adc_disable_dma(u32 adc);
void adc_set_continuous_conversion_mode(u32 adc);
void adc_set_single_conversion_mode(u32 adc);
void adc_set_sample_time(u32 adc, u8 channel, u8 time);
void adc_set_sample_time_on_all_channels(u32 adc, u8 time);
void adc_set_watchdog_high_threshold(u32 adc, u16 threshold);
void adc_set_watchdog_low_threshold(u32 adc, u16 threshold);
void adc_set_regular_sequence(u32 adc, u8 length, u8 channel[]);
void adc_set_injected_sequence(u32 adc, u8 length, u8 channel[]);
bool adc_eoc(u32 adc);
bool adc_eoc_injected(u32 adc);
u32 adc_read_regular(u32 adc);
u32 adc_read_injected(u32 adc, u8 reg);
void adc_set_injected_offset(u32 adc, u8 reg, u32 offset);

void adc_set_clk_prescale(u32 prescaler);
void adc_set_multi_mode(u32 mode);
void adc_enable_external_trigger_regular(u32 adc, u32 trigger, u32 polarity);
void adc_enable_external_trigger_injected(u32 adc, u32 trigger, u32 polarity);
void adc_set_resolution(u32 adc, u16 resolution);
void adc_enable_overrun_interrupt(u32 adc);
void adc_disable_overrun_interrupt(u32 adc);
bool adc_get_overrun_flag(u32 adc);
void adc_clear_overrun_flag(u32 adc);
bool adc_awd(u32 adc);
void adc_eoc_after_each(u32 adc);
void adc_eoc_after_group(u32 adc);
void adc_set_dma_continue(u32 adc);
void adc_set_dma_terminate(u32 adc);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);

END_DECLS

/**@}*/

#endif
