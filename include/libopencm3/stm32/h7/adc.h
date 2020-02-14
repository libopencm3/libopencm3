/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32H7xx Analog to Digital
 * converter</b>
 *
 * @ingroup STM32H7xx_defines
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 allocortech inc
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
/**@}*/

/* --- ADC registers -------------------------------------------------------- */
/** @ingroup adc_registers
 * @{ */

/** ADC channel preselection register */
#define ADC_PCSEL(adc)		MMIO32((adc) + 0x1C)
/** ADC analog watchdog 1 lower threshold register */
#define ADC_LTR1(adc)		MMIO32((adc) + 0x20)
/** ADC analog watchdog 1 higher threshold register */
#define ADC_HTR1(adc)		MMIO32((adc) + 0x24)
/** ADC analog watchdog 2 lower threshold register */
#define ADC_LTR2(adc)		MMIO32((adc) + 0xB0)
/** ADC analog watchdog 2 higher threshold register */
#define ADC_HTR2(adc)		MMIO32((adc) + 0xB4)
/** ADC analog watchdog 3 lower threshold register */
#define ADC_LTR3(adc)		MMIO32((adc) + 0xB8)
/** ADC analog watchdog 3 higher threshold register */
#define ADC_HTR3(adc)		MMIO32((adc) + 0xBC)

/* Compatibility with original ref man names */
#define ADC_CFGR(adc)		ADC_CFGR1(adc)

#define ADC12_CSR			ADC_CSR(ADC1)
#define ADC12_CCR			ADC_CCR(ADC1)
#define ADC12_CDR			ADC_CDR(ADC1)
#define ADC3_CSR			ADC_CSR(ADC3)
#define ADC3_CCR			ADC_CCR(ADC3)
#define ADC3_CDR			ADC_CDR(ADC3)

/* --- ADC_CR values not in common_v2.h or common_v2_multi.h ---------------- */
/** @ingroup adc_cr
 * @{ */

/** DEEPPWD: Deep power down enable */
#define ADC_CR_DEEPPWD			(0x1 << 29)
/** ADVREGEN: ADC voltage regulator enable */
#define ADC_CR_ADVREGEN			(0x1 << 28)
/* LINCALRDYx Set when the linear calibration word can be read from CALFACT2 */
#define ADC_CR_LINCALRDYW6		(0x1 << 27)
#define ADC_CR_LINCALRDYW5		(0x1 << 26)
#define ADC_CR_LINCALRDYW4		(0x1 << 25)
#define ADC_CR_LINCALRDYW3		(0x1 << 24)
#define ADC_CR_LINCALRDYW2		(0x1 << 23)
#define ADC_CR_LINCALRDYW1		(0x1 << 22)
/** ADCCALLIN: Enable calibration with linearity correction */
#define ADC_CR_ADCALLIN			(0x1 << 16)

/* BOOST: Boost mode control to enable faster sampling, Rev Y devices */
#define ADC_CR_BOOST_Y_GTE_20_MHZ	(0x1 << 8)

/* BOOST: Boost mode control to enable faster sampling, Rev V devices */
#define ADC_CR_BOOST_V_0_6250_KHZ	(0x0 << 8)
#define ADC_CR_BOOST_V_6250_12500_KHZ	(0x1 << 8)
#define ADC_CR_BOOST_V_12500_25000_KHZ	(0x2 << 8)
#define ADC_CR_BOOST_V_25000_50000_KHZ	(0x3 << 8)

#define ADC_CR_BOOST_V_MASK		(0x3 << 8)

/** JADSTP: ADC stop of injected conversion command */
#define ADC_CR_JADSTP			(1 << 5)
/** JADSTART: ADC start of injected conversion */
#define ADC_CR_JADSTART			(1 << 3)

/* --- ADC_CFGR values not in common_v2.h or common_v2_multi.h -------------- */
/** @ingroup adc_cfgr1
 * @{ */

/** JQDIS: Injected queue disable */
#define ADC_CFGR1_JQDIS			(1 << 31)

/** EXTSEL[4:0]: External trigger selection for regular group */
#define ADC_CFGR1_EXTSEL_SHIFT		5
#define ADC_CFGR1_EXTSEL_MASK		(0x1f << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x)		((x) << ADC_CFGR1_EXTSEL_SHIFT)

/** @defgroup adc_cfgr1_res RES: Data resolution
@{*/
#define ADC_CFGR1_RES_MASK		(0x7 << 2)
#define ADC_CFGR1_RES_16_BIT		(0x0 << 2)
#define ADC_CFGR1_RES_14_BIT		(0x1 << 2)
#define ADC_CFGR1_RES_12_BIT		(0x2 << 2)
#define ADC_CFGR1_RES_10_BIT		(0x3 << 2)
#define ADC_CFGR1_Y_RES_8_BIT		(0x4 << 2)
#define ADC_CFGR1_V_RES_8_BIT		(0x7 << 2)
/**@}*/

/** @defgroup adc_cfgr1_dmngt DMNGT[1:0] Data management configuration
 *@{*/
#define ADC_CFGR1_DMNGT_DMA_NONE	(0x3 << 0)
#define ADC_CFGR1_DMNGT_DMA_ONCE	(0x3 << 0)
#define ADC_CFGR1_DMNGT_DFSDM		(0x3 << 0)
#define ADC_CFGR1_DMNGT_DMA_CIRC	(0x3 << 0)
#define ADC_CFGR1_DMNGT_MASK		(0x3 << 0)
/**@}*/

/**@}*/

/* --- ADC_CFGR2 Values ----------------------------------------------------- */
/** @ingroup adc_cfgr2
 * @{ */

/** LSHIFT[3:0] Left shift factor */
#define ADC_CFGR2_LSHIFT_VAL(x)		((x) << 28)
#define ADC_CFGR2_LSHIFT_MASK		(0xF << 28)
/** OSVR[9:0] Oversampling ratio */
#define ADC_CFGR2_OSVR_VAL(x)		((x) << 16)
#define ADC_CFGR2_OSVR_MASK		(0x3FF << 16)
/** RSHIFT4: Right-shift data after offset 4 correction */
#define ADC_CFGR2_RSHIFT4		(1 << 14)
/** RSHIFT4: Right-shift data after offset 3 correction */
#define ADC_CFGR2_RSHIFT3		(1 << 13)
/** RSHIFT4: Right-shift data after offset 2 correction */
#define ADC_CFGR2_RSHIFT2		(1 << 12)
/** RSHIFT4: Right-shift data after offset 1 correction */
#define ADC_CFGR2_RSHIFT1		(1 << 11)
/** ROVSM: Regular oversampling mode */
#define ADC_CFGR2_ROVSM			(1 << 10)
/** TROSM: triggered regular oversampling mode */
#define ADC_CFGR2_TROSM			(1 << 9)
/** OVSS[3:0]: Oversampling right shift */
#define ADC_CFGR2_TROSM_VAL(x)		((x) << 5)
#define ADC_CFGR2_TROSM_MASK		(0xF << 5)
/** JOVSE: Injected oversampling enable */
#define ADC_CFGR2_JOVSE			(1 << 1)
/** ROVSE: Regular oversampling enable */
#define ADC_CFGR2_ROVSE			(1 << 0)

/**@}*/

/* --- ADC_SMPRx Values ----------------------------------------------------- */
/** @defgroup adc_sample ADC Sample Time Selection values
 *  @ingroup adc_defines
 *  @{ */
#define ADC_SMPR_SMP_1DOT5CYC		0x0
#define ADC_SMPR_SMP_2DOT5CYC		0x1
#define ADC_SMPR_SMP_8DOT5CYC		0x2
#define ADC_SMPR_SMP_16DOT5CYC		0x3
#define ADC_SMPR_SMP_32DOT5CYC		0x4
#define ADC_SMPR_SMP_64DOT5CYC		0x5
#define ADC_SMPR_SMP_387DOT5CYC		0x6
#define ADC_SMPR_SMP_810DOT5CYC		0x7
/**@}*/

/* --- ADC_JSQR Values ------------------------------------------------------ */
/** @defgroup adc_jsqr ADC injected sequence register values
 *  @ingroup adc_defines
 *  @{ */

/* JSQx[4:0] x'th conversion in the injected sequence */
#define ADC_JSQR_JSQ4_SHIFT		27
#define ADC_JSQR_JSQ3_SHIFT		21
#define ADC_JSQR_JSQ2_SHIFT		15
#define ADC_JSQR_JSQ1_SHIFT		9
#define ADC_JSQR_JSQX_MASK		0x1F

#define ADC_JSQR_JSQ_VAL(n, val)	((val) << (((n) - 1) * 6 + 9))

/* JEXTEN[1:0]: External Trigger Enable and Polarity Selection for injected
 * channels */
#define ADC_JSQR_JEXTEN_DISABLED	(0x0 << 6)
#define ADC_JSQR_JEXTEN_RISING_EDGE	(0x1 << 6)
#define ADC_JSQR_JEXTEN_FALLING_EDGE	(0x2 << 6)
#define ADC_JSQR_JEXTEN_BOTH_EDGES	(0x3 << 6)
#define ADC_JSQR_JEXTEN_MASK		(0x3 << 7)

/** JEXTSEL[4:0]: External trigger selection for injected group */
#define ADC_JSQR_JEXTSEL_VAL(x)		((x) << 2)
#define ADC_JSQR_JEXTSEL_MASK		(0x1F << 2)

/** JL[1:0]: Injected channel sequence length */
#define ADC_JSQR_JL_VAL(val)		(((val) - 1) << ADC_JSQR_JL_SHIFT)
#define ADC_JSQR_JL_MASK		0x3

/**@}*/

/* --- ADC_OFRy Values ------------------------------------------------------ */
/** Signed saturation enable */
#define ADC_OFR_SSATE			(1 << 31)

/** Channel selection for data offset */
#define ADC_OFR_OFFSET_CH_VAL(x)	((x) << 26)
#define ADC_OFR_OFFSET_CH_MASK		(0x1F << 26)

/** Data offset */
#define ADC_OFR_OFFSET_VAL(x)		(x)
#define ADC_OFR_OFFSET_MASK		0x3FFFFFF

/* --- ADC_CSR values  ------------------------------------------------------ */
/** Bit 26 JQOVF_SLV: Injected Context Queue Overflow flag of the slave ADC */
#define ADC_CSR_JQOVF_SLV		(1 << 26)
/** Bit 25 AWD3_SLV: Analog watchdog 3 flag of the slave ADC */
#define ADC_CSR_AWD3_SLV		(1 << 25)
/** Bit 24 AWD2_SLV: Analog watchdog 2 flag of the slave ADC */
#define ADC_CSR_AWD2_SLV		(1 << 24)
/** Bit 23 AWD1_SLV: Analog watchdog 1 flag of the slave ADC */
#define ADC_CSR_AWD1_SLV		(1 << 23)
/** Bit 22 JEOS_SLV: End of injected sequence flag of the slave ADC */
#define ADC_CSR_JEOS_SLV		(1 << 22)
/** Bit 21 JEOC_SLV: End of injected conversion flag of the slave ADC */
#define ADC_CSR_JEOC_SLV		(1 << 21)
/** Bit 20 OVR_SLV: Overrun flag of the slave ADC */
#define ADC_CSR_OVR_SLV			(1 << 20)
/** Bit 19 EOS_SLV: End of regular sequence flag of the slave ADC */
#define ADC_CSR_EOS_SLV			(1 << 19)
/** Bit 18 EOC_SLV: End of regular conversion of the slave ADC */
#define ADC_CSR_EOC_SLV			(1 << 18)
/** Bit 17 EOSMP_SLV: End of Sampling phase flag of the slave ADC */
#define ADC_CSR_EOSMP_SLV		(1 << 17)
/** Bit 16 ADRDY_SLV: Slave ADC ready */
#define ADC_CSR_ADRDY_SLV		(1 << 16)
/** Bit 10 JQOVF_MST: Injected Context Queue Overflow flag of the master ADC */
#define ADC_CSR_JQOVF_MST		(1 << 10)
/** Bit 9 AWD3_MST: Analog watchdog 3 flag of the master ADC */
#define ADC_CSR_AWD3_MST		(1 << 9)
/** Bit 8 AWD2_MST: Analog watchdog 2 flag of the master ADC */
#define ADC_CSR_AWD2_MST		(1 << 8)
/** Bit 7 AWD1_MST: Analog watchdog 1 flag of the master ADC */
#define ADC_CSR_AWD1_MST		(1 << 7)
/** Bit 6 JEOS_MST: End of injected sequence flag of the master ADC */
#define ADC_CSR_JEOS_MST		(1 << 6)
/** Bit 5 JEOC_MST: End of injected conversion flag of the master ADC */
#define ADC_CSR_JEOC_MST		(1 << 5)
/** Bit 4 OVR_MST: Overrun flag of the master ADC */
#define ADC_CSR_OVR_MST			(1 << 4)
/** Bit 3 EOS_MST: End of regular sequence flag of the master ADC */
#define ADC_CSR_EOS_MST			(1 << 3)
/** Bit 2 EOC_MST: End of regular conversion of the master ADC */
#define ADC_CSR_EOC_MST			(1 << 2)
/** Bit 1 EOSMP_MST: End of Sampling phase flag of the master ADC */
#define ADC_CSR_EOSMP_MST		(1 << 1)
/** Bit 0 ADRDY_MST: Master ADC ready */
#define ADC_CSR_ADRDY_MST		(1 << 0)

/* --- ADC_CCR values ------------------------------------------------------- */
/* ADC_CCR_VBATEN, ADC_CCR_TSEN, and ADC_CCR_VREFEN are all defined in
 * adc_common_v2.h */
#define ADC_CCR_VSENSEEN		ADC_CCR_TSEN

/* ADC_CCR_PRESC[3:0]: ADC Prescaler */
enum adc_ccr_presc {
	ADC_CCR_PRESC_NONE =		(0x0 << 18),
	ADC_CCR_PRESC_2 =		(0x1 << 18),
	ADC_CCR_PRESC_4 =		(0x2 << 18),
	ADC_CCR_PRESC_6 =		(0x3 << 18),
	ADC_CCR_PRESC_8 =		(0x4 << 18),
	ADC_CCR_PRESC_10 =		(0x5 << 18),
	ADC_CCR_PRESC_12 =		(0x6 << 18),
	ADC_CCR_PRESC_16 =		(0x7 << 18),
	ADC_CCR_PRESC_32 =		(0x8 << 18),
	ADC_CCR_PRESC_64 =		(0x9 << 18),
	ADC_CCR_PRESC_128 =		(0xA << 18),
	ADC_CCR_PRESC_256 =		(0xB << 18),
};
#define ADC_CCR_PRESC_MASK		(0xF << 18)

/* CKMODE[1:0]: ADC clock mode */
enum adc_ccr_ckmode {
	ADC_CCR_CKMODE_CKX =		(0x0 << 16),
	ADC_CCR_CKMODE_DIV1 =		(0x1 << 16),
	ADC_CCR_CKMODE_DIV2 =		(0x2 << 16),
	ADC_CCR_CKMODE_DIV4 =		(0x3 << 16),
};
#define ADC_CCR_CKMODE_MASK		(0x3 << 16)

/* DAMDF[1:0]: Dual ADC Mode Data Format */
/* On other processors this is also known as ADC_CCR_MDMA */
#define ADC_CCR_DAMDF_DISABLE		(0x0 << 14)
#define ADC_CCR_DAMDF_32_10_BIT		(0x2 << 14)
#define ADC_CCR_DAMDF_8_BIT		(0x3 << 14)

#define ADC_CCR_DAMDF_MASK		(0x3 << 14)

/* DELAY[3:0]: Delay between 2 sampling phases */
#define ADC_CCR_DELAY_SHIFT		8
#define ADC_CCR_DELAY_MASK		0xF

/* DUAL[4:0]: Dual ADC mode selection */
#define ADC_CCR_DUAL_SHIFT		0
#define ADC_CCR_DUAL_MASK		0x1F

/* --- ADC_CDR values ------------------------------------------------------- */
/* Bits 31:16 RDATA_SLV[15:0]: Regular data of the slave ADC */
/* Bits 15:0 RDATA_MST[15:0]: Regular data of the master ADC. */

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_VBAT	17
#define ADC_CHANNEL_TEMP	18
#define ADC_CHANNEL_VREF	19
/**@}*/

BEGIN_DECLS

uint32_t adc_set_clock_param(uint32_t adc, enum adc_ccr_ckmode mode,
			     enum adc_ccr_presc prescale);
void adc_set_boost(uint32_t adc, uint32_t adc_clock_freq);

void adc_set_pcsel(uint32_t adc, uint8_t length, const uint8_t channel[]);

/* There are many features of the H7 ADC that have not been tested, but that
 * probably could have implementations lifted from the F3 ADC code. That problem
 * has been deferred until someone needs and can test them.
 */

END_DECLS

/**@}*/

#endif
