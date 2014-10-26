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

#define ADC1		ADC1_BASE
#define ADC2		ADC2_BASE
#define ADC3		ADC3_BASE
#define ADC4		ADC4_BASE

/* Master and slave ADCs common registers (ADC12 or ADC34) */


/*----------- ADC registers -------------------------------------- */

/* ADC interrupt and status register (ADCx_ISR, x=1..4) */
#define ADC_ISR(adc_base)	MMIO32(adc_base + 0x00)
#define ADC1_ISR		ADC_ISR(ADC1_BASE)
#define ADC2_ISR		ADC_ISR(ADC2_BASE)
#define ADC3_ISR		ADC_ISR(ADC3_BASE)
#define ADC4_ISR		ADC_ISR(ADC4_BASE)


/* Interrupt Enable Register (ADCx_IER, x=1..4) IER */
#define ADC_IER(adc_base)	MMIO32(adc_base + 0x04)
#define ADC1_IER		ADC_IER(ADC1_BASE)
#define ADC2_IER		ADC_IER(ADC2_BASE)
#define ADC3_IER		ADC_IER(ADC3_BASE)
#define ADC4_IER		ADC_IER(ADC4_BASE)


/* Control Register (ADCx_CR, x=1..4) CR */
#define ADC_CR(adc_base)	MMIO32(adc_base + 0x08)
#define ADC1_CR			ADC_CR(ADC1_BASE)
#define ADC2_CR			ADC_CR(ADC2_BASE)
#define ADC3_CR			ADC_CR(ADC3_BASE)
#define ADC4_CR			ADC_CR(ADC4_BASE)


/* Configuration Register (ADCx_CFGR, x=1..4) CFGR */
#define ADC_CFGR(adc_base)	MMIO32(adc_base + 0x0C)
#define ADC1_CFGR		ADC_CFGR(ADC1_BASE)
#define ADC2_CFGR		ADC_CFGR(ADC2_BASE)
#define ADC3_CFGR		ADC_CFGR(ADC3_BASE)
#define ADC4_CFGR		ADC_CFGR(ADC4_BASE)


/* Sample Time Register 1 (ADCx_SMPR1, x=1..4) SMPR1 */
#define ADC_SMPR1(adc_base)	MMIO32(adc_base + 0x14)
#define ADC1_SMPR1		ADC_SMPR1(ADC1_BASE)
#define ADC2_SMPR1		ADC_SMPR1(ADC2_BASE)
#define ADC3_SMPR1		ADC_SMPR1(ADC3_BASE)
#define ADC4_SMPR1		ADC_SMPR1(ADC4_BASE)


/* Sample Time Register 2 (ADCx_SMPR2, x=1..4) SMPR2 */
#define ADC_SMPR2(adc_base)	MMIO32(adc_base + 0x18)
#define ADC1_SMPR2		ADC_SMPR2(ADC1_BASE)
#define ADC2_SMPR2		ADC_SMPR2(ADC2_BASE)
#define ADC3_SMPR2		ADC_SMPR2(ADC3_BASE)
#define ADC4_SMPR2		ADC_SMPR2(ADC4_BASE)


/* Watchdog Threshold Register 1 (ADCx_TR1, x=1..4) TR1 */
#define ADC_TR1(adc_base)	MMIO32(adc_base + 0x20)
#define ADC1_TR1		ADC_TR1(ADC1_BASE)
#define ADC2_TR1		ADC_TR1(ADC2_BASE)
#define ADC3_TR1		ADC_TR1(ADC3_BASE)
#define ADC4_TR1		ADC_TR1(ADC4_BASE)


/* Watchdog Threshold Register 2 (ADCx_TR2, x=1..4) TR2 */
#define ADC_TR2(adc_base)	MMIO32(adc_base + 0x24)
#define ADC1_TR2		ADC_TR2(ADC1_BASE)
#define ADC2_TR2		ADC_TR2(ADC2_BASE)
#define ADC3_TR2		ADC_TR2(ADC3_BASE)
#define ADC4_TR2		ADC_TR2(ADC4_BASE)


/* Watchdog Threshold Register 3 (ADCx_TR3, x=1..4) TR3 */
#define ADC_TR3(adc_base)	MMIO32(adc_base + 0x28)
#define ADC1_TR3		ADC_TR3(ADC1_BASE)
#define ADC2_TR3		ADC_TR3(ADC2_BASE)
#define ADC3_TR3		ADC_TR3(ADC3_BASE)
#define ADC4_TR3		ADC_TR3(ADC4_BASE)


/* Regular Sequence Register 1 (ADCx_SQR1, x=1..4) SQR1 */
#define ADC_SQR1(adc_base)	MMIO32(adc_base + 0x30)
#define ADC1_SQR1		ADC_SQR1(ADC1_BASE)
#define ADC2_SQR1		ADC_SQR1(ADC2_BASE)
#define ADC3_SQR1		ADC_SQR1(ADC3_BASE)
#define ADC4_SQR1		ADC_SQR1(ADC4_BASE)


/* Regular Sequence Register 2 (ADCx_SQR2, x=1..4) SQR2 */
#define ADC_SQR2(adc_base)	MMIO32(adc_base + 0x34)
#define ADC1_SQR2		ADC_SQR2(ADC1_BASE)
#define ADC2_SQR2		ADC_SQR2(ADC2_BASE)
#define ADC3_SQR2		ADC_SQR2(ADC3_BASE)
#define ADC4_SQR2		ADC_SQR2(ADC4_BASE)


/* Regular Sequence Register 3 (ADCx_SQR3, x=1..4) SQR3 */
#define ADC_SQR3(adc_base)	MMIO32(adc_base + 0x38)
#define ADC1_SQR3		ADC_SQR3(ADC1_BASE)
#define ADC2_SQR3		ADC_SQR3(ADC2_BASE)
#define ADC3_SQR3		ADC_SQR3(ADC3_BASE)
#define ADC4_SQR3		ADC_SQR3(ADC4_BASE)


/* Regular Sequence Register 4 (ADCx_SQR3, x=1..4) SQR4 */
#define ADC_SQR4(adc_base)	MMIO32(adc_base + 0x3C)
#define ADC1_SQR4		ADC_SQR4(ADC1_BASE)
#define ADC2_SQR4		ADC_SQR4(ADC2_BASE)
#define ADC3_SQR4		ADC_SQR4(ADC3_BASE)
#define ADC4_SQR4		ADC_SQR4(ADC4_BASE)


/* regular Data Register (ADCx_DR, x=1..4) DR */
#define ADC_DR(adc_base)	MMIO32(adc_base + 0x40)
#define ADC1_DR			ADC_DR(ADC1_BASE)
#define ADC2_DR			ADC_DR(ADC2_BASE)
#define ADC3_DR			ADC_DR(ADC3_BASE)
#define ADC4_DR			ADC_DR(ADC4_BASE)


/* Injected Sequence Register (ADCx_JSQR, x=1..4) JSQR */
#define ADC_JSQR(adc_base)	MMIO32(adc_base + 0x30)
#define ADC1_JSQR		ADC_JSQR(ADC1_BASE)
#define ADC2_JSQR		ADC_JSQR(ADC2_BASE)
#define ADC3_JSQR		ADC_JSQR(ADC3_BASE)
#define ADC4_JSQR		ADC_JSQR(ADC4_BASE)


/* Offset Register x (ADCx_OFRy, x=1..4) (y=1..4) OFRy */
#define ADC_OFR1(adc_base)	MMIO32(adc_base + 0x60)
#define ADC1_OFR1		ADC_OFR1(ADC1_BASE)
#define ADC2_OFR1		ADC_OFR1(ADC2_BASE)
#define ADC3_OFR1		ADC_OFR1(ADC3_BASE)
#define ADC4_OFR1		ADC_OFR1(ADC4_BASE)

#define ADC_OFR2(adc_base)	MMIO32(adc_base + 0x64)
#define ADC1_OFR2		ADC_OFR2(ADC1_BASE)
#define ADC2_OFR2		ADC_OFR2(ADC2_BASE)
#define ADC3_OFR2		ADC_OFR2(ADC3_BASE)
#define ADC4_OFR2		ADC_OFR2(ADC4_BASE)

#define ADC_OFR3(adc_base)	MMIO32(adc_base + 0x68)
#define ADC1_OFR3		ADC_OFR3(ADC1_BASE)
#define ADC2_OFR3		ADC_OFR3(ADC2_BASE)
#define ADC3_OFR3		ADC_OFR3(ADC3_BASE)
#define ADC4_OFR3		ADC_OFR3(ADC4_BASE)

#define ADC_OFR4(adc_base)	MMIO32(adc_base + 0x6C)
#define ADC1_OFR4		ADC_OFR4(ADC1_BASE)
#define ADC2_OFR4		ADC_OFR4(ADC2_BASE)
#define ADC3_OFR4		ADC_OFR4(ADC3_BASE)
#define ADC4_OFR4		ADC_OFR4(ADC4_BASE)


/* Injected Data Register y (ADCx_JDRy, x=1..4, y= 1..4) JDRy */
#define ADC_JDR1(adc_base)	MMIO32(adc_base + 0x80)
#define ADC1_JDR1		ADC_JDR1(ADC1_BASE)
#define ADC2_JDR1		ADC_JDR1(ADC2_BASE)
#define ADC3_JDR1		ADC_JDR1(ADC3_BASE)
#define ADC4_JDR1		ADC_JDR1(ADC4_BASE)

#define ADC_JDR2(adc_base)	MMIO32(adc_base + 0x84)
#define ADC1_JDR2		ADC_JDR2(ADC1_BASE)
#define ADC2_JDR2		ADC_JDR2(ADC2_BASE)
#define ADC3_JDR2		ADC_JDR2(ADC3_BASE)
#define ADC4_JDR2		ADC_JDR2(ADC4_BASE)

#define ADC_JDR3(adc_base)	MMIO32(adc_base + 0x88)
#define ADC1_JDR3		ADC_JDR3(ADC1_BASE)
#define ADC2_JDR3		ADC_JDR3(ADC2_BASE)
#define ADC3_JDR3		ADC_JDR3(ADC3_BASE)
#define ADC4_JDR3		ADC_JDR3(ADC4_BASE)

#define ADC_JDR4(adc_base)	MMIO32(adc_base + 0x8C)
#define ADC1_JDR4		ADC_JDR4(ADC1_BASE)
#define ADC2_JDR4		ADC_JDR4(ADC2_BASE)
#define ADC3_JDR4		ADC_JDR4(ADC3_BASE)
#define ADC4_JDR4		ADC_JDR4(ADC4_BASE)


/* Analog Watchdog 2 Configuration Register (ADCx_AWD2CR, x=1..4) AWD2CR */
#define ADC_AWD2CR(adc_base)	MMIO32(adc_base + 0xA0)
#define ADC1_AWD2CR		ADC_AWD2CR(ADC1_BASE)
#define ADC2_AWD2CR		ADC_AWD2CR(ADC2_BASE)
#define ADC3_AWD2CR		ADC_AWD2CR(ADC3_BASE)
#define ADC4_AWD2CR		ADC_AWD2CR(ADC4_BASE)


/* Analog Watchdog 3 Configuration Register (ADCx_AWD3CR, x=1..4) AWD3CR */
#define ADC_AWD3CR(adc_base)	MMIO32(adc_base + 0xA4)
#define ADC1_AWD3CR		ADC_AWD3CR(ADC1_BASE)
#define ADC2_AWD3CR		ADC_AWD3CR(ADC2_BASE)
#define ADC3_AWD3CR		ADC_AWD3CR(ADC3_BASE)
#define ADC4_AWD3CR		ADC_AWD3CR(ADC4_BASE)


/* Differential Mode Selection Register 2 (ADCx_DIFSEL, x=1..4) DIFSEL */
#define ADC_DIFSEL(adc_base)	MMIO32(adc_base + 0xB0)
#define ADC1_DIFSEL		ADC_DIFSEL(ADC1_BASE)
#define ADC2_DIFSEL		ADC_DIFSEL(ADC2_BASE)
#define ADC3_DIFSEL		ADC_DIFSEL(ADC3_BASE)
#define ADC4_DIFSEL		ADC_DIFSEL(ADC4_BASE)


/* Calibration Factors (ADCx_CALFACT, x=1..4) CALFACT */
#define ADC_CALFACT(adc_base)	MMIO32(adc_base + 0xB4)
#define ADC1_CALFACT		ADC_CALFACT(ADC1_BASE)
#define ADC2_CALFACT		ADC_CALFACT(ADC2_BASE)
#define ADC3_CALFACT		ADC_CALFACT(ADC3_BASE)
#define ADC4_CALFACT		ADC_CALFACT(ADC4_BASE)

/* ADC common (shared) registers */
#define	ADC_COMMON_REGISTERS_BASE	(ADC1_BASE+0x300)
#define ADC_CSR				MMIO32(ADC_COMMON_REGISTERS_BASE + 0x0)
#define ADC_CCR				MMIO32(ADC_COMMON_REGISTERS_BASE + 0x8)
#define ADC_CDR				MMIO32(ADC_COMMON_REGISTERS_BASE + 0xA)


/*------- ADC_ISR values ---------*/

/* QOVF: Injected context queue overflow */
#define ADC_ISR_JQOVF		(1 << 10)

/* AWD3: Analog watchdog 3 flag */
#define ADC_ISR_AWD3		(1 << 9)

/* AWD2: Analog watchdog 2 flag */
#define ADC_ISR_AWD2		(1 << 8)

/* AWD1: Analog watchdog 1 flag */
#define ADC_ISR_AWD1		(1 << 7)

/* JEOS: Injected channel end of sequence flag */
#define ADC_ISR_JEOS		(1 << 6)

/* JEOC: Injected channel end of conversion flag */
#define ADC_ISR_JEOC		(1 << 5)

/* OVR: ADC overrun */
#define ADC_ISR_OVR		(1 << 4)

/* EOS: End of regular sequence flag */
#define ADC_ISR_EOS		(1 << 3)

/* EOC: End of conversion flag */
#define ADC_ISR_EOC		(1 << 2)

/* EOSMP: End of sampling flag */
#define ADC_ISR_EOSMP		(1 << 1)

/* ADRDY: ADC ready */
#define ADC_ISR_ADRDY		(1 << 0)


/*------- ADC_IER values ---------*/

/* JQOVFIE: Injected context queue overflow interrupt enable */
#define ADC_IER_JQOVFIE		(1 << 10)

/* AWD3IE: Analog watchdog 3 interrupt enable */
#define ADC_IER_AWD3IE		(1 << 9)

/* AWD2IE: Analog watchdog 2 interrupt enable */
#define ADC_IER_AWD2IE		(1 << 8)

/* AWD1IE: Analog watchdog 1 interrupt enable */
#define ADC_IER_AWD1IE		(1 << 7)

/* JEOSIE: End of injected sequence of conversions interrupt enable */
#define ADC_IER_JEOSIE		(1 << 6)

/* JEOCIE: End of injected conversion interrupt enable */
#define ADC_IER_JEOCIE		(1 << 5)

/* OVRIE: Overrun interrupt enable */
#define ADC_IER_OVRIE		(1 << 4)

/* EOSIE: End of regular sequence of conversions interrupt enable */
#define ADC_IER_EOSIE		(1 << 3)

/* EOCIE: End of regular conversion interrupt enable */
#define ADC_IER_EOCIE		(1 << 2)

/* EOSMPIE: End of sampling flag interrupt enable for regular conversions */
#define ADC_IER_EOSMPIE		(1 << 1)

/* ADRDYIE : ADC ready interrupt enable */
#define ADC_IER_ADRDYIE		(1 << 0)


/*------- ADC_CR values ---------*/

/* ADCAL: ADC calibration */
#define ADC_CR_ADCAL		(1 << 31)

/* ADCALDIF: Differential mode for calibration */
#define ADC_CR_ADCALDIF		(1 << 30)

/* ADVREGEN: ADC voltage regulador enable */
#define ADC_CR_ADVREGEN_INTERMEDIATE	(0x0 << 28)
#define ADC_CR_ADVREGEN_ENABLE		(0x1 << 28)
#define ADC_CR_ADVREGEN_DISABLE		(0x2 << 28)
/* --- Bit 0x3 reserved --- */

/* JADSTP: ADC stop of injected conversion command */
#define ADC_CR_JADSTP		(1 << 5)

/* ADSTP: ADC stop of regular conversion command */
#define ADC_CR_ADSTP		(1 << 4)

/* JADSTART: ADC start of injected conversion */
#define ADC_CR_JADSTART		(1 << 3)

/* ADSTART: ADC start of regular conversion */
#define ADC_CR_ADSTART		(1 << 2)

/* ADDIS: ADC disable command */
#define ADC_CR_ADDIS		(1 << 1)

/* ADEN: ADC enable control */
#define ADC_CR_ADEN		(1 << 0)


/*------- ADC_CFGR values ---------*/

/* AWD1CH[4:0]: Analog watchdog 1 channel selection */
/* Bit 0x0 reserved */
#define ADC_CFGR_AWD1CH_ADC_IN_CH_1	(0x01 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_2	(0x02 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_3	(0x03 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_4	(0x04 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_5	(0x05 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_6	(0x06 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_7	(0x07 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_8	(0x08 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_9	(0x09 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_10	(0x0A << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_11	(0x0B << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_12	(0x0C << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_13	(0x0D << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_14	(0x0E << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_15	(0x0F << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_16	(0x10 << 26)
#define ADC_CFGR_AWD1CH_ADC_IN_CH_17	(0x11 << 26)

#define ADC_CFGR_AWD1CH_MASK		(0x1F << 26)

/* Ohters bits reserved, must not be used */

/* JAUTO: Autoamtic injected group conversion */
#define ADC_CFGR_JAUTO		(1 << 25)

/* JAWD1EN: Analog watchdog 1 enable on injected channels */
#define ADC_CFGR_JAWD1EN	(1 << 24)

/* AWD1EN: Analog watchdog 1 enable on regular channels */
#define ADC_CFGR_AWD1EN		(1 << 23)

/* AWD1SGL: Enable the watchdog 1 on a single channel or on all channels */
#define ADC_CFGR_AWD1SGL	(1 << 22)

/* JQM: JSQR queue mode */
#define ADC_CFGR_JQM		(1 << 21)

/* JDISCEN: Discontinuous mode on injected channels */
#define ADC_CFGR_JDISCEN	(1 << 20)

/* DISCNUM[2:0]: Discontinuous mode channel count */
#define ADC_CFGR_DISCNUM_1_CH	(0x0 << 17)
#define ADC_CFGR_DISCNUM_2_CH	(0x1 << 17)
#define ADC_CFGR_DISCNUM_3_CH	(0x2 << 17)
#define ADC_CFGR_DISCNUM_4_CH	(0x3 << 17)
#define ADC_CFGR_DISCNUM_5_CH	(0x4 << 17)
#define ADC_CFGR_DISCNUM_6_CH	(0x5 << 17)
#define ADC_CFGR_DISCNUM_7_CH	(0x6 << 17)
#define ADC_CFGR_DISCNUM_8_CH	(0x7 << 17)
#define ADC_CFGR_DISCNUM_SHIFT	17

/* DISCEN: Discontinuous mode for regular channels */
#define ADC_CFGR_DISCEN		(1 << 16)

/* AUTDLY: Delayed conversion mode */
#define ADC_CFGR_AUTDLY		(1 << 14)

/* CONT: Single / continuous conversion mode for regular conversions */
#define ADC_CFGR_CONT		(1 << 13)

/* OVRMOD: Overrun Mode */
#define ADC_CFGR_OVRMOD		(1 << 12)

/*
 * EXTEN[1:0]: External trigger enable and polarity selection for regular
 * channels
 */
#define ADC_CFGR_EXTEN_DISABLED		(0x0 << 10)
#define ADC_CFGR_EXTEN_RISING_EDGE	(0x1 << 10)
#define ADC_CFGR_EXTEN_FALLING_EDGE	(0x2 << 10)
#define ADC_CFGR_EXTEN_BOTH_EDGES	(0x3 << 10)

#define ADC_CFGR_EXTEN_MASK		(0x3 << 10)

/* EXTSEL[3:0]: External trigger selection for regular group */
#define ADC_CFGR_EXTSEL_EVENT_0		(0x0 << 6)
#define ADC_CFGR_EXTSEL_EVENT_1		(0x1 << 6)
#define ADC_CFGR_EXTSEL_EVENT_2		(0x2 << 6)
#define ADC_CFGR_EXTSEL_EVENT_3		(0x3 << 6)
#define ADC_CFGR_EXTSEL_EVENT_4		(0x4 << 6)
#define ADC_CFGR_EXTSEL_EVENT_5		(0x5 << 6)
#define ADC_CFGR_EXTSEL_EVENT_6		(0x6 << 6)
#define ADC_CFGR_EXTSEL_EVENT_7		(0x7 << 6)
#define ADC_CFGR_EXTSEL_EVENT_8		(0x8 << 6)
#define ADC_CFGR_EXTSEL_EVENT_9		(0x9 << 6)
#define ADC_CFGR_EXTSEL_EVENT_10	(0xA << 6)
#define ADC_CFGR_EXTSEL_EVENT_11	(0xB << 6)
#define ADC_CFGR_EXTSEL_EVENT_12	(0xC << 6)
#define ADC_CFGR_EXTSEL_EVENT_13	(0xD << 6)
#define ADC_CFGR_EXTSEL_EVENT_14	(0xE << 6)
#define ADC_CFGR_EXTSEL_EVENT_15	(0xF << 6)

#define ADC_CFGR_EXTSEL_MASK		(0xF << 6)

/* ALIGN: Data alignment */
#define ADC_CFGR_ALIGN		(1 << 5)

/* RES[1:0]: Data resolution */
#define ADC_CFGR_RES_12_BIT	(0x0 << 3)
#define ADC_CFGR_RES_10_BIT	(0x1 << 3)
#define ADC_CFGR_RES_8_BIT	(0x2 << 3)
#define ADC_CFGR_RES_6_BIT	(0x3 << 3)

#define ADC_CFGR_RES_MASK	(0x3 << 3)

/* DMACFG: Direct memory access configuration */
#define ADC_CFGR_DMACFG		(1 << 1)

/* DMAEN: Direct memory access enable */
#define ADC_CFGR_DMAEN		(1 << 0)


/*------- ADC_SMPR1 values ---------*/
#define ADC_SMPR1_SMP8_LSB		24
#define ADC_SMPR1_SMP7_LSB		21
#define ADC_SMPR1_SMP6_LSB		18
#define ADC_SMPR1_SMP5_LSB		15
#define ADC_SMPR1_SMP4_LSB		12
#define ADC_SMPR1_SMP3_LSB		9
#define ADC_SMPR1_SMP2_LSB		6
#define ADC_SMPR1_SMP1_LSB		3
#define ADC_SMPR1_SMP8_MSK		(0x7 << ADC_SMP8_LSB)
#define ADC_SMPR1_SMP7_MSK		(0x7 << ADC_SMP7_LSB)
#define ADC_SMPR1_SMP6_MSK		(0x7 << ADC_SMP6_LSB)
#define ADC_SMPR1_SMP5_MSK		(0x7 << ADC_SMP5_LSB)
#define ADC_SMPR1_SMP4_MSK		(0x7 << ADC_SMP4_LSB)
#define ADC_SMPR1_SMP3_MSK		(0x7 << ADC_SMP3_LSB)
#define ADC_SMPR1_SMP2_MSK		(0x7 << ADC_SMP2_LSB)
#define ADC_SMPR1_SMP1_MSK		(0x7 << ADC_SMP1_LSB)
/****************************************************************************/
/* ADC_SMPR1 ADC Sample Time Selection for Channels */
/** @defgroup adc_sample_r1 ADC Sample Time Selection for ADC1
@ingroup adc_defines

@{*/
#define ADC_SMPR1_SMP_1DOT5CYC		0x0
#define ADC_SMPR1_SMP_2DOT5CYC		0x1
#define ADC_SMPR1_SMP_4DOT5CYC		0x2
#define ADC_SMPR1_SMP_7DOT5CYC		0x3
#define ADC_SMPR1_SMP_19DOT5CYC		0x4
#define ADC_SMPR1_SMP_61DOT5CYC		0x5
#define ADC_SMPR1_SMP_181DOT5CYC	0x6
#define ADC_SMPR1_SMP_601DOT5CYC	0x7
/**@}*/

/* SMPx[2:0]: Channel x sampling time selection */


/*------- ADC_SMPR2 values ---------*/

/* SMPx[2:0]: Channel x sampling time selection */



/*------- ADC_TR1 values ---------*/

/* Bits 27:16 HT1[11:0]: Analog watchdog 1 higher threshold */

/* Bit 11:0 LT1[11:0]: Analog watchdog 1 lower threshold */


/*------- ADC_T2 values ---------*/

/* Bits 23:16 HT2[7:0]: Analog watchdog 2 higher threshold */

/* Bit 7:0 LT2[7:0]: Analog watchdog 2 lower threshold */


/*------- ADC_T3 values ---------*/

/* Bits 23:16 HT3[7:0]: Analog watchdog 3 higher threshold */

/* Bit 7:0 LT3[7:0]: Analog watchdog 3 lower threshold */


/*------- ADC_SQR1 values ---------*/

#define ADC_SQR1_L_LSB			0
#define ADC_SQR1_SQ1_LSB		6
#define ADC_SQR1_SQ2_LSB		12
#define ADC_SQR1_SQ3_LSB		18
#define ADC_SQR1_SQ4_LSB		24
#define ADC_SQR1_L_MSK			(0xf << ADC_SQR1_L_LSB)
#define ADC_SQR1_SQ1_MSK		(0x1f << ADC_SQR1_SQ1_LSB)
#define ADC_SQR1_SQ2_MSK		(0x1f << ADC_SQR1_SQ2_LSB)
#define ADC_SQR1_SQ3_MSK		(0x1f << ADC_SQR1_SQ3_LSB)
#define ADC_SQR1_SQ4_MSK		(0x1f << ADC_SQR1_SQ4_LSB)

/* Bits 28:24 SQ4[4:0]: 4th conversion in regular sequence */

/* Bits 22:18 SQ3[4:0]: 3rd conversion in regular sequence */

/* Bits 16:12 SQ2[4:0]: 2nd conversion in regular sequence */

/* Bits 10:6 SQ1[4:0]: 1st conversion in regular sequence */

/* L[3:0]: Regular channel sequence length */
#define ADC_SQR1_L_1_CONVERSION		(0x0 << 0)
#define ADC_SQR1_L_2_CONVERSION		(0x1 << 0)
#define ADC_SQR1_L_3_CONVERSION		(0x2 << 0)
#define ADC_SQR1_L_4_CONVERSION		(0x3 << 0)
#define ADC_SQR1_L_5_CONVERSION		(0x4 << 0)
#define ADC_SQR1_L_6_CONVERSION		(0x5 << 0)
#define ADC_SQR1_L_7_CONVERSION		(0x6 << 0)
#define ADC_SQR1_L_8_CONVERSION		(0x7 << 0)
#define ADC_SQR1_L_9_CONVERSION		(0x8 << 0)
#define ADC_SQR1_L_10_CONVERSION	(0x9 << 0)
#define ADC_SQR1_L_11_CONVERSION	(0xA << 0)
#define ADC_SQR1_L_12_CONVERSION	(0xB << 0)
#define ADC_SQR1_L_13_CONVERSION	(0xC << 0)
#define ADC_SQR1_L_14_CONVERSION	(0xD << 0)
#define ADC_SQR1_L_15_CONVERSION	(0xE << 0)
#define ADC_SQR1_L_16_CONVERSION	(0xF << 0)


/*------- ADC_SQR2 values ---------*/

/* Bits 28:24 SQ9[4:0]: 9th conversion in regular sequence */

/* Bits 22:18 SQ8[4:0]: 8th conversion in regular sequence */

/* Bits 16:12 SQ7[4:0]: 7th conversion in regular sequence */

/* Bits 10:6 SQ6[4:0]: 6th conversion in regular sequence */

/* Bits 4:0 SQ5[4:0]: 5th conversion in regular sequence */


/*------- ADC_SQR3 values ---------*/

/* Bits 28:24 SQ14[4:0]: 14th conversion in regular sequence */

/* Bits 22:18 SQ13[4:0]: 13th conversion in regular sequence */

/* Bits 16:12 SQ12[4:0]: 12th conversion in regular sequence */

/* Bits 10:6 SQ11[4:0]: 11th conversion in regular sequence */

/* Bits 4:0 SQ10[4:0]: 10th conversion in regular sequence */


/*------- ADC_SQR4 values ---------*/

/* Bits 10:6 SQ16[4:0]: 16th conversion in regular sequence */

/* Bits 4:0 SQ15[4:0]: 15th conversion in regular sequence */


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



BEGIN_DECLS

void adc_power_on(uint32_t adc);
void adc_off(uint32_t adc);
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
void adc_enable_all_awd_interrupt(uint32_t adc);
void adc_disable_all_awd_interrupt(uint32_t adc);
void adc_enable_eoc_interrupt(uint32_t adc);
void adc_disable_eoc_interrupt(uint32_t adc);
void adc_start_conversion_regular(uint32_t adc);
void adc_start_conversion_injected(uint32_t adc);
void adc_disable_external_trigger_regular(uint32_t adc);
void adc_disable_external_trigger_injected(uint32_t adc);
void adc_set_left_aligned(uint32_t adc);
void adc_set_right_aligned(uint32_t adc);
void adc_enable_dma(uint32_t adc);
void adc_disable_dma(uint32_t adc);
void adc_set_continuous_conversion_mode(uint32_t adc);
void adc_set_single_conversion_mode(uint32_t adc);
void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time);
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time);
void adc_set_watchdog_high_threshold(uint32_t adc, uint8_t threshold);
void adc_set_watchdog_low_threshold(uint32_t adc, uint8_t threshold);
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
bool adc_eoc(uint32_t adc);
bool adc_eoc_injected(uint32_t adc);
uint32_t adc_read_regular(uint32_t adc);
uint32_t adc_read_injected(uint32_t adc, uint8_t reg);
void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset);

void adc_set_clk_prescale(uint32_t prescaler);
void adc_set_multi_mode(uint32_t mode);
void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity);
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity);
void adc_set_resolution(uint32_t adc, uint16_t resolution);
void adc_enable_overrun_interrupt(uint32_t adc);
void adc_disable_overrun_interrupt(uint32_t adc);
bool adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);
bool adc_awd(uint32_t adc);
void adc_eoc_after_each(uint32_t adc);
void adc_eoc_after_group(uint32_t adc);
/*void adc_set_dma_continue(uint32_t adc);*/
/*void adc_set_dma_terminate(uint32_t adc);*/
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);

END_DECLS


#endif
