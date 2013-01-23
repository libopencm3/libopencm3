/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Matthew Lai <m@matthewlai.ca>
 * Copyright (C) 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
 * Copyright (C) 2013 ARCOS-Lab UCR <arcoslab.org> 
 * Copyright (C) 2013 Fernando Cortes <fernando.corcam@gmail.com>
 * Copyright (C) 2013 Guillermo Rivera <memogrg@gmail.com>
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

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

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


/* Control Register (ADCx_CR, x=1..4) CR */


/* Configuration Register (ADCx_CFGR, x=1..4) CFGR */


/* Sample Time Register 1 (ADCx_SMPR1, x=1..4) SMPR1 */


/* Sample Time Register 2 (ADCx_SMPR2, x=1..4) SMPR2 */


/* Watchdog Threshold Register 1 (ADCx_TR1, x=1..4) TR1 */


/* Watchdog Threshold Register 2 (ADCx_TR2, x=1..4) TR2 */


/* Watchdog Threshold Register 3 (ADCx_TR3, x=1..4) TR3 */


/* Regular Sequence Register 1 (ADCx_SQR1, x=1..4) SQR1 */


/* Regular Sequence Register 2 (ADCx_SQR2, x=1..4) SQR2 */


/* Regular Sequence Register 3 (ADCx_SQR3, x=1..4) SQR3 */


/* Regular Sequence Register 4 (ADCx_SQR3, x=1..4) SQR4 */


/* regular Data Register (ADCx_DR, x=1..4) DR */


/* Injected Sequence Register (ADCx_JSQR, x=1..4) JSQR */


/* Offset Register x (ADCx_OFRy, x=1..4) (y=1..4) OFRy */


/* Injected Data Register y (ADCx_JDRy, x=1..4, y= 1..4) JDRy */


/* Analog Watchdog 2 Configuration Register (ADCx_AWD2CR, x=1..4) AWD2CR */


/* Analog Watchdog 3 Configuration Register (ADCx_AWD3CR, x=1..4) AWDCR3 */


/* Differential Mode Selection Register 2 (ADCx_DIFSEL, x=1..4) DIFSEL */


/* Calibration Factors (ADCx_CALFACT, x=1..4) CALFACT */





