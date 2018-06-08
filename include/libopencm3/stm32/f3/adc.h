/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F37x Analog to Digital
 * converter</b>
 *
 * @ingroup STM32F3xx_defines
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
 * Copyright (C) 2013 ARCOS-Lab UCR
 * Copyright (C) 2013 Fernando Cortes <fernando.corcam@gmail.com>
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
@ingroup STM32xx_adc_defines
@{*/
#define ADC1		ADC1_BASE
#define ADC2		ADC2_BASE
#define ADC3		ADC3_BASE
#define ADC4		ADC4_BASE
/**@}*/

/* Master and slave ADCs common registers (ADC12 or ADC34) */


/*----------- ADC registers -------------------------------------- */

#define ADC1_ISR		ADC_ISR(ADC1_BASE)
#define ADC2_ISR		ADC_ISR(ADC2_BASE)
#define ADC3_ISR		ADC_ISR(ADC3_BASE)
#define ADC4_ISR		ADC_ISR(ADC4_BASE)

#define ADC1_IER		ADC_IER(ADC1_BASE)
#define ADC2_IER		ADC_IER(ADC2_BASE)
#define ADC3_IER		ADC_IER(ADC3_BASE)
#define ADC4_IER		ADC_IER(ADC4_BASE)

#define ADC1_CR			ADC_CR(ADC1_BASE)
#define ADC2_CR			ADC_CR(ADC2_BASE)
#define ADC3_CR			ADC_CR(ADC3_BASE)
#define ADC4_CR			ADC_CR(ADC4_BASE)

#define ADC1_CFGR1		ADC_CFGR1(ADC1_BASE)
#define ADC2_CFGR1		ADC_CFGR1(ADC2_BASE)
#define ADC3_CFGR1		ADC_CFGR1(ADC3_BASE)
#define ADC4_CFGR1		ADC_CFGR1(ADC4_BASE)
/* Compatibility with original ref man names */
#define ADC_CFGR(adc)		ADC_CFGR1(adc)
#define ADC1_CFGR		ADC_CFGR1(ADC1_BASE)
#define ADC2_CFGR		ADC_CFGR1(ADC2_BASE)
#define ADC3_CFGR		ADC_CFGR1(ADC3_BASE)
#define ADC4_CFGR		ADC_CFGR1(ADC4_BASE)

#define ADC1_SMPR1		ADC_SMPR1(ADC1_BASE)
#define ADC2_SMPR1		ADC_SMPR1(ADC2_BASE)
#define ADC3_SMPR1		ADC_SMPR1(ADC3_BASE)
#define ADC4_SMPR1		ADC_SMPR1(ADC4_BASE)

#define ADC1_SMPR2		ADC_SMPR2(ADC1_BASE)
#define ADC2_SMPR2		ADC_SMPR2(ADC2_BASE)
#define ADC3_SMPR2		ADC_SMPR2(ADC3_BASE)
#define ADC4_SMPR2		ADC_SMPR2(ADC4_BASE)

#define ADC1_TR1		ADC_TR1(ADC1_BASE)
#define ADC2_TR1		ADC_TR1(ADC2_BASE)
#define ADC3_TR1		ADC_TR1(ADC3_BASE)
#define ADC4_TR1		ADC_TR1(ADC4_BASE)

#define ADC1_TR2		ADC_TR2(ADC1_BASE)
#define ADC2_TR2		ADC_TR2(ADC2_BASE)
#define ADC3_TR2		ADC_TR2(ADC3_BASE)
#define ADC4_TR2		ADC_TR2(ADC4_BASE)

#define ADC1_TR3		ADC_TR3(ADC1_BASE)
#define ADC2_TR3		ADC_TR3(ADC2_BASE)
#define ADC3_TR3		ADC_TR3(ADC3_BASE)
#define ADC4_TR3		ADC_TR3(ADC4_BASE)

#define ADC1_SQR1		ADC_SQR1(ADC1_BASE)
#define ADC2_SQR1		ADC_SQR1(ADC2_BASE)
#define ADC3_SQR1		ADC_SQR1(ADC3_BASE)
#define ADC4_SQR1		ADC_SQR1(ADC4_BASE)

#define ADC1_SQR2		ADC_SQR2(ADC1_BASE)
#define ADC2_SQR2		ADC_SQR2(ADC2_BASE)
#define ADC3_SQR2		ADC_SQR2(ADC3_BASE)
#define ADC4_SQR2		ADC_SQR2(ADC4_BASE)

#define ADC1_SQR3		ADC_SQR3(ADC1_BASE)
#define ADC2_SQR3		ADC_SQR3(ADC2_BASE)
#define ADC3_SQR3		ADC_SQR3(ADC3_BASE)
#define ADC4_SQR3		ADC_SQR3(ADC4_BASE)

#define ADC1_SQR4		ADC_SQR4(ADC1_BASE)
#define ADC2_SQR4		ADC_SQR4(ADC2_BASE)
#define ADC3_SQR4		ADC_SQR4(ADC3_BASE)
#define ADC4_SQR4		ADC_SQR4(ADC4_BASE)

#define ADC1_DR			ADC_DR(ADC1_BASE)
#define ADC2_DR			ADC_DR(ADC2_BASE)
#define ADC3_DR			ADC_DR(ADC3_BASE)
#define ADC4_DR			ADC_DR(ADC4_BASE)

#define ADC1_JSQR		ADC_JSQR(ADC1_BASE)
#define ADC2_JSQR		ADC_JSQR(ADC2_BASE)
#define ADC3_JSQR		ADC_JSQR(ADC3_BASE)
#define ADC4_JSQR		ADC_JSQR(ADC4_BASE)

#define ADC1_OFR1		ADC_OFR1(ADC1_BASE)
#define ADC2_OFR1		ADC_OFR1(ADC2_BASE)
#define ADC3_OFR1		ADC_OFR1(ADC3_BASE)
#define ADC4_OFR1		ADC_OFR1(ADC4_BASE)

#define ADC1_OFR2		ADC_OFR2(ADC1_BASE)
#define ADC2_OFR2		ADC_OFR2(ADC2_BASE)
#define ADC3_OFR2		ADC_OFR2(ADC3_BASE)
#define ADC4_OFR2		ADC_OFR2(ADC4_BASE)

#define ADC1_OFR3		ADC_OFR3(ADC1_BASE)
#define ADC2_OFR3		ADC_OFR3(ADC2_BASE)
#define ADC3_OFR3		ADC_OFR3(ADC3_BASE)
#define ADC4_OFR3		ADC_OFR3(ADC4_BASE)

#define ADC1_OFR4		ADC_OFR4(ADC1_BASE)
#define ADC2_OFR4		ADC_OFR4(ADC2_BASE)
#define ADC3_OFR4		ADC_OFR4(ADC3_BASE)
#define ADC4_OFR4		ADC_OFR4(ADC4_BASE)

#define ADC1_JDR1		ADC_JDR1(ADC1_BASE)
#define ADC2_JDR1		ADC_JDR1(ADC2_BASE)
#define ADC3_JDR1		ADC_JDR1(ADC3_BASE)
#define ADC4_JDR1		ADC_JDR1(ADC4_BASE)

#define ADC1_JDR2		ADC_JDR2(ADC1_BASE)
#define ADC2_JDR2		ADC_JDR2(ADC2_BASE)
#define ADC3_JDR2		ADC_JDR2(ADC3_BASE)
#define ADC4_JDR2		ADC_JDR2(ADC4_BASE)

#define ADC1_JDR3		ADC_JDR3(ADC1_BASE)
#define ADC2_JDR3		ADC_JDR3(ADC2_BASE)
#define ADC3_JDR3		ADC_JDR3(ADC3_BASE)
#define ADC4_JDR3		ADC_JDR3(ADC4_BASE)

#define ADC1_JDR4		ADC_JDR4(ADC1_BASE)
#define ADC2_JDR4		ADC_JDR4(ADC2_BASE)
#define ADC3_JDR4		ADC_JDR4(ADC3_BASE)
#define ADC4_JDR4		ADC_JDR4(ADC4_BASE)

#define ADC1_AWD2CR		ADC_AWD2CR(ADC1_BASE)
#define ADC2_AWD2CR		ADC_AWD2CR(ADC2_BASE)
#define ADC3_AWD2CR		ADC_AWD2CR(ADC3_BASE)
#define ADC4_AWD2CR		ADC_AWD2CR(ADC4_BASE)

#define ADC1_AWD3CR		ADC_AWD3CR(ADC1_BASE)
#define ADC2_AWD3CR		ADC_AWD3CR(ADC2_BASE)
#define ADC3_AWD3CR		ADC_AWD3CR(ADC3_BASE)
#define ADC4_AWD3CR		ADC_AWD3CR(ADC4_BASE)

#define ADC1_DIFSEL		ADC_DIFSEL(ADC1_BASE)
#define ADC2_DIFSEL		ADC_DIFSEL(ADC2_BASE)
#define ADC3_DIFSEL		ADC_DIFSEL(ADC3_BASE)
#define ADC4_DIFSEL		ADC_DIFSEL(ADC4_BASE)

#define ADC1_CALFACT		ADC_CALFACT(ADC1_BASE)
#define ADC2_CALFACT		ADC_CALFACT(ADC2_BASE)
#define ADC3_CALFACT		ADC_CALFACT(ADC3_BASE)
#define ADC4_CALFACT		ADC_CALFACT(ADC4_BASE)

#define ADC12_CSR			ADC_CSR(ADC1)
#define ADC12_CCR			ADC_CCR(ADC1)
#define ADC12_CDR			ADC_CDR(ADC1)
#define ADC34_CSR			ADC_CSR(ADC3)
#define ADC34_CCR			ADC_CCR(ADC3)
#define ADC34_CDR			ADC_CDR(ADC3)


/*------- ADC_CR values ---------*/

/** ADVREGEN: ADC voltage regulator enable */
#define ADC_CR_ADVREGEN_ENABLE		(0x1 << 28)
#define ADC_CR_ADVREGEN_DISABLE		(0x2 << 28)
#define ADC_CR_ADVREGEN_MASK		(0x3 << 28)

/****************************************************************************/
/* ADC_SMPRx ADC Sample Time Selection for Channels */
/** @defgroup adc_sample ADC Sample Time Selection values
@ingroup adc_defines

@{*/
#define ADC_SMPR_SMP_1DOT5CYC		0x0
#define ADC_SMPR_SMP_2DOT5CYC		0x1
#define ADC_SMPR_SMP_4DOT5CYC		0x2
#define ADC_SMPR_SMP_7DOT5CYC		0x3
#define ADC_SMPR_SMP_19DOT5CYC		0x4
#define ADC_SMPR_SMP_61DOT5CYC		0x5
#define ADC_SMPR_SMP_181DOT5CYC		0x6
#define ADC_SMPR_SMP_601DOT5CYC		0x7
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
#define ADC_JSQR_JSQ4_LSB		26
#define ADC_JSQR_JSQ3_LSB		20
#define ADC_JSQR_JSQ2_LSB		14
#define ADC_JSQR_JSQ1_LSB		8

#define ADC_JSQR_JSQ_VAL(n, val)	((val) << (((n) - 1) * 6 + 8))
#define ADC_JSQR_JL_VAL(val)		(((val) - 1) << ADC_JSQR_JL_SHIFT)

/* Bits 30:26 JSQ4[4:0]: 4th conversion in the injected sequence */

/* Bits 24:20 JSQ3[4:0]: 3rd conversion in the injected sequence */

/* Bits 18:14 JSQ2[4:0]: 2nd conversion in the injected sequence */

/* Bits 12:8 JSQ1[4:0]: 1st conversion in the injected sequence */

/*
 * JEXTEN[1:0]: External Trigger Enable and Polarity Selection for injected
 * channels
 */
#define ADC_JSQR_JEXTEN_DISABLED	(0x0 << 6)
#define ADC_JSQR_JEXTEN_RISING_EDGE	(0x1 << 6)
#define ADC_JSQR_JEXTEN_FALLING_EDGE	(0x2 << 6)
#define ADC_JSQR_JEXTEN_BOTH_EDGES	(0x3 << 6)

#define ADC_JSQR_JEXTEN_MASK		(0x3 << 6)

/* JEXTSEL[3:0]: External Trigger Selection for injected group */
#define ADC_JSQR_JEXTSEL_EVENT_0	(0x0 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_1	(0x1 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_2	(0x2 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_3	(0x3 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_4	(0x4 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_5	(0x5 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_6	(0x6 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_7	(0x7 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_8	(0x8 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_9	(0x9 << 2)
#define ADC_JSQR_JEXTSEL_EVENT_10	(0xA << 2)
#define ADC_JSQR_JEXTSEL_EVENT_11	(0xB << 2)
#define ADC_JSQR_JEXTSEL_EVENT_12	(0xC << 2)
#define ADC_JSQR_JEXTSEL_EVENT_13	(0xD << 2)
#define ADC_JSQR_JEXTSEL_EVENT_14	(0xE << 2)
#define ADC_JSQR_JEXTSEL_EVENT_15	(0xF << 2)

#define ADC_JSQR_JEXTSEL_MASK		(0xF << 2)

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


/*------- ADC_DIFSEL values ---------*/

/* DIFSEL[18:16]: Differential mode for channels 18 to 16. */

/* Bits 15:1 DIFSEL[15:1]: Differential mode for channels 15 to 1 */


/*------- ADC_CALFACT values ---------*/

/* Bits 22:16 CALFACT_D[6:0]: Calibration Factors in differential mode */

/* Bits 6:0 CALFACT_S[6:0]: Calibration Factors In Single-Ended mode */


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

/* VBATEN: VBAT enable */
#define ADC_CCR_VBATEN			(1 << 24)

/* TSEN: Temperature sensor enable */
#define ADC_CCR_TSEN			(1 << 23)

/* VREFEN: VREFINT enable */
#define ADC_CCR_VREFEN			(1 << 22)

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
#define ADC_CCR_DUAL_SHIFT		0


/*---------------- ADC_CDR values -----------------*/

/* Bits 31:16 RDATA_SLV[15:0]: Regular data of the slave ADC */

/* Bits 15:0 RDATA_MST[15:0]: Regular data of the master ADC. */

/** @defgroup adc_channel ADC Channel Numbers
 * @ingroup adc_defines
 *
 *@{*/
#define ADC_CHANNEL_TEMP	16
#define ADC_CHANNEL_VBAT	17
#define ADC_CHANNEL_VREF	18
/**@}*/


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
/*void adc_enable_scan_mode(uint32_t adc);*/
/*void adc_disable_scan_mode(uint32_t adc);*/
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
void adc_set_watchdog_high_threshold(uint32_t adc, uint8_t threshold);
void adc_set_watchdog_low_threshold(uint32_t adc, uint8_t threshold);
void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
bool adc_eoc_injected(uint32_t adc);
bool adc_eos_injected(uint32_t adc);
uint32_t adc_read_injected(uint32_t adc, uint8_t reg);
void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset);

void adc_set_clk_prescale(uint32_t adc, uint32_t prescaler);
void adc_set_multi_mode(uint32_t adc, uint32_t mode);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity);
bool adc_awd(uint32_t adc);
/*void adc_set_dma_continue(uint32_t adc);*/
/*void adc_set_dma_terminate(uint32_t adc);*/

END_DECLS


#endif
