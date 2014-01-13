/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32L1xx Analog to Digital Converters</b>

@ingroup STM32L1xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013 Ben Gamari <bgamari.foss@gmail.com>

@date 30 May 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
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

/**@{*/

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* ADC port base addresses (for convenience) */
/****************************************************************************/
/** @defgroup adc_reg_base ADC register base addresses
@ingroup STM32L1xx_adc_defines

@{*/
#define ADC1				ADC_BASE
/**@}*/

/* --- ADC registers ------------------------------------------------------- */

/* ADC status register (ADC_SR) */
#define ADC_SR(block)			MMIO32(block + 0x00)
#define ADC1_SR				ADC_SR(ADC1)

/* ADC control register 1 (ADC_CR1) */
#define ADC_CR1(block)			MMIO32(block + 0x04)
#define ADC1_CR1			ADC_CR1(ADC1)

/* ADC control register 2 (ADC_CR2) */
#define ADC_CR2(block)			MMIO32(block + 0x08)
#define ADC1_CR2			ADC_CR2(ADC1)

/* ADC sample time register 1 (ADC_SMPR1) */
#define ADC_SMPR1(block)		MMIO32(block + 0x0c)
#define ADC1_SMPR1			ADC_SMPR1(ADC1)

/* ADC sample time register 2 (ADC_SMPR2) */
#define ADC_SMPR2(block)		MMIO32(block + 0x10)
#define ADC1_SMPR2			ADC_SMPR2(ADC1)

/* ADC sample time register 3 (ADC_SMPR3) */
#define ADC_SMPR3(block)		MMIO32(block + 0x14)
#define ADC1_SMPR3			ADC_SMPR3(ADC1)

/* ADC injected channel data offset register x (ADC_JOFRx) (x=1..4) */
#define ADC_JOFR1(block)		MMIO32(block + 0x18)
#define ADC_JOFR2(block)		MMIO32(block + 0x1c)
#define ADC_JOFR3(block)		MMIO32(block + 0x20)
#define ADC_JOFR4(block)		MMIO32(block + 0x24)
#define ADC1_JOFR1			ADC_JOFR1(ADC1)
#define ADC1_JOFR2			ADC_JOFR2(ADC1)
#define ADC1_JOFR3			ADC_JOFR3(ADC1)
#define ADC1_JOFR4			ADC_JOFR4(ADC1)

/* ADC watchdog high threshold register (ADC_HTR) */
#define ADC_HTR(block)			MMIO32(block + 0x28)
#define ADC1_HTR			ADC_HTR(ADC1)

/* ADC watchdog low threshold register (ADC_LTR) */
#define ADC_LTR(block)			MMIO32(block + 0x2c)
#define ADC1_LTR			ADC_LTR(ADC1)

/* ADC regular sequence register 1 (ADC_SQR1) */
#define ADC_SQR1(block)			MMIO32(block + 0x30)
#define ADC1_SQR1			ADC_SQR1(ADC1)

/* ADC regular sequence register 2 (ADC_SQR2) */
#define ADC_SQR2(block)			MMIO32(block + 0x34)
#define ADC1_SQR2			ADC_SQR2(ADC1)

/* ADC regular sequence register 3 (ADC_SQR3) */
#define ADC_SQR3(block)			MMIO32(block + 0x38)
#define ADC1_SQR3			ADC_SQR3(ADC1)

/* ADC regular sequence register 4 (ADC_SQR4) */
#define ADC_SQR4(block)			MMIO32(block + 0x3c)
#define ADC1_SQR4			ADC_SQR4(ADC1)

/* ADC regular sequence register 5 (ADC_SQR5) */
#define ADC_SQR5(block)			MMIO32(block + 0x40)
#define ADC1_SQR5			ADC_SQR5(ADC1)

/* ADC injected sequence register (ADC_JSQR) */
#define ADC_JSQR(block)			MMIO32(block + 0x44)
#define ADC1_JSQR			ADC_JSQR(ADC1)

/* ADC injected data register x (ADC_JDRx) (x=1..4) */
#define ADC_JDR1(block)			MMIO32(block + 0x48)
#define ADC_JDR2(block)			MMIO32(block + 0x4c)
#define ADC_JDR3(block)			MMIO32(block + 0x50)
#define ADC_JDR4(block)			MMIO32(block + 0x54)
#define ADC1_JDR1			ADC_JDR1(ADC1)
#define ADC1_JDR2			ADC_JDR2(ADC1)
#define ADC1_JDR3			ADC_JDR3(ADC1)
#define ADC1_JDR4			ADC_JDR4(ADC1)

/* ADC regular data register (ADC_DR) */
#define ADC_DR(block)			MMIO32(block + 0x58)
#define ADC1_DR				ADC_DR(ADC1)

/* ADC sample time register 0 (ADC_SMPR0) */
#define ADC_SMPR0(block)		MMIO32(block + 0x5c)
#define ADC1_SMPR0			ADC_SMPR0(ADC1)

#define ADC_COMMON_REGISTERS_BASE	(ADC_BASE + 0x300)

/* ADC common status register (ADC_CSR) */
#define ADC_CSR			        MMIO32(ADC_COMMON_REGISTERS_BASE + 0x0)

/* ADC common control register (ADC_CCR) */
#define ADC_CCR	          		MMIO32(ADC_COMMON_REGISTERS_BASE + 0x4)

/* --- ADC Channels ------------------------------------------------------- */

/****************************************************************************/
/** @defgroup adc_channel ADC Channel Numbers
@ingroup STM32L1xx_adc_defines

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
#define ADC_CHANNEL19		0x13
#define ADC_CHANNEL20		0x14
#define ADC_CHANNEL21		0x15
#define ADC_CHANNEL22		0x16
#define ADC_CHANNEL23		0x17
#define ADC_CHANNEL24		0x18
#define ADC_CHANNEL25		0x19
#define ADC_CHANNEL26		0x1A
#define ADC_CHANNEL27		0x1B
#define ADC_CHANNEL28		0x1C
#define ADC_CHANNEL29		0x1D
#define ADC_CHANNEL30		0x1E
#define ADC_CHANNEL31		0x1F
/**@}*/
#define ADC_MASK		    0x1F
#define ADC_SHIFT		    0

/* --- ADC_SR values ------------------------------------------------------- */

#define ADC_SR_JCNR			(1 << 9)
#define ADC_SR_RCNR			(1 << 8)
#define ADC_SR_ADONS			(1 << 6)
#define ADC_SR_OVR			(1 << 5)
#define ADC_SR_STRT			(1 << 4)
#define ADC_SR_JSTRT			(1 << 3)
#define ADC_SR_JEOC			(1 << 2)
#define ADC_SR_EOC			(1 << 1)
#define ADC_SR_AWD			(1 << 0)

/* --- ADC_CR1 values ------------------------------------------------------ */

#define ADC_CR1_OVRIE			(1 << 26)
#define ADC_CR1_RES_12BIT               (0x0 << 24)
#define ADC_CR1_RES_10BIT               (0x1 << 24)
#define ADC_CR1_RES_8BIT                (0x2 << 24)
#define ADC_CR1_RES_6BIT                (0x3 << 24)
#define ADC_CR1_RES_MASK                (0x3 << 24)
#define ADC_CR1_RES_SHIFT               24
#define ADC_CR1_AWDEN			(1 << 23)
#define ADC_CR1_JAWDEN			(1 << 22)
#define ADC_CR1_PDI			(1 << 17)
#define ADC_CR1_PDD			(1 << 16)

/* DISCNUM[2:0]: Discontinuous mode channel count. */
/****************************************************************************/
/** @defgroup adc_cr1_discnum ADC Number of channels in discontinuous mode.
@ingroup STM32L1xx_adc_defines

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

/* AWDCH[4:0]: Analog watchdog channel bits. (Up to 27 other values reserved) */
/* Notes:
 * ADC1: Analog inputs Channel 16, Channel 17 and Channel 26 are internally
 * connected to the temperature sensor, to VREFINT and to VCOMP, respectively.
 */
/****************************************************************************/
/* ADC_CR1 AWDCH[4:0] ADC watchdog channel */
/** @defgroup adc_watchdog_channel ADC watchdog channel
@ingroup STM32L1xx_adc_defines

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
#define ADC_CR1_AWDCH_CHANNEL18		(0x12 << 0)
#define ADC_CR1_AWDCH_CHANNEL19		(0x13 << 0)
#define ADC_CR1_AWDCH_CHANNEL20		(0x14 << 0)
#define ADC_CR1_AWDCH_CHANNEL21		(0x15 << 0)
#define ADC_CR1_AWDCH_CHANNEL22		(0x16 << 0)
#define ADC_CR1_AWDCH_CHANNEL23		(0x17 << 0)
#define ADC_CR1_AWDCH_CHANNEL24		(0x18 << 0)
#define ADC_CR1_AWDCH_CHANNEL25		(0x19 << 0)
#define ADC_CR1_AWDCH_CHANNEL26		(0x1a << 0)
/**@}*/
#define ADC_CR1_AWDCH_MASK		(0x1F << 0)
#define ADC_CR1_AWDCH_SHIFT		0

/* --- ADC_CR2 values ------------------------------------------------------ */

/* SWSTART: */ /** Start conversion of regular channels. */
#define ADC_CR2_SWSTART			(1 << 30)

/* EXTEN: */ /** External trigger conversion mode for regular channels. */
/****************************************************************************/
/* ADC_CR2 EXTEN[1:0] ADC Trigger Identifier */
/** @defgroup adc_trigger_mode_regular ADC Trigger Mode
@ingroup STM32L1xx_adc_defines

@{*/
#define ADC_CR2_EXTEN_DISABLED		(0x0 << 28)
#define ADC_CR2_EXTEN_RISING		(0x1 << 28)
#define ADC_CR2_EXTEN_FALLING		(0x2 << 28)
#define ADC_CR2_EXTEN_BOTH		(0x3 << 28)
#define ADC_CR2_EXTEN_MASK		(0x3 << 28)
#define ADC_CR2_EXTEN_SHIFT		28
/**@}*/

/* EXTSEL[3:0]: External event select for regular group. */
/****************************************************************************/
/* ADC_CR2 EXTSEL[3:0] ADC Trigger Identifier */
/** @defgroup adc_trigger_regular ADC Trigger Identifier
@ingroup STM32L1xx_adc_defines

@{*/
/** Timer 9 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM9_CC2		(0x0 << 24)
/** Timer 9 Trigger Output */
#define ADC_CR2_EXTSEL_TIM9_TRGO	(0x1 << 24)
/** Timer 2 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM2_CC3		(0x2 << 24)
/** Timer 2 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM2_CC2		(0x3 << 24)
/** Timer 3 Trigger Output */
#define ADC_CR2_EXTSEL_TIM3_TRGO	(0x4 << 24)
/** Timer 4 Compare Output 4 */
#define ADC_CR2_EXTSEL_TIM4_CC4		(0x5 << 24)
/** Timer 2 Trigger Output */
#define ADC_CR2_EXTSEL_TIM2_TRGO	(0x6 << 24)
/** Timer 3 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM3_CC1		(0x7 << 24)
/** Timer 3 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM3_CC3		(0x8 << 24)
/** Timer 4 Trigger Output */
#define ADC_CR2_EXTSEL_TIM4_TRGO	(0x9 << 24)
/** Timer 6 Trigger Output */
#define ADC_CR2_EXTSEL_TIM6_TRGO	(0xa << 24)
/** External Interrupt 11 */
#define ADC_CR2_EXTSEL_EXTI11		(0xf << 24)
/**@}*/

#define ADC_CR2_EXTSEL_MASK		(0xf << 24)
#define ADC_CR2_EXTSEL_SHIFT		24

/* Note: Bit 23 is reserved and must be kept at reset value. */

/* JSWSTART: */ /** Start conversion of injected channels. */
#define ADC_CR2_JSWSTART		(1 << 22)

/* JEXTEN: */ /** External trigger enable for injected channels. */
/****************************************************************************/
/* ADC_CR2 JEXTEN[1:0] ADC Trigger Identifier */
/** @defgroup adc_trigger_mode_injected ADC Trigger Mode
@ingroup STM32L1xx_adc_defines

@{*/
#define ADC_CR2_JEXTEN_DISABLED		(0x0 << 20)
#define ADC_CR2_JEXTEN_RISING		(0x1 << 20)
#define ADC_CR2_JEXTEN_FALLING		(0x2 << 20)
#define ADC_CR2_JEXTEN_BOTH		(0x3 << 20)
#define ADC_CR2_JEXTEN_MASK		(0x3 << 20)
#define ADC_CR2_JEXTEN_SHIFT		20
/**@}*/

/* JEXTSEL[3:0]: External event selection for injected group. */
/****************************************************************************/
/* ADC_CR2 JEXTSEL[2:0] ADC Injected Trigger Identifier */
/** @defgroup adc_trigger_injected ADC Injected Trigger Identifier
@ingroup STM32L1xx_adc_defines

@{*/
/** Timer 9 Compare Output 1 */
#define ADC_CR2_JEXTSEL_TIM9_CC1	(0x0 << 16)
/** Timer 9 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM9_TRGO	(0x1 << 16)
/** Timer 2 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM2_TRGO	(0x2 << 16)
/** Timer 2 Compare Output 1 */
#define ADC_CR2_JEXTSEL_TIM2_CC1	(0x3 << 16)
/** Timer 3 Compare Output 4 */
#define ADC_CR2_JEXTSEL_TIM3_CC4	(0x4 << 16)
/** Timer 4 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM4_TRGO	(0x5 << 16)
/** Timer 4 Compare Output 1 */
#define ADC_CR2_JEXTSEL_TIM4_CC1	(0x6 << 16)
/** Timer 4 Compare Output 2 */
#define ADC_CR2_JEXTSEL_TIM4_CC2	(0x7 << 16)
/** Timer 4 Compare Output 3 */
#define ADC_CR2_JEXTSEL_TIM4_CC3	(0x8 << 16)
/** Timer 10 Compare Output 1 */
#define ADC_CR2_JEXTSEL_TIM10_CC1	(0x9 << 16)
/** Timer 7 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM7_TRGO	(0xa << 16)
/** External Interrupt 15 */
#define ADC_CR2_JEXTSEL_EXTI15		(0xf << 16)
/**@}*/

#define ADC_CR2_JEXTSEL_MASK		(0xf << 16)
#define ADC_CR2_JEXTSEL_SHIFT		16

/* Note: Bits [12:15] are reserved and must be kept at reset value. */

/* ALIGN: Data alignement. */
#define ADC_CR2_ALIGN_RIGHT             (0 << 11)
#define ADC_CR2_ALIGN_LEFT              (1 << 11)
#define ADC_CR2_ALIGN			(1 << 11)

/* EOCS: End of conversion selection */
#define ADC_CR2_EOCS			(1 << 10)

/* DDS: DMA disable selection */
#define ADC_CR2_DDS			(1 << 9)

/* DMA: Direct memory access mode. */
#define ADC_CR2_DMA			(1 << 8)

/* Note: Bit 7 is reserved and must be kept at reset value. */

/* DELS[3:0]: Conversion delay selection. */
/****************************************************************************/
/* ADC_CR2 DELS[2:0] Conversion Delay */
/** @defgroup adc_conversion_delay ADC conversion delay
@ingroup STM32L1xx_adc_defines

@{*/
/** No delay */
#define ADC_CR2_DELS_NONE		(0x0 << 4)
/** Delay until converted data have been read */
#define ADC_CR2_DELS_UNTIL_READ         (0x1 << 4)
/** Delay 7 APB clock cycles after the end of conversion */
#define ADC_CR2_DELS_7CYCLES		(0x2 << 4)
/** Delay 15 APB clock cycles after the end of conversion */
#define ADC_CR2_DELS_15CYCLES		(0x3 << 4)
/** Delay 31 APB clock cycles after the end of conversion */
#define ADC_CR2_DELS_31CYCLES		(0x4 << 4)
/** Delay 63 APB clock cycles after the end of conversion */
#define ADC_CR2_DELS_63CYCLES		(0x5 << 4)
/** Delay 127 APB clock cycles after the end of conversion */
#define ADC_CR2_DELS_127CYCLES		(0x6 << 4)
/** Delay 255 APB clock cycles after the end of conversion */
#define ADC_CR2_DELS_255CYCLES		(0x7 << 4)
/**@}*/

#define ADC_CR2_DELS_MASK		(0x7 << 4)
#define ADC_CR2_DELS_SHIFT		4

/* Note: Bit 3 is reserved and must be kept at reset value. */

/* ADC_CFG: ADC configuration */
#define ADC_CR2_ADC_CFG			(1 << 2)

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
#define ADC_SMPR1_SMP29_LSB		27
#define ADC_SMPR1_SMP28_LSB		24
#define ADC_SMPR1_SMP27_LSB		21
#define ADC_SMPR1_SMP26_LSB		18
#define ADC_SMPR1_SMP25_LSB		15
#define ADC_SMPR1_SMP24_LSB		12
#define ADC_SMPR1_SMP23_LSB		9
#define ADC_SMPR1_SMP22_LSB		6
#define ADC_SMPR1_SMP21_LSB		3
#define ADC_SMPR1_SMP20_LSB		0
#define ADC_SMPR1_SMP29_MSK		(0x7 << ADC_SMPR1_SMP29_LSB)
#define ADC_SMPR1_SMP28_MSK		(0x7 << ADC_SMPR1_SMP28_LSB)
#define ADC_SMPR1_SMP27_MSK		(0x7 << ADC_SMPR1_SMP27_LSB)
#define ADC_SMPR1_SMP26_MSK		(0x7 << ADC_SMPR1_SMP26_LSB)
#define ADC_SMPR1_SMP25_MSK		(0x7 << ADC_SMPR1_SMP25_LSB)
#define ADC_SMPR1_SMP24_MSK		(0x7 << ADC_SMPR1_SMP24_LSB)
#define ADC_SMPR1_SMP23_MSK		(0x7 << ADC_SMPR1_SMP23_LSB)
#define ADC_SMPR1_SMP22_MSK		(0x7 << ADC_SMPR1_SMP22_LSB)
#define ADC_SMPR1_SMP21_MSK		(0x7 << ADC_SMPR1_SMP21_LSB)
#define ADC_SMPR1_SMP20_MSK		(0x7 << ADC_SMPR1_SMP20_LSB)

/* --- ADC_SMPR2 values ---------------------------------------------------- */

#define ADC_SMPR2_SMP19_LSB		27
#define ADC_SMPR2_SMP18_LSB		24
#define ADC_SMPR2_SMP17_LSB		21
#define ADC_SMPR2_SMP16_LSB		18
#define ADC_SMPR2_SMP15_LSB		15
#define ADC_SMPR2_SMP14_LSB		12
#define ADC_SMPR2_SMP13_LSB		9
#define ADC_SMPR2_SMP12_LSB		6
#define ADC_SMPR2_SMP11_LSB		3
#define ADC_SMPR2_SMP10_LSB		0
#define ADC_SMPR2_SMP19_MSK		(0x7 << ADC_SMPR2_SMP19_LSB)
#define ADC_SMPR2_SMP18_MSK		(0x7 << ADC_SMPR2_SMP18_LSB)
#define ADC_SMPR2_SMP17_MSK		(0x7 << ADC_SMPR2_SMP17_LSB)
#define ADC_SMPR2_SMP16_MSK		(0x7 << ADC_SMPR2_SMP16_LSB)
#define ADC_SMPR2_SMP15_MSK		(0x7 << ADC_SMPR2_SMP15_LSB)
#define ADC_SMPR2_SMP14_MSK		(0x7 << ADC_SMPR2_SMP14_LSB)
#define ADC_SMPR2_SMP13_MSK		(0x7 << ADC_SMPR2_SMP13_LSB)
#define ADC_SMPR2_SMP12_MSK		(0x7 << ADC_SMPR2_SMP12_LSB)
#define ADC_SMPR2_SMP11_MSK		(0x7 << ADC_SMPR2_SMP11_LSB)
#define ADC_SMPR2_SMP10_MSK		(0x7 << ADC_SMPR2_SMP10_LSB)

/* --- ADC_SMPR3 values ---------------------------------------------------- */

#define ADC_SMPR3_SMP9_LSB		27
#define ADC_SMPR3_SMP8_LSB		24
#define ADC_SMPR3_SMP7_LSB		21
#define ADC_SMPR3_SMP6_LSB		18
#define ADC_SMPR3_SMP5_LSB		15
#define ADC_SMPR3_SMP4_LSB		12
#define ADC_SMPR3_SMP3_LSB		9
#define ADC_SMPR3_SMP2_LSB		6
#define ADC_SMPR3_SMP1_LSB		3
#define ADC_SMPR3_SMP0_LSB		0
#define ADC_SMPR3_SMP9_MSK		(0x7 << ADC_SMPR3_SMP9_LSB)
#define ADC_SMPR3_SMP8_MSK		(0x7 << ADC_SMPR3_SMP8_LSB)
#define ADC_SMPR3_SMP7_MSK		(0x7 << ADC_SMPR3_SMP7_LSB)
#define ADC_SMPR3_SMP6_MSK		(0x7 << ADC_SMPR3_SMP6_LSB)
#define ADC_SMPR3_SMP5_MSK		(0x7 << ADC_SMPR3_SMP5_LSB)
#define ADC_SMPR3_SMP4_MSK		(0x7 << ADC_SMPR3_SMP4_LSB)
#define ADC_SMPR3_SMP3_MSK		(0x7 << ADC_SMPR3_SMP3_LSB)
#define ADC_SMPR3_SMP2_MSK		(0x7 << ADC_SMPR3_SMP2_LSB)
#define ADC_SMPR3_SMP1_MSK		(0x7 << ADC_SMPR3_SMP1_LSB)
#define ADC_SMPR3_SMP0_MSK		(0x7 << ADC_SMPR3_SMP0_LSB)

/* --- ADC_SMPRx generic values -------------------------------------------- */
/****************************************************************************/
/* ADC_SMPRG ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup STM32L1xx_adc_defines

@{*/
#define ADC_SMPR_SMP_4CYC		0x0
#define ADC_SMPR_SMP_9CYC		0x1
#define ADC_SMPR_SMP_16CYC	        0x2
#define ADC_SMPR_SMP_24CYC		0x3
#define ADC_SMPR_SMP_48CYC		0x4
#define ADC_SMPR_SMP_96CYC		0x5
#define ADC_SMPR_SMP_192CYC	        0x6
#define ADC_SMPR_SMP_384CYC	        0x7
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
#define ADC_SQR1_SQ28_LSB		15
#define ADC_SQR1_SQ27_LSB		10
#define ADC_SQR1_SQ26_LSB		5
#define ADC_SQR1_SQ25_LSB		0
#define ADC_SQR1_L_MSK			(0x1f << ADC_SQR1_L_LSB)
#define ADC_SQR1_SQ28_MSK		(0x1f << ADC_SQR1_SQ28_LSB)
#define ADC_SQR1_SQ27_MSK		(0x1f << ADC_SQR1_SQ27_LSB)
#define ADC_SQR1_SQ26_MSK		(0x1f << ADC_SQR1_SQ26_LSB)
#define ADC_SQR1_SQ25_MSK		(0x1f << ADC_SQR1_SQ25_LSB)

/* --- ADC_SQR2 values ----------------------------------------------------- */

#define ADC_SQR2_SQ24_LSB		25
#define ADC_SQR2_SQ23_LSB		20
#define ADC_SQR2_SQ22_LSB		15
#define ADC_SQR2_SQ21_LSB		10
#define ADC_SQR2_SQ20_LSB		5
#define ADC_SQR2_SQ19_LSB		0
#define ADC_SQR2_SQ24_MSK		(0x1f << ADC_SQR2_SQ24_LSB)
#define ADC_SQR2_SQ23_MSK		(0x1f << ADC_SQR2_SQ23_LSB)
#define ADC_SQR2_SQ22_MSK		(0x1f << ADC_SQR2_SQ22_LSB)
#define ADC_SQR2_SQ21_MSK		(0x1f << ADC_SQR2_SQ21_LSB)
#define ADC_SQR2_SQ20_MSK		(0x1f << ADC_SQR2_SQ20_LSB)
#define ADC_SQR2_SQ19_MSK		(0x1f << ADC_SQR2_SQ19_LSB)

/* --- ADC_SQR3 values ----------------------------------------------------- */

#define ADC_SQR3_SQ18_LSB		25
#define ADC_SQR3_SQ17_LSB		20
#define ADC_SQR3_SQ16_LSB		15
#define ADC_SQR3_SQ15_LSB		10
#define ADC_SQR3_SQ14_LSB		5
#define ADC_SQR3_SQ13_LSB		0
#define ADC_SQR3_SQ18_MSK		(0x1f << ADC_SQR3_SQ18_LSB)
#define ADC_SQR3_SQ17_MSK		(0x1f << ADC_SQR3_SQ17_LSB)
#define ADC_SQR3_SQ16_MSK		(0x1f << ADC_SQR3_SQ16_LSB)
#define ADC_SQR3_SQ15_MSK		(0x1f << ADC_SQR3_SQ15_LSB)
#define ADC_SQR3_SQ14_MSK		(0x1f << ADC_SQR3_SQ14_LSB)
#define ADC_SQR3_SQ13_MSK		(0x1f << ADC_SQR3_SQ13_LSB)

/* --- ADC_SQR4 values ----------------------------------------------------- */

#define ADC_SQR4_SQ12_LSB		25
#define ADC_SQR4_SQ11_LSB		20
#define ADC_SQR4_SQ10_LSB		15
#define ADC_SQR4_SQ9_LSB		10
#define ADC_SQR4_SQ8_LSB		5
#define ADC_SQR4_SQ7_LSB		0
#define ADC_SQR4_SQ12_MSK		(0x1f << ADC_SQR4_SQ12_LSB)
#define ADC_SQR4_SQ11_MSK		(0x1f << ADC_SQR4_SQ11_LSB)
#define ADC_SQR4_SQ10_MSK		(0x1f << ADC_SQR4_SQ10_LSB)
#define ADC_SQR4_SQ9_MSK		(0x1f << ADC_SQR4_SQ9_LSB)
#define ADC_SQR4_SQ8_MSK		(0x1f << ADC_SQR4_SQ8_LSB)
#define ADC_SQR4_SQ7_MSK		(0x1f << ADC_SQR4_SQ7_LSB)

/* --- ADC_SQR5 values ----------------------------------------------------- */

#define ADC_SQR5_SQ6_LSB		25
#define ADC_SQR5_SQ5_LSB		20
#define ADC_SQR5_SQ4_LSB		15
#define ADC_SQR5_SQ3_LSB		10
#define ADC_SQR5_SQ2_LSB		5
#define ADC_SQR5_SQ1_LSB		0
#define ADC_SQR5_SQ6_MSK		(0x1f << ADC_SQR5_SQ6_LSB)
#define ADC_SQR5_SQ5_MSK		(0x1f << ADC_SQR5_SQ5_LSB)
#define ADC_SQR5_SQ4_MSK		(0x1f << ADC_SQR5_SQ4_LSB)
#define ADC_SQR5_SQ3_MSK		(0x1f << ADC_SQR5_SQ3_LSB)
#define ADC_SQR5_SQ2_MSK		(0x1f << ADC_SQR5_SQ2_LSB)
#define ADC_SQR5_SQ1_MSK		(0x1f << ADC_SQR5_SQ1_LSB)

/* --- ADC_JSQR values ----------------------------------------------------- */

#define ADC_JSQR_JL_LSB			20
#define ADC_JSQR_JSQ4_LSB		15
#define ADC_JSQR_JSQ3_LSB		10
#define ADC_JSQR_JSQ2_LSB		5
#define ADC_JSQR_JSQ1_LSB		0

/* JL[2:0]: Injected sequence length. */
/****************************************************************************/
/** @defgroup adc_jsqr_jl ADC Number of channels in discontinuous mode fro injected channels.
@ingroup STM32L1xx_adc_defines

@{*/
#define ADC_JSQR_JL_1CHANNELS		(0x0 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_2CHANNELS		(0x1 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_3CHANNELS		(0x2 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JL_4CHANNELS		(0x3 << ADC_JSQR_JL_LSB)
/**@}*/
#define ADC_JSQR_JL_MSK			(0x2 << ADC_JSQR_JL_LSB)
#define ADC_JSQR_JSQ4_MSK		(0x1f << ADC_JSQR_JSQ4_LSB)
#define ADC_JSQR_JSQ3_MSK		(0x1f << ADC_JSQR_JSQ3_LSB)
#define ADC_JSQR_JSQ2_MSK		(0x1f << ADC_JSQR_JSQ2_LSB)
#define ADC_JSQR_JSQ1_MSK		(0x1f << ADC_JSQR_JSQ1_LSB)

/* --- ADC_JDRx, ADC_DR values --------------------------------------------- */

#define ADC_JDATA_LSB			0
#define ADC_JDATA_MSK			(0xffff << ADC_JDATA_LSB)
#define ADC_DATA_LSB			0
#define ADC_DATA_MSK			(0xffff << ADC_DATA_LSB)

/* --- ADC_SMPR0 values ---------------------------------------------------- */
#define ADC_SMPR0_SMP31_LSB		3
#define ADC_SMPR0_SMP30_LSB		0
#define ADC_SMPR0_SMP31_MSK		(0x7 << ADC_SMPR0_SMP31_LSB)
#define ADC_SMPR0_SMP30_MSK		(0x7 << ADC_SMPR0_SMP30_LSB)

/* --- ADC_CSR values ------------------------------------------------------ */
#define ADC_CSR_AWD			(1 << 0)
#define ADC_CSR_EOC			(1 << 1)
#define ADC_CSR_JEOC			(1 << 2)
#define ADC_CSR_JSTRT			(1 << 3)
#define ADC_CSR_STRT			(1 << 4)
#define ADC_CSR_OVR			(1 << 5)
#define ADC_CSR_ADONS			(1 << 6)

/* --- ADC_CCR values ------------------------------------------------------ */
#define ADC_CCR_TSVREFE			(1 << 23)
#define ADC_CCR_ADCPRE_DIV1		(0x0 << 16)
#define ADC_CCR_ADCPRE_DIV2		(0x1 << 16)
#define ADC_CCR_ADCPRE_DIV4		(0x2 << 16)
#define ADC_CCR_ADCPRE_MASK		(0x3 << 16)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

/* Operation mode API */
void adc_set_continuous_conversion_mode(uint32_t adc);
void adc_set_single_conversion_mode(uint32_t adc);
void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length);
void adc_disable_discontinuous_mode_regular(uint32_t adc);
void adc_enable_discontinuous_mode_injected(uint32_t adc);
void adc_disable_discontinuous_mode_injected(uint32_t adc);
void adc_enable_scan_mode(uint32_t adc);
void adc_disable_scan_mode(uint32_t adc);

/* Trigger API */
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t mode, uint32_t trigger);
void adc_disable_external_trigger_regular(uint32_t adc);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t mode, uint32_t trigger);
void adc_disable_external_trigger_injected(uint32_t adc);

/* Conversion API */
bool adc_eoc(uint32_t adc);
void adc_clear_eoc(uint32_t adc);
bool adc_eoc_injected(uint32_t adc);
void adc_clear_eoc_injected(uint32_t adc);
uint32_t adc_read_regular(uint32_t adc);
uint32_t adc_read_injected(uint32_t adc, uint8_t reg);
void adc_start_conversion_regular(uint32_t adc);
void adc_start_conversion_injected(uint32_t adc);
void adc_enable_automatic_injected_group_conversion(uint32_t adc);
void adc_disable_automatic_injected_group_conversion(uint32_t adc);
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
bool adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);
void adc_set_eoc_of_each_conversion(uint32_t adc);
void adc_set_eoc_of_each_sequence(uint32_t adc);

/* Interrupt configuration */
void adc_enable_eoc_interrupt(uint32_t adc);
void adc_disable_eoc_interrupt(uint32_t adc);
void adc_enable_eoc_interrupt_injected(uint32_t adc);
void adc_disable_eoc_interrupt_injected(uint32_t adc);
void adc_enable_ovr_interrupt(uint32_t adc);
void adc_disable_ovr_interrupt(uint32_t adc);
void adc_enable_awd_interrupt(uint32_t adc);
void adc_disable_awd_interrupt(uint32_t adc);

/* Basic configuration */
void adc_power_on(uint32_t adc);
void adc_power_off(uint32_t adc);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_set_clk_prescale(uint32_t prescaler);
void adc_set_left_aligned(uint32_t adc);
void adc_set_right_aligned(uint32_t adc);
void adc_enable_dma(uint32_t adc);
void adc_disable_dma(uint32_t adc);
void adc_set_single_dma(uint32_t adc);
void adc_set_continuous_dma(uint32_t adc);
void adc_enable_power_down_idle(uint32_t adc);
void adc_disable_power_down_idle(uint32_t adc);
void adc_enable_power_down_delay(uint32_t adc);
void adc_disable_power_down_delay(uint32_t adc);
void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset);
void adc_set_resolution(uint32_t adc, uint16_t resolution);
void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time);
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time);

/* Analog Watchdog */
void adc_enable_analog_watchdog_regular(uint32_t adc);
void adc_disable_analog_watchdog_regular(uint32_t adc);
void adc_enable_analog_watchdog_injected(uint32_t adc);
void adc_disable_analog_watchdog_injected(uint32_t adc);
void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold);
void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold);
void adc_enable_analog_watchdog_on_all_channels(uint32_t adc);
void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc, uint8_t channel);
bool adc_get_watchdog_flag(uint32_t adc);
void adc_clear_watchdog_flag(uint32_t adc);

END_DECLS

#endif
/**@}*/

