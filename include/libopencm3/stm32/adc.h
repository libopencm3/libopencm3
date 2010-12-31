/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* ADC port base addresses (for convenience) */
#define ADC1				ADC1_BASE
#define ADC2				ADC2_BASE
#define ADC3				ADC3_BASE

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

/* --- ADC_SR values ------------------------------------------------------- */

#define ADC_SR_STRT			(1 << 4)
#define ADC_SR_JSTRT			(1 << 3)
#define ADC_SR_JEOC			(1 << 2)
#define ADC_SR_EOC			(1 << 1)
#define ADC_SR_AWD			(1 << 0)

/* --- ADC_CR1 values ------------------------------------------------------ */

#define ADC_CR1_AWDEN			(1 << 23)
#define ADC_CR1_JAWDEN			(1 << 22)
#define ADC_CR1_DUALMOD_LSB		16
#define ADC_CR1_DUALMOD_MSK		(0xf << ADC_DUALMOD_LSB) /* ADC1 only */
#define ADC_CR1_DISCNUM_LSB		13
#define ADC_CR1_DISCNUM_MSK		(0x7 << ADC_DISCNUM_LSB)
#define ADC_CR1_JDISCEN			(1 << 12)
#define ADC_CR1_DISCEN			(1 << 11)
#define ADC_CR1_JAUTO			(1 << 10)
#define ADC_CR1_AWDSGL			(1 << 9)
#define ADC_CR1_SCAN			(1 << 8)
#define ADC_CR1_JEOCIE			(1 << 7)
#define ADC_CR1_AWDIE			(1 << 6)
#define ADC_CR1_EOCIE			(1 << 5)
#define ADC_CR1_AWDCH_LSB		0
#define ADC_CR1_AWDCH_MSK		(0x1f << ADC_AWDCH_LSB)

/* --- ADC_CR2 values ------------------------------------------------------ */

#define ADC_CR2_TSVREFE			(1 << 23) /* ADC1 only! */
#define ADC_CR2_SWSTART			(1 << 22)
#define ADC_CR2_JSWSTART		(1 << 21)
#define ADC_CR2_EXTTRIG			(1 << 20)
#define ADC_CR2_EXTSEL_LSB		17
#define ADC_CR2_EXTSEL_MSK		(0x7 << ADC_EXTSEL_LSB)
/* The following are only valid for ADC1 and ADC2. */
#define ADC_CR2_EXTSEL_TIM1_CC1		0x0
#define ADC_CR2_EXTSEL_TIM1_CC2		0x1
#define ADC_CR2_EXTSEL_TIM1_CC3		0x2
#define ADC_CR2_EXTSEL_TIM2_CC2		0x3
#define ADC_CR2_EXTSEL_TIM3_TRGO	0x4
#define ADC_CR2_EXTSEL_TIM4_CC4		0x5
#define ADC_CR2_EXTSEL_EXTI11		0x6
#define ADC_CR2_EXTSEL_SWSTART		0x7

/* The following are only valid for ADC3 */
#define ADC_CR2_EXTSEL_TIM3_CC1		0x0
#define ADC_CR2_EXTSEL_TIM2_CC3		0x1
#define ADC_CR2_EXTSEL_TIM8_CC1		0x3
#define ADC_CR2_EXTSEL_TIM8_TRGO	0x4
#define ADC_CR2_EXTSEL_TIM5_CC1		0x5
#define ADC_CR2_EXTSEL_TIM5_CC3		0x6

/* Bit 16: reserved, must be kept cleared */
#define ADC_CR2_JEXTTRIG		(1 << 15)
#define ADC_CR2_JEXTSEL_LSB		12
#define ADC_CR2_JEXTSEL_MSK		(0x7 << ADC_JEXTSEL_LSB)
/* The following are only valid for ADC1 and ADC2. */
#define ADC_CR2_JEXTSEL_TIM1_TRGO	0x0
#define ADC_CR2_JEXTSEL_TIM1_CC4	0x1
#define ADC_CR2_JEXTSEL_TIM2_TRGO	0x2
#define ADC_CR2_JEXTSEL_TIM2_CC1	0x3
#define ADC_CR2_JEXTSEL_TIM3_CC4	0x4
#define ADC_CR2_JEXTSEL_TIM4_TRGO	0x5
#define ADC_CR2_JEXTSEL_EXTI15		0x6
#define ADC_CR2_JEXTSEL_JSWSTART	0x7

/* The following are the different meanings for ADC3 only. */
#define ADC_CR2_JEXTSEL_TIM4_CC3	0x2
#define ADC_CR2_JEXTSEL_TIM8_CC2	0x3
#define ADC_CR2_JEXTSEL_TIM8_CC4	0x4
#define ADC_CR2_JEXTSEL_TIM5_TRGO	0x5
#define ADC_CR2_JEXTSEL_TIM5_CC4	0x6

#define ADC_CR2_ALIGN			(1 << 11)
#define ADC_CR2_DMA			(1 << 8) /* ADC 1 & 3 only! */
/* Bits [7:4] have to be kept 0. */
#define ADC_CR2_RSTCAL			(1 << 3)
#define ADC_CR2_CAL			(1 << 2)
#define ADC_CR2_CONT			(1 << 1)
#define ADC_CR2_ADON			(1 << 0) /* Must be separately written. */

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
#define ADC_SMPR1_SMP_1DOT5CYC		0x0
#define ADC_SMPR1_SMP_7DOT5CYC		0x1
#define ADC_SMPR1_SMP_13DOT5CYC		0x2
#define ADC_SMPR1_SMP_28DOT5CYC		0x3
#define ADC_SMPR1_SMP_41DOT5CYC		0x4
#define ADC_SMPR1_SMP_55DOT5CYC		0x5
#define ADC_SMPR1_SMP_71DOT5CYC		0x6
#define ADC_SMPR1_SMP_239DOT5CYC	0x7

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
#define ADC_SMPR2_SMP_1DOT5CYC		0x0
#define ADC_SMPR2_SMP_7DOT5CYC		0x1
#define ADC_SMPR2_SMP_13DOT5CYC		0x2
#define ADC_SMPR2_SMP_28DOT5CYC		0x3
#define ADC_SMPR2_SMP_41DOT5CYC		0x4
#define ADC_SMPR2_SMP_55DOT5CYC		0x5
#define ADC_SMPR2_SMP_71DOT5CYC		0x6
#define ADC_SMPR2_SMP_239DOT5CYC	0x7

/* --- ADC_SMPRx generic values -------------------------------------------- */

#define ADC_SMPR_SMP_1DOT5CYC		0x0
#define ADC_SMPR_SMP_7DOT5CYC		0x1
#define ADC_SMPR_SMP_13DOT5CYC		0x2
#define ADC_SMPR_SMP_28DOT5CYC		0x3
#define ADC_SMPR_SMP_41DOT5CYC		0x4
#define ADC_SMPR_SMP_55DOT5CYC		0x5
#define ADC_SMPR_SMP_71DOT5CYC		0x6
#define ADC_SMPR_SMP_239DOT5CYC		0x7

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
#define ADC_SQR1_L_MSK			(0xf << ADC_L_LSB)
#define ADC_SQR1_SQ16_MSK		(0x1f << ADC_SQ16_LSB)
#define ADC_SQR1_SQ15_MSK		(0x1f << ADC_SQ15_LSB)
#define ADC_SQR1_SQ14_MSK		(0x1f << ADC_SQ14_LSB)
#define ADC_SQR1_SQ13_MSK		(0x1f << ADC_SQ13_LSB)

/* --- ADC_SQR2 values ----------------------------------------------------- */

#define ADC_SQR2_SQ12_LSB		25
#define ADC_SQR2_SQ11_LSB		20
#define ADC_SQR2_SQ10_LSB		15
#define ADC_SQR2_SQ9_LSB		10
#define ADC_SQR2_SQ8_LSB		5
#define ADC_SQR2_SQ7_LSB		0
#define ADC_SQR2_SQ12_MSK		(0x1f << ADC_SQ12_LSB)
#define ADC_SQR2_SQ11_MSK		(0x1f << ADC_SQ11_LSB)
#define ADC_SQR2_SQ10_MSK		(0x1f << ADC_SQ10_LSB)
#define ADC_SQR2_SQ9_MSK		(0x1f << ADC_SQ9_LSB)
#define ADC_SQR2_SQ8_MSK		(0x1f << ADC_SQ8_LSB)
#define ADC_SQR2_SQ7_MSK		(0x1f << ADC_SQ7_LSB)

/* --- ADC_SQR3 values ----------------------------------------------------- */

#define ADC_SQR3_SQ6_LSB		25
#define ADC_SQR3_SQ5_LSB		20
#define ADC_SQR3_SQ4_LSB		15
#define ADC_SQR3_SQ3_LSB		10
#define ADC_SQR3_SQ2_LSB		5
#define ADC_SQR3_SQ1_LSB		0
#define ADC_SQR3_SQ6_MSK		(0x1f << ADC_SQ6_LSB)
#define ADC_SQR3_SQ5_MSK		(0x1f << ADC_SQ5_LSB)
#define ADC_SQR3_SQ4_MSK		(0x1f << ADC_SQ4_LSB)
#define ADC_SQR3_SQ3_MSK		(0x1f << ADC_SQ3_LSB)
#define ADC_SQR3_SQ2_MSK		(0x1f << ADC_SQ2_LSB)
#define ADC_SQR3_SQ1_MSK		(0x1f << ADC_SQ1_LSB)

/* --- ADC_JSQR values ----------------------------------------------------- */

#define ADC_JSQR_JL_LSB			20
#define ADC_JSQR_JSQ4_LSB		15
#define ADC_JSQR_JSQ3_LSB		10
#define ADC_JSQR_JSQ2_LSB		5
#define ADC_JSQR_JSQ1_LSB		0
#define ADC_JSQR_JL_MSK			(0x2 << ADC_JL_LSB)
#define ADC_JSQR_JSQ4_MSK		(0x1f << ADC_JSQ4_LSB)
#define ADC_JSQR_JSQ3_MSK		(0x1f << ADC_JSQ3_LSB)
#define ADC_JSQR_JSQ2_MSK		(0x1f << ADC_JSQ2_LSB)
#define ADC_JSQR_JSQ1_MSK		(0x1f << ADC_JSQ1_LSB)

/* --- ADC_JDRx, ADC_DR values --------------------------------------------- */

#define ADC_JDATA_LSB			0
#define ADC_DATA_LSB			0
#define ADC_ADC2DATA_LSB		16 /* ADC1 only (dual mode) */
#define ADC_JDATA_MSK			(0xffff << ADC_JDATA_LSB)
#define ADC_DATA_MSK			(0xffff << ADC_DA)
#define ADC_ADC2DATA_MSK		(0xffff << ADC_ADC2DATA_LSB)
						/* ADC1 only (dual mode) */

/* --- Function prototypes ------------------------------------------------- */


/* TODO */
void adc_enable_analog_watchdog_regular(u32 adc);
void adc_disable_analog_watchdog_regular(u32 adc);
void adc_enable_analog_watchdog_injected(u32 adc);
void adc_disable_analog_watchdog_injected(u32 adc);
void adc_enable_discontinous_mode_regular(u32 adc);
void adc_disable_discontinous_mode_regular(u32 adc);
void adc_enable_discontinous_mode_injected(u32 adc);
void adc_disable_discontinous_mode_injected(u32 adc);
void adc_enable_automatic_injected_group_conversion(u32 adc);
void adc_disable_automatic_injected_group_conversion(u32 adc);
void adc_enable_analog_watchdog_on_all_channels(u32 adc);
void adc_enable_analog_watchdog_on_selected_channel(u32 adc, u8 channel);
void adc_enable_scan_mode(u32 adc);
void adc_disable_scan_mode(u32 adc);
void adc_enable_jeoc_interrupt(u32 adc);
void adc_disable_jeoc_interrupt(u32 adc);
void adc_enable_awd_interrupt(u32 adc);
void adc_disable_awd_interrupt(u32 adc);
void adc_enable_eoc_interrupt(u32 adc);
void adc_disable_eoc_interrupt(u32 adc);
void adc_enable_temperature_sensor(u32 adc);
void adc_disable_temperature_sensor(u32 adc);
void adc_start_conversion_regular(u32 adc);
void adc_start_conversion_injected(u32 adc);
void adc_enable_external_trigger_regular(u32 adc, u8 trigger);
void adc_disable_external_trigger_regular(u32 adc);
void adc_enable_external_trigger_injected(u32 adc, u8 trigger);
void adc_disable_external_trigger_injected(u32 adc);
void adc_set_left_aligned(u32 adc);
void adc_set_right_aligned(u32 adc);
void adc_enable_dma(u32 adc);
void adc_disable_dma(u32 adc);
void adc_reset_calibration(u32 adc);
void adc_calibration(u32 adc);
void adc_set_continous_conversion_mode(u32 adc);
void adc_set_single_conversion_mode(u32 adc);
void adc_on(u32 adc);
void adc_off(u32 adc);
void adc_set_conversion_time(u32 adc, u8 channel, u8 time);
void adc_set_conversion_time_on_all_channels(u32 adc, u8 time);
void adc_set_watchdog_high_threshold(u32 adc, u16 threshold);
void adc_set_watchdog_low_threshold(u32 adc, u16 threshold);
void adc_set_regular_sequence(u32 adc, u8 length, u8 channel[]);
void adc_set_injected_sequence(u32 adc, u8 length, u8 channel[]);

#endif
