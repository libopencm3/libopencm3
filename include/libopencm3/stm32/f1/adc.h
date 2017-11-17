/** @defgroup adc_defines ADC Defines

@brief <b>Defined Constants and Types for the STM32F1xx Analog to Digital
Converters</b>

@ingroup STM32F1xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Edward Cheeseman <evbuilder@users.sourceforge.net>

@date 18 August 2012

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

#include <libopencm3/stm32/common/adc_common_v1.h>

/* --- Convenience macros -------------------------------------------------- */

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


/* --- ADC_CR1 values ------------------------------------------------------ */

/* Note: Bits [21:20] are reserved, and must be kept at reset value. */

/* DUALMOD[3:0]: Dual mode selection. (ADC1 only) */
/* Legend:
 * IND: Independent mode.
 * CRSISM: Combined regular simultaneous + injected simultaneous mode.
 * CRSATM: Combined regular simultaneous + alternate trigger mode.
 * CISFIM: Combined injected simultaneous + fast interleaved mode.
 * CISSIM: Combined injected simultaneous + slow interleaved mode.
 * ISM: Injected simultaneous mode only.
 * RSM: Regular simultaneous mode only.
 * FIM: Fast interleaved mode only.
 * SIM: Slow interleaved mode only.
 * ATM: Alternate trigger mode only.
 */
/****************************************************************************/
/* ADC_CR1 DUALMOD[3:0] ADC Mode Selection */
/** @defgroup adc_cr1_dualmod ADC Mode Selection
@ingroup adc_defines

@{*/
/** Independent (non-dual) mode */
#define ADC_CR1_DUALMOD_IND             (0x0 << 16)
/** Combined regular simultaneous + injected simultaneous mode. */
#define ADC_CR1_DUALMOD_CRSISM          (0x1 << 16)
/** Combined regular simultaneous + alternate trigger mode. */
#define ADC_CR1_DUALMOD_CRSATM          (0x2 << 16)
/** Combined injected simultaneous + fast interleaved mode. */
#define ADC_CR1_DUALMOD_CISFIM          (0x3 << 16)
/** Combined injected simultaneous + slow interleaved mode. */
#define ADC_CR1_DUALMOD_CISSIM          (0x4 << 16)
/** Injected simultaneous mode only. */
#define ADC_CR1_DUALMOD_ISM             (0x5 << 16)
/** Regular simultaneous mode only. */
#define ADC_CR1_DUALMOD_RSM             (0x6 << 16)
/** Fast interleaved mode only. */
#define ADC_CR1_DUALMOD_FIM             (0x7 << 16)
/** Slow interleaved mode only. */
#define ADC_CR1_DUALMOD_SIM             (0x8 << 16)
/** Alternate trigger mode only. */
#define ADC_CR1_DUALMOD_ATM             (0x9 << 16)
/**@}*/
#define ADC_CR1_DUALMOD_MASK		(0xF << 16)
#define ADC_CR1_DUALMOD_SHIFT		16

#define ADC_CR1_AWDCH_MAX		17

/* --- ADC_CR2 values ------------------------------------------------------ */

/* TSVREFE: */ /** Temperature sensor and V_REFINT enable. (ADC1 only!) */
#define ADC_CR2_TSVREFE			(1 << 23)

/* SWSTART: */ /** Start conversion of regular channels. */
#define ADC_CR2_SWSTART			(1 << 22)

/* JSWSTART: */ /** Start conversion of injected channels. */
#define ADC_CR2_JSWSTART		(1 << 21)

/* EXTTRIG: */ /** External trigger conversion mode for regular channels. */
#define ADC_CR2_EXTTRIG			(1 << 20)

/* EXTSEL[2:0]: External event select for regular group. */
/* The following are only valid for ADC1 and ADC2. */
/****************************************************************************/
/* ADC_CR2 EXTSEL[2:0] ADC Trigger Identifier for ADC1 and ADC2 */
/** @defgroup adc_trigger_regular_12 ADC Trigger Identifier for ADC1 and ADC2
@ingroup adc_defines

@{*/
/** Timer 1 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM1_CC1		(0x0 << 17)
/** Timer 1 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM1_CC2		(0x1 << 17)
/** Timer 1 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM1_CC3		(0x2 << 17)
/** Timer 2 Compare Output 2 */
#define ADC_CR2_EXTSEL_TIM2_CC2		(0x3 << 17)
/** Timer 3 Trigger Output */
#define ADC_CR2_EXTSEL_TIM3_TRGO	(0x4 << 17)
/** Timer 4 Compare Output 4 */
#define ADC_CR2_EXTSEL_TIM4_CC4		(0x5 << 17)
/** External Interrupt 11 */
#define ADC_CR2_EXTSEL_EXTI11		(0x6 << 17)
/** Software Trigger */
#define ADC_CR2_EXTSEL_SWSTART		(0x7 << 17)
/**@}*/

/* The following are only valid for ADC3 */
/****************************************************************************/
/* ADC_CR2 EXTSEL[2:0] ADC Trigger Identifier for ADC3 */
/** @defgroup adc_trigger_regular_3 ADC Trigger Identifier for ADC3
@ingroup adc_defines

@{*/
/** Timer 2 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM3_CC1		(0x0 << 17)
/** Timer 2 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM2_CC3		(0x1 << 17)
/** Timer 1 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM1_CC3		(0x2 << 17)
/** Timer 8 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM8_CC1		(0x3 << 17)
/** Timer 8 Trigger Output */
#define ADC_CR2_EXTSEL_TIM8_TRGO	(0x4 << 17)
/** Timer 5 Compare Output 1 */
#define ADC_CR2_EXTSEL_TIM5_CC1		(0x5 << 17)
/** Timer 5 Compare Output 3 */
#define ADC_CR2_EXTSEL_TIM5_CC3		(0x6 << 17)
/**@}*/

#define ADC_CR2_EXTSEL_MASK		(0x7 << 17)
#define ADC_CR2_EXTSEL_SHIFT		17

/* Note: Bit 16 is reserved, must be kept at reset value. */

/* JEXTTRIG: External trigger conversion mode for injected channels. */
#define ADC_CR2_JEXTTRIG		(1 << 15)

/* JEXTSEL[2:0]: External event selection for injected group. */
/* The following are only valid for ADC1 and ADC2. */
/****************************************************************************/
/* ADC_CR2 JEXTSEL[2:0] ADC Injected Trigger Identifier for ADC1 and ADC2 */
/** @defgroup adc_trigger_injected_12 ADC Injected Trigger Identifier for ADC1
and ADC2
@ingroup adc_defines

@{*/
/** Timer 1 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM1_TRGO	(0x0 << 12)
/** Timer 1 Compare Output 4 */
#define ADC_CR2_JEXTSEL_TIM1_CC4	(0x1 << 12)
/** Timer 2 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM2_TRGO	(0x2 << 12)
/** Timer 2 Compare Output 1 */
#define ADC_CR2_JEXTSEL_TIM2_CC1	(0x3 << 12)
/** Timer 3 Compare Output 4 */
#define ADC_CR2_JEXTSEL_TIM3_CC4	(0x4 << 12)
/** Timer 4 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM4_TRGO	(0x5 << 12)
/** External Interrupt 15 */
#define ADC_CR2_JEXTSEL_EXTI15		(0x6 << 12)
/** Injected Software Trigger */
#define ADC_CR2_JEXTSEL_JSWSTART	(0x7 << 12) /* Software start. */
/**@}*/

/* The following are the different meanings for ADC3 only. */
/****************************************************************************/
/* ADC_CR2 JEXTSEL[2:0] ADC Injected Trigger Identifier for ADC3 */
/** @defgroup adc_trigger_injected_3 ADC Injected Trigger Identifier for ADC3
@ingroup adc_defines

@{*/
/** Timer 1 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM1_TRGO	(0x0 << 12)
/** Timer 1 Compare Output 4 */
#define ADC_CR2_JEXTSEL_TIM1_CC4	(0x1 << 12)
/** Timer 4 Compare Output 3 */
#define ADC_CR2_JEXTSEL_TIM4_CC3	(0x2 << 12)
/** Timer 8 Compare Output 2 */
#define ADC_CR2_JEXTSEL_TIM8_CC2	(0x3 << 12)
/** Timer 8 Compare Output 4 */
#define ADC_CR2_JEXTSEL_TIM8_CC4	(0x4 << 12)
/** Timer 5 Trigger Output */
#define ADC_CR2_JEXTSEL_TIM5_TRGO	(0x5 << 12)
/** Timer 5 Compare Output 4 */
#define ADC_CR2_JEXTSEL_TIM5_CC4	(0x6 << 12)
/** Injected Software Trigger */
#define ADC_CR2_JEXTSEL_JSWSTART	(0x7 << 12) /* Software start. */
/**@}*/

#define ADC_CR2_JEXTSEL_MASK		(0x7 << 12)
#define ADC_CR2_JEXTSEL_SHIFT		12

/* ALIGN: Data alignment. */
#define ADC_CR2_ALIGN_RIGHT             (0 << 11)
#define ADC_CR2_ALIGN_LEFT              (1 << 11)
#define ADC_CR2_ALIGN			(1 << 11)

/* Note: Bits [10:9] are reserved and must be kept at reset value. */

/* DMA: Direct memory access mode. (ADC1 and ADC3 only!) */
#define ADC_CR2_DMA			(1 << 8)

/* Note: Bits [7:4] are reserved and must be kept at reset value. */

/* RSTCAL: Reset calibration. */
#define ADC_CR2_RSTCAL			(1 << 3)

/* CAL: A/D Calibration. */
#define ADC_CR2_CAL			(1 << 2)

/* CONT: Continuous conversion. */
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
#define ADC_SMPR1_SMP17_MSK		(0x7 << ADC_SMPR1_SMP17_LSB)
#define ADC_SMPR1_SMP16_MSK		(0x7 << ADC_SMPR1_SMP16_LSB)
#define ADC_SMPR1_SMP15_MSK		(0x7 << ADC_SMPR1_SMP15_LSB)
#define ADC_SMPR1_SMP14_MSK		(0x7 << ADC_SMPR1_SMP14_LSB)
#define ADC_SMPR1_SMP13_MSK		(0x7 << ADC_SMPR1_SMP13_LSB)
#define ADC_SMPR1_SMP12_MSK		(0x7 << ADC_SMPR1_SMP12_LSB)
#define ADC_SMPR1_SMP11_MSK		(0x7 << ADC_SMPR1_SMP11_LSB)
#define ADC_SMPR1_SMP10_MSK		(0x7 << ADC_SMPR1_SMP10_LSB)

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
#define ADC_SMPR2_SMP9_MSK		(0x7 << ADC_SMPR2_SMP9_LSB)
#define ADC_SMPR2_SMP8_MSK		(0x7 << ADC_SMPR2_SMP8_LSB)
#define ADC_SMPR2_SMP7_MSK		(0x7 << ADC_SMPR2_SMP7_LSB)
#define ADC_SMPR2_SMP6_MSK		(0x7 << ADC_SMPR2_SMP6_LSB)
#define ADC_SMPR2_SMP5_MSK		(0x7 << ADC_SMPR2_SMP5_LSB)
#define ADC_SMPR2_SMP4_MSK		(0x7 << ADC_SMPR2_SMP4_LSB)
#define ADC_SMPR2_SMP3_MSK		(0x7 << ADC_SMPR2_SMP3_LSB)
#define ADC_SMPR2_SMP2_MSK		(0x7 << ADC_SMPR2_SMP2_LSB)
#define ADC_SMPR2_SMP1_MSK		(0x7 << ADC_SMPR2_SMP1_LSB)
#define ADC_SMPR2_SMP0_MSK		(0x7 << ADC_SMPR2_SMP0_LSB)

/* --- ADC_SMPRx values --------------------------------------------------- */
/****************************************************************************/
/* ADC_SMPRG ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup adc_defines

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
#define ADC_ADC2DATA_LSB		16 /* ADC1 only (dual mode) */
#define ADC_JDATA_MSK			(0xffff << ADC_JDATA_LSB)
#define ADC_DATA_MSK			(0xffff << ADC_DA)
#define ADC_ADC2DATA_MSK		(0xffff << ADC_ADC2DATA_LSB)
					/* ADC1 only (dual mode) */

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_TEMP	16
#define ADC_CHANNEL_VREF	17
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void adc_start_conversion_direct(uint32_t adc);
void adc_set_dual_mode(uint32_t mode);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger);
void adc_reset_calibration(uint32_t adc);
void adc_calibration(uint32_t adc)
	LIBOPENCM3_DEPRECATED("see adc_calibrate/_async");
void adc_calibrate_async(uint32_t adc);
bool adc_is_calibrating(uint32_t adc);
void adc_calibrate(uint32_t adc);

END_DECLS

#endif
/**@}*/

