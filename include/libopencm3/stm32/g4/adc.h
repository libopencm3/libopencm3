/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32G4xx Analog to Digital
 * converter</b>
 *
 * @ingroup STM32G4xx_defines
 *
 * @version 1.0.0
 *
 * @date 10 Jul 2020
 *
 *LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/stm32/common/adc_common_v2.h>
#include <libopencm3/stm32/common/adc_common_v2_multi.h>

/**@{*/

/** @defgroup adc_reg_base ADC register base addresses
@ingroup STM32xx_adc_defines
@{*/
#define ADC1		ADC1_BASE
#define ADC2		ADC2_BASE
#define ADC3		ADC3_BASE
#define ADC4		ADC4_BASE
#define ADC5		ADC5_BASE
/**@}*/


/*----------- ADC registers -------------------------------------- */
/** ADC_GCOMP Gain compensation Register */
#define ADC_GCOMP(adc)	MMIO32((adc) + 0xC0)

/*------- ADC_CR values ---------*/

/* DEEPPWD: Deep power down */
#define ADC_CR_DEEPPWD		(1 << 29)

/** ADVREGEN: ADC voltage regulator enable bit */
#define ADC_CR_ADVREGEN		(1 << 28)

/*------- ADC_CFGR1 values ---------*/

/** ALIGN: Data alignment */
#define ADC_CFGR1_ALIGN			(1 << 15)

/** EXTSEL[4:0]: External trigger selection for regular group */
#define ADC_CFGR1_EXTSEL_SHIFT		5
#define ADC_CFGR1_EXTSEL_MASK		(0x1f << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x)		((x) << ADC_CFGR1_EXTSEL_SHIFT)

/** CFGR1: ADC configuration register */
#define ADC12_CFGR1_EXTSEL_TIM1_CC1		ADC_CFGR1_EXTSEL_VAL(0)
#define ADC12_CFGR1_EXTSEL_TIM1_CC2		ADC_CFGR1_EXTSEL_VAL(1)
#define ADC12_CFGR1_EXTSEL_TIM1_CC3		ADC_CFGR1_EXTSEL_VAL(2)
#define ADC12_CFGR1_EXTSEL_TIM2_CC2		ADC_CFGR1_EXTSEL_VAL(3)
#define ADC12_CFGR1_EXTSEL_TIM3_TRGO		ADC_CFGR1_EXTSEL_VAL(4)
#define ADC12_CFGR1_EXTSEL_TIM4_CC4		ADC_CFGR1_EXTSEL_VAL(5)
#define ADC12_CFGR1_EXTSEL_EXTI11		ADC_CFGR1_EXTSEL_VAL(6)
#define ADC12_CFGR1_EXTSEL_TIM8_TRGO		ADC_CFGR1_EXTSEL_VAL(7)
#define ADC12_CFGR1_EXTSEL_TIM8_TRGO2		ADC_CFGR1_EXTSEL_VAL(8)
#define ADC12_CFGR1_EXTSEL_TIM1_TRGO		ADC_CFGR1_EXTSEL_VAL(9)
#define ADC12_CFGR1_EXTSEL_TIM1_TRGO2		ADC_CFGR1_EXTSEL_VAL(10)
#define ADC12_CFGR1_EXTSEL_TIM2_TRGO		ADC_CFGR1_EXTSEL_VAL(11)
#define ADC12_CFGR1_EXTSEL_TIM4_TRGO		ADC_CFGR1_EXTSEL_VAL(12)
#define ADC12_CFGR1_EXTSEL_TIM6_TRGO		ADC_CFGR1_EXTSEL_VAL(13)
#define ADC12_CFGR1_EXTSEL_TIM15_TRGO		ADC_CFGR1_EXTSEL_VAL(14)
#define ADC12_CFGR1_EXTSEL_TIM3_CC4		ADC_CFGR1_EXTSEL_VAL(15)
#define ADC12_CFGR1_EXTSEL_TIM20_TRGO		ADC_CFGR1_EXTSEL_VAL(16)
#define ADC12_CFGR1_EXTSEL_TIM20_TRGO2		ADC_CFGR1_EXTSEL_VAL(17)
#define ADC12_CFGR1_EXTSEL_TIM20_CC1		ADC_CFGR1_EXTSEL_VAL(18)
#define ADC12_CFGR1_EXTSEL_TIM20_CC2		ADC_CFGR1_EXTSEL_VAL(19)
#define ADC12_CFGR1_EXTSEL_TIM20_CC3		ADC_CFGR1_EXTSEL_VAL(20)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG1	ADC_CFGR1_EXTSEL_VAL(21)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG3	ADC_CFGR1_EXTSEL_VAL(22)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG5	ADC_CFGR1_EXTSEL_VAL(23)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG6	ADC_CFGR1_EXTSEL_VAL(24)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG7	ADC_CFGR1_EXTSEL_VAL(25)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG8	ADC_CFGR1_EXTSEL_VAL(26)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG9	ADC_CFGR1_EXTSEL_VAL(27)
#define ADC12_CFGR1_EXTSEL_HRTIM_ADC_TRG10	ADC_CFGR1_EXTSEL_VAL(28)
#define ADC12_CFGR1_EXTSEL_LPTIMOUT		ADC_CFGR1_EXTSEL_VAL(29)
#define ADC12_CFGR1_EXTSEL_TIM7_TRGO		ADC_CFGR1_EXTSEL_VAL(30)

#define ADC345_CFGR1_EXTSEL_TIM3_CC1		ADC_CFGR1_EXTSEL_VAL(0)
#define ADC345_CFGR1_EXTSEL_TIM2_CC3		ADC_CFGR1_EXTSEL_VAL(1)
#define ADC345_CFGR1_EXTSEL_TIM1_CC3		ADC_CFGR1_EXTSEL_VAL(2)
#define ADC345_CFGR1_EXTSEL_TIM8_CC1		ADC_CFGR1_EXTSEL_VAL(3)
#define ADC345_CFGR1_EXTSEL_TIM3_TRGO		ADC_CFGR1_EXTSEL_VAL(4)
#define ADC345_CFGR1_EXTSEL_EXTI2		ADC_CFGR1_EXTSEL_VAL(5)
#define ADC345_CFGR1_EXTSEL_TIM4_CC1		ADC_CFGR1_EXTSEL_VAL(6)
#define ADC345_CFGR1_EXTSEL_TIM8_TRGO		ADC_CFGR1_EXTSEL_VAL(7)
#define ADC345_CFGR1_EXTSEL_TIM8_TRGO2		ADC_CFGR1_EXTSEL_VAL(8)
#define ADC345_CFGR1_EXTSEL_TIM1_TRGO		ADC_CFGR1_EXTSEL_VAL(9)
#define ADC345_CFGR1_EXTSEL_TIM1_TRGO2		ADC_CFGR1_EXTSEL_VAL(10)
#define ADC345_CFGR1_EXTSEL_TIM2_TRGO		ADC_CFGR1_EXTSEL_VAL(11)
#define ADC345_CFGR1_EXTSEL_TIM4_TRGO		ADC_CFGR1_EXTSEL_VAL(12)
#define ADC345_CFGR1_EXTSEL_TIM6_TRGO		ADC_CFGR1_EXTSEL_VAL(13)
#define ADC345_CFGR1_EXTSEL_TIM15_TRGO		ADC_CFGR1_EXTSEL_VAL(14)
#define ADC345_CFGR1_EXTSEL_TIM2_CC1		ADC_CFGR1_EXTSEL_VAL(15)
#define ADC345_CFGR1_EXTSEL_TIM20_TRGO		ADC_CFGR1_EXTSEL_VAL(16)
#define ADC345_CFGR1_EXTSEL_TIM20_TRGO2		ADC_CFGR1_EXTSEL_VAL(17)
#define ADC345_CFGR1_EXTSEL_TIM20_CC1		ADC_CFGR1_EXTSEL_VAL(18)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG2	ADC_CFGR1_EXTSEL_VAL(19)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG4	ADC_CFGR1_EXTSEL_VAL(20)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG1	ADC_CFGR1_EXTSEL_VAL(21)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG3	ADC_CFGR1_EXTSEL_VAL(22)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG5	ADC_CFGR1_EXTSEL_VAL(23)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG6	ADC_CFGR1_EXTSEL_VAL(24)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG7	ADC_CFGR1_EXTSEL_VAL(25)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG8	ADC_CFGR1_EXTSEL_VAL(26)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG9	ADC_CFGR1_EXTSEL_VAL(27)
#define ADC345_CFGR1_EXTSEL_HRTIM_ADC_TRG10	ADC_CFGR1_EXTSEL_VAL(28)
#define ADC345_CFGR1_EXTSEL_LPTIMOUT		ADC_CFGR1_EXTSEL_VAL(29)
#define ADC345_CFGR1_EXTSEL_TIM7_TRGO		ADC_CFGR1_EXTSEL_VAL(30)

/*------- ADC_CFGR2 values ---------*/

/** ROVSE: Regular Oversampling Enable */
#define ADC_CFGR2_ROVSE				(1 << 0)

/** JOVSE: Injected Oversampling Enable */
#define ADC_CFGR2_JOVSE				(1 << 1)

/** OVSR[2:0]: Oversampling ratio */
#define ADC_CFGR2_OVSR_SHIFT			2
#define ADC_CFGR2_OVSR_MASK			(0x7 << ADC_CFGR2_OVSR_SHIFT)
#define ADC_CFGR2_OVSR_VAL(x)			((x) << ADC_CFGR2_OVSR_SHIFT)

#define ADC_CFGR2_OVSR_2x			ADC_CFGR2_OVSR_VAL(0)
#define ADC_CFGR2_OVSR_4x			ADC_CFGR2_OVSR_VAL(1)
#define ADC_CFGR2_OVSR_8x			ADC_CFGR2_OVSR_VAL(2)
#define ADC_CFGR2_OVSR_16x			ADC_CFGR2_OVSR_VAL(3)
#define ADC_CFGR2_OVSR_32x			ADC_CFGR2_OVSR_VAL(4)
#define ADC_CFGR2_OVSR_64x			ADC_CFGR2_OVSR_VAL(5)
#define ADC_CFGR2_OVSR_128x			ADC_CFGR2_OVSR_VAL(6)
#define ADC_CFGR2_OVSR_256x			ADC_CFGR2_OVSR_VAL(7)

/** OVSS[3:0]: Oversampling shift */
#define ADC_CFGR2_OVSS_SHIFT			5
#define ADC_CFGR2_OVSS_MASK			(0xf << ADC_CFGR2_OVSS_SHIFT)
#define ADC_CFGR2_OVSS_VAL(x)			((x) << ADC_CFGR2_OVSS_SHIFT)

/** TROVS: Triggered Regular Oversampling */
#define ADC_CFGR2_TROVS				(1 << 9)

/** ROVSM: Regular Oversampling mode */
#define ADC_CFGR2_ROVSM				(1 << 10)

/** GCOMP: Gain compensation mode */
#define ADC_CFGR2_GCOMP				(1 << 16)

/** SWTRIG: Software trigger bit for sampling time control trigger mode */
#define ADC_CFGR2_SWTRIG			(1 << 25)

/** BULB: Bulb sampling mode */
#define ADC_CFGR2_BULB				(1 << 26)

/** SMPTRIG: Sampling time control trigger mode */
#define ADC_CFGR2_SMPTRIG			(1 << 27)

/****************************************************************************/
/* ADC_SMPRx ADC Sample Time Selection for Channels */
/** @defgroup adc_sample ADC Sample Time Selection values
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_2DOT5CYC		0x0
#define ADC_SMPR_SMP_6DOT5CYC		0x1
#define ADC_SMPR_SMP_12DOT5CYC		0x2
#define ADC_SMPR_SMP_24DOT5CYC		0x3
#define ADC_SMPR_SMP_47DOT5CYC		0x4
#define ADC_SMPR_SMP_92DOT5CYC		0x5
#define ADC_SMPR_SMP_247DOT5CYC 	0x6
#define ADC_SMPR_SMP_640DOT5CYC		0x7

#define ADC_SMPR1_SMP_PLUSONE		(1 << 31)

/**@}*/

/* SMPx[2:0]: Channel x sampling time selection */

/*------- ADC_T2 values ---------*/

/* Bits 23:16 HT2[7:0]: Analog watchdog 2 higher threshold */

/* Bit 7:0 LT2[7:0]: Analog watchdog 2 lower threshold */


/*------- ADC_T3 values ---------*/

/* Bits 23:16 HT3[7:0]: Analog watchdog 3 higher threshold */

/* Bit 7:0 LT3[7:0]: Analog watchdog 3 lower threshold */


/*------- ADC_DR values ---------*/

/* Bits 15:0 RDATA[15:0]: Regular Data converted */


/*------- ADC_JSQR values ---------*/

#define ADC_JSQR_JL_LSB			0
#define ADC_JSQR_JL_SHIFT		0
#define ADC_JSQR_JSQ4_LSB		27
#define ADC_JSQR_JSQ3_LSB		21
#define ADC_JSQR_JSQ2_LSB		15
#define ADC_JSQR_JSQ1_LSB		9

#define ADC_JSQR_JSQ_VAL(n, val)	((val) << (((n) - 1) * 6 + 8))
#define ADC_JSQR_JL_VAL(val)		(((val) - 1) << ADC_JSQR_JL_SHIFT)

/* Bits 31:27 JSQ4[4:0]: 4th conversion in the injected sequence */

/* Bits 25:21 JSQ3[4:0]: 3rd conversion in the injected sequence */

/* Bits 19:15 JSQ2[4:0]: 2nd conversion in the injected sequence */

/* Bits 13:9 JSQ1[4:0]: 1st conversion in the injected sequence */

/*
 * JEXTEN[1:0]: External Trigger Enable and Polarity Selection for injected
 * channels
 */
#define ADC_JSQR_JEXTEN_DISABLED	(0x0 << 7)
#define ADC_JSQR_JEXTEN_RISING_EDGE	(0x1 << 7)
#define ADC_JSQR_JEXTEN_FALLING_EDGE	(0x2 << 7)
#define ADC_JSQR_JEXTEN_BOTH_EDGES	(0x3 << 7)

#define ADC_JSQR_JEXTEN_MASK		(0x3 << 7)

/* JEXTSEL[3:0]: External Trigger Selection for injected group */
#define ADC_JSQR_JEXTSEL_SHIFT			2

#define ADC12_JSQR_JEXTSEL_TIM1_TRGO		(0 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM1_CC4		(1 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM2_TRGO		(2 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM2_CC1		(3 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM3_CC4		(4 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM4_TRGO		(5 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_EXTI15		(6 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM8_CC4		(7 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM1_TRGO2		(8 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM8_TRGO		(9 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM8_TRGO2		(10 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM3_CC3		(11 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM3_TRGO		(12 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM3_CC1		(13 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM6_TRGO		(14 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM15_TRGO		(15 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM20_TRGO		(16 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM20_TRGO2		(17 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM20_CC4		(18 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG2	(19 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG4	(20 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG5	(21 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG6	(22 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG7	(23 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG8	(24 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG9	(25 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_HRTIM_ADC_TRG10	(26 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM16_CC1		(27 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_LPTIMOUT		(29 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC12_JSQR_JEXTSEL_TIM7_TRGO		(30 << ADC_JSQR_JEXTSEL_SHIFT)

#define ADC345_JSQR_JEXTSEL_TIM1_TRGO		(0 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM1_CC4		(1 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM2_TRGO		(2 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM8_CC2		(3 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM4_CC3		(4 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM4_TRGO		(5 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM4_CC4		(6 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM8_CC4		(7 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM1_TRGO2		(8 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM8_TRGO		(9 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM8_TRGO2		(10 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM1_CC3		(11 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM3_TRGO		(12 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_EXTI3		(13 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM6_TRGO		(14 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM15_TRGO		(15 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM20_TRGO		(16 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM20_TRGO2		(17 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM20_CC2		(18 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG2	(19 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG4	(20 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG5	(21 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG6	(22 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG7	(23 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG8	(24 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG9	(25 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG10	(26 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG1	(27 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_HRTIM_ADC_TRG3	(28 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_LPTIMOUT		(29 << ADC_JSQR_JEXTSEL_SHIFT)
#define ADC345_JSQR_JEXTSEL_TIM7_TRGO		(30 << ADC_JSQR_JEXTSEL_SHIFT)

#define ADC_JSQR_JEXTSEL_MASK			(0x1F << ADC_JSQR_JEXTSEL_SHIFT)

/* JL[1:0]: Injected channel sequence length */
#define ADC_JSQR_JL_1_CONVERSION	(0x0 << 0)
#define ADC_JSQR_JL_2_CONVERSIONS	(0x1 << 0)
#define ADC_JSQR_JL_3_CONVERSIONS	(0x2 << 0)
#define ADC_JSQR_JL_4_CONVERSIONS	(0x3 << 0)

/*------- ADC_OFR1 values ---------*/

/* OFFSET1_EN: Offset 1 Enable */
#define ADC_OFR1_OFFSET1_EN	(1 << 31)

/* Bits 30:26 OFFSET1_CH[4:0]: Channel selection for the Data offset 1 */

/*
 * Bits 11:0 OFFSET1[11:0]: Data offset y for the channel programmed into bits
 * OFFSET1_CH[4:0]
 */


/*------- ADC_OFR2 values ---------*/

/* OFFSET2_EN: Offset 2 Enable */
#define ADC_OFR2_OFFSET2_EN	(1 << 31)

/* Bits 30:26 OFFSET2_CH[4:0]: Channel selection for the Data offset 2 */

/*
 * Bits 11:0 OFFSET2[11:0]: Data offset y for the channel programmed into bits
 * OFFSET2_CH[4:0]
 */


/*------- ADC_OFR3 values ---------*/

/* OFFSET3_EN: Offset 3 Enable */
#define ADC_OFR3_OFFSET3_EN	(1 << 31)

/* Bits 30:26 OFFSET3_CH[4:0]: Channel selection for the Data offset 3 */

/*
 * Bits 11:0 OFFSET3[11:0]: Data offset y for the channel programmed into bits
 * OFFSET3_CH[4:0]
 */


/*------- ADC_OFR4 values ---------*/

/* OFFSET4_EN: Offset 4 Enable */
#define ADC_OFR4_OFFSET4_EN	(1 << 31)

/* Bits 30:26 OFFSET4_CH[4:0]: Channel selection for the Data offset 4 */

/*
 * Bits 11:0 OFFSET4[11:0]: Data offset y for the channel programmed into bits
 * OFFSET4_CH[4:0]
 */


/*------- ADC_JDRy, y= 1..4 values -------*/

/* Bits 15:0 JDATA[15:0]: Injected data */


/*------- ADC_AWD2CR values ---------*/

/* Bits 18:1 AWD2CH[18:1]: Analog watchdog 2 channel selection */


/*------- ADC_AWD3CR values ---------*/

/* Bits 18:1 AWD3CH[18:1]: Analog watchdog 3 channel selection */

/*--------------- ADC_CSR values  ------------------------*/

/* Bit 26 JQOVF_SLV: Injected Context Queue Overflow flag of the slave ADC */
#define ADC_CSR_JQOVF_SLV		(1 << 26)

/* Bit 25 AWD3_SLV: Analog watchdog 3 flag of the slave ADC */
#define ADC_CSR_AWD3_SLV		(1 << 25)

/* Bit 24 AWD2_SLV: Analog watchdog 2 flag of the slave ADC */
#define ADC_CSR_AWD2_SLV		(1 << 24)

/* Bit 23 AWD1_SLV: Analog watchdog 1 flag of the slave ADC */
#define ADC_CSR_AWD1_SLV		(1 << 23)

/* Bit 22 JEOS_SLV: End of injected sequence flag of the slave ADC */
#define ADC_CSR_JEOS_SLV		(1 << 22)

/* Bit 21 JEOC_SLV: End of injected conversion flag of the slave ADC */
#define ADC_CSR_JEOC_SLV		(1 << 21)

/* Bit 20 OVR_SLV: Overrun flag of the slave ADC */
#define ADC_CSR_OVR_SLV			(1 << 20)

/* Bit 19 EOS_SLV: End of regular sequence flag of the slave ADC */
#define ADC_CSR_EOS_SLV			(1 << 19)

/* Bit 18 EOC_SLV: End of regular conversion of the slave ADC */
#define ADC_CSR_EOC_SLV			(1 << 18)

/* Bit 17 EOSMP_SLV: End of Sampling phase flag of the slave ADC */
#define ADC_CSR_EOSMP_SLV		(1 << 17)

/* Bit 16 ADRDY_SLV: Slave ADC ready */
#define ADC_CSR_ADRDY_SLV		(1 << 16)

/* Bit 10 JQOVF_MST: Injected Context Queue Overflow flag of the master ADC */
#define ADC_CSR_JQOVF_MST		(1 << 10)

/* Bit 9 AWD3_MST: Analog watchdog 3 flag of the master ADC */
#define ADC_CSR_AWD3_MST		(1 << 9)

/* Bit 8 AWD2_MST: Analog watchdog 2 flag of the master ADC */
#define ADC_CSR_AWD2_MST		(1 << 8)

/* Bit 7 AWD1_MST: Analog watchdog 1 flag of the master ADC */
#define ADC_CSR_AWD1_MST		(1 << 7)

/* Bit 6 JEOS_MST: End of injected sequence flag of the master ADC */
#define ADC_CSR_JEOS_MST		(1 << 6)

/* Bit 5 JEOC_MST: End of injected conversion flag of the master ADC */
#define ADC_CSR_JEOC_MST		(1 << 5)

/* Bit 4 OVR_MST: Overrun flag of the master ADC */
#define ADC_CSR_OVR_MST			(1 << 4)

/* Bit 3 EOS_MST: End of regular sequence flag of the master ADC */
#define ADC_CSR_EOS_MST			(1 << 3)

/* Bit 2 EOC_MST: End of regular conversion of the master ADC */
#define ADC_CSR_EOC_MST			(1 << 2)

/* Bit 1 EOSMP_MST: End of Sampling phase flag of the master ADC */
#define ADC_CSR_EOSMP_MST		(1 << 1)

/* Bit 0 ADRDY_MST: Master ADC ready */
#define ADC_CSR_ADRDY_MST		(1 << 0)


/*-------- ADC_CCR values ------------*/

/* Bits 21:18 PRESC[21:18]: ADC Prescaler */
#define ADC_CCR_PRESC_MASK		(0xf)
#define ADC_CCR_PRESC_SHIFT		(18)
/** @defgroup adc_ccr_presc ADC clock prescaler
 *@{*/
#define ADC_CCR_PRESC_NODIV		(0x0 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV1		(0x1 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV2		(0x2 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV6		(0x3 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV8		(0x4 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV10		(0x5 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV12		(0x6 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV16		(0x7 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV32		(0x8 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV64		(0x9 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV128		(0x10 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV256		(0x11 << ADC_CCR_PRESC_SHIFT)
/**@}*/

/* CKMODE[1:0]: ADC clock mode */
#define ADC_CCR_CKMODE_CKX		(0x0 << 16)
#define ADC_CCR_CKMODE_DIV1		(0x1 << 16)
#define ADC_CCR_CKMODE_DIV2		(0x2 << 16)
#define ADC_CCR_CKMODE_DIV4		(0x3 << 16)

#define ADC_CCR_CKMODE_MASK		(0x3 << 16)

/* MDMA[1:0]: Direct memory access mode for dual ADC mode */
#define ADC_CCR_MDMA_DISABLE		(0x0 << 14)
/*#define ADC_CCR_MDMA_RESERVED		(0x1 << 14)*/
#define ADC_CCR_MDMA_12_10_BIT		(0x2 << 14)
#define ADC_CCR_MDMA_8_6_BIT		(0x3 << 14)

/* DMACFG: DMA configuration (for dual ADC mode) */
#define ADC_CCR_DMACFG			(1 << 13)

/* DELAY: Delay between 2 sampling phases */
#define ADC_CCR_DELAY_SHIFT		8

/* DUAL[4:0]: Dual ADC mode selection */
/****************************************************************************/
/** @defgroup adc_multi_mode ADC Multi mode selection
@ingroup adc_defines

@{*/

/** All ADCs independent */
#define ADC_CCR_DUAL_INDEPENDENT			0x0

/* Dual modes: (ADC1 master + ADC2 slave or ADC3 master + ADC4 slave) */
/**
 * Dual modes combined regular simultaneous +
 * injected simultaneous mode.
 */
#define ADC_CCR_DUAL_REG_SIMUL_AND_INJECTED_SIMUL	0x1
/**
 * Dual mode Combined regular simultaneous +
 * alternate trigger mode.
 */
#define ADC_CCR_DUAL_REG_SIMUL_AND_ALTERNATE_TRIG	0x2
/**
 * Dual mode Combined interleaved mode +
 * injected simultaneous mode.
 */
#define ADC_CCR_DUAL_REG_INTERLEAVED_AND_INJECTED_SIMUL	0x3

/** Dual mode Injected simultaneous mode only. */
#define ADC_CCR_DUAL_INJECTED_SIMUL			0x5
/** Dual mode Regular simultaneous mode only. */
#define ADC_CCR_DUAL_REGULAR_SIMUL			0x6
/** Dual mode Interleaved mode only. */
#define ADC_CCR_DUAL_INTERLEAVED			0x7
/** Dual mode Alternate trigger mode only. */
#define ADC_CCR_DUAL_ALTERNATE_TRIG			0x9
/**@}*/

#define ADC_CCR_DUAL_MASK				(0x1f)
#define ADC_CCR_DUAL_SHIFT				0


/*---------------- ADC_CDR values -----------------*/

/* Bits 31:16 RDATA_SLV[15:0]: Regular data of the slave ADC */

/* Bits 15:0 RDATA_MST[15:0]: Regular data of the master ADC. */

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_TEMP		16
#define ADC_CHANNEL_VBAT		17
#define ADC_CHANNEL_VREF		18
/**@}*/

#define ADC_CHANNEL_COUNT 		19
#define ADC_CHANNEL_IS_FAST(x)		((x) <= 5)


BEGIN_DECLS

void adc_enable_analog_watchdog_regular(uint32_t adc);
void adc_disable_analog_watchdog_regular(uint32_t adc);
void adc_enable_analog_watchdog_injected(uint32_t adc);
void adc_disable_analog_watchdog_injected(uint32_t adc);
void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length);
void adc_disable_discontinuous_mode_regular(uint32_t adc);
void adc_enable_discontinuous_mode_injected(uint32_t adc);
void adc_disable_discontinuous_mode_injected(uint32_t adc);
void adc_enable_automatic_injected_group_conversion(uint32_t adc);
void adc_disable_automatic_injected_group_conversion(uint32_t adc);
void adc_enable_analog_watchdog_on_all_channels(uint32_t adc);
void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc,
						    uint8_t channel);
void adc_enable_eoc_interrupt_injected(uint32_t adc);
void adc_disable_eoc_interrupt_injected(uint32_t adc);
void adc_enable_eos_interrupt_injected(uint32_t adc);
void adc_disable_eos_interrupt_injected(uint32_t adc);
void adc_enable_all_awd_interrupt(uint32_t adc);
void adc_disable_all_awd_interrupt(uint32_t adc);
void adc_enable_eos_interrupt(uint32_t adc);
void adc_disable_eos_interrupt(uint32_t adc);
void adc_start_conversion_injected(uint32_t adc);
void adc_disable_external_trigger_regular(uint32_t adc);
void adc_disable_external_trigger_injected(uint32_t adc);
void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold);
void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold);
void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
bool adc_eoc_injected(uint32_t adc);
bool adc_eos_injected(uint32_t adc);
uint32_t adc_read_injected(uint32_t adc, uint8_t reg);
void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset);
void adc_set_clk_source(uint32_t adc, uint32_t source);
void adc_set_clk_prescale(uint32_t adc, uint32_t prescaler);
void adc_set_multi_mode(uint32_t adc, uint32_t mode);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity);
bool adc_awd(uint32_t adc);
void adc_enable_deeppwd(uint32_t adc);
void adc_disable_deeppwd(uint32_t adc);

END_DECLS

/**@}*/


#endif

