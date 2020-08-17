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
#ifndef LIBOPENCM3_ADC_COMMON_V2_MULTI_H
#define LIBOPENCM3_ADC_COMMON_V2_MULTI_H

/*
 * The adc v2 peripheral optionally supports per channel sampling, injected
 * sequences, watchdogs, offsets and other "advanced" features, and is
 * found on the (so far) F3 and L4,
 * or only a much "simpler" version as found on (so far) f0 and l0.
 */

/** @addtogroup adc_registers
 *@{*/
/* ----- ADC registers  -----------------------------------------------------*/
/* Sample Time Register 2 */
#define ADC_SMPR2(adc)		MMIO32((adc) + 0x18)
/* Watchdog Threshold Register 2 */
#define ADC_TR2(adc)		MMIO32((adc) + 0x24)
/* Watchdog Threshold Register 3 */
#define ADC_TR3(adc)		MMIO32((adc) + 0x28)
/* Regular Sequence Register x (ADCx_SQRy, x=1..4, y=1..4) SQRy */
#define ADC_SQR1(adc)		MMIO32((adc) + 0x30)
#define ADC_SQR2(adc)		MMIO32((adc) + 0x34)
#define ADC_SQR3(adc)		MMIO32((adc) + 0x38)
#define ADC_SQR4(adc)		MMIO32((adc) + 0x3C)

/* Injected Sequence Register (ADCx_JSQR, x=1..4) JSQR */
#define ADC_JSQR(adc)		MMIO32((adc) + 0x30)

/* Offset Register x (ADCx_OFRy, x=1..4) (y=1..4) OFRy */
#define ADC_OFR1(adc)		MMIO32((adc) + 0x60)
#define ADC_OFR2(adc)		MMIO32((adc) + 0x64)
#define ADC_OFR3(adc)		MMIO32((adc) + 0x68)
#define ADC_OFR4(adc)		MMIO32((adc) + 0x6C)

/* Injected Data Register y (ADCx_JDRy, x=1..4, y= 1..4) JDRy */
#define ADC_JDR1(adc)		MMIO32((adc) + 0x80)
#define ADC_JDR2(adc)		MMIO32((adc) + 0x84)
#define ADC_JDR3(adc)		MMIO32((adc) + 0x88)
#define ADC_JDR4(adc)		MMIO32((adc) + 0x8C)

/* Analog Watchdog 2 Configuration Register (ADCx_AWD2CR, x=1..4) AWD2CR */
#define ADC_AWD2CR(adc)		MMIO32((adc) + 0xA0)
/* Analog Watchdog 3 Configuration Register (ADCx_AWD3CR, x=1..4) AWD3CR */
#define ADC_AWD3CR(adc)		MMIO32((adc) + 0xA4)

/* Differential Mode Selection Register 2 (ADCx_DIFSEL, x=1..4) DIFSEL */
#define ADC_DIFSEL(adc)		MMIO32((adc) + 0xB0)

/* Calibration Factors (ADCx_CALFACT, x=1..4) CALFACT */
#define ADC_CALFACT(adc)	MMIO32((adc) + 0xB4)

/* ADC common (shared) registers */
#define ADC_CSR(adc)		MMIO32((adc) + 0x300 + 0x0)
#define ADC_CDR(adc)		MMIO32((adc) + 0x300 + 0xc)
/**@}*/

/* --- Register values ------------------------------------------------------*/
/* ADC_ISR Values -----------------------------------------------------------*/

/* QOVF: Injected context queue overflow */
#define ADC_ISR_JQOVF		(1 << 10)
/* AWD3: Analog watchdog 3 flag */
#define ADC_ISR_AWD3		(1 << 9)
/* AWD2: Analog watchdog 2 flag */
#define ADC_ISR_AWD2		(1 << 8)
/* JEOS: Injected channel end of sequence flag */
#define ADC_ISR_JEOS		(1 << 6)
/* JEOC: Injected channel end of conversion flag */
#define ADC_ISR_JEOC		(1 << 5)

/* ADC_IER Values -----------------------------------------------------------*/

/* JQOVFIE: Injected context queue overflow interrupt enable */
#define ADC_IER_JQOVFIE		(1 << 10)
/* AWD3IE: Analog watchdog 3 interrupt enable */
#define ADC_IER_AWD3IE		(1 << 9)
/* AWD2IE: Analog watchdog 2 interrupt enable */
#define ADC_IER_AWD2IE		(1 << 8)
/* JEOSIE: End of injected sequence of conversions interrupt enable */
#define ADC_IER_JEOSIE		(1 << 6)
/* JEOCIE: End of injected conversion interrupt enable */
#define ADC_IER_JEOCIE		(1 << 5)

/* ADC_CR Values ------------------------------------------------------------*/

/* ADCALDIF: Differential mode for calibration */
#define ADC_CR_ADCALDIF		(1 << 30)
/* JADSTP: ADC stop of injected conversion command */
#define ADC_CR_JADSTP		(1 << 5)
/* JADSTART: ADC start of injected conversion */
#define ADC_CR_JADSTART		(1 << 3)

/* ADC_CFGR1 Values ---------------------------------------------------------*/

/* JAUTO: Autoamtic injected group conversion */
#define ADC_CFGR1_JAUTO		(1 << 25)

/* JAWD1EN: Analog watchdog 1 enable on injected channels */
#define ADC_CFGR1_JAWD1EN	(1 << 24)

/* JQM: JSQR queue mode */
#define ADC_CFGR1_JQM		(1 << 21)

/* JDISCEN: Discontinuous mode on injected channels */
#define ADC_CFGR1_JDISCEN	(1 << 20)

/* DISCNUM[2:0]: Discontinuous mode channel count */
#define ADC_CFGR1_DISCNUM_SHIFT	17
#define ADC_CFGR1_DISCNUM_MASK  (0x7 << ADC_CFGR1_DISCNUM_SHIFT)
#define ADC_CFGR1_DISCNUM_VAL(x)	(((x) - 1) << ADC_CFGR1_DISCNUM_SHIFT)

/* ADC_SQRx Values: Regular Sequence ordering------------------------------- */

#define ADC_SQR1_L_SHIFT		0
#define ADC_SQR1_L_MASK			0xf
#define ADC_SQRx_SQx_MASK		0x1f
#define ADC_SQR1_SQ1_SHIFT		6
#define ADC_SQR1_SQ2_SHIFT		12
#define ADC_SQR1_SQ3_SHIFT		18
#define ADC_SQR1_SQ4_SHIFT		24
#define ADC_SQR2_SQ5_SHIFT		0
#define ADC_SQR2_SQ6_SHIFT		6
#define ADC_SQR2_SQ7_SHIFT		12
#define ADC_SQR2_SQ8_SHIFT		18
#define ADC_SQR2_SQ9_SHIFT		24
#define ADC_SQR3_SQ10_SHIFT		0
#define ADC_SQR3_SQ11_SHIFT		6
#define ADC_SQR3_SQ12_SHIFT		12
#define ADC_SQR3_SQ13_SHIFT		18
#define ADC_SQR3_SQ14_SHIFT		24
#define ADC_SQR4_SQ15_SHIFT		0
#define ADC_SQR4_SQ16_SHIFT		6

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time);
void adc_enable_regulator(uint32_t adc);
void adc_disable_regulator(uint32_t adc);

END_DECLS

#endif
/** @cond */
#endif
/** @endcond */
/**@}*/
