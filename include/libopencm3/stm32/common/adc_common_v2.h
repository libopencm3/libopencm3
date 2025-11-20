/** @addtogroup adc_defines

@author @htmlonly &copy; @endhtmlonly 2015 Karl Palsson <karlp@tweak.net.au>

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

/**@{*/

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA ADC.H
The order of header inclusion is important. adc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_ADC_H
/** @endcond */
#ifndef LIBOPENCM3_ADC_COMMON_V2_H
#define LIBOPENCM3_ADC_COMMON_V2_H

/** @defgroup adc_registers ADC registers
@{*/
/* ----- ADC registers  -----------------------------------------------------*/
/** ADC interrupt and status register */
#define ADC_ISR(adc)		MMIO32((adc) + 0x00U)
/** Interrupt Enable Register */
#define ADC_IER(adc)		MMIO32((adc) + 0x04U)
/** Control Register */
#define ADC_CR(adc)		MMIO32((adc) + 0x08U)
/** Configuration Register 1 */
#define ADC_CFGR1(adc)			MMIO32((adc) + 0x0cU)
/** Configuration Register 2 */
#define ADC_CFGR2(adc)			MMIO32((adc) + 0x10U)
/** Sample Time Register 1 */
#define ADC_SMPR1(adc)			MMIO32((adc) + 0x14U)
/** Watchdog Threshold Register 1*/
#define ADC_TR1(adc)			MMIO32((adc) + 0x20U)
/** Regular Data Register */
#define ADC_DR(adc)			MMIO32((adc) + 0x40U)
/* CALFACT for all but f0 :(*/

/** Common Configuration register */
#define ADC_CCR(adc)		MMIO32((adc) + 0x300U + 0x8U)
/**@}*/

/* --- Register values -------------------------------------------------------*/

/* ADC_ISR Values -----------------------------------------------------------*/
/** @defgroup adc_isr ISR ADC interrupt status register
@{*/

/** AWD1: Analog watchdog 1 flag */
#define ADC_ISR_AWD1		(1U << 7U)
/** OVR: Overrun flag */
#define ADC_ISR_OVR			(1U << 4U)
/** EOS: End of sequence conversions flag */
#define ADC_ISR_EOS			(1U << 3U)   // FIXME - move to single/multi here.
#define ADC_ISR_EOSEQ			ADC_ISR_EOS /* TODO - keep only one? */
/** EOS: End of regular conversion flag */
#define ADC_ISR_EOC			(1U << 2U)
/** EOSMP: End of sampling flag */
#define ADC_ISR_EOSMP			(1U << 1U)
/** ADRDY: Ready flag */
#define ADC_ISR_ADRDY			(1U << 0U)

/**@}*/

/* ADC_IER Values -----------------------------------------------------------*/
/** @defgroup adc_ier IER ADC interrupt enable register
@{*/

/** AWD1IE: Analog watchdog 1 interrupt enable */
#define ADC_IER_AWD1IE		(1U << 7U)
/** OVRIE: Overrun interrupt enable */
#define ADC_IER_OVRIE		(1U << 4U)
/** EOSIE: End of regular sequence of conversions interrupt enable */
#define ADC_IER_EOSIE		(1U << 3U)
#define ADC_IER_EOSEQIE		ADC_IER_EOSIE /* TODO - keep only one? */
/** EOCIE: End of regular conversion interrupt enable */
#define ADC_IER_EOCIE		(1U << 2U)
/** EOSMPIE: End of sampling flag interrupt enable for regular conversions */
#define ADC_IER_EOSMPIE		(1U << 1U)
/** ADRDYIE: ADC ready interrupt enable */
#define ADC_IER_ADRDYIE		(1U << 0U)

/**@}*/

/* ADC_CR Values -----------------------------------------------------------*/
/** @defgroup adc_cr CR ADC control register
@{*/

/** ADCAL: ADC calibration */
#define ADC_CR_ADCAL		(1U << 31U)
/** ADSTP: ADC stop of regular conversion command */
#define ADC_CR_ADSTP		(1U << 4U)
/** ADSTART: ADC start of regular conversion */
#define ADC_CR_ADSTART		(1U << 2U)
/** ADDIS: ADC disable command */
#define ADC_CR_ADDIS		(1U << 1U)
/** ADEN: ADC enable control */
#define ADC_CR_ADEN		(1U << 0U)

/**@}*/

/* ADC_CFGR1 Values -----------------------------------------------------------*/
/** @defgroup adc_cfgr1 CFGR1 ADC configuration register 1
@{*/

#define ADC_CFGR1_AWD1CH_SHIFT		26U
#define ADC_CFGR1_AWD1CH			(0x1fU << ADC_CFGR1_AWD1CH_SHIFT)
/** AWD1CH: Analog watchdog 1 channel selection */
#define ADC_CFGR1_AWD1CH_VAL(x)		((x) << ADC_CFGR1_AWD1CH_SHIFT)

/** AWD1EN: Analog watchdog 1 enable on regular channels */
#define ADC_CFGR1_AWD1EN		(1U << 23U)
/** AWD1SGL: Enable the watchdog 1 on a single channel or on all channels */
#define ADC_CFGR1_AWD1SGL		(1U << 22U)
/** DISCEN: Discontinuous mode for regular channels */
#define ADC_CFGR1_DISCEN		(1U << 16U)
/** AUTDLY: Delayed conversion mode */
#define ADC_CFGR1_AUTDLY		(1U << 14U)
/** CONT: Single / continuous conversion mode for regular conversions */
#define ADC_CFGR1_CONT		(1U << 13U)
/** OVRMOD: Overrun Mode */
#define ADC_CFGR1_OVRMOD		(1U << 12U)

#define ADC_CFGR1_EXTEN_MASK		(0x3U << 10U)
/** @defgroup adc_cfgr1_exten EXTEN: External trigger enable and polarity selection for regular channels
@{*/
#define ADC_CFGR1_EXTEN_DISABLED		(0x0U << 10)
#define ADC_CFGR1_EXTEN_RISING_EDGE	(0x1U << 10)
#define ADC_CFGR1_EXTEN_FALLING_EDGE	(0x2U << 10)
#define ADC_CFGR1_EXTEN_BOTH_EDGES	(0x3U << 10)
/**@}*/

#define ADC_CFGR1_RES_MASK	(0x3U << 3U)
/** @defgroup adc_cfgr1_res RES: Data resolution
@{*/
#define ADC_CFGR1_RES_12_BIT	(0x0U << 3U)
#define ADC_CFGR1_RES_10_BIT	(0x1U << 3U)
#define ADC_CFGR1_RES_8_BIT	(0x2U << 3U)
#define ADC_CFGR1_RES_6_BIT	(0x3U << 3U)
/**@}*/

/** DMACFG: Direct memory access configuration */
#define ADC_CFGR1_DMACFG		(1U << 1U)

/** DMAEN: Direct memory access enable */
#define ADC_CFGR1_DMAEN		(1U << 0U)

/**@}*/

/* ADC_SMPR Values -----------------------------------------------------------*/
/** @defgroup adc_smpr SMPR ADC sample time register
@{*/

/**@}*/

/* ADC_CFGR2 Values -----------------------------------------------------------*/
/** @defgroup adc_cfgr2 CFGR2 ADC configuration register 2
@{*/

/**@}*/

/* ADC_TR1 Values ------------------------------------------------------------*/
/** @defgroup adc_tr1 TR1 ADC watchdog threshold register 1
@{*/

#define ADC_TR1_LT_SHIFT		0U
#define ADC_TR1_LT_MASK			0xfffU
#define ADC_TR1_LT			(ADC_TR1_LT_MASK << ADC_TR1_LT_SHIFT)
/** TR1_LT: analog watchdog 1 threshold low */
#define ADC_TR1_LT_VAL(x)		(((x) & ADC_TR1_LT_MASK) << ADC_TR1_LT_SHIFT)

#define ADC_TR1_HT_SHIFT		16U
#define ADC_TR1_HT_MASK			0xfffU
#define ADC_TR1_HT			(ADC_TR1_HT_MASK << ADC_TR1_HT_SHIFT)
/** TR1_HT: analog watchdog 1 threshold high */
#define ADC_TR1_HT_VAL(x)		(((x) & ADC_TR1_HT_MASK) << ADC_TR1_HT_SHIFT)

/**@}*/

/* ADC_CCR Values -----------------------------------------------------------*/
/** @defgroup adc_ccr CCR ADC common configuration register
@{*/

/** VBATEN: Enable VBAT Channel */
#define ADC_CCR_VBATEN			(1U << 24U)

/** TSEN: Enable Temperature Sensor */
#define ADC_CCR_TSEN			(1U << 23U)

/** VREFEN: Enable internal Voltage Reference */
#define ADC_CCR_VREFEN			(1U << 22U)

/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void adc_power_on_async(uint32_t adc);
void adc_power_on(uint32_t adc);
bool adc_is_power_on(uint32_t adc);
void adc_power_off_async(uint32_t adc);
void adc_power_off(uint32_t adc);
bool adc_is_power_off(uint32_t adc);
void adc_calibrate_async(uint32_t adc);
bool adc_is_calibrating(uint32_t adc);
void adc_calibrate(uint32_t adc);
void adc_set_continuous_conversion_mode(uint32_t adc);
void adc_set_single_conversion_mode(uint32_t adc);
void adc_set_regular_sequence(uint32_t adc, uint8_t length, const uint8_t channel[]);
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_enable_vrefint(void);
void adc_disable_vrefint(void);
void adc_set_resolution(uint32_t adc, uint16_t resolution);
void adc_set_left_aligned(uint32_t adc);
void adc_set_right_aligned(uint32_t adc);
void adc_enable_dma(uint32_t adc);
void adc_disable_dma(uint32_t adc);
bool adc_eoc(uint32_t adc);
bool adc_eos(uint32_t adc);
void adc_enable_eoc_interrupt(uint32_t adc);
void adc_disable_eoc_interrupt(uint32_t adc);
void adc_enable_overrun_interrupt(uint32_t adc);
void adc_disable_overrun_interrupt(uint32_t adc);
bool adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);
uint32_t adc_read_regular(uint32_t adc);
void adc_start_conversion_regular(uint32_t adc);
void adc_enable_dma_circular_mode(uint32_t adc);
void adc_disable_dma_circular_mode(uint32_t adc);
void adc_enable_delayed_conversion_mode(uint32_t adc);
void adc_disable_delayed_conversion_mode(uint32_t adc);
END_DECLS

#endif
/** @cond */
#endif
/** @endcond */
/**@}*/
