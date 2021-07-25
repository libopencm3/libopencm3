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

#include <libopencm3/stm32/common/adc_common_v2.h>
#include <libopencm3/stm32/common/adc_common_v2_single.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/** @defgroup adc_reg_base ADC register base addresses
 * @ingroup adc_defines
 *
 *@{*/
#define ADC				ADC_BASE
#define ADC1				ADC_BASE/* for API compatibility */
/**@}*/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define ADC1_ISR			ADC_ISR(ADC)
#define ADC1_IER			ADC_IER(ADC)
#define ADC1_CR				ADC_CR(ADC)
#define ADC1_CFGR1			ADC_CFGR1(ADC)
#define ADC1_CFGR2			ADC_CFGR2(ADC)
#define ADC1_SMPR1			ADC_SMPR1(ADC)
#define ADC_SMPR(adc)			ADC_SMPR1(adc)  /* Compatibility */
#define ADC1_SMPR			ADC_SMPR1(ADC) /* Compatibility */
#define ADC1_TR1			ADC_TR1(ADC)
#define ADC_TR(adc)			ADC_TR1(adc) /* Compatibility */
#define ADC1_TR				ADC1_TR(ADC) /* Compatibility */
#define ADC1_CHSELR			ADC_CHSELR(ADC)
#define ADC1_DR				ADC_DR(ADC)
#define ADC1_CCR			ADC_CCR(ADC)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

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


/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/** @defgroup adc_api_res ADC resolutions
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_RESOLUTION_12BIT		ADC_CFGR1_RES_12_BIT
#define ADC_RESOLUTION_10BIT		ADC_CFGR1_RES_10_BIT
#define ADC_RESOLUTION_8BIT		ADC_CFGR1_RES_8_BIT
#define ADC_RESOLUTION_6BIT		ADC_CFGR1_RES_6_BIT
/**@}*/

/** @defgroup adc_api_smptime ADC sampling time
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_SMPTIME_001DOT5		ADC_SMPR_SMP_001DOT5
#define ADC_SMPTIME_007DOT5		ADC_SMPR_SMP_007DOT5
#define ADC_SMPTIME_013DOT5		ADC_SMPR_SMP_013DOT5
#define ADC_SMPTIME_028DOT5		ADC_SMPR_SMP_028DOT5
#define ADC_SMPTIME_041DOT5		ADC_SMPR_SMP_041DOT5
#define ADC_SMPTIME_055DOT5		ADC_SMPR_SMP_055DOT5
#define ADC_SMPTIME_071DOT5		ADC_SMPR_SMP_071DOT5
#define ADC_SMPTIME_239DOT5		ADC_SMPR_SMP_239DOT5
/**@}*/

/** @defgroup adc_api_clksource ADC clock source
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CLKSOURCE_ADC		ADC_CFGR2_CKMODE_CK_ADC
#define ADC_CLKSOURCE_PCLK_DIV2		ADC_CFGR2_CKMODE_PCLK_DIV2
#define ADC_CLKSOURCE_PCLK_DIV4		ADC_CFGR2_CKMODE_PCLK_DIV4
/**@}*/

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_TEMP	16
#define ADC_CHANNEL_VREF	17
#define ADC_CHANNEL_VBAT	18
/**@}*/

/** @defgroup adc_api_opmode ADC Operation Modes
 * @ingroup adc_defines
 *
 *@{*/
enum adc_opmode {
	ADC_MODE_SEQUENTIAL,
	ADC_MODE_SCAN,
	ADC_MODE_SCAN_INFINITE,
};
/**@}*/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/


BEGIN_DECLS

/* Operation mode API */
void adc_enable_discontinuous_mode(uint32_t adc);
void adc_disable_discontinuous_mode(uint32_t adc);
void adc_set_operation_mode(uint32_t adc, enum adc_opmode opmode);

/* Trigger API */
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
				uint32_t polarity);
void adc_disable_external_trigger_regular(uint32_t adc);

/* Interrupt configuration */
void adc_enable_watchdog_interrupt(uint32_t adc);
void adc_disable_watchdog_interrupt(uint32_t adc);
bool adc_get_watchdog_flag(uint32_t adc);
void adc_clear_watchdog_flag(uint32_t adc);
void adc_enable_eoc_sequence_interrupt(uint32_t adc);
void adc_disable_eoc_sequence_interrupt(uint32_t adc);
bool adc_get_eoc_sequence_flag(uint32_t adc);
void adc_clear_eoc_sequence_flag(uint32_t adc);

/* Basic configuration */
void adc_set_clk_source(uint32_t adc, uint32_t source);
void adc_enable_vbat_sensor(void);
void adc_disable_vbat_sensor(void);
void adc_calibrate_start(uint32_t adc)
	LIBOPENCM3_DEPRECATED("see adc_calibrate/_async");
void adc_calibrate_wait_finish(uint32_t adc)
	LIBOPENCM3_DEPRECATED("see adc_is_calibrating");

/* Analog Watchdog */
void adc_enable_analog_watchdog_on_all_channels(uint32_t adc);
void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc, uint8_t chan);
void adc_disable_analog_watchdog(uint32_t adc);
void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold);
void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold);

END_DECLS

#endif
