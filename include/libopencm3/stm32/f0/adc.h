/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Analog to Digital
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

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define ADC				ADC_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/* ADC interrupt and status register */
#define ADC_ISR(base)			MMIO32(base + 0x00)
#define ADC1_ISR			ADC_ISR(ADC)

/* Interrupt Enable Register */
#define ADC_IER(base)			MMIO32(base + 0x04)
#define ADC1_IER			ADC_IER(ADC)

/* Control Register */
#define ADC_CR(base)			MMIO32(base + 0x08)
#define ADC1_CR				ADC_CR(ADC)


/* Configuration Register 1 */
#define ADC_CFGR1(base)			MMIO32(base + 0x0C)
#define ADC1_CFGR1			ADC_CFGR1(ADC)


/* Configuration Register 2 */
#define ADC_CFGR2(base)			MMIO32(base + 0x10)
#define ADC1_CFGR2			ADC_CFGR2(ADC)


/* Sample Time Register 1 */
#define ADC_SMPR(base)			MMIO32(base + 0x14)
#define ADC1_SMPR			ADC_SMPR(ADC)


/* Watchdog Threshold Register */
#define ADC_TR(base)			MMIO32(base + 0x20)
#define ADC1_TR				ADC_TR(ADC)


/* Channel Select Register */
#define ADC_CHSELR(base)		MMIO32(base + 0x28)
#define ADC1_CHSELR			ADC_CHSELR(ADC)


/* Regular Data Register */
#define ADC_DR(base)			MMIO32(base + 0x40)
#define ADC1_DR				ADC_DR(ADC)


/* Regular Data Register */
#define ADC_CCR				MMIO32(ADC_BASE + 0x308)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* ADC_ISR Values -----------------------------------------------------------*/

#define ADC_ISR_AWD			(1 << 7)
#define ADC_ISR_OVR			(1 << 4)
#define ADC_ISR_EOSEQ			(1 << 3)
#define ADC_ISR_EOC			(1 << 2)
#define ADC_ISR_EOSMP			(1 << 1)
#define ADC_ISR_ADRDY			(1 << 0)

/* ADC_IER Values -----------------------------------------------------------*/

#define ADC_IER_AWDIE			(1 << 7)
#define ADC_IER_OVRIE			(1 << 4)
#define ADC_IER_EOSEQIE			(1 << 3)
#define ADC_IER_EOCIE			(1 << 2)
#define ADC_IER_EOSMPIE			(1 << 1)
#define ADC_IER_ADRDYIE			(1 << 0)

/* ADC_CR Values ------------------------------------------------------------*/

#define ADC_CR_ADCAL			(1 << 31)
#define ADC_CR_ADSTP			(1 << 4)
#define ADC_CR_ADSTART			(1 << 2)
#define ADC_CR_ADDIS			(1 << 1)
#define ADC_CR_ADEN			(1 << 0)

/* ADC_CFGR1 Values ---------------------------------------------------------*/

#define ADC_CFGR1_AWDCH_SHIFT		26
#define ADC_CFGR1_AWDCH			(0x1F << ADC_CFGR1_AWDCH_SHIFT)
#define ADC_CFGR1_AWDCH_VAL(x)		((x) << ADC_CFGR1_AWDCH_SHIFT)

#define ADC_CFGR1_AWDEN			(1 << 23)
#define ADC_CFGR1_AWDSGL		(1 << 22)
#define ADC_CFGR1_DISCEN		(1 << 16)
#define ADC_CFGR1_AUTOFF		(1 << 15)
#define ADC_CFGR1_WAIT			(1 << 14)
#define ADC_CFGR1_CONT			(1 << 13)
#define ADC_CFGR1_OVRMOD		(1 << 12)

#define ADC_CFGR1_EXTEN_SHIFT		10
#define ADC_CFGR1_EXTEN			(3 << ADC_CFGR1_EXTEN_SHIFT)
#define ADC_CFGR1_EXTEN_DISABLE		(0 << ADC_CFGR1_EXTEN_SHIFT)
#define ADC_CFGR1_EXTEN_RISING		(1 << ADC_CFGR1_EXTEN_SHIFT)
#define ADC_CFGR1_EXTEN_FALLING		(2 << ADC_CFGR1_EXTEN_SHIFT)
#define ADC_CFGR1_EXTEN_BOTH		(3 << ADC_CFGR1_EXTEN_SHIFT)

#define ADC_CFGR1_EXTSEL_SHIFT		6
#define ADC_CFGR1_EXTSEL		(7 << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x)		((x) << ADC_CFGR1_EXTSEL_SHIFT)

#define ADC_CFGR1_ALIGN			(1 << 5)

#define ADC_CFGR1_RES_SHIFT		3
#define ADC_CFGR1_RES			(3 << ADC_CFGR1_RES_SHIFT)
#define ADC_CFGR1_RES_12_BIT		(0 << ADC_CFGR1_RES_SHIFT)
#define ADC_CFGR1_RES_10_BIT		(1 << ADC_CFGR1_RES_SHIFT)
#define ADC_CFGR1_RES_8_BIT		(2 << ADC_CFGR1_RES_SHIFT)
#define ADC_CFGR1_RES_6_BIT		(3 << ADC_CFGR1_RES_SHIFT)

#define ADC_CFGR1_SCANDIR		(1 << 2)
#define ADC_CFGR1_DMACFG		(1 << 1)
#define ADC_CFGR1_DMAEN			(1 << 0)

/* ADC_CFGR2 Values ---------------------------------------------------------*/

#define ADC_CFGR2_CKMODE_SHIFT		30
#define ADC_CFGR2_CKMODE		(3 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_CK_ADC		(0 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK_DIV2	(1 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK_DIV4	(2 << ADC_CFGR2_CKMODE_SHIFT)

/* ADC_SMPR Values ----------------------------------------------------------*/

#define ADC_SMPR_SMP_SHIFT		0
#define ADC_SMPR_SMP			(7 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_001DOT5		(0 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_007DOT5		(1 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_013DOT5		(2 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_028DOT5		(3 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_041DOT5		(4 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_055DOT5		(5 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_071DOT5		(6 << ADC_SMPR_SMP_SHIFT)
#define ADC_SMPR_SMP_239DOT5		(7 << ADC_SMPR_SMP_SHIFT)

/* ADC_TR Values ------------------------------------------------------------*/

#define ADC_TR_LT_SHIFT			0
#define ADC_TR_LT			(0xFFF << ADC_TR_LT_SHIFT)
#define ADC_TR_LT_VAL(x)		((x) << ADC_TR_LT_SHIFT)

#define ADC_TR_HT_SHIFT			16
#define ADC_TR_HT			(0xFFF << ADC_TR_HT_SHIFT)
#define ADC_TR_HT_VAL(x)		((x) << ADC_TR_HT_SHIFT)

/* ADC_CHSELR Values --------------------------------------------------------*/

#define ADC_CHSELR_CHSEL(x)		(1 << (x))

/* ADC_DR Values ------------------------------------------------------------*/

#define ADC_DR_DATA			0xFFFF

/* ADC_CCR Values -----------------------------------------------------------*/

#define ADC_CCR_VBATEN			(1 << 24)
#define ADC_CCR_TSEN			(1 << 23)
#define ADC_CCR_VREFEN			(1 << 22)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/


BEGIN_DECLS

END_DECLS

#endif
