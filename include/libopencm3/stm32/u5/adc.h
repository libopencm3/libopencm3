/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32U5xx Analog to Digital
 * Converters</b>
 *
 * @ingroup STM32U5xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2025
 * Rachel Mant <git@dragonmux.network>
 *
 * @date 31 October 2025
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

/** @defgroup adc_reg_base ADC register base addresses
 * @ingroup adc_defines
 *
 *@{*/
#define ADC1 ADC1_BASE
#define ADC2 ADC2_BASE
#define ADC4 ADC4_BASE
/**@}*/

/** ADC Channel Preselection Register */
#define ADC_PCSEL(adc) MMIO32((adc) + 0x1cU)
/** ADC Channel Selection Register */
#define ADC_CHSELR(adc) MMIO32((adc) + 0x28U)
/** ADC Power Register */
#define ADC_PWRR(adc) MMIO32((adc) + 0x44U)
/** ADC <> Register */
#define ADC_GCOMPR(adc) MMIO32((adc) + 0x70U)
/** ADC <> Register */
#define ADC_LTR1(adc) MMIO32((adc) + 0xa8U)
/** ADC <> Register */
#define ADC_HTR1(adc) MMIO32((adc) + 0xacU)
/** ADC <> Register */
#define ADC_LTR2(adc) MMIO32((adc) + 0xb0U)
/** ADC <> Register */
#define ADC_HTR2(adc) MMIO32((adc) + 0xb4U)
/** ADC <> Register */
#define ADC_LTR3(adc) MMIO32((adc) + 0xb8U)
/** ADC <> Register */
#define ADC_HTR3(adc) MMIO32((adc) + 0xbcU)
/** ADC Option Register */
#define ADC_OR(adc) MMIO32((adc) + 0xd0U)

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_VREF   0U
#define ADC_CHANNEL_VCORE  12U
#define ADC_CHANNEL_VSENSE 13U
#define ADC_CHANNEL_TEMP   ADC_CHANNEL_VSENSE
#define ADC_CHANNEL_VBAT   14U
/**@}*/

/* ADC_ISR Values -----------------------------------------------------------*/

/** LDORDY: ADC voltage regulator ready */
#define ADC_ISR_LDORDY (1U << 12U)

/* ADC_CR Values ------------------------------------------------------------*/

/** DEEPPWD: Deep-power-down enable */
#define ADC_CR_DEEPPWD (1U << 29U)
/** ADVREGEN: Voltage regulator enable bit */
#define ADC_CR_ADVREGEN (1U << 28U)
/** ADCALLIN: Linearity calibration */
#define ADC_CR_ADCALLIN (1U << 16U)

/* ADC_CFGR1 Values ---------------------------------------------------------*/

/** SCANDIR: Scan sequence direction */
#define ADC_CFGR1_SCANDIR (1U << 4U)

/** ALIGN: Data alignment */
#define ADC_CFGR1_ALIGN (1U << 5U)

/** EXTSEL[2:0]: External trigger selection for regular group */
#define ADC_CFGR1_EXTSEL_SHIFT  6U
#define ADC_CFGR1_EXTSEL_MASK   (0x7U << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x) ((x) << ADC_CFGR1_EXTSEL_SHIFT)

/** CHSELRMOD: Mode selection fo the ADC_CHSELR register */
#define ADC_CFGR1_CHSELRMOD (1U << 21U)

/* ADC_PWRR Values ----------------------------------------------------------*/

/** AUTOFF: Auto-off mode bit */
#define ADC_PWRR_AUTOFF (1U << 0U)

/** DPD: Deep-power-down mode bit */
#define ADC_PWRR_DPD (1U << 1U)

/** VREFPROT: Vref+ protection bit */
#define ADC_PWRR_VREFPROT (1U << 2U)

/** VREFSECSMP: Vref+ second sample bit */
#define ADC_PWRR_VREFSECSMP (1U << 3U)

/* ADC_OR Values ----------------------------------------------------------*/

/** CHN21SEL: Channel 21 selection bit */
#define ADC_OR_CHN21SEL (1U << 0U)

/****************************************************************************/
/* ADC12_SMPRx ADC Sample Time Selection for Channels */
/** @defgroup adc12_sample ADC Sample Time Selection values
@ingroup adc_defines

@{*/
#define ADC12_SMPR_SMP_5CYC   0x0U
#define ADC12_SMPR_SMP_6CYC   0x1U
#define ADC12_SMPR_SMP_12CYC  0x2U
#define ADC12_SMPR_SMP_20CYC  0x3U
#define ADC12_SMPR_SMP_36CYC  0x4U
#define ADC12_SMPR_SMP_68CYC  0x5U
#define ADC12_SMPR_SMP_391CYC 0x6U
#define ADC12_SMPR_SMP_814CYC 0x7U
/**@}*/

/****************************************************************************/
/* ADC4_SMPRx ADC Sample Time Selection for Channels */
/** @defgroup adc4_sample ADC Sample Time Selection values
@ingroup adc_defines

@{*/
#define ADC4_SMPR_SMP_1DOT5CYC   0x0U
#define ADC4_SMPR_SMP_3DOT5CYC   0x1U
#define ADC4_SMPR_SMP_7DOT5CYC   0x2U
#define ADC4_SMPR_SMP_12DOT5CYC  0x3U
#define ADC4_SMPR_SMP_19DOT5CYC  0x4U
#define ADC4_SMPR_SMP_39DOT5CYC  0x5U
#define ADC4_SMPR_SMP_79DOT5CYC  0x6U
#define ADC4_SMPR_SMP_814DOT5CYC 0x7U
/**@}*/

/* ADC12_CCR Values ---------------------------------------------------------*/

#define ADC12_CCR_PRESC_MASK   0xfU
#define ADC12_CCR_PRESC_SHIFT  18U
#define ADC12_CCR_PRESC_DIV1   0x0U
#define ADC12_CCR_PRESC_DIV2   0x1U
#define ADC12_CCR_PRESC_DIV4   0x2U
#define ADC12_CCR_PRESC_DIV6   0x3U
#define ADC12_CCR_PRESC_DIV8   0x4U
#define ADC12_CCR_PRESC_DIV10  0x5U
#define ADC12_CCR_PRESC_DIV12  0x6U
#define ADC12_CCR_PRESC_DIV16  0x7U
#define ADC12_CCR_PRESC_DIV32  0x8U
#define ADC12_CCR_PRESC_DIV64  0x9U
#define ADC12_CCR_PRESC_DIV128 0xaU
#define ADC12_CCR_PRESC_DIV256 0xbU

BEGIN_DECLS

void adc_disable_external_trigger_regular(uintptr_t adc);
void adc_clear_eoc(uintptr_t adc);
void adc_clear_eos(uintptr_t adc);
void adc_set_common_prescaler(uint8_t prescaling);
void adc_ungate_power(uintptr_t adc);
void adc_calibrate_linearity(uintptr_t adc);
void adc_channel_preselect(uintptr_t adc, uint8_t channel);

END_DECLS

#endif
