/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L0xx Analog to Digital
 * Converter</b>
 *
 * @ingroup STM32L0xx_defines
 *
 * @version 1.0.0
 *
 * @date 16 Oct 2015
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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
#include <libopencm3/stm32/common/adc_common_v2_single.h>

/** @defgroup adc_reg_base ADC register base addresses
 * @ingroup adc_defines
 *
 *@{*/
#define ADC1				ADC1_BASE
/**@}*/


/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_VLCD	16
#define ADC_CHANNEL_VREF	17
#define ADC_CHANNEL_TEMP	18
/**@}*/

/* Calibration Factors */
#define ADC_CALFACT(adc)	MMIO32((adc) + 0xB4)

/* Register values */
/* ADC_CFGR1 Values ---------------------------------------------------------*/

/** ALIGN: Data alignment */
#define ADC_CFGR1_ALIGN			(1 << 5)

/* EXTSEL[2:0]: External trigger selection for regular group */
#define ADC_CFGR1_EXTSEL_SHIFT		6
#define ADC_CFGR1_EXTSEL		(0x7 << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x)		((x) << ADC_CFGR1_EXTSEL_SHIFT)

/* ADC_CFGR2 Values ---------------------------------------------------------*/

#define ADC_CFGR2_CKMODE_SHIFT		30
#define ADC_CFGR2_CKMODE		(3 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_CK_ADC		(0 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK_DIV2	(1 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK_DIV4	(2 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK		(3 << ADC_CFGR2_CKMODE_SHIFT)

/** @defgroup adc_sample_rg ADC Sample Time Selection for All Channels
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_1DOT5CYC		0x0
#define ADC_SMPR_SMP_3DOT5CYC		0x1
#define ADC_SMPR_SMP_7DOT5CYC		0x2
#define ADC_SMPR_SMP_12DOT5CYC		0x3
#define ADC_SMPR_SMP_19DOT5CYC		0x4
#define ADC_SMPR_SMP_39DOT5CYC		0x5
#define ADC_SMPR_SMP_79DOT5CYC		0x6
#define ADC_SMPR_SMP_160DOT5CYC		0x7
/**@}*/

BEGIN_DECLS


END_DECLS


#endif
