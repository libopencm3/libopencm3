/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *
 * Definitions of interrupt names on EFM32 Tiny Gecko systems
 *
 * The names and numbers are taken from d0034_efm32tg_reference_manual.pdf table 4.1.
 */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_VECTOR_H
#define LIBOPENCM3_EFM32_TINYGECKO_VECTOR_H

#define	IRQ_DMA		0
#define	IRQ_GPIO_EVEN	1
#define	IRQ_TIMER0	2
#define	IRQ_USART0_RX	3
#define	IRQ_USART0_TX	4
#define	IRQ_ACMP01	5
#define	IRQ_ADC0	6
#define	IRQ_DAC0	7
#define	IRQ_I2C0	8
#define	IRQ_GPIO_ODD	9
#define	IRQ_TIMER1	10
#define	IRQ_USART1_RX	11
#define	IRQ_USART1_TX	12
#define	IRQ_LESENSE	13
#define	IRQ_LEUART0	14
#define	IRQ_LETIMER0	15
#define	IRQ_PCNT0	16
#define	IRQ_RTC		17
#define	IRQ_CMU		18
#define	IRQ_VCMP	19
#define	IRQ_LCD		20
#define	IRQ_MSC		21
#define	IRQ_AES		22
#define	IRQ_COUNT	23 /**< See also d0002_efm32_cortex-m3_reference_manual.pdf's table 1.1's "number of interrupts" line, which shows that there are really no more interrupts and it is sufficient to allocate only 23 slots. */

#endif
